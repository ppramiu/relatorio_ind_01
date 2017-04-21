#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	float h; //valor do espa�amento
	double x; //valor para avalia��o da fun��o
	double f,dfav,dfat,dfc; //valor da fun��o
	int i=0;
	double vecx[6],vec_dfav[6],vec_dfat[6],vec_dfc[6];
	FILE *file = popen("gnuplot -persistent","w");
	h = 0.1;
	x = 1;
	f = sin(x);

	printf("Valor de f'(x)=cos(x) ou  f'(%f)=cos(%f)=%f\n",x,x,cos(x));
	printf("h \t\t D+ \t\t D- \t\t D0 \n");
	while (h>0.001){
		f = sin(x);
	        dfav = (sin(x+h)-sin(x))/h; //diferen�as finitas avan�adas
        	dfat = (sin(x)-sin(x-h))/h; //diferen�as finitas atrasadas
	        dfc = (sin(x+h)-sin(x-h))/(2*h); //diferen�as finitas centrais
		printf("%f\t %f \t %f \t %f \n",h,dfav,dfat,dfc);  
		h = h/2;
	}
	h = 0.1;
 	printf("Valores do Erro\n");
	printf("h \t\t D+ \t\t D- \t\t D0 \n");
        while (h>0.001){
		f = sin(x);
	        vecx[i]=h;
		vec_dfav[i] = (sin(x+h)-sin(x))/h; //diferen�as finitas avan�adas
	        vec_dfat[i] = (sin(x)-sin(x-h))/h; //diferen�as finitas atrasadas
	        vec_dfc[i] = (sin(x+h)-sin(x-h))/(2*h); //diferen�as finitas centrais
		printf("%f\t %.4e \t %.4e \t %.4e \n",h,vec_dfav[i]-cos(x),
			vec_dfat[i]-cos(x),vec_dfc[i]-cos(x));
		h = h/2;
		i++;
	}
	return 0;
}
