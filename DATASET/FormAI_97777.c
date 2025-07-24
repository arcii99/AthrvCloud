//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define SIZE 1048576 //1 MB, change according to your preference

int main()
{
    char* data = (char*) malloc(sizeof(char) * SIZE); //allocate memory for data
    if(data == NULL) //checking if memory is allocated or not
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    //measuring time taken to download data from server
    double time_taken;
    clock_t t;

    printf("Starting speed test...\n");
    t = clock(); //start the clock

    //downloading data from server
    sleep(1); //simulating download time
    printf("Data downloaded successfully.\n");

    t = clock() - t; //stop the clock
    time_taken = ((double)t)/CLOCKS_PER_SEC; //calculate total time taken in seconds

    //calculate and print internet speed
    printf("Speed test completed!\nDownload Speed: %.2f MB/s\n", (SIZE/time_taken)/(1024*1024));

    free(data); //free memory allocated for data
    return 0;
}