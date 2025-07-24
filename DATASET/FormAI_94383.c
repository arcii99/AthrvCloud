//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: artistic
#include<stdio.h>
#include<time.h>

int main(){

    int i, j, k, l;
    double start, end, result;
    printf("Welcome to the Internet Speed Test Application!\n");

    printf("Please enter the number of iterations to be performed: ");
    scanf("%d",&k);

    for(l=1;l<=k;l++){
        start = clock();
        printf("Testing Iteration %d:\n",l);
        for(i=0;i<10;i++){
            for(j=0;j<100000000;j++);
        }
        end = clock();
        result = (double)(end - start)/CLOCKS_PER_SEC;
        printf("Test %d completed.\n",l);
        printf("Time taken for the test is %f seconds\n",result);
    }

    printf("\nThanks for using the Internet Speed Test Application!");

    return 0;
}