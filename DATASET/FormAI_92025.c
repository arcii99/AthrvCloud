//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rating;
    srand(time(NULL));
    rating = rand() % 10 + 1;
    printf("Welcome to the Post-Apocalyptic Movie Rating System!\n");
    printf("Please enter the rating for the movie you just watched (1-10): ");
    scanf("%d", &rating);
    if (rating < 1 || rating > 10) {
        printf("Invalid rating entered.\n");
        return 1;
    } else if (rating < 4) {
        printf("Sorry, this movie was a disaster. Stay away at all costs.\n");
    } else if (rating < 7) {
        printf("This movie was okay, but there are definitely better options out there.\n");
    } else if (rating < 9) {
        printf("This movie was pretty good. You should watch it if you have time.\n");
    } else {
        printf("This movie was incredible! A must-see for any post-apocalyptic movie fan.\n");
    }
    return 0;
}