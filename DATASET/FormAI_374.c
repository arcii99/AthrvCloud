//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seeding random number generator

    int total_ram = rand() % 1000 + 1000; // ram size between 1000 to 2000 KB
    int min_ram = rand() % 50 + 50;  // minimum ram usage between 50 to 100 KB
    int max_ram = total_ram - min_ram; // maximum ram usage is remaining after minimum usage
    
    int current_ram = min_ram; // starting with minimum usage

    printf("Welcome to the Medieval RAM Usage Monitor!\n\n");
    printf("Total RAM size: %d KB\n", total_ram);
    printf("Minimum RAM usage: %d KB\n", min_ram);
    printf("Maximum RAM usage: %d KB\n\n", max_ram);
    
    while (1) { // running indefinitely
        printf("Current RAM usage: %d KB\n", current_ram);
        printf("Enter a new RAM usage value (Between %d and %d KB): ", min_ram, max_ram);
        int new_ram;
        scanf("%d", &new_ram);
        
        if (new_ram < min_ram || new_ram > max_ram) { // new ram value outside permitted range
            printf("Invalid RAM usage value. Please enter a value between %d and %d KB.\n\n", min_ram, max_ram);
            continue; // start loop again
        }
        
        current_ram = new_ram; // updating current ram usage value
        
        if (current_ram >= max_ram) { // maximum ram usage reached
            printf("\n\nRAM usage has reached maximum capacity! System may crash!\n\n");
            break; // end program
        }
    }
    
    printf("Thank you for using the Medieval RAM Usage Monitor!\n");

    return 0;
}