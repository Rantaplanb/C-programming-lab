/*Assignment 1 - Translate program - 4457 Loukas Mertzanis*/

#include<stdio.h>

typedef enum /*FSM states*/
{
    standard, critical_M, critical_N, critical_m, critical_n
}FsmState;


/*Function Declarations*/
void initializeMatches(int match[256][3]);
FsmState basic(int);
FsmState M_state(int);
FsmState m_state(int);
FsmState N_state(int);
FsmState n_state(int);


/* 2D array to hold the mappings */
/* Global, because all functions */
/* need access to it.            */
int map[255][3] = {{0}};


/* Array of pointers to functions                */
/* The appropriate function is called each time, */
/* depending on the current state of the FSM.    */
FsmState (*functionController[5])(int c) = {basic, M_state, N_state, m_state, n_state};


/*----------------------------------------------------------------------------*/
/* Main Function: reads char from stdin unless EOF is reached.                 */
/* Then, the appropriate function is called, depending on the FSM state.      */
/* The current state gets updated to the return value of the called function, */
/* and the program moves on to the next character!                            */
/*----------------------------------------------------------------------------*/
int main()
{
    int ch;
    FsmState tmpState, currentState = standard; /*Initialize FSM state to standard*/
    initializeMatches(map);
    while((ch = getchar()) != EOF)
    {
			tmpState = (functionController[currentState])(ch);
			currentState = tmpState; /*Update the state of the FSM*/
    }

    /* If FSM is in a critical state and then we get EOF, */
    /* the critical character must be printed before program termination */
	if(currentState == critical_M)
		putchar('M');
	else if(currentState == critical_m)
		putchar('m');
	else if(currentState == critical_N)
		putchar('N');
	else if(currentState == critical_n)
		putchar('n');
    
    return 0;
}


/*-----------------------------------------------------------*/
/* The function initializes the 2D array with the            */
/* appropriate values, in order to map the input chars of    */
/* the ISO8859-7, to the equivalent chars of the ISO8859-1   */
/*-----------------------------------------------------------*/
void initializeMatches(int match[255][3]) /*Argument: address of the array's 1st element*/
{
int i;
/* The chars 0-179 are same in ISO8859-1 and ISO8859-7 */
for(i=0; i<180; i++)
    match[i][0] = i;

/* The rest of the characters must be matched manually */
match[180][0]=39;
match[181][0]=34; match[181][1]=39;
match[182][0]=39; match[182][1]=65;
match[183][0]=183;
match[184][0]=39; match[184][1]=69;
match[185][0]=39; match[185][1]=72;
match[186][0]=39; match[186][1]=73;
match[187][0]=187;
match[188][0]=39; match[188][1]=79;
match[189][0]=189;
match[190][0]=39; match[190][1]=89;
match[191][0]=39; match[191][1]=87;
match[192][0]=105; match[192][1]=39; match[192][2]=34;
match[193][0]=65;
match[194][0]=86;
match[195][0]=71;
match[196][0]=68;
match[197][0]=69;
match[198][0]=90;
match[199][0]=72;
match[200][0]=56;
match[201][0]=73;
match[202][0]=75;
match[203][0]=76;
match[204][0]=77;
match[205][0]=78;
match[206][0]=75; match[206][1]=83;
match[207][0]=79;
match[208][0]=80;
match[209][0]=82;
match[211][0]=83;
match[212][0]=84;
match[213][0]=89;
match[214][0]=70;
match[215][0]=88;
match[216][0]=80; match[216][1]=83;
match[217][0]=87;
match[218][0]=73; match[218][1]=34;
match[219][0]=89; match[219][1]=34;
match[220][0]=97; match[220][1]=39;
match[221][0]=101; match[221][1]=39;
match[222][0]=104; match[222][1]=39;
match[223][0]=105; match[223][1]=39;
match[224][0]=121; match[224][1]=39; match[224][2]=34;
match[225][0]=97;
match[226][0]=118;
match[227][0]=103;
match[228][0]=100;
match[229][0]=101;
match[230][0]=122;
match[231][0]=104;
match[232][0]=56;
match[233][0]=105;
match[234][0]=107;
match[235][0]=108;
match[236][0]=109;
match[237][0]=110;
match[238][0]=107; match[238][1]=115;
match[239][0]=111;
match[240][0]=112;
match[241][0]=114;
match[242][0]=115;
match[243][0]=115;
match[244][0]=116;
match[245][0]=121;
match[246][0]=102;
match[247][0]=120;
match[248][0]=112; match[248][1]=115;
match[249][0]=119;
match[250][0]=105; match[250][1]=34;
match[251][0]=121; match[251][1]=34;
match[252][0]=111; match[252][1]=39;
match[253][0]=121; match[253][1]=39;
match[254][0]=119; match[254][1]=39;
}


