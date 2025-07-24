//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include<stdio.h>
#include<time.h>
#include<math.h>

int main(){

    // Declare variables
    double start_time, end_time, elapsed_time; 
    double speed; 
    long int size = 1000000000L; // 1GB
    char buffer[size];

    // Start timer
    start_time = clock();

    // Start internet speed test
    printf("Running Internet Speed Test...\n");

    // Attempt to download 1GB file
    printf("Downloading a 1GB file, please wait...\n");

    // Simulate internet download speed
    int download_speed = rand() % 10 + 1; // Random download speed between 1-10 MB/s

    // Loop through buffer and simulate download
    for(int i = 0; i < size; i++){
        buffer[i] = '0';
        if(i % (download_speed * 1000000) == 0 && i != 0)
            printf("%d MB downloaded...\n", i/1000000); // Track progress of download
    }

    // End timer
    end_time = clock();

    // Calculate elapsed time and internet speed
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    speed = (double)(size / pow(1024,2)) / elapsed_time; // Convert file size to MB and divide by elapsed time

    // Print results
    printf("Download complete.\n");
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    if(speed > 5.0) // Suspiciously high internet speed
        printf("Your internet speed is %.2f MB/s. This may not be accurate, beware!\n", speed);
    else
        printf("Your internet speed is %.2f MB/s. This is an average speed.\n", speed);

    return 0;
}