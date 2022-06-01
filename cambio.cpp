# include <stdio.h>
# include <conio.h>

void cambio (int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
     *y = aux;
  }

void cambia (int &x, int &y){
    int aux;
    aux = x;
    x = y;
    y = aux;
  }

void error (int x, int y){
    int aux;
    aux = x;
    x = y;
    y = aux;
    printf ("e = %d, f = %d\n", x, y);
  }

void main (void) {
   int a = 89, b, c, d, e, f;
   int *z;
   z = &a;
 clrscr ();
 printf ("%d %d\n", a, *z);
   scanf ("%d", z);
 printf ("%d %d\n", a, *z);
   *z = *z + 1;
 printf ("%d %d\n", a, *z);
   (*z )++;
 printf ("%d %d\n", a, *z);
 printf ("intercambio\n");
   a = 10;
   b = 25;
   printf ("a = %d, b = %d\n", a, b);
     cambio (&a, &b);
   printf ("a = %d, b = %d\n\n", a, b);
     c = 100;
     d = 200;
   printf ("c = %d, d = %d\n", c, d);
     cambia (c, d);
   printf ("c = %d, d = %d\n\n", c, d);
     e = 34;
     f = 45;
   printf ("e = %d, f = %d\n", e, f);
     error (e, f);
   printf ("e = %d, f = %d\n", e, f);
   getch ();
}