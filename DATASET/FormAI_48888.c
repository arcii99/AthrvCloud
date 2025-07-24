//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TIME_LIMIT 5 // 5 seconds time limit for download

int main() {
    char cmd[BUFFER_SIZE], speed_string[BUFFER_SIZE];
    printf("Running internet speed test, please wait...\n");
    sprintf(cmd, "wget --output-document=/dev/null http://speedtest.wdc01.softlayer.com/downloads/test500.zip 2>&1 | awk '/%.2f/{print $2$3}'", (float)TIME_LIMIT);
    // Runs wget command with 5 second timeout and pipes output to awk to extract download speed
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }
    fgets(speed_string, sizeof(speed_string), fp);
    pclose(fp);
    float speed = atof(speed_string);
    printf("Download speed: %.2f Mbps\n", speed);
    return 0;
}