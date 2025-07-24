//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include<stdio.h>
#include<time.h>

void wasteTime(int seconds) //This function wastes time, quite literally.
{
    time_t start, current;
    time(&start);
    do
    {
        time(&current);
    } while((current-start)<seconds);
}

int main()
{
    printf("Welcome to the Great Benchmarking Program!\n");
    printf("This program tests how fast your computer is.\n");
    printf("We will start with some basic calculations.\n");
    int a=4;
    int b=3;
    printf("Calculating 4+3...\n");
    printf("%d\n",a+b);
    
    printf("Calculating 9*8...\n");
    printf("%d\n",9*8);
    
    printf("Calculating 7^5...\n");
    printf("%d\n",7*7*7*7*7);
    
    printf("Now let's check how fast your computer can count.\n");
    int i;
    printf("Counting from 1 to 1000000...\n");
    for(i=0;i<=1000000;i++)
    {
        //Do nothing
    }
    printf("Done!\n");
    
    printf("Now let's test how long it takes to waste some time.\n");
    printf("Wasting 5 seconds...\n");
    wasteTime(5);
    printf("Done wasting time!\n");
    
    printf("Finally, let's check the speed of your hard drive.\n");
    printf("We will write 10000 lines of text to a file named 'benchmark.txt'.\n");
    FILE *fptr;
    fptr=fopen("benchmark.txt","w");
    if(fptr==NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }
    for(i=0;i<10000;i++)
    {
        fprintf(fptr,"This line is part of the benchmarking program.\n");
    }
    fclose(fptr);
    printf("Done writing to file!\n");
    printf("Great job! Your computer is lightning fast!\n");
    return 0;
}