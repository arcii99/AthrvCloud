//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// function to test internet speed
void test_speed() {
    double start_time, end_time, speed;
    int file_size = 100000000; // 100 MB
    char url[50] = "https://speed.hetzner.de/100MB.bin";
    char command[100] = "curl -s -o /dev/null ";
    strcat(command, url);
    strcat(command, " 2>&1");

    printf("Testing internet speed...\n");
    start_time = clock();
    system(command);
    end_time = clock();
    speed = (double) file_size / (end_time - start_time) * CLOCKS_PER_SEC / 1048576; // convert to Mbps
    printf("Your internet speed is: %.2f Mbps\n", speed);
}

// driver function
int main() {
    test_speed();
    return 0;
}