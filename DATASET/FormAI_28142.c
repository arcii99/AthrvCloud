//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

//function prototype
void generateRandomSequence(char[]);
void printSequence(char[]);
void analyzeSequence(char[]);

int main()
{
    char genome[SIZE];
    
    //generate random sequence
    generateRandomSequence(genome);
    
    //print the sequence
    printf("The generated sequence is:\n");
    printSequence(genome);
    
    //analyze the sequence
    analyzeSequence(genome);
    
    return 0;
}

//function to generate random sequence
void generateRandomSequence(char arr[])
{
    int i;
    char nucleotide[] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    
    for(i=0; i<SIZE; i++)
    {
        arr[i] = nucleotide[rand()%4];
    }
}

//function to print the sequence
void printSequence(char arr[])
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

//function to analyze the sequence
void analyzeSequence(char arr[])
{
    int i, countA=0, countC=0, countG=0, countT=0;
    
    for(i=0; i<SIZE; i++)
    {
        if(arr[i] == 'A')
        {
            countA++;
        }
        else if(arr[i] == 'C')
        {
            countC++;
        }
        else if(arr[i] == 'G')
        {
            countG++;
        }
        else if(arr[i] == 'T')
        {
            countT++;
        }
    }
    
    //display the analysis result
    printf("Analysis of the sequence:\n");
    printf("A: %d\n", countA);
    printf("C: %d\n", countC);
    printf("G: %d\n", countG);
    printf("T: %d\n", countT);    
}