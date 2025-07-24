//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>

int main() {
    float rating;
    printf("Enter the movie rating between 1-10: ");
    scanf("%f", &rating);
    if(rating < 0 || rating > 10) {
        printf("Invalid rating\n");
    }
    else if(rating >= 9) {
        printf("Outstanding movie\n");
    }
    else if(rating >= 7) {
        printf("Good movie\n");
    }
    else if(rating >= 5) {
        printf("Average movie\n");
    }
    else {
        printf("Bad movie\n");
    }
    return 0;
}