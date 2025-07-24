//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

enum Rating { G, PG, PG13, R, NC17 }; // create enum for rating values

// function to output the correct rating string based on input rating value
void printRating(enum Rating rating) {
    switch(rating) {
        case G:
            printf("G (General Audiences)\n");
            break;
        case PG:
            printf("PG (Parental Guidance Suggested)\n");
            break;
        case PG13:
            printf("PG-13 (Parents Strongly Cautioned)\n");
            break;
        case R:
            printf("R (Restricted)\n");
            break;
        case NC17:
            printf("NC-17 (No One 17 and Under Admitted)\n");
            break;
        default:
            printf("Invalid rating");
            break;
    }
}

int main() {
    enum Rating rating;
    int i;

    // iterate through each rating value and print out the corresponding string
    for(i = 0; i <= 4; i++) {
        rating = i;
        printf("Movie rating value: %d\n", i);
        printRating(rating);
    }

    return 0;
}