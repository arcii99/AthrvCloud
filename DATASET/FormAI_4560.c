//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize variables
    int download_speed, upload_speed, latency;
    float test_duration;
    char again;
    
    printf("Welcome to the C Internet Speed Test Application\n\n");
    
    //loop to allow user to perform multiple tests if desired
    do {
        //simulate test with random values
        srand(time(NULL)); //seed random number generator
        download_speed = rand() % 1000 + 1; //generate random download speed between 1 and 1000 Mbps
        upload_speed = rand() % 1000 + 1; //generate random upload speed between 1 and 1000 Mbps
        latency = rand() % 100 + 1; //generate random latency between 1 and 100 ms
        test_duration = (float)(rand() % 500000 + 100000) / 1000000; //generate random test duration between 0.1 and 0.6 seconds
        
        //output test results
        printf("Download speed: %d Mbps\n", download_speed);
        printf("Upload speed: %d Mbps\n", upload_speed);
        printf("Latency: %d ms\n", latency);
        printf("Test duration: %.2f seconds\n\n", test_duration);
        
        //prompt user to perform another test if desired
        printf("Would you like to perform another test? (Y/N): ");
        scanf(" %c", &again);
        
    } while (again == 'Y' || again == 'y');
    
    printf("Thank you for using the C Internet Speed Test Application.");
    
    return 0;
}