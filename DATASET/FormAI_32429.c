//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000 //1MB

int main()
{
    clock_t start, end;
    double cpu_time_used;
    float internet_speed;
    char buffer[SIZE];

    FILE *fp = fopen("test.txt", "w");

    srand(time(NULL)); //initializing random seed

    for(int i = 0; i < SIZE; i++) //generating random characters to write in file
    {
        buffer[i] = rand() % 256;
        fprintf(fp, "%c", buffer[i]);
    }

    fclose(fp);

    fp = fopen("test.txt", "r");

    if(fp == NULL) //error handling
    {
        printf("\nError: File not found.");
        return 1;
    }

    start = clock(); //starting timer

    while(fgets(buffer, SIZE, fp)) {} //reading file

    end = clock(); //stopping timer

    fclose(fp);

    remove("test.txt"); //deleting file

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    internet_speed = (SIZE / cpu_time_used) / 1000000; //calculating internet speed in MBPS

    printf("\nYour internet speed is: %.2f MBPS", internet_speed);

    return 0;
}