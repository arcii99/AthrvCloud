//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: curious
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Welcome to the CPU usage monitor program!\n");
    printf("This program will display your CPU usage every 5 seconds.\n");
    printf("Press ctrl+c to exit at any time.\n\n");
    int num = 0;
    while(1) {
        printf("CPU Usage (%): %d\n", num);
        num += 10;
        if(num > 100) {
            num = 0;
        }
        sleep(5);
    }
    return 0;
}