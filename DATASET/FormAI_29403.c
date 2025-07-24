//FormAI DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void printRating(int rating) {
    switch(rating) {
        case 0:
            printf("This movie has not yet been rated.\n");
            break;
        case 1:
            printf("This movie is terrible.\n");
            break;
        case 2:
            printf("This movie is bad.\n");
            break;
        case 3:
            printf("This movie is average.\n");
            break;
        case 4:
            printf("This movie is good.\n");
            break;
        case 5:
            printf("This movie is excellent!\n");
            break;
        default:
            printf("Invalid rating.\n");
    }
}

int main() {
    int rating = 0;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale from 1 to 5:\n");
    scanf("%d", &rating);
  
    if(rating < 1 || rating > 5) {
        printf("Invalid rating.\n");
        return -1;
    }
  
    printf("You have rated the movie as: ");
    printRating(rating);

    return 0;
}