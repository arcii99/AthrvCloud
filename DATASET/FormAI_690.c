//FormAI DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to our C Movie Rating System\n");
    printf("Please rate this romantic movie with a number from 1 to 10: ");

    scanf("%d", &rating);

    if (rating <= 5) { 
        printf("We're sorry that you didn't enjoy the movie. Perhaps this one just wasn't for you.\n");
    } else if (rating > 5 && rating <= 8) {
        printf("Thank you for your feedback. We're glad that you enjoyed the movie.\n");
    } else if (rating > 8 && rating <= 10) {
        printf("Wow, a perfect 10! We're thrilled that you loved the movie. Thank you for your rating!\n");
    } else { 
        printf("Please rate this romantic movie with a number from 1 to 10. Thank you!\n"); 
    }
    return 0;
}