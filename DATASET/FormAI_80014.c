//FormAI DATASET v1.0 Category: System boot optimizer ; Style: multivariable
#include <stdio.h>

int boot_optimizer(int boot_time, int num_programs, int num_services){

    // Define variables
    int total_boot_time = boot_time;
    int program_time;
    int service_time;
    int i, j;

    // Calculate total program time
    for (i=0; i<num_programs; i++) {
        program_time = i * 5; // Assume each program takes 5 seconds to load
        total_boot_time += program_time;
    }

    // Calculate total service time
    for (j=0; j<num_services; j++) {
        service_time = j * 2; // Assume each service takes 2 seconds to load
        total_boot_time += service_time;
    }

    // Return optimized boot time
    return total_boot_time;
}

int main() {

    // Define variables
    int boot_time = 10; // Assume computer takes 10 seconds to boot up
    int num_programs = 5;
    int num_services = 3;

    // Optimize boot time
    int optimized_boot_time = boot_optimizer(boot_time, num_programs, num_services);

    // Output optimized boot time
    printf("Your computer's optimized boot time is %d seconds.", optimized_boot_time);

    return 0;
}