//FormAI DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
/* Ken Thompson Style Online Exam System */

#include<stdio.h>

// A function to display the menu
void displayMenu() {
    printf("====== Online Exam System ====== \n");
    printf("1. Take the Exam \n");
    printf("2. View Previous Results \n");
    printf("3. Exit \n");
}

int main() {
    int choice;
    char name[20];
    int marks;
    
    printf("Welcome to the Online Exam System! Please enter your name: ");
    scanf("%s", name);
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Welcome, %s! You have 60 minutes to complete the exam. Good luck! \n", name);
                // Code to take the exam
                printf("Enter your exam marks: ");
                scanf("%d", &marks);
                printf("Your exam marks are: %d \n", marks);
                break;
            case 2:
                // Code to view previous results
                printf("No Previous Results Found. \n");
                break;
            case 3:
                printf("Thank you for using the Online Exam System! \n");
                break;
            default:
                printf("Invalid Choice. Please try again. \n");
        }
    } while(choice != 3);
    
    return 0;
}