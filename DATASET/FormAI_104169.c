//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define constants for minimum and maximum rating
#define MIN_RATING 1
#define MAX_RATING 10

// Define the structure for a movie, which includes the movie name and its rating
typedef struct {
    char *title;
    int rating;
} Movie;

// Define the array of movies and the length of the array
Movie movies[] = {
    {"The Shawshank Redemption", 9},
    {"The Godfather", 10},
    {"The Dark Knight", 8},
    {"The Godfather: Part II", 9},
    {"12 Angry Men", 8},
    {"Schindler's List", 9},
    {"The Lord of the Rings: The Return of the King", 10},
    {"Pulp Fiction", 9},
    {"The Lord of the Rings: The Fellowship of the Ring", 8},
    {"Forrest Gump", 7}
};
int num_movies = sizeof(movies) / sizeof(movies[0]);

// Define an array of locks, one lock for each movie
pthread_mutex_t locks[sizeof(movies) / sizeof(movies[0])];

// Define the thread function for rating a movie
void *rate_movie(void *arg) {
    int movie_index = *(int *) arg;
    pthread_mutex_lock(&locks[movie_index]);  // lock the movie
    printf("Enter rating for %s (1-10): ", movies[movie_index].title);
    scanf("%d", &movies[movie_index].rating); // update the rating
    pthread_mutex_unlock(&locks[movie_index]);  // unlock the movie
    return NULL;
}

// Define the main function
int main() {
    // Initialize the locks
    for (int i = 0; i < num_movies; i++) {
        pthread_mutex_init(&locks[i], NULL);
    }

    // Create threads for each movie
    pthread_t threads[num_movies];
    int indices[num_movies];
    for (int i = 0; i < num_movies; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, rate_movie, &indices[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_movies; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final ratings
    printf("\nFinal Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d\n", movies[i].title, movies[i].rating);
    }

    // Destroy the locks
    for (int i = 0; i < num_movies; i++) {
        pthread_mutex_destroy(&locks[i]);
    }

    return 0;
}