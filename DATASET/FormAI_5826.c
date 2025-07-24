//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int push_ups = 0;
    int sit_ups = 0;
    int lunges = 0;
    int squats = 0;

    printf("Welcome to the Surrealist Fitness Tracker!\n");

    while(1){
        printf("\nWhat exercise did you do today?\n");
        printf("1. Push-ups\n");
        printf("2. Sit-ups\n");
        printf("3. Lunges\n");
        printf("4. Squats\n");
        printf("5. Surreal Exercise\n");
        printf("6. Exit Program\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("How many push-ups did you do?\n");
                scanf("%d", &push_ups);
                printf("You did %d push-ups today!\n", push_ups);
                break;
            case 2:
                printf("How many sit-ups did you do?\n");
                scanf("%d", &sit_ups);
                printf("You did %d sit-ups today!\n", sit_ups);
                break;
            case 3:
                printf("How many lunges did you do?\n");
                scanf("%d", &lunges);
                printf("You did %d lunges today!\n", lunges);
                break;
            case 4:
                printf("How many squats did you do?\n");
                scanf("%d", &squats);
                printf("You did %d squats today!\n", squats);
                break;
            case 5:
                printf("You have chosen the Surreal Exercise!\n");
                printf("Please enter the number of surreal reps you did.\n");

                int surreal_reps;
                scanf("%d", &surreal_reps);

                printf("Wow! %d surreal reps! You are a true surrealist.\n", surreal_reps);
                break;
            case 6:
                printf("Thanks for using the Surrealist Fitness Tracker. Have a surreal day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a number from 1-6.\n");
        }
    }
    return 0;
}