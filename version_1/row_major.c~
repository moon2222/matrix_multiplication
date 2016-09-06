#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

struct timeval  tv1, tv2;
 
main()
{
    double *mat1, *mat2,*res;
    int k,i,j,r1,c1,r2,c2;
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

    res=(double*)calloc((r1*c2),sizeof(double));

//Input Matrix1
    for(i=0; i<r1*c1; i++)
          mat1[i]=rand();
//Input Matrix2
    for(i=0; i<r2*c2; i++)
        mat2[i]=rand();

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

//Multiplication
 gettimeofday(&tv1, NULL);

    for (i = 0; i < r1; i++) {
        for (j = 0; j <c2; j++) {
            for (k = 0; k < c1; k++) {
                res[j + i * c2] += mat1[k + i * c1] * mat2[j + k * c2];
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





    
