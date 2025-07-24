//FormAI DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Brave Movie Rating System!\n");

    do {
        printf("Please rate the movie out of 10: ");
        scanf("%d", &rating);

        if (rating > 10 || rating < 0) {
            printf("Invalid rating. Please enter a rating between 0 and 10.\n");
        } else {
            printf("Thank you for your rating of %d out of 10!\n", rating);
        }

    } while (rating > 10 || rating < 0);

    printf("Based on your rating of %d out of 10, we recommend the following:\n", rating);

    if (rating >= 9) {
        printf("This movie is a must-see! It's a rare gem that is truly worth your time and money.\n");
    } else if (rating >= 7) {
        printf("This movie is definitely worth watching. It's not perfect, but it has some excellent moments that make it worth your while.\n");
    } else if (rating >= 5) {
        printf("This movie could go either way. It has some good moments, but it also has some flaws that you may or may not be willing to overlook.\n");
    } else {
        printf("We cannot recommend this movie based on your rating. It may have some redeeming qualities, but overall it falls short.\n");
    }
    return 0;
}