//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>

// Initialize the global variables
int num_ratings = 0;
int total_rating = 0;
double average_rating = 0;
pthread_mutex_t lock;

void *update_ratings(void *arg){
    int rating = *(int*)arg;

    // Lock the mutex
    pthread_mutex_lock(&lock);
    
    // Update the rating statistics
    total_rating += rating;
    num_ratings++;
    average_rating = (double)total_rating / num_ratings;

    // Unlock the mutex
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(){
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads to update the ratings
    int ratings[] = {5, 6, 7, 8, 9};
    pthread_t threads[5];
    for(int i=0; i<5; i++){
        pthread_create(&threads[i], NULL, update_ratings, &ratings[i]);
    }

    // Join the threads
    for(int i=0; i<5; i++){
        pthread_join(threads[i], NULL);
    }

    // Print the final rating statistics
    printf("Number of ratings: %d\n", num_ratings);
    printf("Total rating: %d\n", total_rating);
    printf("Average rating: %.2f\n", average_rating);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}