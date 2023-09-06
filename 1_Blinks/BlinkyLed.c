/*------------------------------------------------------------
* Name: BlinkyLed.c
* Purpose: LED PG7 Flasher for MCBSTM32F200
*----------------------------------------------------------*/
/*------------------------------------------------------------
Main function
*----------------------------------------------------------*/
int main (void)
{
//-------Declaration of type of variables---------------------
	int i; //counter for get ready delay
	unsigned long int j; //counter for blinky delay
	//-------Initialization of variables--------------------------
	i=0;
	j=0;
	//-------Main cycle of algorithm------------------------------
	*(unsigned long*)(0x40023830) |= 0x40; //Enable port G clocking


	for(i=0; i<4; i++){} //small delay for GPIOG get ready
		
//	Set PG7 as General purpose output
	*(unsigned long*)(0x40021800) = (*(unsigned long*)(0x40021800) & (~0x00008000)) | (0x00004000); 
		
	while(1)
	{
		*(unsigned long*)(0x40021814) |= 0x80; //Turn LED ON!
		for( j=0; j<2000000 ;j++ ){} //Delay
		*(unsigned long*)(0x40021814) &= ~0x80; //Turn LED OFF
		for(j=0; j<2000000 ; j++){} //Delay
	}
}
