#include<reg51.h>
void delay(int time)
{ 
	int i,j;
	for(i=0 ; i<time , i++)
	for(j=0 ; j<1275 , j++)	
}
void main()
{
	while(1)
	{
		P2=0x00
		delay(50);
		P2=0xff
		delay(50);
	}	
}
		