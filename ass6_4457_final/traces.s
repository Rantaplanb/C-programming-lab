In text section:
   0x8048aac <readString>:      push   %ebp							#Stack frame setup: save base stack pointer's return value (in current stack frame)
   0x8048aad <readString+1>:    mov    %esp,%ebp					#esp := ebp
   0x8048aaf <readString+3>:    sub    $0x34,%esp					#decrement stack ptr, to allocate memory for local variables (52 bytes)
   0x8048ab2 <readString+6>:    movl   $0x0,-0x4(%ebp)				#int i = 0;
   0x8048ab9 <readString+13>:   mov    0x80d4b44,%eax				#stdin is given to eax register
   0x8048abe <readString+18>:   push   %eax							#push argument before the function call
   0x8048abf <readString+19>:   call   0x8050850 <getc>				#call fgetc();
   0x8048ac4 <readString+24>:   add    $0x4,%esp					#deallocate the previously allocated memory in stack
   0x8048ac7 <readString+27>:   mov    %eax,-0x8(%ebp)				#c = return value of fgetc()
   0x8048aca <readString+30>:   cmpl   $0xffffffff,-0x8(%ebp)		#if(c == EOF)
   0x8048ace <readString+34>:   je     0x8048ae8 <readString+60>	#break;
   0x8048ad0 <readString+36>:   cmpl   $0xa,-0x8(%ebp)				#if(c == '\n')
   0x8048ad4 <readString+40>:   je     0x8048ae8 <readString+60>	#break;
   0x8048ad6 <readString+42>:   mov    -0x4(%ebp),%eax				#eax contains value of i
   0x8048ad9 <readString+45>:   lea    0x1(%eax),%edx				#address of 1st byte of i is loaded to edx register
   0x8048adc <readString+48>:   mov    %edx,-0x4(%ebp)
   0x8048adf <readString+51>:   mov    -0x8(%ebp),%edx				#edx contains value of c
   0x8048ae2 <readString+54>:   mov    %dl,-0x34(%ebp,%eax,1)		#buf[i] = c;
   0x8048ae6 <readString+58>:   jmp    0x8048ab9 <readString+13>	#execute another while loop block
   0x8048ae8 <readString+60>:   lea    -0x34(%ebp),%edx				#end of while loop
   0x8048aeb <readString+63>:   mov    -0x4(%ebp),%eax				#value of i contained in eax register
   0x8048aee <readString+66>:   add    %edx,%eax					#i++; (?)
   0x8048af0 <readString+68>:   movb   $0x0,(%eax)					#buf[i] = 0;
   0x8048af3 <readString+71>:   movl   $0x0,-0x4(%ebp)				#i = 0;
   0x8048afa <readString+78>:   jmp    0x8048b15 <readString+105>	#jump to loop comparison
   0x8048afc <readString+80>:   mov    -0x4(%ebp),%edx				#loop block
   0x8048aff <readString+83>:   mov    0x8(%ebp),%eax				#register preperation
   0x8048b02 <readString+86>:   add    %eax,%edx
   0x8048b04 <readString+88>:   lea    -0x34(%ebp),%ecx				#loads buffer address
   0x8048b07 <readString+91>:   mov    -0x4(%ebp),%eax				#value of i is contained to eax register
   0x8048b0a <readString+94>:   add    %ecx,%eax
   0x8048b0c <readString+96>:   movzbl (%eax),%eax					#address of eax is copied to eax register
   0x8048b0f <readString+99>:   mov    %al,(%edx)					#s[i] = buf[i];
   0x8048b11 <readString+101>:  addl   $0x1,-0x4(%ebp)				#i++;
   0x8048b15 <readString+105>:  cmpl   $0x2b,-0x4(%ebp)				#if(i < 44)
   0x8048b19 <readString+109>:  jle    0x8048afc <readString+80>	#jump to execute another for loop block
   0x8048b1b <readString+111>:  nop
   0x8048b1c <readString+112>:  leave
   0x8048b1d <readString+113>:  ret									#return;
   
   0x8048b1e <main>:    push   %ebp									#Stack frame setup: save ebp
   0x8048b1f <main+1>:  mov    %esp,%ebp							#esp := ebp
   0x8048b21 <main+3>:  mov    $0x80d65e0,%eax						#name address is moved to eax register
   0x8048b26 <main+8>:  and    $0xfffff000,%eax						#0xfffff000 := Name & 0xfffff000
   0x8048b2b <main+13>: push   $0x7									#push function's arguments in stack
   0x8048b2d <main+15>: push   $0x1									#push function's arguments in stack
   0x8048b2f <main+17>: push   %eax									#push function's arguments in stack
   0x8048b30 <main+18>: call   0x805e180 <mprotect>					#call mprotect() function
   0x8048b35 <main+23>: add    $0xc,%esp							#deallocate memory that was used for local variables of called function
   0x8048b38 <main+26>: push   $0x80ab0a8							#fush function's argument before function call
   0x8048b3d <main+31>: call   0x804f070 <puts>						#printf("What is your name?\n"); //call puts()

   0x8048b42 <main+36>: add    $0x4,%esp							#deallocate memory for local vars of last fun call
   0x8048b45 <main+39>: push   $0x80d65e0							#push argument for readstring
   0x8048b4a <main+44>: call   0x8048aac <readString>				#readString(Name);
   0x8048b4f <main+49>: add    $0x4,%esp							#...
   0x8048b52 <main+52>: push   $0x80ab0bb
   0x8048b57 <main+57>: push   $0x80d65e0
   0x8048b5c <main+62>: call   0x805af90 <strcmp>					#strcmp(Name, "Angelos Bilas");
   0x8048b61 <main+67>: add    $0x8,%esp
   0x8048b64 <main+70>: test   %eax,%eax							#if(returned value of strcmp NOT equal to zero)
   0x8048b66 <main+72>: jne    0x8048b6f <main+81>					#jump (skip next instruction)
   0x8048b68 <main+74>: movb   $0x36,0x80d46e8						#grade = '6';
   0x8048b6f <main+81>: push   $0x80d65e0
   0x8048b74 <main+86>: push   $0x80ab0c9
   0x8048b79 <main+91>: call   0x804eaf0 <printf>					#printf("Thank you, %s.\n", Name);
   0x8048b7e <main+96>: add    $0x8,%esp
   0x8048b81 <main+99>: movzbl 0x80d46e8,%eax
   0x8048b88 <main+106>:        movsbl %al,%eax
   0x8048b8b <main+109>:        push   %eax
   0x8048b8c <main+110>:        push   $0x80ab0dc
   0x8048b91 <main+115>:        call   0x804eaf0 <printf>			#printf("I recommend that you get a grade of %c on this assignment.\n",grade);
   0x8048b96 <main+120>:        add    $0x8,%esp
   0x8048b99 <main+123>:        push   $0x0
   0x8048b9b <main+125>:        call   0x804e110 <exit>				#exit(0);
   
