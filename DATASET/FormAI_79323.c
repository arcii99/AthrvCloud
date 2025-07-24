//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n, i, j, k, x;
    srand(time(0));
    printf("\nWelcome to Genome Sequencing Simulator!!!\n");
    printf("\nEnter the length of the genome: ");
    scanf("%d", &n);
    char genome[n+1];
    genome[n] = '\0';

    for(i=0;i<n;i++){
        genome[i] = rand()%4 + 'A';
    }

    printf("\nGenerating genome sequence......\n");
    printf("\nThe genome sequence is as follows:\n");
    printf("%s\n", genome);
    printf("\nEnter the length of sequence to be searched: ");
    scanf("%d", &k);

    char sequence[k+1];
    sequence[k] = '\0';

    printf("\nGenerating sequence to search......\n");

    i = rand()%(n-k+1);

    for(j=i, x=0;j<i+k;j++,x++)
        sequence[x] = genome[j];

    printf("\nThe sequence to search is as follows:\n");
    printf("%s\n", sequence);

    return 0;

}