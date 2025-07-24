//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    // The movie rating system is a mystery to most people, but not to me, Sherlock Holmes. Let's solve this case!
    
    int rating;
    printf("Greetings! Welcome to the C Movie Rating System, where we determine the rating of a movie based on its reviews.\n");
    printf("Please enter the number of positive reviews for the movie: ");
    scanf("%d", &rating);
    
    if(rating >= 0 && rating <= 5) {
        printf("It seems that this movie is not worth watching. I would give it a rating of 1 out of 10, with a warning to approach with caution.\n");
    } else if(rating > 5 && rating <= 10) {
        printf("This movie has received mixed reviews, but overall has some redeeming qualities. I would give it a rating of 4 out of 10, with the advice to watch at your own risk.\n");
    } else if(rating > 10 && rating <= 15) {
        printf("It appears that this movie has received good reviews and is worth watching. I would give it a rating of 7 out of 10, with the recommendation to give it a chance.\n");
    } else if(rating > 15 && rating <= 20) {
        printf("This movie has been a hit with audiences and critics alike. I would give it a rating of 9 out of 10, and recommend it to anyone looking for a good film.\n");
    } else {
        printf("It appears that there has been some sort of mistake. Please enter a rating between 0 and 20 (inclusive).\n");
    }
    
    return 0;
}