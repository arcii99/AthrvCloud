//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define G 50    //number of genes in genome
#define M 100   //maximum value for gene (inclusive)

//function to generate genome
void generateGenome(int genome[])
{
    int i;

    //initialize random seed
    srand(time(NULL));

    //generate random genome
    for(i=0;i<G;i++)
        genome[i] = rand()%(M+1);
}

//function to print genome
void printGenome(int genome[])
{
    int i;

    //print genome
    for(i=0;i<G;i++)
        printf("%d ", genome[i]);
    printf("\n");
}

//function to mutate genome
void mutateGenome(int genome[])
{
    int i, j, k;

    //initialize random seed
    srand(time(NULL));

    //mutate up to 10 genes
    for(i=0;i<10;i++)
    {
        j = rand()%G;  //randomly select gene to mutate
        k = rand()%(M+1);  //generate random value for gene
        genome[j] = k;  //mutate gene
    }
}

//main function
int main()
{
    int genome[G];

    //generate genome
    generateGenome(genome);

    //print original genome
    printf("Original genome:\n");
    printGenome(genome);

    //mutate genome
    mutateGenome(genome);

    //print mutated genome
    printf("\nMutated genome:\n");
    printGenome(genome);

    return 0;
}