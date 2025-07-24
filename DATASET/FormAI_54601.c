//FormAI DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>

int main() {
    int rating;
    
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie you just watched on a scale of 1-10: ");
    scanf("%d", &rating);
    
    switch (rating) {
        case 1:
        case 2:
            printf("\nWe're sorry you didn't enjoy the movie.\n");
            break;
        case 3:
        case 4:
            printf("\nThanks for your feedback! We'll try to do better next time.\n");
            break;
        case 5:
            printf("\nGlad to hear you thought the movie was average.\n");
            break;
        case 6:
        case 7:
            printf("\nThank you for your positive rating! We're glad you enjoyed the movie.\n");
            break;
        case 8:
        case 9:
            printf("\nWow, a great rating! Thank you so much for watching and enjoying our movie.\n");
            break;
        case 10:
            printf("\nPerfection! We're honored you think our movie is deserving of a 10/10 rating. Thank you!\n");
            break;
        default:
            printf("\nInvalid rating entered. Please rate the movie on a scale of 1-10.\n");
            break;
    }
    
    return 0;
}