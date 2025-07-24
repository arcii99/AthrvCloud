//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Sassy Database Querying Compiler!\n");
    printf("Let's see what juicy data we can dig up...\n");

    int data[] = {2, 4, 6, 8, 10};
    int size = sizeof(data) / sizeof(data[0]);

    printf("\nLet's start by showing all the data we have:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n\nNow let's find the average of the numbers in our database...\n");
    int sum = 0;
    double average;

    for(int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    average = (double)sum / size;

    printf("\nDrumroll please...the average is: %.2f\n", average);

    printf("\nOkay, let's get sassy and show only the even numbers in our database...\n");
    for(int i = 0; i < size; i++)
    {
        if(data[i] % 2 == 0)
        {
            printf("%d ", data[i]);
        }
    }

    printf("\n\nOne more sassy move, let's reverse the order of our database...\n");
    int temp;
    for(int i = 0; i < size / 2; i++)
    {
        temp = data[i];
        data[i] = data[size - i - 1];
        data[size - i - 1] = temp;
    }

    printf("\nWithout further ado, our reversed database is:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n\nLooks like we have an empty database now, time to close up shop!\n");
    printf("Thanks for querying with Sassy Database Querying Compiler, have a sassy day!\n\n");

    return 0;
}