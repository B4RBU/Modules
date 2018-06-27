#include <xc.h>
#include "mcc_generated_files/mcc.h"


unsigned long loc,BootSector, RootDir, SectorsPerFat, RootDirCluster, DataSector, FileCluster, FileSize;	//
unsigned int BytesPerSector, ReservedSectors, card;	//, RootEntries

unsigned char sdhc=0, SectorsPerCluster, Fats;	//standard sd

void file(unsigned int offset, unsigned char sect)	//find files
{
	unsigned int r,i=0;
	unsigned char fc[4], fs[4]; //
	r = Command(17,(RootDir+sect)*card,0xFF);		//read boot-sector for info from file entry
				//if command failed
	
	while(SPI(0xFF) != 0xFe);	// wait for first byte
	for(i=0;i<512;i++){
		if(i==offset){fc[2]=SPI(0xFF);} 
		else if(i==offset+1){fc[3]=SPI(0xFF);}
		else if(i==offset+6){fc[0]=SPI(0xFF);}
		else if(i==offset+7){fc[1]=SPI(0xFF);}
		
		else if(i==offset+8){fs[0]=SPI(0xFF);}
		else if(i==offset+9){fs[1]=SPI(0xFF);}
		else if(i==offset+10){fs[2]=SPI(0xFF);}
		else if(i==offset+11){fs[3]=SPI(0xFF);}
		else{SPI(0xFF);}
		
	}
	SPI(0xFF);	//discard of CRC
	SPI(0xFF);
    SPI(0xFF);
	FileCluster = fc[0] | ( (unsigned long)fc[1] << 8 ) | ( (unsigned long)fc[2] << 16 ) | ( (unsigned long)fc[3] << 24 );
	FileSize = fs[0] | ( (unsigned long)fs[1] << 8 ) | ( (unsigned long)fs[2] << 16 ) | ( (unsigned long)fs[3] << 24 );
	FileSize = FileSize/512+1;		//file size in sectors
}
	
void readSD(void)
{
	unsigned int i,r;
	unsigned char data;
	
	CS_SetLow();
	r = Command(18,loc,0xFF);	//read multi-sector
				//if command failed

	while(FileSize--)
	{	
		while(SPI(0xFF) != 0xFE);	// wait for first byte
		for(i=0;i<512;i++){
			while(!T0IF){}
			TMR0=165;		//(256-91) 91 counts to get 22KHz, play speed
			T0IF = 0;
			data = SPI(0xFF);

			CCPR1L = (data >> 2);
		}
		SPI(0xFF);	//discard of CRC
		SPI(0xFF);
	}
	Command(12,0x00,0xFF);	//stop transmit
	SPI(0xFF);
	SPI(0xFF);
	CS_SetHigh();SPI(0xFF);
}

void fat (void)
{
	unsigned int r,i;
	unsigned char pfs[4],bps1,bps2,rs1,rs2,spf[4],rdc[4]; //pfs=partition first sector ,de1,de2,spf1,d[7]
	
       //CS_SetLow();
	r = Command(17,0,0xFF);		//read MBR-sector
    if(r != 0){LED1_SetHigh();
                    LED2_SetHigh();
                    LED3_SetHigh();}
	
	
	while(SPI(0xFF) != 0xFe);	// wait for first byte
	for(i=0;i<512;i++){
		if(i==454){pfs[0]=SPI(0xFF);}	//pfs=partition first sector
		else if(i==455){pfs[1]=SPI(0xFF);}
		else if(i==456){pfs[2]=SPI(0xFF);}
		else if(i==457){pfs[3]=SPI(0xFF);}
		else{SPI(0xFF);}
		
	}
	SPI(0xFF);	//discard of CRC
	SPI(0xFF);
	SPI(0xFF);
	//convert 4 bytes to long int
	BootSector = pfs[0] | ( (unsigned long)pfs[1] << 8 ) | ( (unsigned long)pfs[2] << 16 ) | ( (unsigned long)pfs[3] << 24 );
	
	
	r = Command(17,BootSector*card,0xFF);		//read boot-sector
			//if command failed
	
	while(SPI(0xFF) != 0xFe);	// wait for first byte
	for(i=0;i<512;i++){
		
		if(i==11){bps1=SPI(0xFF);} //bytes per sector
		else if(i==12){bps2=SPI(0xFF);}
		else if(i==13){SectorsPerCluster=SPI(0xFF);}
		else if(i==14){rs1=SPI(0xFF);}
		else if(i==15){rs2=SPI(0xFF);}
		else if(i==16){Fats=SPI(0xFF);}	//number of FATs
		else if(i==36){spf[0]=SPI(0xFF);}
		else if(i==37){spf[1]=SPI(0xFF);}
		else if(i==38){spf[2]=SPI(0xFF);}
		else if(i==39){spf[3]=SPI(0xFF);}
		else if(i==44){rdc[0]=SPI(0xFF);}
		else if(i==45){rdc[1]=SPI(0xFF);}
		else if(i==46){rdc[2]=SPI(0xFF);}
		else if(i==47){rdc[3]=SPI(0xFF);}
		else{SPI(0xFF);}
		
	}
	SPI(0xFF);	//discard of CRC
	SPI(0xFF);
	SPI(0xFF);		
	
	BytesPerSector = bps1 | ( (unsigned int)bps2 << 8 );
	ReservedSectors = rs1 | ( (unsigned int)rs2 << 8 );	//from partition start to first FAT
	RootDirCluster = rdc[0] | ( (unsigned long)rdc[1] << 8 ) | ( (unsigned long)rdc[2] << 16 ) | ( (unsigned long)rdc[3] << 24 );
	SectorsPerFat = spf[0] | ( (unsigned long)spf[1] << 8 ) | ( (unsigned long)spf[2] << 16 ) | ( (unsigned long)spf[3] << 24 );
	DataSector = BootSector + (unsigned long)Fats * (unsigned long)SectorsPerFat + (unsigned long)ReservedSectors;	// + 1  
	RootDir = (RootDirCluster -2) * (unsigned long)SectorsPerCluster + DataSector;
}

