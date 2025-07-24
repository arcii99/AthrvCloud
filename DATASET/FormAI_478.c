//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

int main() {
    
    // Greet the user with a cheerful message
    printf("Welcome to the C Movie Rating System!\n");
    printf("We rate movies on a scale of 1-10, with 10 being the best!\n");
    
    // Get user input for a movie title
    char title[100];
    printf("Please enter the title of the movie you want to rate: ");
    scanf("%[^\n]s", title);
    
    // Get user input for the movie rating
    int rating;
    printf("Great! Now, please enter your rating for %s (1-10): ", title);
    scanf("%d", &rating);
    
    // Check if the rating is within the valid range
    if (rating < 1 || rating > 10) {
        printf("Oops! You entered an invalid rating. Please enter a rating between 1 and 10.\n");
        printf("Let's try again.\n");
        
        // Get the user to enter a valid rating
        printf("Please enter your rating for %s (1-10): ", title);
        scanf("%d", &rating);
    }
    
    // Display the final rating to the user
    printf("Thank you for rating %s! Your rating of %d has been recorded.\n", title, rating);
    
    // Cheerful goodbye message
    printf("We hope you enjoyed using the C Movie Rating System. Goodbye!\n");
    
    return 0;
}