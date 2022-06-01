# include <stdio.h> //llamado de librería
# include <conio.h> //llamado de librería
void borrar (void){
asm {
         MOV AX,0600H
         MOV BH,07H
         MOV CX,000H
         MOV DX,184FH
         INT 10H
   }
}
void cursor (unsigned char x, unsigned char y){
 asm {
     	MOV AH,02H
	MOV BH,00H
	MOV DH,y
	MOV DL,x
	INT 10H
   }
}
void main (void){ //declaracion del menú
    int car;
     unsigned char a = 1, b = 1;
    borrar ();
    for ( car = 0; car <= 255; car ++) {
	cursor (a, b);
        printf ("%d %c", car, car);
     b ++;
     if ((car+1)%23==0){
         b = 1;
         a += 6;
     }
}
 getch ();
}