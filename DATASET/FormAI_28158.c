//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 1024

double calculate_speed(double file_size_mb, double time_taken);

int main()
{
    char buffer[BUFFER_SIZE];
    double file_size_mb;
    clock_t start_time, end_time;
    double time_taken;
    double speed;

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please enter the size of the file in MB: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    file_size_mb = atof(buffer);

    printf("Starting download...\n");
    start_time = clock();

    // Simulate downloading the file by sleeping for a random amount of time (between 1-5 seconds)
    srand(time(NULL));
    int random_time = rand() % 5 + 1;
    sleep(random_time);

    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Download complete in %.2f seconds.\n", time_taken);

    // Calculate the download speed in megabits per second (Mbps)
    speed = calculate_speed(file_size_mb, time_taken);
    printf("Your internet speed is %.2f Mbps.\n", speed);

    return 0;
}

double calculate_speed(double file_size_mb, double time_taken)
{
    double file_size_bits = file_size_mb * 8 * pow(10, 6);
    double speed = file_size_bits / time_taken / pow(10, 6);
    return speed;
}