//FormAI DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to C Movie Rating System\n");
    printf("Enter a rating between 1-10 for the movie: ");
    scanf("%d", &rating);

    if(rating >= 1 && rating <= 10) {
        printf("Thank you for your rating of %d\n", rating);
        printf("According to our system, this is a ");
        switch(rating) {
            case 1:
            case 2:
            case 3:
                printf("poor");
                break;
            case 4:
            case 5:
                printf("below average");
                break;
            case 6:
            case 7:
                printf("average");
                break;
            case 8:
            case 9:
                printf("good");
                break;
            case 10:
                printf("great");
                break;
        }
        printf(" rating.\n");
    } else {
        printf("Invalid rating. Please enter a rating between 1-10.\n");
    }

    return 0;
}