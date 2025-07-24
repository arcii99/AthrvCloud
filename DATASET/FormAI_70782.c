//FormAI DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[50];
    printf("Hello, what is your name?");
    scanf("%s", name);
    printf("Welcome to your digital diary, %s!\n", name);
    
    int choice;
    do {
        printf("\nMenu\n");
        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Code to add entry
                break;
            case 2:
                // Code to view entry
                break;
            case 3:
                printf("Thank you for using your digital diary, %s.\n", name);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);
    
    return 0;
}