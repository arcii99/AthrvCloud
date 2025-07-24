//FormAI DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the movie from 1 to 5: ");
    scanf("%d", &rating);
    
    if(rating < 1 || rating > 5) {
        printf("Invalid rating. Please rate the movie from 1 to 5.\n");
        return 0;
    }
    
    switch(rating) {
        case 1:
            printf("You gave the movie a rating of 1. We're sorry to hear that you did not enjoy the movie.\n");
            break;
        case 2:
            printf("You gave the movie a rating of 2. We're sorry to hear that you did not enjoy the movie.\n");
            break;
        case 3:
            printf("You gave the movie a rating of 3. We're glad to hear that you enjoyed the movie.\n");
            break;
        case 4:
            printf("You gave the movie a rating of 4. We're glad to hear that you enjoyed the movie.\n");
            break;
        case 5:
            printf("You gave the movie a rating of 5. We're thrilled to hear that you loved the movie!\n");
            break;
    }
    
    return 0;
}