#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

struct timeval  tv1, tv2;
 
main()
{
    double *mat1, *mat2,*res,*mat2T;
    int k,i,j,n,r1,c1,r2,c2;
    double timeofday;
   

    printf("\nEnter the Order of the First matrix...\n");
    scanf("%d %d",&r1,&c1);
    printf("\nEnter the Order of the Second matrix...\n");
    scanf("%d %d",&r2,&c2);

    if(c1!=r2)
    {
        printf("Invalid Order of matrix");
        exit(EXIT_SUCCESS);
    }

    mat1= (double*) malloc((r1*c1)*sizeof(double));

    mat2= (double*) malloc((r2*c2)*sizeof(double));
    
    mat2T= (double*) malloc((r2*c2)*sizeof(double));
    
    res=(double*)calloc((r1*c2),sizeof(double));
    
    
    if (mat1== NULL ||mat2 == NULL ||res == NULL) {
      printf( "\n ERROR: Can't allocate memory for matrices. Aborting... \n\n");
      free(mat1);
      free(mat2);
      free(mat2T);
      free(res);
      return 1;
    }
//Input Matrix1
    for(i=0; i<r1*c1; i++)
          mat1[i]=rand();
//Input Matrix2
    for(i=0; i<r2*c2; i++)
        mat2[i]=rand();
        
//calculating matrix2 transpose
    
    for( n = 0; n<r2*c2; n++)
     {
         i = n/r2;
         j = n%c2;
        mat2T[n] = mat2[c2*j + i];
    }


//Printing Input Matrix 1 & 2

   printf("\n Matrix 1: \n");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            printf("%lf\t ",mat1[j+i*c1]);
        printf("\n");
    }

    printf("\n Matrix 2: \n");
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            printf("%lf \t",mat2[j+i*c2]);
        printf("\n");
    }
    
    printf("\n Matrix 2 transpose: \n");
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            printf("%lf \t",mat2T[j+i*c2]);
        printf("\n");
    }
    

//Multiplication
 gettimeofday(&tv1, NULL);

    for (i = 0; i < r1; i++) {
        for (j = 0; j <c2; j++) {
            for (k = 0; k < c1; k++) {
                res[j + i * c2] += mat1[k + i * c1] * mat2T[k + j* r2];  //mat1*mat2T
            }
        }
    }
   gettimeofday(&tv2, NULL);

    timeofday=(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +(double) (tv2.tv_sec - tv1.tv_sec);
     
     
  

printf("\nThe Multiplication of two matrix is\n");
    for(i=0; i<r1; i++)
    {
        printf("\n");
        for(j=0; j<c2; j++)
            printf("%lf\t",res[j+i*c2]);
    }
    printf("\n\n\n");
    printf ( "%f\n",timeofday*1000);
    
    
        return 0;
}





    
