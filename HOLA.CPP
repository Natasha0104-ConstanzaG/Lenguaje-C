# include <stdio.h> //llamado de librería
# include <conio.h> //llamado de librería

void main (void){ //declaracion del menú
    char cad [] = {"Hola Mundo"};
    clrscr ();
    gotoxy (35,12);
    printf ("%s\n",cad);
    getch ();
}