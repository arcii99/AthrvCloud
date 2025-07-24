//FormAI DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1-10: ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) {
        printf("Invalid rating. Please provide a rating between 1-10.\n");
    } else {
        switch(rating) {
            case 1:
            case 2:
                printf("The movie was terrible!\n");
                break;
            case 3:
            case 4:
                printf("The movie was bad.\n");
                break;
            case 5:
                printf("The movie was just average.\n");
                break;
            case 6:
            case 7:
                printf("The movie was good.\n");
                break;
            case 8:
            case 9:
                printf("The movie was great!\n");
                break;
            case 10:
                printf("The movie was a masterpiece!\n");
                break;
            default:
                printf("Invalid rating. Please provide a rating between 1-10.\n");
        }
    }

    return 0;
}