//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Happy Movie Rating System!\n");
    printf("Please rate the movie you just watched on a scale of 1-10: ");
    scanf("%d", &rating);

    if(rating >= 8) {
        printf("\nWow! You really enjoyed the movie!\n");
        printf("We give it a 5-star rating!\n");
    } else if(rating >= 6) {
        printf("\nYou liked the movie!\n");
        printf("We give it a 4-star rating!\n");
    } else if(rating >= 4) {
        printf("\nIt seems that you didn't enjoy the movie that much.\n");
        printf("We give it a 3-star rating!\n");
    } else if(rating >= 2) {
        printf("\nYou really didn't like the movie, did you?\n");
        printf("We give it a 2-star rating!\n");
    } else {
        printf("\nSorry to hear that you didn't enjoy the movie.\n");
        printf("We give it a 1-star rating.\n");
    }

    return 0;
}