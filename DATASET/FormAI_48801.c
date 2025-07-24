//FormAI DATASET v1.0 Category: System boot optimizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void delay(int seconds) {
    time_t start_time, curr_time;
    start_time = time(NULL);
    curr_time = start_time;
    while((curr_time - start_time) < seconds) {
        curr_time = time(NULL);
    }
}

void print_loading_bar(int percentage) {
    int i;
    printf("|");
    for(i=1; i<=50; i++) {
        if(i<=percentage/2) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("| %d%%\n", percentage);
}

int main() {
    int boot_time = 30;
    int startup_percentage = 0;
    printf("Welcome to System Boot Optimizer\n");
    printf("Optimizing startup programs...\n");
    while(startup_percentage < 100) {
        delay(boot_time/100);
        startup_percentage += 10;
        print_loading_bar(startup_percentage);
    }
    printf("Startup programs optimized successfully!\n");
    printf("Optimizing system processes...\n");
    int optimize_percentage = 0;
    int optimize_time = 60;
    while(optimize_percentage < 100) {
        delay(optimize_time/100);
        optimize_percentage += 5;
        print_loading_bar(optimize_percentage);
    }
    printf("System processes optimized successfully!\n");
    printf("Your system is optimized and ready to use.\n");
    return 0;
}