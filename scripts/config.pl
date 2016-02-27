#!/usr/bin/env perl

use warnings;
use strict;

use constant {
    UART0_CLKFREQ => 3000000, # 3Mhz
};

my %special = (
    'uart_baudrate' => \&set_baudrate,
    );

sub gen_define {
    my ($name, $value) = @_;

    "#define $name $value";
}

sub set_baudrate {
    my $baud = shift;

    my $magic = UART0_CLKFREQ / (16 * $baud);

    my $dv = gen_define( 'UART0_BR_DV' => int($magic) );
    my $fr = gen_define( 'UART0_BR_FR' => int((($magic - int($magic)) * 64) + 0.5));

    "$dv\n$fr";
}

sub gen_config {
    my $file = shift;

    open my $cfh, '<', $file or die $!;
    
    while (my $line = <$cfh>) {

	chomp $line;
	$line =~ s/\s+|\s+$//; # trim
	next if $line =~ /^#/; # ignore comments

	my ($parameter, $value) = split ':', $line;

	# Ignore empty parameters / values:
	next unless $parameter;
	next unless $value;

	$parameter =~ s/\s+|\s+$//;
	$value     =~ s/\s+|\s+$//;

	if ( exists($special{$parameter}) ) {
	    print $special{$parameter}->($value) . "\n";
	}

	else {

	    print gen_define( $parameter => $value ) . "\n";
	}
    }

    close $cfh;
}

my $file = shift or die "usage: $0 <configfile>\n";

while (my $line = <DATA>) {

    if ($line =~ /^\./) {

	gen_config($file);
	next;
    }

    print $line;
}

__DATA__
#ifndef __CONFIG_H__
#define __CONFIG_H__


...

#endif // __CONFIG_H__
