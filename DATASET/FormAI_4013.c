//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 10:\n");

    scanf("%d", &rating);

    if(rating >= 1 && rating <= 10) {
        printf("Thank you for rating the movie!\n");

        if(rating < 5) {
            printf("Sorry to hear that you did not enjoy the movie. We will make sure to improve for next time.\n");
        } else if(rating >= 5 && rating < 7) {
            printf("Glad to hear that you found the movie average. We hope to improve and provide a better experience next time.\n");
        } else if(rating >= 7 && rating < 9) {
            printf("Thank you for the positive rating! We are happy to hear you enjoyed the movie.\n");
        } else {
            printf("Wow! Thank you for the excellent rating! We are thrilled that you loved the movie.\n");
        }
    } else {
        printf("Invalid rating. Please rate the movie on a scale of 1 to 10.\n");
    }

    return 0;
}