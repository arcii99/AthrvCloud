//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>

int main() {

    //Initialize required variables
    int year = 2021, month, day, choice;
    char event[100];

    printf("========================================\n");
    printf("            DIGITAL DIARY               \n");
    printf("========================================\n\n");

    //Loop through the diary
    do {
        printf("Enter the month and day (MM DD): ");
        scanf("%d %d", &month, &day);

        //Check if the date is valid
        if(month<=0 || month>12 || day<=0 || day>31) {
            printf("Invalid Date! Please try again.\n");
        } else {
            printf("Enter the event: ");
            scanf("%s", event);
            printf("Event added to diary successfully!\n");
        }

        //Ask if the user wants to continue adding events
        printf("\nDo you want to add an event for another day? (1 - yes, 0 - no): ");
        scanf("%d", &choice);

    } while(choice!=0);

    printf("\n\nEnd of Diary!\n");

    return 0;
}