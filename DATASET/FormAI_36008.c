//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_URL_LENGTH 256 // Maximum URL length allowed
#define REFRESH_RATE 30 // Refresh rate in seconds

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please specify at least one URL to monitor.\nUsage: uptime_monitor url1 [url2 ...]\n");
        return 1;
    }

    char cmd[MAX_URL_LENGTH + 32]; // Command buffer
    char url[MAX_URL_LENGTH]; // URL buffer
    char response[MAX_URL_LENGTH]; // Response buffer
    int status; // HTTP response code
    int counter = 0; // Counter for refresh rate
    int i; // Counter for URLs

    while (1) {
        if (++counter > REFRESH_RATE) { // If refresh rate has been reached
            counter = 0; // Reset counter
            system("clear"); // Clear the screen
            printf("Website Uptime Monitor\n\n");
            for (i = 1; i < argc; i++) {
                sprintf(cmd, "curl -s -I %s | grep HTTP/ | cut -d' ' -f2", argv[i]); // Construct curl command
                FILE *pipe = popen(cmd, "r"); // Open pipe for curl command
                if (!pipe) {
                    printf("%s - Failed to execute curl command.\n", argv[i]);
                    continue;
                }
                fgets(response, MAX_URL_LENGTH, pipe); // Read HTTP response code from pipe
                status = atoi(response); // Convert response to integer
                if (status >= 200 && status < 300) {
                    printf("%s - \x1b[32mOnline\x1b[0m - HTTP %d\n", argv[i], status); // Print green if online
                } else {
                    printf("%s - \x1b[31mOffline\x1b[0m - HTTP %d\n", argv[i], status); // Print red if offline
                }
                pclose(pipe); // Close pipe
            }
            printf("\nPress Ctrl+C to exit.\n");
        }
        sleep(1); // Wait for 1 second
    }

    return 0;
}