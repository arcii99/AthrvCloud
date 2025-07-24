//FormAI DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option;
    do {
        printf("Select an option:\n");
        printf("1. Display system date and time\n");
        printf("2. Display CPU information\n");
        printf("3. Display RAM usage\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                system("date");
                break;
            case 2:
                system("lscpu");
                break;
            case 3:
                system("free -m");
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        } 

        // Clear input buffer
        while ((getchar()) != '\n');

        printf("\n");

    } while (option != 4);

    return 0;
}