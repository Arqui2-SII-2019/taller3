#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emmintrin.h> //v2
#include <smmintrin.h> //v4

void testA(){
	printf("\n ***************** prueba A: calculando mayor de la matriz sin SSEx ***************** \n");
	short matriz[2][8];
	short vectorMax[8];
	printf("ingrese el dato\n");
	//filling the matrix
	for(int i=0; i<2; i++){
		for(int j=0; j<8; j++){
			//asking the user to insert the datas, first columns
			//then rows
			printf("[%d][%d]=",i,j);
			scanf("%hi", &matriz[i][j]);
		}
		printf("\n");
	}
	
	//analizing the matrix for the maximun values
	for(int i=0; i<8; i++){
		//the search is made by columns, since the 
		//there are only two row the search will be 
		//easier this way.
		if(matriz[0][i]<matriz[1][i]){
			vectorMax[i]=matriz[1][i];
			continue;
		}
		vectorMax[i]=matriz[0][i];
	}
	printf("\nvector resultante\n"); 
	//printing the maximun values find on the matrix
	for(int i=0; i<8; i++){
		printf("%hi \t",vectorMax[i]);
	}
	printf("\n");
}

void testB(){
	printf("\n ***************** prueba B: calculando mayor de la matriz con SSEx ***************** \n");
	//****Nota: este código requiere SSE4****//
	short matriz[2][8];
	printf("ingrese el dato\n");
	//filling the matrix
	for(int i=0; i<2; i++){
		for(int j=0; j<8; j++){
			//asking the user to insert the datas, first columns
			//then rows
			printf("[%d][%d]=",i,j);
			scanf("%hi", &matriz[i][j]);
		}
		printf("\n");
	}
	__m128i vector1 = _mm_set_epi16(matriz[0][7],matriz[0][6],matriz[0][5],matriz[0][4],
									matriz[0][3],matriz[0][2],matriz[0][1],matriz[0][0]); // Little endian, stored in 'reverse'
	__m128i vector2 = _mm_set_epi16(matriz[1][7],matriz[1][6],matriz[1][5],matriz[1][4],
									matriz[1][3],matriz[1][2],matriz[1][1],matriz[1][0]); // Little endian, stored in 'reverse');
	
	__m128i resultMax = _mm_max_epi16(vector1,vector2);
	
	//Vector Printing
	int data = 0;
	printf("Result *********************** \n");
	
	data = _mm_extract_epi16(resultMax,0); 
	printf("%d \t", data);

	data = _mm_extract_epi16(resultMax,1); 
	printf("%d \t", data);

	data = _mm_extract_epi16(resultMax,2); 
	printf("%d \t", data);

	data = _mm_extract_epi16(resultMax,3); 
	printf("%d \t", data);
	
	data = _mm_extract_epi16(resultMax,4); 
	printf("%d \t", data);

	data = _mm_extract_epi16(resultMax,5); 
	printf("%d \t", data);

	data = _mm_extract_epi16(resultMax,6); 
	printf("%d \t", data);

	data = _mm_extract_epi16(resultMax,7); 
	printf("%d \t", data);
	printf("\n");
}