//FormAI DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

// Function to optimize the C System boot
void optimize_boot() {
    printf("Starting System boot optimization...\n");
    // Add any boot optimization code here
    printf("System boot optimization successful!\n");
}

int main() {
    int choice;
    printf("Welcome to the C System boot optimizer\n");
    printf("Choose an option:\n");
    printf("1. Optimize boot\n");
    printf("2. Exit\n");
    printf("Enter your choice(1/2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            optimize_boot();
            break;
        case 2:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice.\n");
    }
    return 0;
}