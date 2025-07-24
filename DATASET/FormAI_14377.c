//FormAI DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to our C Movie Rating System!\n");
    printf("Please rate the movie from 1 to 5: ");
    scanf("%d", &rating);

    if(rating < 1 || rating > 5) {
        printf("Invalid rating. Please try again with a rating from 1 to 5.\n");
        return 0;
    }

    printf("You have rated the movie ");

    switch(rating) {
        case 1:
            printf("Terrible.\n");
            break;
        case 2:
            printf("Poor.\n");
            break;
        case 3:
            printf("Average.\n");
            break;
        case 4:
            printf("Good.\n");
            break;
        case 5:
            printf("Excellent!\n");
            break;
    }

    printf("Thank you for using our C Movie Rating System.\n");

    return 0;
}