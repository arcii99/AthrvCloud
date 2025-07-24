//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_REQUESTS 5
#define BUFFER_SIZE 1024

// function to generate a random download speed within a specified range
double generate_download_speed(double min, double max){
    double range = (max - min); 
    double download_speed = min + (double)rand() / RAND_MAX * range;
    return download_speed;
}

int main() {
    char url[BUFFER_SIZE];
    double download_speed;
    int num_requests;
    double download_speeds[MAX_REQUESTS];

    // prompt user to enter URL and number of requests
    printf("Enter the URL: ");
    scanf("%s", url);
    printf("Enter the number of speed test requests: ");
    scanf("%d", &num_requests);

    // initialize random seed
    srand(time(NULL));

    // loop through each request and generate a random download speed
    for(int i = 0; i < num_requests; i++){
        download_speeds[i] = generate_download_speed(0.5, 6.0); // generate a speed between 0.5 Mbps and 6.0 Mbps
        printf("Request %d: Download speed %.2f Mbps\n", i+1, download_speeds[i]);
    }

    // calculate average download speed
    double total_speeds = 0.0;
    for(int i = 0; i < num_requests; i++){
        total_speeds += download_speeds[i];
    }
    double avg_speed = total_speeds / num_requests;
    printf("Average download speed for %d requests: %.2f Mbps", num_requests, avg_speed);

    return 0;
}