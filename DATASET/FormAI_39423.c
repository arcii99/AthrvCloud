//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Cheerful C Movie Rating System!\n");

    int rating;
    char movieTitle[50];
    char movieGenre[20];

    printf("Please enter the title of the movie: ");
    scanf("%[^\n]%*c", movieTitle);

    printf("Please enter the genre of the movie: ");
    scanf("%s", movieGenre);

    printf("Please rate this movie on a scale of 1 to 10: ");
    scanf("%d", &rating);

    if(rating >= 8) {
        printf("Wow!! %s is an amazing %s movie with a rating of %d!\n", movieTitle, movieGenre, rating);
    }
    else if(rating >= 5) {
        printf("%s is a decent %s movie with a rating of %d.\n", movieTitle, movieGenre, rating);
    }
    else {
        printf("%s is a below average %s movie with a rating of %d. We suggest you to watch something else!\n", movieTitle, movieGenre, rating);
    }

    printf("Thank you for using the Cheerful C Movie Rating System!\n");

    return 0;
}