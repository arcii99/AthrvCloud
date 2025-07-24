//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>

int main() {
    int rating;
    char movieTitle[50];
    
    printf("Enter the title of the movie: ");
    scanf("%s", movieTitle);
    
    printf("Enter your rating for %s (0-10): ", movieTitle);
    scanf("%d", &rating);
    
    if (rating < 0 || rating > 10) {
        printf("Error: Rating must be between 0 and 10.\n");
        return 1;
    }
    
    printf("Thank you for rating %s a %d out of 10!\n", movieTitle, rating);
    
    if (rating < 5) {
        printf("Sorry to hear that you didn't enjoy the movie.\n");
    } else if (rating < 8) {
        printf("Glad to hear that you enjoyed the movie!\n");
    } else {
        printf("Wow! That's an excellent rating. You must have loved the movie!\n");
    }
    
    return 0;
}