//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{  
    int genome[1000];
    srand(time(0));
    
    for(int i=0; i<1000; i++)
    {
        genome[i] = rand()%4+1;
        
        if(genome[i]==1)
        {
            printf("A");
        }
        else if(genome[i]==2)
        {
            printf("C");
        }
        else if(genome[i]==3)
        {
            printf("G");
        }
        else
        {
            printf("T");
        }
    }
    printf("\n\nGenome Sequenced Successfully!\n");
    return 0;
}