/*--------------------------------------------------------*/
/* basic state: If the input character is critical, we */
/* transition to the critical state, otherwise we         */
/* print the equivalent chars of the ISO8859-7            */
/*--------------------------------------------------------*/
FsmState basic(int c)
{
    if(c == 204)
        return critical_M;
    else if(c == 236)
        return critical_m;
    else if(c == 205)
        return critical_N;
    else if(c == 237)
        return critical_n;
    else
    {
        int i;
		for(i=0; i<3; i++){
			if(map[c][i] != 0)
				putchar(map[c][i]);
		}
        return standard;
    }

}


/*-------------------------------------------------------------------*/
/* The following critical-state functions work like this:            */
/* -If the input char makes a dipthong with the equivalent           */
/* critical state char, we print 1 char matching the dipthong.       */
/* -If the input char is a critical one, we print the last critical  */
/* char and transition to a critical state again.                    */
/* -If the input char is anything else, we print both of them,       */
/* mapped to the ISO8859-1 and transition to the base state          */
/*-------------------------------------------------------------------*/

FsmState M_state(int c)
{
    if(c == 208){
        putchar('B');
        return standard;
    }
    else if(c == 240){
        putchar('B');
        return standard;
    }
    else if(c == 204){
        putchar('M');
        return critical_M;
    }
    else if(c == 236){
        putchar('M');
        return critical_m;
    }
    else if(c == 205){
        putchar('M');
        return critical_N;
    }
    else if(c == 237){
        putchar('M');
        return critical_n;
    }
    else{
        putchar('M');
        int i;
		for(i=0; i<3; i++){
			if(map[c][i] != 0)
				putchar(map[c][i]);
		}
        return standard;
    }
}


FsmState m_state(int c)
{
    if(c == 208){
        putchar('b');
        return standard;
    }
    else if(c == 240){
        putchar('b');
        return standard;
    }
    else if(c == 204){
        putchar('m');
        return critical_M;
    }
    else if(c == 236){
        putchar('m');
        return critical_m;
    }
    else if(c == 205){
        putchar('m');
        return critical_N;
    }
    else if(c == 237){
        putchar('m');
        return critical_n;
    }
    else{
        putchar('m');
        int i;
		for(i=0; i<3; i++){
			if(map[c][i] != 0)
				putchar(map[c][i]);
		}
        return standard;
    }
}


FsmState N_state(int c)
{
    if(c == 212){
        putchar('D');
        return standard;
    }
    else if(c == 244){
        putchar('D');
        return standard;
    }
    else if(c == 205){
        putchar('N');
        return critical_N;
    }
    else if(c == 237){
        putchar('N');
        return critical_n;
    }
    else if(c == 204){
        putchar('N');
        return critical_M;
    }
    else if(c == 236){
        putchar('N');
        return critical_m;
    }
    else{
        putchar('N');
        int i;
		for(i=0; i<3; i++){
			if(map[c][i] != 0)
				putchar(map[c][i]);
		}
        return standard;
    }
}


FsmState n_state(int c)
{
    if(c == 212){
        putchar('d');
        return standard;
    }
    else if(c == 244){
        putchar('d');
        return standard;
    }
    else if(c == 204){
        putchar('n');
        return critical_M;
    }
    else if(c == 236){
        putchar('n');
        return critical_m;
    }
    else if(c == 205){
        putchar('n');
        return critical_N;
    }
    else if(c == 237){
        putchar('n');
        return critical_n;
    }
    else{
        putchar('n');
        int i;
		for(i=0; i<3; i++){
			if(map[c][i] != 0)
				putchar(map[c][i]);
		}
        return standard;
    }
}
