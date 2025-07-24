//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n\n");
    printf("Please rate the movie you just watched on a scale of 1-10: ");
    scanf("%d", &rating);

    if(rating >= 1 && rating <= 3) {
        printf("\nWe're sorry to hear that you didn't enjoy the movie.\n");
    }
    else if(rating >= 4 && rating <= 7) {
        printf("\nWe're glad to hear that you found the movie enjoyable.\n");
    }
    else if(rating >= 8 && rating <= 10) {
        printf("\nWow! We're thrilled to hear that you absolutely loved the movie.\n");
    }
    else {
        printf("\nOops, it seems like you entered an invalid rating.\n");
    }
    return 0;
}