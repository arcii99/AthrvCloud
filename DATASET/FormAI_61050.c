//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    printf("1. Play as Romeo\n");
    printf("2. Play as Juliet\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            // Run game as Romeo
            break;
        case 2:
            // Run game as Juliet
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}