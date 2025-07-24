//FormAI DATASET v1.0 Category: Movie Rating System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Struct to hold movie data
typedef struct movie {
    char title[50];
    int ratings[5];
    double avg_rating;
} movie;

// Mutex for accessing movie data
pthread_mutex_t movie_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to generate a random rating between 1 and 5
int generate_rating() {
    srand(time(NULL));
    return rand() % 5 + 1;
}

// Function to calculate the average rating of a movie
double calculate_average(int *ratings) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += ratings[i];
    }
    return total / 5.0;
}

// Function to add a rating to a movie
void add_rating(movie *m) {
    pthread_mutex_lock(&movie_mutex);
    int rating = generate_rating();
    m->ratings[rating-1]++;
    m->avg_rating = calculate_average(m->ratings);
    pthread_mutex_unlock(&movie_mutex);
}

// Function to print the ratings of a movie
void print_ratings(movie *m) {
    printf("%s Ratings:\n", m->title);
    for (int i = 0; i < 5; i++) {
        printf("%d star: %d\n", i+1, m->ratings[i]);
    }
    printf("Average rating: %.2f\n\n", m->avg_rating);
}

// Function to run as a thread and add ratings to a movie periodically
void *run_movie_thread(void *arg) {
    movie *m = (movie*)arg;
    while (true) {
        add_rating(m);
        sleep(1);
    }
    return NULL;
}

int main() {
    // Create some sample movies
    movie avengers = {"Avengers", {0,0,0,0,0}, 0.0};
    movie inception = {"Inception", {0,0,0,0,0}, 0.0};
    movie dark_knight = {"The Dark Knight", {0,0,0,0,0}, 0.0};
    
    // Create threads to simulate ratings being added over time
    pthread_t avengers_thread, inception_thread, dark_knight_thread;
    pthread_create(&avengers_thread, NULL, run_movie_thread, (void*)&avengers);
    pthread_create(&inception_thread, NULL, run_movie_thread, (void*)&inception);
    pthread_create(&dark_knight_thread, NULL, run_movie_thread, (void*)&dark_knight);
    
    // Wait for threads to finish
    pthread_join(avengers_thread, NULL);
    pthread_join(inception_thread, NULL);
    pthread_join(dark_knight_thread, NULL);
    
    // Print final ratings for each movie
    print_ratings(&avengers);
    print_ratings(&inception);
    print_ratings(&dark_knight);
    
    return 0;
}