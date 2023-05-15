/*
Write a function named getKeyValue(int A[], int n, intkey_val, int *pos)
which takes an array of integers A of size n and a key value key_val as
argument, it returns 1 if the key value is present in the array, else it returns
0. If the key value is present the smallest array index having the value is
returned through another argument variable pos. 

Write a program which reads N integers (to be read from the key-board)
in an array. The program reads a sequence of integer values in a while
loop and prints the value, if it exists and deletes the element from the
array. Otherwise, it prints “The key is not present in the array.” The
program terminates when the array size becomes 0 with a message,
“The array becomes empty”, or when the number of failure (not finding
a key value) reaches N with a message, “The number of failure equals
the input size.”).

*/



#include<stdio.h>
#include<stdlib.h>

int getKeyValue(int A[], int n, int key_val, int *pos)
     {

     	for( int i=0; i<n; i++)
     		  {
     		  	if(A[i]== key_val && i<n)
     		  	 {
     		  	 *pos=i;
     		  	 return 1;
     		  	}
     		  }
     		  
  return 0;
     }



int main()
{
	int N; int number[100];int i=0;
	int pos=0;int value;
	int failure=0;
	int key_val;int n;
	printf("Enter the total numbers to be input\n");
	scanf("%d",&N);
    n=N;
	printf("Enter the numbers\n");
	for(int i=0; i<N; i++)
	{
		scanf("%d",&number[i]);
		printf("The number at intdex %d is %d \n",i,number[i]);
	}
	

    while(1)
   	 {
   	 	printf("Enter the key:\n");
   	 	scanf("%d",&key_val);
   	 	value=getKeyValue(&number[0],N,key_val,&pos);
   	 	 if(value==1)
   	 	 {
           for(int i=pos; i<N-1; i++) number[i]=number[i+1];
           	N=N-1;
   	 	 }
   	 	else {
			printf("The key not found:\n");
			failure++;
		}

   	 	if(N==0) {
   	 		printf("The array is empty\n");
   	 		break;
   	 	}
		if(failure==n){
		printf("The number of failure equals the input size.\n");
		exit(1);
		}
   	 }


}