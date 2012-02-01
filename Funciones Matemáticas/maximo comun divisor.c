#include <stdio.h>
/*	ALGORITMO RECURSIVO EN C*/
/*	CÁLCULO DE MÁXIMO COMÚN DIVISOR ENTRE 'a' Y 'b'*/
int mcd (int a, int b)
{
	if( a < 0)
		a = a * -1;	
		
	if( b < 0)
		b = b * -1;
		
  a = a % b;
  if (a > 0)
    return mcd (b, a);
  else
    return b;
}
/*	=================================================	*/

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("el gcd es %d\n\n", mcd(a,b));
return 0;
}
