//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

// function to convert rating to stars
void convertToStars(int rating) {
    printf("Rated ");
    for(int i=0; i<rating; i++) {
        printf("* ");
    }
    printf("(%d/10)\n", rating);
}

int main() {
    char title[50];
    int rating;

    printf("Welcome to the C Movie Rating System!\n");

    // get movie title and rating
    printf("Enter a movie title: ");
    scanf("%[^\n]", title);

    printf("Enter a rating out of 10: ");
    scanf("%d", &rating);

    printf("\n");

    // print out movie details
    printf("Here are the details for \"%s\":\n", title);
    convertToStars(rating);

    printf("Thank you for using the C Movie Rating System!\n");

    return 0;
}