#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

struct timeval  tv1, tv2;


main()
{
    double **mat1, **mat2,**res;
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

    mat1= (double**) malloc(r1*sizeof(double*));

    for(i=0; i<c1; i++)
        mat1[i]=(double*)malloc(c1*sizeof(double));

    mat2= (double**) malloc(r2*sizeof(double*));

    for(i=0; i<c2; i++)
        mat2[i]=(double*)malloc(c2*sizeof(double));

    res=(double**)calloc(r1,sizeof(double*));

    for(i=0; i<c2; i++)
        res[i]=(double*)calloc(c2,sizeof(double));

//Input Matrix1
    for(i=0; i<r1; i++)
        for(j=0; j<c1; j++)
            mat1[i][j]=rand();
//Input Matrix2
    for(i=0; i<r2; i++)
        for(j=0; j<c2; j++)
            mat2[i][j]=rand();

//Printing Input Matrix 1 and 2

    printf("\n Entered Matrix 1: \n");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            printf("%lf ",mat1[i][j]);
        printf("\n");
    }

    printf("\n Entered Matrix 2: \n");
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            printf("%lf ",mat2[i][j]);
        printf("\n");
    }

//Multiplication
gettimeofday(&tv1, NULL);

    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            res[i][j]=0;
            for(k=0; k<c1; k++)
                res[i][j]+= mat1[i][k]*mat2[k][j];

        }

    }
    gettimeofday(&tv2, NULL);

    timeofday=(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +(double) (tv2.tv_sec - tv1.tv_sec);
    
   printf("\nThe Multiplication of two matrix is\n");
    for(i=0; i<r1; i++)
    {
        printf("\n");
        for(j=0; j<c2; j++)
            printf("%lf\t",res[i][j]);
    }
    printf("\n\n\n");
    printf ( "%f\n",timeofday*1000);

    


    return 0;
}

