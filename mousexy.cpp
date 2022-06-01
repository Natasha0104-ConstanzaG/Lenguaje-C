#include <stdio.h>
#include <conio.h>
#include <dos.h>

void cursor (unsigned char x, unsigned char y){
    asm{
        MOV AH,02H
        MOV BH,00H
        MOV DH,y
        MOV DL,x
        INT 10H
    }
}
void borrado (unsigned char color){
    asm{
        MOV AX,0600H
        MOV BH,color
        MOV CX,0000H
        MOV DX,184FH
        INT 10H
    }
    cursor (0,0);
}
void iniraton(void){
    asm{
        MOV AX,00H
        INT 33H
    }
    asm{
        MOV AX,01H
        INT 33H
    }
}
int btnraton(int *x, int *y){
    int bn,a,b;
    asm{
        MOV AX,03H
        INT 33H
        MOV bn,BX
        MOV a,CX
        MOV b,DX
    }
    *x=a;
    *y=b;
    return bn;
}
void apagraton(void){
    asm{
        MOV AX,02H
        INT 33H
    }
}
void main (void){
    int bn,r = 0,c = 0,aux1 = 1, aux2 = 1;
    borrado(7);
    iniraton();
    cursor(32,12);
    printf("x= ");
    cursor(41,12);
    printf("y= ");
    do{
        bn = btnraton (&c,&r);
        if(r != aux1 || c!= aux2){
            cursor (37,12);
            printf("%d ",c/8);
            cursor (44,12);
            printf ("%d ",r/8);
            aux1 = r;
            aux2 = c;
        }
    }while(bn != 1);
    apagraton();
}

