//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
//Program: Sherlock Holmes' Movie Rating System
//Author: [Your Name]

#include <stdio.h>
#include <string.h>

int main() {
    //Declaration of variables and constants
    const int MAX_MOVIES = 10;
    char movie_titles[MAX_MOVIES][100];
    int movie_ratings[MAX_MOVIES];
    char user_input[100];
    int counter = 0;
    int i, j;
    int rating = 0;
    int highest_rating = 0;
    int lowest_rating = 5;
    char highest_rated_movie[100];
    char lowest_rated_movie[100];
    
    //Introduction and explanation of the program
    printf("Welcome to Sherlock Holmes' Movie Rating System.\n");
    printf("You can enter up to 10 different movie titles, and then rate each one on a scale of 1 to 5.\n");
    printf("Once you're done, the program will tell you the highest and lowest rated movies.\n\n");

    //Loop through movie titles, prompt user for title and rating
    while (counter<MAX_MOVIES) {
        printf("Please enter the title of a movie, or type 'done' if you're finished: ");
        fgets(user_input, sizeof(user_input), stdin);
        if (strcmp(user_input, "done\n") == 0) {
            break;
        } else {
            //Remove newline from end of user_input and store title in array
            user_input[strcspn(user_input, "\n")] = 0;
            strcpy(movie_titles[counter], user_input);
            printf("Please rate %s on a scale of 1 to 5: ", movie_titles[counter]);
            fgets(user_input, sizeof(user_input), stdin);
            rating = atoi(user_input);
            if (rating<1 || rating>5) {
                printf("Invalid rating. Rating must be between 1 and 5. Please try again.\n");
            } else {
                movie_ratings[counter] = rating;
                counter++;
            }
        }
    }
    
    if (counter == 0) {
        printf("No movies entered. Exiting program.\n");
        return 0;
    }
    
    //Print list of movies and their ratings
    printf("\nHere are the movies you entered and their ratings:\n");
    for (i=0; i<counter; i++) {
        printf("%s: %d\n", movie_titles[i], movie_ratings[i]);
        if (movie_ratings[i] > highest_rating) {
            highest_rating = movie_ratings[i];
            strcpy(highest_rated_movie, movie_titles[i]);
        }
        if (movie_ratings[i] < lowest_rating) {
            lowest_rating = movie_ratings[i];
            strcpy(lowest_rated_movie, movie_titles[i]);
        }
    }
    
    //Print highest and lowest rated movies
    printf("\n%s is the highest rated movie with a rating of %d.\n", highest_rated_movie, highest_rating);
    printf("%s is the lowest rated movie with a rating of %d.\n", lowest_rated_movie, lowest_rating);
    
    return 0;
}