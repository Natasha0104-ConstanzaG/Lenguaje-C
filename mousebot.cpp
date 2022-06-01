# include <stdio.h>
# include <conio.h>

void borrar (void){ //borrar pantalla
   asm{
   MOV AX,0600H
   MOV BH,07H
   MOV CX,0000H
   MOV DX,184FH
   INT 10H
 }
}

void iniMouse (void){
   asm{
   MOV AX,00H
   INT 33H
}
   asm{
   MOV AX,01H
   INT 33H 
     }
}

void botonXY (unsigned int &a,unsigned int &b, unsigned int &c){
 unsigned int col, ren, btn;
   asm {
   MOV AX,03H
   INT 33H
   MOV btn,BX
   MOV col,CX
   MOV ren,DX
   }
  a=col;
  b=ren;
  c=btn;
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

void cierraMouse (void){
   asm {
   MOV AX,02H
   INT 33H
   } 
}

void main (void) {
    unsigned char x, y;
    unsigned int r,c, boton;
    borrar ();
    iniMouse ();
    do{
      botonXY (c, r, boton);
      r = r/8;
      c = c/8;
      c++;
      x = (char) c;
      y = (char) r;
       if (boton == 1){
           cursor (x,y);
           printf ("Boton Izquierdo"); 
    }
          if (boton == 2){
           cursor (x,y);
           printf ("Boton Derecho  "); 
         }
             if (boton == 4){
           cursor (x,y);
           printf ("Boton Central  "); 
    }

  } while(boton != 3);
      cierraMouse ();  
}