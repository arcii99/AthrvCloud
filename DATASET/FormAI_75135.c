//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    
    printf("Welcome to C Drone Remote Control!\n");
    
    while(1) {
        printf("Please choose an option:\n");
        printf("1. Take off\n");
        printf("2. Land\n");
        printf("3. Hover\n");
        printf("4. Move forward\n");
        printf("5. Move backward\n");
        printf("6. Move left\n");
        printf("7. Move right\n");
        printf("8. Turn left\n");
        printf("9. Turn right\n");
        printf("10. Exit\n");
        
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Drone takes off.\n");
                break;
            case 2:
                printf("Drone lands.\n");
                break;
            case 3:
                printf("Drone hovers.\n");
                break;
            case 4:
                printf("Drone moves forward.\n");
                break;
            case 5:
                printf("Drone moves backward.\n");
                break;
            case 6:
                printf("Drone moves left.\n");
                break;
            case 7:
                printf("Drone moves right.\n");
                break;
            case 8:
                printf("Drone turns left.\n");
                break;
            case 9:
                printf("Drone turns right.\n");
                break;
            case 10:
                printf("Exiting C Drone Remote Control.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}