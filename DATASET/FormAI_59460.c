//FormAI DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main() {
    int rating;
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the movie out of 10: ");
    scanf("%d", &rating);

    if(rating >= 8 && rating <= 10) {
        printf("Excellent! This movie is a must-watch.\n");
    }
    else if(rating >= 6 && rating < 8) {
        printf("Good! This movie is worth watching.\n");
    }
    else if(rating >= 4 && rating < 6) {
        printf("Average. You may or may not enjoy this movie.\n");
    }
    else if(rating >= 2 && rating < 4) {
        printf("Bad. This movie is not worth your time.\n");
    }
    else if(rating >= 0 && rating < 2) {
        printf("Terrible. Avoid this movie at all costs.\n");
    }
    else {
        printf("Invalid rating. Please choose a rating between 0 and 10.\n");
    }

    return 0;
}