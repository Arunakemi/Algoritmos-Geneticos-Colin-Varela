/**
 * Arunakemi Colin Varela
 * 3CM5
 * Algoritmos Geneticos
 * PRACTICA 3
*/
#include "stdio.h"
#include "plotsdl/plot.h"
#include "plotsdl/llist.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
  	//0 - 32 ind
 	//0 - 15 generaciónes
int decimal(int *ind)
{
	int i;
	int cont = 0;
	for (i = 0; i < 5; ++i)
	{
		cont = cont + (ind[i]*pow(2,4-i)); 
	}	
	return cont;
}
void imprimir_ind(int **ind,int x)
{
	int i,i2;
	for (i = 0; i < x; ++i)
	{
		printf("\nI[%d] = ", i+1);
		for (i2 = 0; i2 < 5; ++i2)
		{
			printf("%d ",ind[i][i2]);
		}
	}
	printf("\n\n");
}
void copiar_ind(int *ind, int *des)
{
	int i;
	for (int i = 0; i < 5; ++i)
	{
		des[i] = ind[i];
	}
}
void mutar(int *des)
{
	int i;
	int s;
	for (int i = 0; i < 5; ++i)
	{
		s = rand()%100;
		if(s<=5) des[i] = abs(des[i]-1);
	}
}
void cruzar(int *ind1,int *ind2,int punto)
{
	int i,val;
	for (i = punto; i < 5; ++i)
	{
		val = ind1[i];
		ind1[i] = ind2[i];
		ind2[i] = val;
	}
}
int generar(int **ind,int **des, int in, double *min, double *max)
{
	int i,cnt,cnt2;
	double *valores = (double*) malloc(in*sizeof(double*));
	double *sumaprom = (double*) malloc(in*sizeof(double*));
	double suma=0;
	double dec=0;
	double random;
	imprimir_ind(ind,in);
	for(cnt=0;cnt<in;cnt++)
	{
		valores[cnt] = pow(decimal(ind[cnt]),2);
		if(valores[cnt]>*max)
		{ 
			*max=valores[cnt];
		}
		if(valores[cnt]<*min) 
		{
			*min=valores[cnt];
		}
		suma = suma + valores[cnt];
	}
	*max = *max / suma;
	*min = *min / suma; 
	for(cnt=0;cnt<in;cnt++)
	{
		valores[cnt] = valores[cnt] / suma;
		if(cnt!=0)
		sumaprom[cnt] = sumaprom[cnt-1] + valores[cnt];
		else
		sumaprom[cnt] = valores[cnt];	
	}
	for (cnt = 0; cnt < in; ++cnt)
	{
		random = rand()%100;
		dec = random / 100;
		for(cnt2=0;cnt2<in;cnt2++)
		{
			if(cnt2==0&&dec<=sumaprom[cnt2])
			{
				copiar_ind(ind[cnt2],des[cnt]);
				break;
			}
			else if(dec>sumaprom[cnt2-1]&&dec<=sumaprom[cnt2])
			{
				//Copiar individuo
				copiar_ind(ind[cnt2],des[cnt]);
				break;
			}
			else if(dec>1)
			{
				copiar_ind(ind[in-1],des[cnt]);
				break;
			}
		}
	}
	//Cruza
	for ( cnt = 0; cnt < in; cnt+=2)
	{
		cruzar(des[cnt],des[cnt+1],(rand()%4) + 1);
	}
	//Muta
	for (cnt = 0; cnt < in; ++cnt)
	{
		mutar(des[cnt]);
	}
	//Copia la descendenca en los nuevo individuos
	for (cnt = 0; cnt < in; ++cnt)
	{
		copiar_ind(des[cnt],ind[cnt]);
	}
	free(valores);
	free(sumaprom);
}
int main(int argc, char* argv[])
{
	if ( argc != 2 )
	{
		printf( "usage: %s font file name (.ttf)\n", argv[0] );
		return EXIT_FAILURE;
	}
	//populate caption list
	captionlist caption_list = NULL;
	caption_list=push_back_caption(caption_list,"Maximos",0,0x0000FF);
	caption_list=push_back_caption(caption_list,"Minimos",1,0xFF00FF);
	//Generar numeros
	int gen,ind;
	printf("\n\nPractica 3: Seleccion por ruleta\n");
	printf("Alumna: Arunakemi Colin Varela\n");
	do
	{
		printf("\nIndique el numero de individuos (Numero par) [2-32] : ");
		scanf("%d",&ind);
		if(ind%2!=0) 
		{
			printf("\nFavor de usar un numero par!\n");
			ind=0;
		}
	}while(ind>32||ind<2);
	do
	{
		printf("\nIndique un numero de generaciones [1-15] : ");
		scanf("%d",&gen);
	}while(gen>15||gen<1);
	srand(time(NULL)); 
	int **individuos,**descendencia;
	int i,i2;
	individuos = (int**) malloc(ind*sizeof(int*));
	descendencia = (int**) malloc(ind*sizeof(int*));
	for(i=0;i<ind;i++)
	{
		individuos[i] = (int*) malloc(5*sizeof(int)); 
		descendencia[i] = (int*) malloc(5*sizeof(int)); 
		for (int i2 = 0; i2 < 5; ++i2)
		{
			individuos[i][i2] = rand()%2;
			descendencia[i][i2] = 0;
		}
	}
	coordlist coordinate_list=NULL;
	double min,max;
	double max2=0;
	for(i=0;i<gen;i++)
	{
		min=1024;
		max=0;
		printf("Generacion n°%d : \n", i+1);
		generar(individuos,descendencia,ind,&min,&max);
		coordinate_list=push_back_coord(coordinate_list,0,i,max);
		coordinate_list=push_back_coord(coordinate_list,1,i,min);
		if(max>max2)max2=max;
	}
	free(individuos);
	free(descendencia);

	//populate plot parameter object
	plot_params params;

	params.screen_width=800;
	params.screen_heigth=640;
	params.plot_window_title="Numeros Aleatorios";
	params.font_text_path=argv[1];
	params.font_text_size=18;
	params.caption_text_x="";
	params.caption_text_y="";
	params.caption_list = caption_list;
	params.coordinate_list = coordinate_list;
	params.scale_x = 5;
	params.scale_y = 1;
	params.max_x = gen;
	params.max_y = max2;

	int ret = plot_graph(&params);

	if (ret == EXIT_FAILURE)
	{
		printf("plot_graph return with status %d\n",ret);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}