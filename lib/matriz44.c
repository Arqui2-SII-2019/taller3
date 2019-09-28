#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h> //v1
#include <smmintrin.h> //v4

#define N 4
#define flag 0xff

void testC(){
	float matrizA[N][N];
	float matrizB[N][N];
	float resultant[N][N];	
	//filling the matrix
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			matrizA[i][j]=j*i+j;
			matrizB[i][j]=i*j+i;
			resultant[i][j]=0.0;
		}
	}
	
	printf("\n matrizA \n");
	//printing the values of the matrix
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf(" %f \t",matrizA[i][j]);
		}
		printf("\n");
	}
	printf(" matrizB\n");
	//printing the values of the matrix
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf(" %f \t",matrizB[i][j]);
		}
		printf("\n");
	}
	
	//calculating the multiplication of the two matrices
	for(int j=0; j<N; j++){
		for(int k=0; k<N; k++){
			for(int m=0; m<N; m++){
				resultant[j][k]+=(matrizA[j][m]*matrizB[m][k]);
			}
		}
	}
	printf("\n ***************** prueba C: calculando la multiplicacion sin SSEx ***************** \n");
	
	printf("\n matriz resultante \n");
	//printing the values of the matrix
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf(" %f\t",i,j,resultant[i][j]);
		}
		printf("\n");
	}
}

void testD(){
	printf("\n ***************** prueba D: calculando la multiplicacion con SSEx ***************** \n");
	float matrizA[N][N];
	float matrizB[N][N];
	
	//filling the vectors
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			matrizA[i][j]=j*i+j;
			matrizB[i][j]=i*j+i;
		}
	}
	__m128 vectMA0=_mm_load_ps(&matrizA[0]);
	__m128 vectMA1=_mm_load_ps(&matrizA[1]);
	__m128 vectMA2=_mm_load_ps(&matrizA[2]);
	__m128 vectMA3=_mm_load_ps(&matrizA[3]);
	__m128 vectMB0=_mm_set_ps(matrizB[3][0],matrizB[2][0],matrizB[1][0],matrizB[0][0]);
	__m128 vectMB1=_mm_set_ps(matrizB[3][1],matrizB[2][1],matrizB[1][1],matrizB[0][1]);
	__m128 vectMB2=_mm_set_ps(matrizB[3][2],matrizB[2][2],matrizB[1][2],matrizB[0][2]);
	__m128 vectMB3=_mm_set_ps(matrizB[3][3],matrizB[2][3],matrizB[1][3],matrizB[0][3]);
	
	__m128 pos00= _mm_dp_ps(vectMA0,vectMB0,0xff);
	__m128 pos01= _mm_dp_ps(vectMA0,vectMB1,0xff);
	__m128 pos02= _mm_dp_ps(vectMA0,vectMB2,0xff);
	__m128 pos03= _mm_dp_ps(vectMA0,vectMB3,0xff);
	__m128 pos10= _mm_dp_ps(vectMA1,vectMB0,0xff);
	__m128 pos11= _mm_dp_ps(vectMA1,vectMB1,0xff);
	__m128 pos12= _mm_dp_ps(vectMA1,vectMB2,0xff);
	__m128 pos13= _mm_dp_ps(vectMA1,vectMB3,0xff);
	__m128 pos20= _mm_dp_ps(vectMA2,vectMB0,0xff);
	__m128 pos21= _mm_dp_ps(vectMA2,vectMB1,0xff);
	__m128 pos22= _mm_dp_ps(vectMA2,vectMB2,0xff);
	__m128 pos23= _mm_dp_ps(vectMA2,vectMB3,0xff);
	__m128 pos30= _mm_dp_ps(vectMA3,vectMB0,0xff);
	__m128 pos31= _mm_dp_ps(vectMA3,vectMB1,0xff);
	__m128 pos32= _mm_dp_ps(vectMA3,vectMB2,0xff);
	__m128 pos33= _mm_dp_ps(vectMA3,vectMB3,0xff);
	
	float* data =NULL;
	printf("\n matriz resultante \n");
	
	data=&pos00;
	printf("%f \t", data[0]);
	
	data=&pos01;
	printf("%f \t", data[0]);
	
	data=&pos02;
	printf("%f \t", data[0]);
	
	data=&pos03;
	printf("%f \n", data[0]);
	
	data=&pos10;
	printf("%f \t", data[0]);
	
	data=&pos11;
	printf("%f \t", data[0]);
	
	data=&pos12;
	printf("%f \t", data[0]);
	
	data=&pos13;
	printf("%f \n", data[0]);
	
	data=&pos20;
	printf("%f \t", data[0]);
	
	data=&pos21;
	printf("%f \t", data[0]);
	
	data=&pos22;
	printf("%f \t", data[0]);
	
	data=&pos23;
	printf("%f \n", data[0]);
	
	data=&pos30;
	printf("%f \t", data[0]);
	
	data=&pos31;
	printf("%f \t", data[0]);
	
	data=&pos32;
	printf("%f \t", data[0]);
	
	data=&pos33;
	printf("%f \n", data[0]);
}