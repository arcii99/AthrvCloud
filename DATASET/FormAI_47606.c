//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed, upload_speed;
    float latency;
    
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please wait while we perform the test...\n\n");
    
    // Generate random values for download speed, upload speed, and latency
    srand(time(0));
    download_speed = rand() % 100 + 1;
    upload_speed = rand() % 100 + 1;
    latency = (float) (rand() % 200) / 10;
    
    // Output the test results
    printf("Download Speed: %d Mbps\n", download_speed);
    printf("Upload Speed: %d Mbps\n", upload_speed);
    printf("Latency: %.1f ms\n\n", latency);
    
    // Allow the user to configure the test by entering new values
    char response;
    printf("Do you want to configure the test? (Y/N): ");
    scanf(" %c", &response);
    
    if (response == 'Y')
    {
        printf("\nEnter new values for the download speed, upload speed, and latency.\n");
        printf("Download Speed (Mbps): ");
        scanf("%d", &download_speed);
        printf("Upload Speed (Mbps): ");
        scanf("%d", &upload_speed);
        printf("Latency (ms): ");
        scanf("%f", &latency);
        
        // Output the new values
        printf("\nNew Download Speed: %d Mbps\n", download_speed);
        printf("New Upload Speed: %d Mbps\n", upload_speed);
        printf("New Latency: %.1f ms\n\n", latency);
    }
    
    printf("Thank you for using the Internet Speed Test Application!");
    
    return 0;
}