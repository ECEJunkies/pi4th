//Written by Hunter R Smith, Electrical Engineering, University of Maine in Orono, 03/07/2016

struct boot_sector{				//Making note of byte offsets for the perpose of finding specific fields for info.
	char BS_jmpBoot=0;
	char BS_OEMName=3;
	char BPB_BytsPerSec=11;
	char BPB_SecPerClus=13;
	char BPB_RsvdSecCnt=14;
	char BPB_NumFATs=16;
	char BPB_RootEntCnt=17;
	char BPB_TotSec16=19;
	char BPB_Media=21;
	char BPB_FATSz16=22;
	char BPB_SecPerTrk=24;
	char BPB_NumHeads=26;
	char BPB_HiddSec=28;
	char BPB_TotSec32=32;		//As defined by microsoft extrnsible firmware initiative fat32 file system specification
	char BPB_FATSz32=36;
	char BPB_ExtFlags=40;
	char BPB_FSVer=42;
	char BPB_RootClus=44;
	char BPB_FSInfo=48;
	char BPB_BkBootSec=50;
	char BPB_Reserved=52;
	char BS_DrvNum=64;
	char BS_Reserved1=65;
	char BS_BootSig=66;
	char BS_VolID=67;
	char BS_VolLab=71;
	char BS_FilSysType=82;
}; struct boot_sector

//I want to read from the sd card.

//I want to write to the sd card.

//I would like to get file system information from the sd card
