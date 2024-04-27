/**
 * Arunakemi Colin Varela
 * 3CM5
 * Algoritmos Geneticos
 * PRACTICA 2
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int op; //Opcion del menu
	int i,i2;
	do
	{
		printf("\n\nPractica 2: Representación de algoritmos geneticos\n");
		printf("Alumna: Arunakemi Colin Varela\n");
		printf("Menu:\n");
		printf("1) Representación binaria\n");
		printf("2) Códigos de Gray\n");
		printf("3) Codificación en números reales\n");
		printf("4) Codificación en números enteros\n");
		printf(":  ");
		scanf("%d",&op);
		//Representación binaria
		if(op==1)
		{
			int A[10][7];
			for ( i = 0; i < 10; ++i)
				for ( i2 = 0; i2 < 7; ++i2)
					A[i][i2] = rand()%2;	//Genera los numeros
			for ( i = 0; i < 10; ++i)
			{
				printf("\nIndividuo %d\n", i);
				for ( i2 = 0; i2 < 7; ++i2)
					printf(" %d |", A[i][i2]);	//Imprime
			}
			char c = getchar();
			printf("\n\nENTER para volver al menu\n");	
			c = getchar();
		}
		//Códigos de Gray
		else if(op==2)
		{
			int A[10][7];
			for ( i = 0; i < 10; ++i)
				for ( i2 = 0; i2 < 7; ++i2)
					A[i][i2] = rand()%2;	//Genera los numeros

			for ( i = 0; i < 10; ++i)
				for ( i2 = 6; i2 > 0; --i2)
				{
					if(A[i][i2]==A[i][i2-1])	//Genera el Gray
						A[i][i2] = 0;
					else
						A[i][i2] = 1;
				}
			for ( i = 0; i < 10; ++i)
			{
				printf("\nIndividuo %d\n", i);
				for ( i2 = 0; i2 < 7; ++i2)
					printf(" %d |", A[i][i2]);	//Imprime
			}
			char c = getchar();
			printf("\n\nENTER para volver al menu\n");	
			c = getchar();
		}
		//Codificación en números reales
		else if(op==3)
		{
			float A[10][7];
			for ( i = 0; i < 10; ++i)
				for ( i2 = 0; i2 < 7; ++i2)
				{
					float rand2 = rand()%1000;
					A[i][i2] = rand2/100;	//Genera los numeros
				}
			for ( i = 0; i < 10; ++i)
			{
				printf("\nIndividuo %d\n", i);
				for ( i2 = 0; i2 < 7; ++i2)
					printf(" %.2f |", A[i][i2]);	//Imprime
			}
			char c = getchar();
			printf("\n\nENTER para volver al menu\n");	
			c = getchar();
		}
		//Codificación en números enteros
		else if(op==4)
		{
			int A[10][7];
			for ( i = 0; i < 10; ++i)
				for ( i2 = 0; i2 < 7; ++i2)
					A[i][i2] = rand()%10;	//Genera los numeros
			for ( i = 0; i < 10; ++i)
			{
				printf("\nIndividuo %d\n", i);
				for ( i2 = 0; i2 < 7; ++i2)
					printf(" %d |", A[i][i2]);	//Imprime
			}
			char c = getchar();
			printf("\n\nENTER para volver al menu\n");	
			c = getchar();
		}
	}
	while(op!=0);
	return 42;
}