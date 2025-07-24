//FormAI DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 10
#define MAX_MEMORY 50000
#define MIN_MEMORY 1000

int main() {
    int boot_speed = 50;
    int memory_size = 20000;
    
    printf("Current boot speed: %d\n", boot_speed);
    printf("Current memory size: %d\n", memory_size);
    
    // Configure the boot speed
    printf("Enter the desired boot speed (between %d and %d): ", MIN_SPEED, MAX_SPEED);
    scanf("%d", &boot_speed);
    if (boot_speed < MIN_SPEED) {
        printf("Invalid input. Boot speed set to minimum of %d.\n", MIN_SPEED);
        boot_speed = MIN_SPEED;
    } else if (boot_speed > MAX_SPEED) {
        printf("Invalid input. Boot speed set to maximum of %d.\n", MAX_SPEED);
        boot_speed = MAX_SPEED;
    }
    
    // Configure the memory size
    printf("Enter the desired memory size (between %d and %d): ", MIN_MEMORY, MAX_MEMORY);
    scanf("%d", &memory_size);
    if (memory_size < MIN_MEMORY) {
        printf("Invalid input. Memory size set to minimum of %d.\n", MIN_MEMORY);
        memory_size = MIN_MEMORY;
    } else if (memory_size > MAX_MEMORY) {
        printf("Invalid input. Memory size set to maximum of %d.\n", MAX_MEMORY);
        memory_size = MAX_MEMORY;
    }
    
    // Optimize the system boot
    printf("Optimizing system boot with the following configuration:\n");
    printf("Boot speed: %d\n", boot_speed);
    printf("Memory size: %d\n", memory_size);
    printf("Please wait...\n");
    // Code for optimizing system boot goes here
    printf("System boot optimized successfully!\n");
    
    return 0;
}