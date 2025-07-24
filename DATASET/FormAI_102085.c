//FormAI DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100 // Maximum number of movies that can be added to the library

typedef struct {
    char title[100]; // Movie's title
    char director[50]; // Movie's director
    int year; // Year of release
    int rating; // Rating out of 10
} Movie;

int main() {
    Movie library[MAX_MOVIES]; // Create library of movies
    int numMovies = 0; // Number of movies in the library
    char userInput[10]; // User input for adding or searching movies
    int i; // Counter variable for loops
    int found = 0; // Flag for searching movies

    // Welcome message
    printf("Welcome to the Movie Rating System!\n\n");

    // Menu for user to select action
    while (1) {
        printf("Please select an action:\n");
        printf("[1] Add a movie\n");
        printf("[2] Search for a movie\n");
        printf("[3] Display all movies\n");
        printf("[0] Exit program\n");
        printf("Enter your choice: ");
        fgets(userInput, sizeof(userInput), stdin); // Get user input

        // Add movie
        if (strcmp(userInput, "1\n") == 0) {
            if (numMovies == MAX_MOVIES) {
                printf("Error: Library is full!\n\n");
            }
            else {
                printf("Enter movie title: ");
                fgets(library[numMovies].title, sizeof(library[numMovies].title), stdin);
                library[numMovies].title[strcspn(library[numMovies].title, "\n")] = 0; // Remove newline character

                printf("Enter movie director: ");
                fgets(library[numMovies].director, sizeof(library[numMovies].director), stdin);
                library[numMovies].director[strcspn(library[numMovies].director, "\n")] = 0; // Remove newline character

                printf("Enter year of release: ");
                scanf("%d", &library[numMovies].year);
                printf("Enter movie rating (out of 10): ");
                scanf("%d", &library[numMovies].rating);
                getchar(); // Remove newline character
                numMovies++;
                printf("Movie added successfully!\n\n");
            }
        }

        // Search for movie
        else if (strcmp(userInput, "2\n") == 0) {
            printf("Enter movie title: ");
            fgets(userInput, sizeof(userInput), stdin);
            userInput[strcspn(userInput, "\n")] = 0; // Remove newline character

            for (i = 0; i < numMovies; i++) {
                if (strcmp(userInput, library[i].title) == 0) {
                    printf("Movie found:\n");
                    printf("Title: %s\n", library[i].title);
                    printf("Director: %s\n", library[i].director);
                    printf("Year of release: %d\n", library[i].year);
                    printf("Rating: %d/10\n\n", library[i].rating);
                    found = 1; // Set flag to indicate movie was found
                    break;
                }
            }

            if (!found) {
                printf("No movie found with that title.\n\n");
            }
            found = 0; // Reset flag for next search
        }

        // Display all movies
        else if (strcmp(userInput, "3\n") == 0) {
            if (numMovies == 0) {
                printf("Library is empty.\n\n");
            }
            else {
                printf("Library contents:\n");
                for (i = 0; i < numMovies; i++) {
                    printf("Movie %d:\n", i+1);
                    printf("Title: %s\n", library[i].title);
                    printf("Director: %s\n", library[i].director);
                    printf("Year of release: %d\n", library[i].year);
                    printf("Rating: %d/10\n\n", library[i].rating);
                }
            }
        }

        // Exit program
        else if (strcmp(userInput, "0\n") == 0) {
            printf("Exiting program...\n");
            break;
        }

        // Invalid input
        else {
            printf("Invalid input. Please try again.\n\n");
        }
    }

    return 0;
}