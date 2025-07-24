//FormAI DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the latest movie you watched on a scale of 1 to 5:\n");
    scanf("%d", &rating);
    switch(rating) {
        case 1:
            printf("Sorry you did not enjoy the movie. We will do better next time!\n");
            break;
        case 2:
            printf("Thank you for your feedback. We will work on improving the movie!\n");
            break;
        case 3:
            printf("Glad to hear you found the movie average. Any suggestions to make it better?\n");
            break;
        case 4:
            printf("Thank you for your positive feedback. We are happy you enjoyed the movie!\n");
            break;
        case 5:
            printf("Wow, a perfect score! We are thrilled you loved the movie. Thank you!\n");
            break;
        default:
            printf("Invalid rating. Please try again with a rating between 1 to 5.\n");
    }
    return 0;
}