//FormAI DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

typedef struct movie_rating {
    char title[MAX_TITLE_LENGTH];
    int rating;
} movie_rating;

void print_ratings(movie_rating ratings[], int num_ratings);
void add_rating(movie_rating ratings[], int *num_ratings);
void paranoid_clear_screen();
void paranoid_pause();

int main() {
    movie_rating ratings[MAX_MOVIES];
    int num_ratings = 0;
    char choice;

    printf("Welcome to the Paranoid Movie Rating System!\n");

    do {
        paranoid_clear_screen();
        printf("Choose an option:\n");
        printf("A) Add a new movie rating\n");
        printf("P) Print all movie ratings\n");
        printf("Q) Quit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a':
                add_rating(ratings, &num_ratings);
                paranoid_pause();
                break;

            case 'P':
            case 'p':
                print_ratings(ratings, num_ratings);
                paranoid_pause();
                break;

            case 'Q':
            case 'q':
                printf("Goodbye, human.\n");
                paranoid_pause();
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                paranoid_pause();
                break;
        }

    } while (choice != 'Q' && choice != 'q');

    return 0;
}

void print_ratings(movie_rating ratings[], int num_ratings) {
    if (num_ratings == 0) {
        printf("There are no ratings yet.\n");
        return;
    }

    printf("\nMovie Ratings:\n");

    for (int i = 0; i < num_ratings; i++) {
        printf("%s - %d/10\n", ratings[i].title, ratings[i].rating);
    }

    printf("\n");
}

void add_rating(movie_rating ratings[], int *num_ratings) {
    if (*num_ratings == MAX_MOVIES) {
        printf("Maximum number of ratings reached.\n");
        return;
    }

    movie_rating new_rating;
    printf("Enter the movie title (max %d characters):\n", MAX_TITLE_LENGTH - 1);
    scanf(" %[^\n]", new_rating.title);
    printf("Enter the movie rating (0-10):\n");
    scanf(" %d", &new_rating.rating);

    if (new_rating.rating < 0) {
        printf("Negative ratings aren't allowed.\n");
        return;
    } else if (new_rating.rating > 10) {
        printf("We don't allow ratings over 10.\n");
        return;
    }

    ratings[*num_ratings] = new_rating;
    (*num_ratings)++;

    printf("Rating successfully added.\n");
}

void paranoid_clear_screen() {
    // This function uses a paranoid method to clear the screen by printing 
    // 100 blank lines. This is done to ensure that no previous output can be seen.
    for (int i = 0; i < 100; i++) {
        printf("\n");
    }
}

void paranoid_pause() {
    // This function ensures that the program waits for user input before 
    // continuing. This is done to make sure that the user is aware of 
    // what the program is doing at all times.
    char enter;
    printf("\nPress enter to continue...");
    scanf(" %c", &enter);
}