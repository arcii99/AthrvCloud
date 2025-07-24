//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include<stdio.h>
#include<time.h>

void display_todays_date(){
   time_t t = time(NULL);
   struct tm *tm = localtime(&t);
   printf("Today's Date: %s", asctime(tm));
}

void display_fixed_date(char* input_date){
    struct tm tm = {0};
    strptime(input_date, "%m/%d/%Y", &tm);
    time_t t = mktime(&tm);
    printf("Fixed Date: %s", asctime(localtime(&t)));
}

int main(){
    int choice;
    char input_date[20];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Display today's date\n");
    printf("2. Travel to a specific date\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            display_todays_date();
            break;
        case 2:
            printf("Enter the date in mm/dd/yyyy format: ");
            scanf("%s", input_date);
            display_fixed_date(input_date);
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 0;
    }

    return 0;
}