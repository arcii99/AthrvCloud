//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k,n;
    float sec;
    printf("Enter the number of iterations to test the speed: ");
    scanf("%d",&n);

    clock_t start = clock();
    for(i=0;i<n;i++)
    {
        system("ping -c 1 google.com > output.txt");

        FILE *fptr;
        fptr = fopen("output.txt","r");

        char buffer[1000];

        while(!feof(fptr))
        {
            fgets(buffer,1000,fptr);
        }

        fclose(fptr);
    }
    clock_t end = clock();

    sec = (float)(end-start)/CLOCKS_PER_SEC;

    float avg = sec/n;

    printf("Average Time taken for %d iterations is %f seconds\n",n,avg);
    return 0;
}