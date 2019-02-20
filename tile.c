#include <stdlib.h>
#include <stdio.h>
#define b1size 8
#define b2size 16
#define M 64
#define N 64
#define P 64

void bijk(float** A, float** B, float** C, int n, int bsize1, int bsize2)
{
  int i, j, k, kk, jj,x,y,z;
  double sum;
  int en = n; /*Amount that fits evenly into blocks*/
#ifdef DEBUG
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      {C[i][j] = 0.0;
B[i][j] = 1;
A[i][j] = 2;

}
#endif
  bsize1 = b1size;
  bsize2 = b2size;
  
  for (x=0;x<n;x+=bsize2){
    for (y=0;y<n;y+=bsize2){
      for (z=0;z<n;z+=bsize2){


      for (kk = x; kk < x+bsize2; kk += bsize1) 
      {
        for (jj = y; jj < y+bsize2; jj += bsize1) {
          for (i = z; i < z+bsize2; i++) {
            for (j = jj; j < jj + bsize1; j++) {
              sum = C[i][j];
//		sum = 0.0f;

              for (k = kk; k < kk + bsize1; k++) {
                sum += A[i][k]*B[k][j];
              }
              C[i][j] = sum;
            }
          }
        }
      }
    }
  }
 }
#ifdef DEBUG
for(int i =0;i<M;i++)
{for(int j=0;j<M;j++)
{
 printf("%f ",C[i][j]);
}
printf("\n");
}
#endif
}




// function to allocate a matrix on the heap
// creates an mXn matrix and returns the pointer.
//
// the matrices are in row-major order.
void create_matrix(float*** A, int m, int n) {
  float **T = 0;
  int i;

  T = (float**)malloc( m*sizeof(float*));
  for ( i=0; i<m; i++ ) {
     T[i] = (float*)malloc(n*sizeof(float));
  }
  *A = T;
}

int main() {
  float** A;
  float** B;
  float** C;

  create_matrix(&A, M, P);
  create_matrix(&B, P, N);
  create_matrix(&C, M, N);

  // assume some initialization of A and B
  // think of this as a library where A and B are
  // inputs in row-major format, and C is an output
  // in row-major.


  bijk(A,B,C,M,b1size,b2size);

 
  return (0);
}



