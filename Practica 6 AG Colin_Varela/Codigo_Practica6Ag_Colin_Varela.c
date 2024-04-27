/**
 * Arunakemi Colin Varela
 * 3CM5
 * Algoritmos Geneticos
 * PRACTICA 6
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
		printf("\n\nPractica 6: Métodos de cruza o recombinación\n");
		printf("Alumna: Arunakemi Colin Varela\n");
		printf("Menu:\n");
		printf("1) Cruza de un punto\n");
		printf("2) Cruza de dos puntos\n");
		printf("3) Cruza Uniforme\n");
		printf("4) Cruza Acentuada\n\n");
		printf("0) Salir\n");
		printf(":  ");
		scanf("%d",&op);
		//Generamos los padres para la cruza
		int A1[8],A2[8],B1[8],B2[8],i,H1[8],H2[8];
		for(i=0;i<8;i++)
		{
			A1[i] = rand()%2;
			A2[i] = rand()%2;
			B1[i] = rand()%2;
			B2[i] = rand()%2;
		}
		// Cruza de un punto
		if(op==1)
		{
			int num = (rand()%7) + 1;
			printf("\nCruza de un punto en %i\n", num);
			for(i=0;i<num;i++)
			{
				H1[i] = A1[i];
				H2[i] = B1[i];
			}
			for(i=num;i<8;i++)
			{
				H1[i] = A2[i];
				H2[i] = B2[i];
			}
		}
		//Cruza de dos puntos
		else if(op==2)
		{
			int num = (rand()%7) + 1,num2;
			do
			{
				num2 = (rand()%7) + 1;
			}while(num==num2);
			printf("\nCruza de dos puntos en %i y %i\n", num,num2);
			if(num2<num)
			{
				int hp = num2;
				num2 = num;
				num = hp;
			}
			for(i=0;i<num;i++)
			{
				H1[i] = A1[i];
				H2[i] = B1[i];
			}
			for(i=num;i<num2;i++)
			{
				H1[i] = A2[i];
				H2[i] = B2[i];
			}
			for(i=num2;i<8;i++)
			{
				H1[i] = A1[i];
				H2[i] = B1[i];
			}
		}
		//Cruza Uniforme
		else if(op==3)
		{
			int m[8];
			for(i=0;i<8;i++)
			{
				m[i] = rand()%2;
			}
			for(i=0;i<8;i++)
			{
				if(m[i]==1)
				{
					H1[i] = A1[i];
					H2[i] = B1[i];
				}
				else
				{
					H1[i] = A2[i];
					H2[i] = B2[i];
				}
			}
			printf("\nCruza Uniforme con la\n");
			printf("Mascara : \t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i | ", m[i]);
			}
		}
		//Cruza Acentuada
		else if(op==4)
		{
			int m1[8],m2[8];
			for(i=0;i<8;i++)
			{
				m1[i] = rand()%2;
				m2[i] = rand()%2;
			}
			printf("\n\nPadre 1 : \t");
			for (i = 0; i < 8; ++i)
			{
				if(m1[i]==1)
					printf("%i! | ", A1[i]);
				else
					printf("%i  | ", A1[i]);
			}
			printf("\nPadre 2 : \t");
			for (i = 0; i < 8; ++i)
			{
				if(m2[i]==1)
					printf("%i! | ", A2[i]);
				else
					printf("%i  | ", A2[i]);
			}

			int cnt=0;
			for(i=0;i<8;i++)
			{
				if(m2[i]==1) 
					m1[i] = 1;
				if(m1[i]==1)
					cnt = abs(cnt-1);
				if(cnt==0)
				{
					H1[i] = A1[i];
					H2[i] = A2[i];
				}
				else
				{
					H1[i] = A2[i];
					H2[i] = A1[i];
				}
			}

			printf("\n\nHijo 1 : \t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i  | ", H1[i]);
			}
			printf("\n\nHijo 2 : \t");
			for (i = 0; i < 8; ++i)
			{
				if(m1[i]==1)
					printf("%i! | ", H2[i]);
				else
					printf("%i  | ", H2[i]);
			}
			char c = getchar();
			printf("\n\nENTER para volver al menu\n");	
			c = getchar();
			
		}
		if(op==1||op==2||op==3)
		{
			printf("\n\nPadre 1 : \t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i | ", A1[i]);
			}
			printf("\nPadre 2 : \t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i | ", A2[i]);
			}
			printf("\n\nHijo : \t\t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i | ", H1[i]);
			}
			printf("\n\nPadre 3 : \t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i | ", B1[i]);
			}
			printf("\nPadre 4 : \t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i | ", B2[i]);
			}
			printf("\n\nHijo : \t\t");
			for (i = 0; i < 8; ++i)
			{
				printf("%i | ", H2[i]);
			}
			char c = getchar();
			printf("\n\nENTER para volver al menu\n");	
			c = getchar();
		}
	}
	while(op!=0);
	return 42;
}