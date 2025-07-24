//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAM 1024     // Maximum RAM in KB
#define BINARY_BASE 2    // Base for converting KB to binary
#define SECONDS_DELAY 2  // Time delay between each check in seconds

int main(void) {
    srand(time(NULL));  // Seed for random numbers
    
    printf("Welcome to the surreal RAM usage monitor!\n");
    printf("The program will generate random RAM usage levels and print them out every %d seconds\n\n", SECONDS_DELAY);
    
    while(1) {
        int ram_used = rand() % MAX_RAM;  // Randomly generate RAM usage
        
        if(ram_used == MAX_RAM) {
            printf("The RAM is completely full!\n");
        } else if(ram_used > MAX_RAM / 2) {
            printf("The RAM is more than half full, but not completely!\n");
        } else if(ram_used > MAX_RAM / 4) {
            printf("The RAM is more than a quarter full, but less than half full!\n");
        } else {
            printf("The RAM is less than a quarter full!\n");
        }
        
        int binary_ram_used = ram_used / BINARY_BASE;  // Convert RAM usage to binary
        printf("RAM usage in binary: ");
        while(binary_ram_used > 0) {
            if(binary_ram_used % 2 == 0) {
                printf("0");
            } else {
                printf("1");
            }
            binary_ram_used /= 2;
        }
        printf("\n\n");
        
        sleep(SECONDS_DELAY);  // Wait for some time before checking again
    }
    
    return 0;
}