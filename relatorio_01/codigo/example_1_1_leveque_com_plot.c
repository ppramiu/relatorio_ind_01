#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	float h; //valor do espaçamento
	double x; //valor para avaliação da função
	double f,dfav,dfat,dfc; //valor da função
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
	        dfav = (sin(x+h)-sin(x))/h; //diferenças finitas avançadas
        	dfat = (sin(x)-sin(x-h))/h; //diferenças finitas atrasadas
	        dfc = (sin(x+h)-sin(x-h))/(2*h); //diferenças finitas centrais
		printf("%f\t %f \t %f \t %f \n",h,dfav,dfat,dfc);  
		h = h/2;
	}
	h = 0.1;
 	printf("Valores do Erro\n");
	printf("h \t\t D+ \t\t D- \t\t D0 \n");
        while (h>0.001){
		f = sin(x);
	        vecx[i]=h;
		vec_dfav[i] = (sin(x+h)-sin(x))/h; //diferenças finitas avançadas
	        vec_dfat[i] = (sin(x)-sin(x-h))/h; //diferenças finitas atrasadas
	        vec_dfc[i] = (sin(x+h)-sin(x-h))/(2*h); //diferenças finitas centrais
		printf("%f\t %.4e \t %.4e \t %.4e \n",h,vec_dfav[i]-cos(x),vec_dfat[i]-cos(x),vec_dfc[i]-cos(x));
		h = h/2;
		i++;
	}
   
	fprintf(file, "set term png; "
	"set out 'grafico_erro.png'\n"
	"set xlabel 'Valor de h'\n"
	"set ylabel 'Valor do Erro'\n"
	//"set style data lines\n"
	"set multiplot\n"
	"set logscale xy\n"
	"plot '-' using 1:2 with linespoints title 'D A'\n, '-' using 1:3 title 'D C'\n");
	

	//or use fprintf directly
	for (int i=0; i<7; i++){
	  	fprintf(file, "%f %f %f \n", vecx[i], fabs(vec_dfav[i]-cos(x)), fabs(vec_dfc[i]-cos(x)));
//		fprintf(file, "%g %g \n", vecx[i], fabs(vec_dfc[i]-cos(x)));
			
	}
	fprintf(file,"e\n");

	fclose(file);
}
