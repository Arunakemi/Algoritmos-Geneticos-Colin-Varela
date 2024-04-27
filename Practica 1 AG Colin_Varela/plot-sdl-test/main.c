/**
 * Arunakemi Colin Varela
 * 3CM5
 * Algoritmos Geneticos
 * PRACTICA 1
*/
#include "stdio.h"
#include "plotsdl/plot.h"
#include "plotsdl/llist.h"
#include <time.h>
#include <stdlib.h>
  
int main(int argc, char* argv[])
{
	if ( argc != 2 )
	{
		printf( "usage: %s font file name (.ttf)\n", argv[0] );
		return EXIT_FAILURE;
	}

	//populate caption list
	captionlist caption_list = NULL;

	caption_list=push_back_caption(caption_list,"Valor 1",0,0x0000FF);

	//print_list_caption(caption_list);

	//Generar numeros
	int A[10];
	int i;
	srand(time(NULL)); 
	for (i = 0; i < 10; ++i)
	{
		A[i] = rand()%120;
	}
	//populate coordinate list
	coordlist coordinate_list=NULL;
	coordinate_list=push_back_coord(coordinate_list,0,0,A[0]);
	coordinate_list=push_back_coord(coordinate_list,0,1,A[1]);
	coordinate_list=push_back_coord(coordinate_list,0,2,A[2]);
	coordinate_list=push_back_coord(coordinate_list,0,3,A[3]);
	coordinate_list=push_back_coord(coordinate_list,0,4,A[4]);
	coordinate_list=push_back_coord(coordinate_list,0,5,A[5]);
	coordinate_list=push_back_coord(coordinate_list,0,6,A[6]);
	coordinate_list=push_back_coord(coordinate_list,0,7,A[7]);
	coordinate_list=push_back_coord(coordinate_list,0,8,A[8]);
	coordinate_list=push_back_coord(coordinate_list,0,9,A[9]);
	//print_list_coord(coordinate_list);

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
	params.scale_x = 1;
	params.scale_y = 10;
	params.max_x = 9;
	params.max_y = 120;

	int ret = plot_graph(&params);

	if (ret == EXIT_FAILURE)
	{
		printf("plot_graph return with status %d\n",ret);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}