In data section:
	(gdb) print &grade
	$1 = 0x80d46e8 <grade> "3"
	(gdb) print grade
	$2 = 51 '3'
	
In bss section:
	(gdb) print &Name
	$1 = (char (*)[44]) 0x80d65e0 <Name>
	
Stack frame of readString: //me breakpoints sta +71 kai inputName "Merzanis"
	(gdb) print $esp
	$1 = (void *) 0xbffff578
	(gdb) print $ebp
	$2 = (void *) 0xbffff5ac
	
	ebp - esp = 34(hex) = (52)decimal
	Αρα πρεπει να εξετασουμε 52 bytes gia to stack frame content, + 4 bytes (ebp) + 4 bytes (return address)
	Συνολο 60 bytes. (+4 ακομη αν θεωρησουμε πως πρεπει να εξετασουμε και το argument της συναρτησης,
	το οποιο ειναι αποθηκευμενο στο τελος και προκειται για εναν pointer σε string).
	
	(gdb) x/60b $esp
0xbffff578:     0x4d    0x65    0x72    0x74    0x7a    0x61    0x6e    0x69
0xbffff580:     0x73    0x00    0x04    0x08    0x80    0x48    0x0d    0x08
0xbffff588:     0x0a    0x00    0x00    0x00    0x12    0x00    0x00    0x00
0xbffff590:     0x01    0x00    0x00    0x00    0x44    0xf6    0xff    0xbf
0xbffff598:     0x4c    0xf6    0xff    0xbf    0x01    0x00    0x00    0x00
0xbffff5a0:     0x34    0x80    0x04    0x08    0x0a    0x00    0x00    0x00
0xbffff5a8:     0x09    0x00    0x00    0x00    0xb8    0xf5    0xff    0xbf
0xbffff5b0:     0x4f    0x8b    0x04    0x08

Στα πρωτα 10 bytes βρισκονται οι χαρακτηρες 'M', 'e', 'r', 't', 'z', 'a', 'n', 'i', 's', '\0' κωδικοποιημενοι σε ascii.
Τα επομενα 34 bytes του buffer περιεχουν σκουπιδια.
Εν συνεχεια ακολουθουν: η μεταβλητη c (4 bytes και τιμη 10 λογω του τελευταιου χαρακτηρα που εισηγαγα '\n', ο οποιος λογω της συνθηκης τερματισε το loop)
η μεταβλητη i (4 ακομα bytes και τιμη 9, αφου strlen("Mertzanis") == 9 ),
επειτα 4 bytes για την τιμη του base stack pointer, για το stack frame της καλουσας συναρτησης (στην οποια θα επιστρεψουμε),
και στα 4 τελευταια bytes η διευθυνση επιστροφης της συναρτησης readString() (addr: 0x08048b4f, αρχιτεκτονικη little endian προφανως).
Τα 4 τελευταια bytes του stack frame που δεν φαινονται στο παραπανω σχημα(γιατι δεν ζητουνται απο την εκφωνηση) αντιστοιχουν στο argument της συναρτησης (pointer se string).

Ολα οσα ζητουνται απο την εκφωνηση εξηγηθηκαν, για οποιαδηποτε περεταιρω εξηγηση ρωτηστε με κατα την προφορικη εξεταση της ασκησης!