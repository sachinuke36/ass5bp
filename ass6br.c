#include<stdio.h>
#include<stdlib.h>
//M=rows N=cols


void Allocating_2D_Array(double*** a1, int M, int N) {
    *a1 = (double**)malloc(M * sizeof(double*));
    for (int i = 0; i < M; i++)
        (*a1)[i] = (double*)malloc(N * sizeof(double));
    if (*a1 == NULL)
         printf("malloc fail");
}


void Read_2D_Array(int M, int N, double** arr) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) 
        {
            printf("Enter the %d%d element:\n", i, j);
            scanf("%lf", &arr[i][j]);
        }
    }
}

  
  void Print_2D_Array(double** prnt, int N, int M) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf \t", prnt[i][j]);
        }
        printf("\n");
    }
}


void Free_2D_Array(int M, int N, double** freeUp)
   {
    for(int i=0; i<M; i++) free(freeUp[i]);
    free(freeUp);
   }
   
  void Matrix_multiplication(double** Matrix1,double** Matrix2,int M,int L,int N,double** Mat_multi)
   { 
       for(int i=0; i<M; i++)
         {
             for(int j=0; j<N; j++)
               { 
                   Mat_multi[i][j] = 0.0;
                   for(int k=0; k<L; k++)
                     {
                         Mat_multi[i][j]+= (Matrix1[i][k])*Matrix2[k][j];
                     }
               }
         }
       
   }
   
   int Compute_trace(double** matrix,int rows,int columns,double* Trace)
   {  if(rows==columns)
      {
       for(int i=0; i<rows; i++)
          {
              for(int j=0; j<rows; j++)
               {
                   
                  if(i==j) *Trace= matrix[i][j]+ *Trace;
               }
          }
       
      }
      else {
          printf("Trace cannot be found\n");
            return -1;
          }
   }
   
   

int main()
 {  int M,N,L,K;
    
//Matrix1 allocating,reading and printing
    printf("For Matrix1 Enter the number of rows and columns:\n");
    scanf("%d%d", &M, &N);
    double **Matrix1;//not Matrix[M][N]
    Allocating_2D_Array(&Matrix1, M, N);
    Read_2D_Array(M, N, Matrix1);
    Print_2D_Array(Matrix1, N, M);

//Matrix2 allocating,reading and printing
    printf("For Matrix2 Enter the number of rows and columns:\n");
    scanf("%d%d",&K,&L);
    double **Matrix2;
    Allocating_2D_Array(&Matrix2, K, L);
    Read_2D_Array(K, L, Matrix2);
    Print_2D_Array(Matrix2, L, K);

//Allocating space to result and result of matrix multiplication
     double** Mat_multi;
     Allocating_2D_Array(&Mat_multi,M,L);
     if(N==K)
     { N=K;
         Matrix_multiplication(Matrix1,Matrix2,M,L,N,Mat_multi);
          printf("Multiplication of matrix is\n");
          Print_2D_Array(Mat_multi,L,M);
     }
     else printf("Matrix multiplication is not possible\n");
    
    
//Calculating the trace
    double Trace=0;
    Compute_trace(Matrix1,M,N,&Trace);
  if(Trace!=0)  printf("Trace of matrix is :%lf",Trace);
 }