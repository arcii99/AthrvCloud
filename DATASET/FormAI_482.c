//FormAI DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>

int main() {
    int rating;
    printf("\nWelcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie you have just watched with a number from 1 to 10:\n");
    scanf("%d", &rating);

    if(rating < 1 || rating > 10) {
        printf("Invalid rating.\n");
        return 0;
    }

    printf("You rated the movie with a %d out of 10.\n", rating);

    printf("The verdict:\n");
    switch(rating) {
        case 1:
            printf("What a waste of time.\n");
            break;
        case 2:
            printf("Boring.\n");
            break;
        case 3:
            printf("Better luck next time.\n");
            break;
        case 4:
            printf("Not terrible, but not great either.\n");
            break;
        case 5:
            printf("Average.\n");
            break;
        case 6:
            printf("Good.\n");
            break;
        case 7:
            printf("Very good.\n");
            break;
        case 8:
            printf("Excellent.\n");
            break;
        case 9:
            printf("Almost perfect.\n");
            break;
        default:
            printf("Perfect! A must-watch!\n");
            break;
    }

    printf("\nWe hope you enjoyed our unique C Movie Rating System. Have a great day!");
    return 0;
}