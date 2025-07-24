//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    printf("Welcome to C System Boot Optimizer!\n");
    printf("This program will optimize your system boot time.\n");
    
    int num_of_processes = 0;
    printf("Enter the number of processes to be optimized: ");
    scanf("%d", &num_of_processes);
    
    int process_time[num_of_processes];
    printf("Enter the time for each process in ms: ");
    for(int i = 0; i < num_of_processes; i++) {
        scanf("%d", &process_time[i]);
    }
    
    // Implementing bubble sort for sorting the processes in ascending order
    for(int i = 0; i < num_of_processes - 1; i++) {
        for(int j = 0; j < num_of_processes - i - 1; j++) {
            if(process_time[j] > process_time[j + 1]) {
                int temp = process_time[j];
                process_time[j] = process_time[j + 1];
                process_time[j + 1] = temp;
            }
        }
    }
    
    // Calculating and displaying the total optimized boot time
    int total_time = 0;
    for(int i = 0; i < num_of_processes; i++) {
        total_time += process_time[i];
    }
    printf("Optimized boot time: %d ms\n", total_time);
    
    return 0;
}