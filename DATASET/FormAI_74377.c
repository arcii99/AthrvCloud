//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEST_SIZE 1024
#define TEST_COUNT 10
#define MS_PER_SEC 1000

int main(void) {
    int i, j;
    int total_time_ms = 0;
    double avg_speed_mbps, elapsed_time_sec;
    char cmd[256], results[1024], *token, *saveptr;
    clock_t start, end;
    FILE *pipe;
    
    // Run the speed test multiple times to get more accurate results
    for (i = 0; i < TEST_COUNT; i++) {
        printf("Running test %d of %d...\n", i + 1, TEST_COUNT);
        
        // Start the clock
        start = clock();
        
        // Run the speed test command and read the results into a string
        sprintf(cmd, "speedtest-cli --bytes --json");
        pipe = popen(cmd, "r");
        if (!pipe) {
            printf("Error executing speed test command.\n");
            return 1;
        }
        memset(results, 0, sizeof(results));
        while (fgets(results, sizeof(results), pipe) != NULL) {}
        pclose(pipe);
        
        // Parse the download speed from the results
        token = strtok_r(results, ",", &saveptr);
        while (token != NULL) {
            if (strstr(token, "\"download\":")) {
                sscanf(token, "\"download\": %lf", &avg_speed_mbps);
                break;
            }
            token = strtok_r(NULL, ",", &saveptr);
        }
        if (token == NULL) {
            printf("Error parsing speed test results.\n");
            return 1;
        }
        
        // End the clock and calculate the elapsed time
        end = clock();
        elapsed_time_sec = (double)(end - start) / CLOCKS_PER_SEC;
        total_time_ms += (int)(elapsed_time_sec * MS_PER_SEC);
        
        // Print the results
        printf("Download speed: %.2lf Mbps\n", avg_speed_mbps);
        printf("Elapsed time: %.2lf seconds\n", elapsed_time_sec);
    }
    
    // Print the average download speed and total test time
    printf("\nAverage download speed: %.2lf Mbps\n", avg_speed_mbps);
    printf("Total test time: %d ms\n", total_time_ms);
    
    return 0;
}