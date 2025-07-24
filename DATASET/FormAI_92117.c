//FormAI DATASET v1.0 Category: System boot optimizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    int boot_time = 45;
    int optimize_time = 10;
    
    printf("Welcome to the C System Boot Optimizer!\n");
    printf("This program will help optimize your system boot time.\n");
    printf("Starting optimization in %d seconds...\n", boot_time);
    
    sleep(boot_time);
    
    printf("Starting optimization...\n");
    
    int num_apps = 5;
    char app_names[5][20] = {"Chrome", "Spotify", "Discord", "Steam", "VS Code"};
    int app_times[5] = {5, 3, 2, 7, 4};
    int total_time = 0;
    
    for (int i=0; i<num_apps; i++) {
        printf("Optimizing %s...\n", app_names[i]);
        sleep(app_times[i]);
        total_time += app_times[i];
    }
    
    printf("Optimization complete!\n");
    printf("Total optimization time: %d seconds\n", total_time + optimize_time);
    
    return 0;
}