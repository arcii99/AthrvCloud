//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <string.h>

struct movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

int main() {

    struct movie my_movie;
    printf("Welcome to the Happy Movie Rating System!\n\n");

    // Title
    printf("What is the title of the movie you want to rate? ");
    fgets(my_movie.title, 50, stdin);

    // Director
    printf("Who is the director of the movie? ");
    fgets(my_movie.director, 50, stdin);

    // Year
    printf("What year did the movie come out? ");
    scanf("%d", &my_movie.year);

    // Rating
    printf("What rating would you give this movie on a scale of 1-10? ");
    scanf("%f", &my_movie.rating);
    getchar();

    // Feedback
    printf("\nThank you for rating \"%s\", directed by %s, which came out in %d.\n", my_movie.title, my_movie.director, my_movie.year);
    printf("Your rating of %.1f has been recorded and we appreciate your feedback!\n\n", my_movie.rating);

    // Suggestions
    if (my_movie.rating >= 8.0) {
        printf("Wow, you gave this movie a great rating! You would love our \"Top Picks\" section on our website.\n");
    } else if (my_movie.rating >= 5.0) {
        printf("Thanks for your feedback! Our \"Most Popular\" section might interest you.\n");
    } else {
        printf("Thank you for your feedback. We hope to see you soon to improve our suggestions for you.\n");
    }

    return 0;
}