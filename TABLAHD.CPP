# include <stdio.h> //llamado de librería
# include <conio.h> //llamado de librería

void main (void){ //declaracion del menú
    int car;
     unsigned char x = 1, y = 1;
    asm {
	 MOV AX,0600H
	 MOV BH,07H
	 MOV CX,000H
	 MOV DX,184FH
	 INT 10H
}
    for (car = 0; car <= 255; car ++) {
       asm {
	MOV AH,02H
	MOV BH,00H
	MOV DH,y
	MOV DL,x
	INT 10H
}
	 printf ("%d %c", car, car);
     y++;
     if ((car+1)%23==0){
	 y = 1;
	 x += 6;
     }
}
 getch ();
}