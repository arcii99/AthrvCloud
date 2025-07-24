//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>

int main() {
    int rating;
    char name[50];
    
    // Greeting the user
    printf("Welcome to the Unique C Movie Rating System!\n");
    
    // Getting user input for movie name and rating
    printf("What is the name of the movie you want to rate? ");
    scanf("%s", name);
    
    printf("What rating out of 10 would you give %s? ", name);
    scanf("%d", &rating);
    
    // Checking if rating is within range and giving feedback accordingly
    if (rating >= 0 && rating <= 10) {
        printf("\nThank you for rating %s!\n", name);
        if (rating < 5) {
            printf("We're sorry you didn't enjoy %s. We'll try to suggest a better movie next time.\n", name);
        } else if (rating < 8) {
            printf("We're glad you enjoyed %s, but we know you can find even better movies out there!\n", name);
        } else {
            printf("Wow! It seems like you really loved %s! We'll make sure to recommend similar movies.\n", name);
        }
    } else {
        printf("\nWe're sorry, %d is not a valid rating. Please try again with a number between 0 and 10.\n", rating);
    }
    
    return 0;
}