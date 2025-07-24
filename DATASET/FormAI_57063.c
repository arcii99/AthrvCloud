//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate a random rating for the movie
    srand(time(NULL));
    int rating = rand() % 11;
    
    printf("Welcome to the Sherlock Holmes Movie Rating System!\n");
    printf("Your movie rating is: %d\n", rating);
    
    // Determine the rating description
    char* ratingDescription;
    switch(rating) {
        case 0:
            ratingDescription = "This movie is not worth watching.";
            break;
        case 1:
            ratingDescription = "This movie is terrible.";
            break;
        case 2:
            ratingDescription = "This movie is bad.";
            break;
        case 3:
            ratingDescription = "This movie is below average.";
            break;
        case 4:
            ratingDescription = "This movie is average.";
            break;
        case 5:
            ratingDescription = "This movie is above average.";
            break;
        case 6:
            ratingDescription = "This movie is good.";
            break;
        case 7:
            ratingDescription = "This movie is very good!";
            break;
        case 8:
            ratingDescription = "This movie is excellent!";
            break;
        case 9:
            ratingDescription = "This movie is a must-see!";
            break;
        case 10:
            ratingDescription = "This movie is a masterpiece!";
            break;
        default:
            ratingDescription = "Invalid rating.";
    }
    
    // Output the rating description
    printf("%s\n", ratingDescription);
    
    return 0;
}