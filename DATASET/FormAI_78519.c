//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include<stdio.h>

int main(){
    int rating;
    printf("Welcome to the Post-Apocalyptic C Movie Rating System\n");
    printf("Please rate the movie out of 10\n");
    scanf("%d", &rating);

    if(rating > 10 || rating < 0) { // Check for invalid input
        printf("Invalid input!\n");
        return 0;
    }

    printf("The movie has been rated %d out of 10\n", rating);
    printf("Do you want to give a short review of the movie?\n");
    char review[1000];
    scanf("%s", review);

    if(strcmp(review, "") == 0) { // No review given
        printf("No review given. Thank you for using our rating system.\n");
        return 0;
    }

    // Print the review in an apocalyptic style
    printf("The world as we knew it is gone. We have no future, no hope. But amidst all this chaos, a movie has emerged - one that gives us a glimmer of humanity, a ray of light in a world of darkness.\n");
    printf("The movie has been rated %d out of 10, but that is not enough to do justice to its brilliance.\n", rating);
    printf("Here's what one survivor had to say about it:\n");
    printf("%s\n", review);
    printf("We may never know what it feels like to live in a world without destruction, but this movie takes us one step closer to that reality. Thank you for sharing your thoughts with us. Keep surviving!\n");

    return 0;
}