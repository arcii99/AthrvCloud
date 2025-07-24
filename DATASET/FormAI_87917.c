//FormAI DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include<stdio.h>

int main(){
    int rating;
    printf("Welcome to the C Movie Rating System!\nPlease rate this movie out of 5: ");
    scanf("%d", &rating);

    if (rating >= 1 && rating <= 5) {
        printf("Thank you for rating this movie!\n");
        printf("Your rating: %d out of 5\n", rating);

        switch(rating){
            case 5:
                printf("Wow, you really loved this movie!\n");
                break;
            case 4:
                printf("Glad to hear you enjoyed this movie!\n");
                break;
            case 3:
                printf("Thanks for your review, we'll strive to improve!\n");
                break;
            case 2:
                printf("Sorry to hear you didn't enjoy this movie.\n");
                break;
            case 1:
                printf("Thanks for your feedback, we'll work to do better next time.\n");
                break;
            default:
                printf("Invalid rating.\n");
                break;
        }
    } else {
        printf("Invalid rating input. Please rate the movie out of 5.\n");
    }

    return 0;
}