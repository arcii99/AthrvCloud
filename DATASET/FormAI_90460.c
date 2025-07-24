//FormAI DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include <stdio.h>

int main() {
    int rating = 0;
    char movieTitle[50];
    
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter the title of the movie: ");
    fgets(movieTitle, 50, stdin);
    
    printf("Please enter your rating for %s: ", movieTitle);
    scanf("%d", &rating);
    
    if (rating < 0 || rating > 10) {
        printf("Error: Invalid rating.\n");
    } else if (rating == 0) {
        printf("You did not rate %s.\n", movieTitle);
    } else if (rating >= 1 && rating <= 3) {
        printf("You rated %s as a bad movie.\n", movieTitle);
    } else if (rating >= 4 && rating <= 6) {
        printf("You rated %s as an average movie.\n", movieTitle);
    } else if (rating >= 7 && rating <= 9) {
        printf("You rated %s as a good movie.\n", movieTitle);
    } else {
        printf("You rated %s as an excellent movie!\n", movieTitle);
    }
    
    return 0;
}