unsigned char SPI(unsigned char spidata)		// send character over SPI
{
	SSP1BUF = spidata;			// load character
	while (!BF);		// sent
	return SSP1BUF;		// received character
}

char Command(unsigned char frame1, unsigned long adrs, unsigned char frame2 )
{	
	unsigned char i, res;
	
	//SPI(0xFF);
	SPI((frame1 | 0x40) & 0x7F);	//first 2 bits are 01
	SPI((adrs & 0xFF000000) >> 24);		//first of the 4 bytes address
	SPI((adrs & 0x00FF0000) >> 16);
	SPI((adrs & 0x0000FF00) >> 8);
	SPI(adrs & 0x000000FF);	
	SPI(frame2 | 1);				//CRC and last bit 1

	for(i=0;i<10;i++)	// wait for received character
	{
		res = SPI(0xFF);
		if(res != 0xFF)break;
	}
	return res;	  
}

void initSD(void)
{
	unsigned char i,r[4];
	
	CS_SetHigh();
	for(i=0; i < 10; i++)SPI(0xFF);		// min 74 clocks
	CS_SetLow();			// Enabled for SPI mode

	//if (Command(0x00,0,0x95) !=1) errorLED = 1;	//start SPI mode
	i=100;	//try enter idle state for up to 100 times
	while(Command(0x00,0,0x95) !=1 && i!=0)
	{ 
		//CS_SetHigh();
		SPI(0xFF);
		//CS_SetLow();
		i--;
	}
if(i==0)
        {	LED1_SetHigh();
            LED2_SetHigh();
            LED3_SetHigh();
        }	//idle failed
		
	if (Command(8,0x01AA,0x87)==1){					//check card is 3.3V
		r[0]=SPI(0xFF); r[1]=SPI(0xFF); r[2]=SPI(0xFF); r[3]=SPI(0xFF);		//rest of R7
		if ( r[2] == 0x01 && r[3] == 0xAA ){ 		//Vdd OK (3.3V)
			
			//Command(59,0,0xFF);		//CRC off
			Command(55,0,0xFF);
			while(Command(41,0x40000000,0xFF)){Command(55,0,0xFF);} 	//ACMD41 with HCSsd bit
			}else{ 	LED1_SetHigh();
                    LED2_SetHigh();
                    LED3_SetHigh();} 
                                	}
	
	if (Command(58,0,0xFF)==0)
    {		//read CCSsd in the OCR - SD or SDHC
		r[0]=SPI(0xFF); r[1]=SPI(0xFF); r[2]=SPI(0xFF); r[3]=SPI(0xFF);		//rest of R3
		sdhc=r[0] & 0x40;
	}
	
//SSPM1 = 0;	// full speed 2MHz
	//SPI(0xFF);
	
}
  


void main(void) 
{
unsigned char fn=1, sn=1; //file #, sector# 
    SYSTEM_Initialize();
    initSD();
    fat();
    card=512;
    while (1) 
    {         
        file(fn*32+20,sn);		//32 bytes per file descriptor at offset of 20
				if(FileCluster){	//cluster reads 0 is end of files entries
					loc=(1 + (DataSector) + (unsigned long)(FileCluster-2) * SectorsPerCluster) * card ;
					readSD();
    }
}    

}/**
 End of File
 */
   