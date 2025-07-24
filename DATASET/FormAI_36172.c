//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MB 1024*1024

void delay(int number_of_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + number_of_seconds * CLOCKS_PER_SEC);
}

float test_speed()
{
    float result = 0;
    int filesize = 25 * MB;
    clock_t start_time, end_time;
    FILE *file;

    start_time = clock();

    file = fopen("testfile", "w+");
    if (file == NULL)
    {
        printf("Error creating file\n");
        return -1;
    }

    for (int i = 0; i < filesize; i++)
    {
        fputc(rand() % 100, file);
        delay(0.001);
    }

    fclose(file);

    end_time = clock();

    result = ((float)filesize / (float)(end_time - start_time)) * CLOCKS_PER_SEC / MB;
    remove("testfile");

    return result;
}

int main()
{
    float speed = 0;

    printf("Testing internet speed...\n");
    speed = test_speed();

    printf("Your internet speed is: %.2f MB/s\n", speed);

    return 0;
}