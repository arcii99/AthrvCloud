//FormAI DATASET v1.0 Category: Movie Rating System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>

//Movie struct to store movie information
typedef struct {
    int movie_id;
    char movie_name[50];
    float rating;
} Movie;

//client struct to store client information
typedef struct {
    int client_id;
    char client_name[50];
} Client;

//function to rate a movie
void rateMovie(Movie* movie, float rating) {
    movie->rating = rating;
}

//function to get the average rating of a movie
float getAverageRating(Movie* movie) {
    return movie->rating;
}

//function to display movie details
void displayMovieDetails(Movie* movie) {
    printf("Movie ID: %d\n", movie->movie_id);
    printf("Movie Name: %s\n", movie->movie_name);
    printf("Rating: %.2f\n", movie->rating);
}

//function to display client details
void displayClientDetails(Client* client) {
    printf("Client ID: %d\n", client->client_id);
    printf("Client Name: %s\n", client->client_name);
}

//main function
int main() {
    //creating movies
    Movie movie1 = {1001, "The Godfather", 0.0};
    Movie movie2 = {1002, "The Shawshank Redemption", 0.0};
    Movie movie3 = {1003, "The Dark Knight", 0.0};
    
    //creating clients
    Client client1 = {101, "John"};
    Client client2 = {102, "Mary"};
    Client client3 = {103, "David"};
    
    //rate movies
    rateMovie(&movie1, 8.7);
    rateMovie(&movie2, 9.3);
    rateMovie(&movie3, 9.0);
    
    //get average ratings
    float avgRating1 = getAverageRating(&movie1);
    float avgRating2 = getAverageRating(&movie2);
    float avgRating3 = getAverageRating(&movie3);
    
    //display movie and client details
    printf("Movie Details:\n");
    displayMovieDetails(&movie1);
    printf("\n");
    displayMovieDetails(&movie2);
    printf("\n");
    displayMovieDetails(&movie3);
    printf("\n");
    
    printf("Client Details:\n");
    displayClientDetails(&client1);
    printf("\n");
    displayClientDetails(&client2);
    printf("\n");
    displayClientDetails(&client3);
    printf("\n");
    
    return 0;
}