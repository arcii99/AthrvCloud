//FormAI DATASET v1.0 Category: System administration ; Style: scientific
#include<stdio.h>

// Declare a structure to store system information
struct system_info {
   char name[20];
   int num_cores;
   float ram_size;
   float disk_size;
};

int main() {
    // Create an instance of the system_info structure
    struct system_info my_sys;

    // Get system name
    printf("Enter system name: ");
    scanf("%s", my_sys.name);

    // Get number of cores
    printf("Enter number of CPU cores: ");
    scanf("%d", &my_sys.num_cores);

    // Get RAM size in GB
    printf("Enter RAM size (in GB): ");
    scanf("%f", &my_sys.ram_size);

    // Get disk size in GB
    printf("Enter disk size (in GB): ");
    scanf("%f", &my_sys.disk_size);

    // Print system information
    printf("\nSystem Information:\n");
    printf("Name: %s\n", my_sys.name);
    printf("Number of CPU cores: %d\n", my_sys.num_cores);
    printf("RAM size (in GB): %f\n", my_sys.ram_size);
    printf("Disk size (in GB): %f\n", my_sys.disk_size);

    return 0;
}