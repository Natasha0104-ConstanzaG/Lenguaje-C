# include <stdio.h> //llamado de librería
# include <conio.h> //llamado de librería

void main (void){ //declaracion del menú
    int car, x = 1, y = 1;
    clrscr ();
    for ( car = 0; car <= 255; car ++){
    gotoxy (x,y);
	 printf ("%d %c",car,car);
     y++;
     if ((car+1)%23==0){
         y = 1;
         x += 6;
     }
}
 getch ();
}