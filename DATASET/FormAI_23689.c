//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A struct to represent a movie
struct Movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

// A struct to represent a review
struct Review {
    char reviewer[50];
    char comment[500];
    float rating;
};

// A function to add a new movie
void add_movie(struct Movie *movies[], int *num_movies) {
    struct Movie *new_movie = malloc(sizeof(struct Movie));

    printf("\nEnter Movie Title: ");
    scanf("%s", new_movie->title);

    printf("Enter Movie Director: ");
    scanf("%s", new_movie->director);

    printf("Enter Movie Release Year: ");
    scanf("%d", &(new_movie->year));

    printf("Enter Movie Initial Rating (0-10): ");
    scanf("%f", &(new_movie->rating));

    movies[*num_movies] = new_movie;
    *num_movies += 1;

    printf("\n--- Movie Added Successfully! ---\n");
}

// A function to view all movies
void view_movies(struct Movie *movies[], int num_movies) {
    printf("==========================\n");
    printf("======= MOVIE LIST =======\n");
    printf("==========================\n\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s (%s, %d)\n", (i+1), movies[i]->title, movies[i]->director, movies[i]->year);
        printf("    Rating: %.1f\n", movies[i]->rating);
        printf("\n");
    }
}

// A function to add a new review
void add_review(struct Movie *movies[], int num_movies) {
    char movie_title[50];
    printf("\nEnter Movie Title: ");
    scanf("%s", movie_title);

    struct Movie *selected_movie = NULL;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i]->title, movie_title) == 0) {
            selected_movie = movies[i];
            break;
        }
    }

    if (selected_movie == NULL) {
        printf("\n--- Movie Not Found! ---\n");
        return;
    }

    struct Review new_review;

    printf("\nEnter Reviewer Name: ");
    scanf("%s", new_review.reviewer);

    printf("Enter Review Comment (max 500 characters):\n");
    getchar();
    fgets(new_review.comment, 500, stdin);

    printf("Enter Review Rating (0-10): ");
    scanf("%f", &(new_review.rating));

    selected_movie->rating = (selected_movie->rating + new_review.rating) / 2;

    printf("\n--- Review Added Successfully! ---\n");
}

int main() {
    struct Movie *movies[100];
    int num_movies = 0;
    int choice;

    do {
        printf("==========\n");
        printf(" MAIN MENU\n");
        printf("==========\n");
        printf("1. Add a Movie\n");
        printf("2. View Movies\n");
        printf("3. Add a Review\n");
        printf("4. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                view_movies(movies, num_movies);
                break;
            case 3:
                add_review(movies, num_movies);
                break;
            case 4:
                exit(0);
            default:
                printf("\n--- Invalid Choice! ---\n");
                break;
        }

        printf("\n");
    } while (true);

    return 0;
}