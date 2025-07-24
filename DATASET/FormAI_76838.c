//FormAI DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random numbers */
int randomGen()
{
    int num;
    num = (rand() % 1000) + 1;   // Generates numbers between 1 and 1000
    return num;
}

/* Function to shuffle the array */
void shuffle(int arr[], int n)
{
    int i, temp;
    for(i=0; i<n; i++)
    {
        int j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/* Function to calculate the average */
float average(int arr[], int n)
{
    int i, sum=0;
    for(i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return ((float)sum/n);
}

/* Main function */
int main()
{
    int boot_times[10], i;
    float avg_time;

    srand(time(NULL));   // Seeding the random number generator

    /* Generating random boot times */
    printf("Randomly generated boot times:\n");
    for(i=0; i<10; i++)
    {
        boot_times[i] = randomGen();
        printf("%d\t", boot_times[i]);
    }

    /* Shuffling the array */
    shuffle(boot_times, 10);

    /* Displaying the shuffled array */
    printf("\n\nShuffled boot times:\n");
    for(i=0; i<10; i++)
    {
        printf("%d\t", boot_times[i]);
    }

    /* Calculating the average */
    avg_time = average(boot_times, 10);

    /* Displaying the average */
    printf("\n\nAverage boot time: %.2f seconds", avg_time);

    return 0;
}