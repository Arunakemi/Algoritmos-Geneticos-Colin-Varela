/**
 * Arunakemi Colin Varela
 * 3CM5
 * Algoritmos Geneticos
 * PRACTICA 4
*/
#include "plotsdl/plot.h"
#include "plotsdl/llist.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
	Recibimos parametros:
	 - Numero de alelos
	 - Numero de Individuos
	 - Numero de Generaciones

	Genera padres 
	for(Numero de generaciones)
	{
		Selecciona 
		Cruza
		Mutacion
	}

	Grafica Ultima generación
	- Uno que grafique Maximos y minimos 
	- Otro que grafique probabilidades


	main()
	{
		recibimos parametros();
		generamos padres();
		for(#generaciones)
		{
			selecciona("");
			cruza();
			muta():
		}
	}
*/
#define VAR double
//Variable utilizadas por todas las funciones
int cnt,cnt2,cnt3,i; //Contadores
VAR *valor, *valorProm, **ind , **des, *max, *min, *maxProm, *minProm; //Individuos y la descendencia de estos
int n_al,n_gen,n_ind; //Numero de alelos, generaciones y numero de individuos
//Funciones
void pedirDatos()
{
	int 			
	//Alelos
	max_al = 10, 
	min_al = 5, 
	//Alelos
	max_ind = 32, 
	min_ind = 2, 
	//Alelos
	max_gen = 100, 
	min_gen = 1;
	/*
	do //Numero de alelos
	{
		printf("\nIngrese el numero de alelos [%d-%d] : ",min_al,max_al);
		scanf("%d",&n_al);
	}
	while(n_al>max_al||n_al<min_al);
	do //Numero de individuos
	{
		printf("\nIngrese el numero de individuos [%d-%d] : ",min_ind,max_ind);
		scanf("%d",&n_ind);
		if(n_ind%2!=0) 
		{
			printf("\nFavor de usar un numero par!\n");
			n_ind=0;
		}
	}
	while(n_ind>max_ind||n_ind<min_ind);
	//*/
	n_al=4;
	n_ind=16;
	do //Numero de generaciones
	{
		printf("\nIngrese el numero de generaciones [%d-%d] : ",min_gen,max_gen);
		scanf("%d",&n_gen);
	}
	while(n_gen>max_gen||n_gen<min_gen);
}
VAR decimal(VAR *in)
{
	VAR ret=0;
	for (cnt3=0;cnt3<n_al;cnt3++)
	{
		ret = ret + (in[cnt3]*pow(2,n_al-1-cnt3));
	}
	return ret;
}
VAR funcionEv(VAR x)
{
	VAR fx;
	fx = abs((x-5)/(2+sin(x)));
	return fx;
}
void valuarInd()
{
	VAR total=0;
	for(cnt=0;cnt<n_ind;cnt++)
	{
		valor[cnt] = funcionEv(decimal(ind[cnt]));
		total = total + valor[cnt];
	}
	for(cnt=0;cnt<n_ind;cnt++)
	{
		valorProm[cnt] = (valor[cnt] * 100) / total;
	}
}
void imprimir()
{
	printf("\nN°\t| Individuo");
	int e;
	for(e=0;e<n_al;e++)
		printf(" ");
	printf("\t| Valor decimal\t| Aptitud\t| Promedio");
	for (cnt = 0; cnt<n_ind; ++cnt)
	{
		printf("\n%d\t| ",cnt+1);
		for(cnt2=0;cnt2<n_al;cnt2++)
		{
			printf("%.0lf ", ind[cnt][cnt2]);
		}
		printf("\t|      %.0lf    \t|  %.2lf   \t|   %.2lf", decimal(ind[cnt]), valor[cnt], valorProm[cnt]);
	}
	printf("\n\n");
}
void generarPadres()
{
	ind = (VAR**) malloc(n_ind * sizeof(VAR*));
	des = (VAR**) malloc(n_ind * sizeof(VAR*));
	valor = (VAR*) malloc(n_ind * sizeof(VAR));
	valorProm =  (VAR*) malloc(n_ind * sizeof(VAR));
	for(cnt=0;cnt<n_ind;cnt++)
	{
		ind[cnt] = (VAR*) malloc(n_al * sizeof(VAR));
		des[cnt] = (VAR*) malloc(n_al * sizeof(VAR));
		for (cnt2=0;cnt2<n_al;cnt2++)
			ind[cnt][cnt2] = rand()%2;
		 
	}
	valuarInd(); //Llenara la matriz valores respecto a los padres
}
void desciende(int x, int y)
{
	int i2;
	for(i2=0;i2<n_al;i2++)
		des[x][i2]=ind[y][i2];
}
void copiarDescendencia()
{
	int y,y2;
	for(y=0;y<n_ind;y++)
		for(y2=0;y2<n_al;y2++)
			ind[y][y2]=des[y][y2];
}
void seleccionTorneo()
{
	cnt3=0;
	int cont=2;
	//Barajar
	int num;
	int *b = (int*) malloc(n_ind * sizeof(int)),
		*a = (int*) malloc(n_ind * sizeof(int));
	while(cont>0)
	{
		for(cnt=0;cnt<n_ind;cnt++)
		{
			b[cnt]=1;
		}
		for(cnt=0;cnt<n_ind;cnt++)
		{
			do
			{
				num = rand()%n_ind;
			}
			while(b[num]==0);
			b[num]=0;
			a[cnt]=num;
		}
		/*
		for(cnt=0;cnt<n_ind;cnt++)
		{
			printf("%d  |  %d\n",b[cnt],a[cnt] +1);
		}
		*/
		//Seleccionamos padres
		for(cnt=0;cnt<n_ind;cnt+=2)
		{
			num = rand()%101;
			if(valor[a[cnt]]>valor[a[cnt+1]])
			{
				if(num>30)
				{
					desciende(cnt3,a[cnt]);
				}
				else
					desciende(cnt3,a[cnt+1]);
			} 
			else
			{
				if(num>30)
				{
					desciende(cnt3,a[cnt+1]);
				}
				else
					desciende(cnt3,a[cnt]);
			} 
			cnt3++;
		}
		cont--;
	}
	copiarDescendencia();
	free(a);free(b);
}
void cruza()
{
	int punto;
	VAR z;
	for(cnt=0;cnt<n_ind;cnt+=2)
	{
		punto = (rand()%(n_al-1))+1;
		for(cnt2=punto;cnt2<n_al;cnt2++)
		{
			z = ind[cnt][cnt2];
			ind[cnt][cnt2] = ind[cnt+1][cnt2];
			ind[cnt+1][cnt2] = z;
		}
	}
}
void muta(int por)
{
	int num = (n_ind * por) / 100;
	int ran,ran2;
	for(cnt=0;cnt<num;cnt++)
	{
		ran = rand()%n_ind;
		ran2 = rand()%n_al;
		ind[ran][ran2] = abs(ind[ran][ran2]-1);
	}
}
void maxMinProm(int g)
{
	VAR up=valorProm[0],
		down=valorProm[0];
	for(cnt=0;cnt<n_ind;cnt++)
	{
		if(valorProm[cnt]>up)
			up=valorProm[cnt];
		if(valorProm[cnt]<down)
			down=valorProm[cnt];
	}
	maxProm[g]=up;
	minProm[g]=down;
}
void maxMin(int g)
{
	VAR up=valor[0],
		down=valor[0];
	for(cnt=0;cnt<n_ind;cnt++)
	{
		if(valor[cnt]>up)
			up=valor[cnt];
		if(valor[cnt]<down)
			down=valor[cnt];
	}
	max[g]=up;
	min[g]=down;
}
int main(int argc, char* argv[])
{
	if ( argc != 2 )
	{
		printf( "usage: %s font file name (.ttf)\n", argv[0] );
		return EXIT_FAILURE;
	}
	srand(time(NULL));

	pedirDatos();
	generarPadres();
	max = (VAR*) malloc(n_gen*sizeof(VAR));
	min = (VAR*) malloc(n_gen*sizeof(VAR));
	maxProm = (VAR*) malloc(n_gen*sizeof(VAR));
	minProm = (VAR*) malloc(n_gen*sizeof(VAR));
	for(i=0;i<n_gen;i++)
	{
		seleccionTorneo();
		cruza();
		muta(30);
		valuarInd();
		maxMinProm(i);
		maxMin(i);
		printf("\nGeneracion %d :",i+1);
		imprimir();
	}

	printf("Se estan visualizando los : Promedios\nCierra la ventana para ver los valores\n\n");
	//~~~~  Grafica de promedios ~~~~~
	//Creamos y populamos coordenadas
	captionlist caption_list = NULL;
	caption_list=push_back_caption(caption_list,"Maximos Promedios",0,0x0000FF);
	caption_list=push_back_caption(caption_list,"Minimos Promedios",1,0xFF00FF);
	coordlist coordinate_list=NULL;
	coordinate_list=push_back_coord(coordinate_list,0,0,0);
	coordinate_list=push_back_coord(coordinate_list,1,0,0);
	//Populamos
	for(cnt=1;cnt<=n_gen;cnt++)
	{
		coordinate_list=push_back_coord(coordinate_list,0,cnt,maxProm[cnt-1]);
		coordinate_list=push_back_coord(coordinate_list,1,cnt,minProm[cnt-1]);
	}
	//Parametros
	plot_params params;
	params.screen_width=800;
	params.screen_heigth=640;
	params.plot_window_title="Promedio de Aptitud de las Generaciones";
	params.font_text_path=argv[1];
	params.font_text_size=18;
	params.caption_text_x="";
	params.caption_text_y="";
	params.caption_list = caption_list;
	params.coordinate_list = coordinate_list;
	params.scale_x = 5;
	params.scale_y = 5;
	params.max_x = n_gen;
	params.max_y = 100;
	//Graficamos
	int ret = plot_graph(&params);
	if (ret == EXIT_FAILURE)
	{
		printf("plot_graph return with status %d\n",ret);
		return EXIT_FAILURE;
	}
	//~~~~  Grafica de valores ~~~~~
	printf("Se estan visualizando los : Valores\nCierra la ventana para salir\n\n");
	//Creamos y populamos coordenadas
	captionlist caption_list2 = NULL;
	caption_list2=push_back_caption(caption_list2,"Maximos Valores",0,0x0000FF);
	caption_list2=push_back_caption(caption_list2,"Minimos Valores",1,0xFF00FF);
	coordlist coordinate_list2=NULL;
	coordinate_list2=push_back_coord(coordinate_list2,0,0,0);
	coordinate_list2=push_back_coord(coordinate_list2,1,0,0);
	//Populamos
	for(cnt=1;cnt<=n_gen;cnt++)
	{
		coordinate_list2=push_back_coord(coordinate_list2,0,cnt,max[cnt-1]);
		coordinate_list2=push_back_coord(coordinate_list2,1,cnt,min[cnt-1]);
	}
	//Parametros
	params.plot_window_title="Valores de Aptitud de las Generaciones";
	params.scale_y = 1;
	params.max_y = max[n_gen-1]+10;
	params.caption_list = caption_list2;
	params.coordinate_list = coordinate_list2;
	//Graaficamos
	ret = plot_graph(&params);
	if (ret == EXIT_FAILURE)
	{
		printf("plot_graph return with status %d\n",ret);
		return EXIT_FAILURE;
	}

	//Liberamos y nos vamos
	free(valor);
	free(valorProm);
	free(ind);
	free(des); 
	free(max);
	free(min);
	return EXIT_SUCCESS;
}