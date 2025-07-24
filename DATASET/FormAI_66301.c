//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10000000 // 10 million bytes

double calculate_speed(char *data, int size, double time_elapsed)
{
    double speed = (double)size / (time_elapsed * 1000000);
    return speed;
}

int main()
{
    char *data;
    double time_elapsed;
    clock_t start, end;
    
    // allocate memory for test data
    data = (char*) malloc(sizeof(char) * SIZE);
    if (!data)
    {
        printf("Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // fill the data with random characters
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = 'a' + rand() % 26;
    }

    // perform the test
    start = clock();
    for (int i = 0; i < 1000; i++)
    {
        fwrite(data, sizeof(char), SIZE, stdout); // send to standard output
    }
    end = clock();

    // calculate the speed
    time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    double speed = calculate_speed(data, SIZE, time_elapsed);

    printf("Internet Speed Test Result:\n");
    printf("Speed: %.2f Mbps\n", speed);
    printf("Download Time: %.2f seconds\n", time_elapsed);
 
    // free the memory
    free(data);
    
    return EXIT_SUCCESS;
}