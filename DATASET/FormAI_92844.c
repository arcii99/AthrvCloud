//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include<stdio.h>
#include<string.h>

// Defining movie structure
struct movie{
    char name[50];
    char genre[20];
    int rating;
};

// Function to get user input
void get_input(struct movie *m){
    printf("\nEnter the name of the movie: ");
    scanf(" %[^\n]",m->name);
    printf("Enter the genre of the movie: ");
    scanf(" %[^\n]",m->genre);
    printf("Enter your rating (out of 10) for the movie: ");
    scanf("%d",&m->rating);
}

// Function to display movie details
void display_movie(struct movie m){
    printf("\nName of the movie: %s",m.name);
    printf("\nGenre of the movie: %s",m.genre);
    printf("\nRating of the movie (out of 10): %d\n",m.rating);
}

// Function to calculate overall rating of the movie
float calculate_rating(struct movie *m){
    float overall_rating;

    // Assigning different weights based on genre
    if(strcmp(m->genre,"Action")==0){
        overall_rating = (0.3*m->rating) + (0.2*8) + (0.1*5) + (0.4*6);
    }
    else if(strcmp(m->genre,"Comedy")==0){
        overall_rating = (0.3*m->rating) + (0.2*7) + (0.1*8) + (0.4*4);
    }
    else if(strcmp(m->genre,"Drama")==0){
        overall_rating = (0.3*m->rating) + (0.2*6) + (0.1*9) + (0.4*7);
    }
    else if(strcmp(m->genre,"Fantasy")==0){
        overall_rating = (0.3*m->rating) + (0.2*9) + (0.1*6) + (0.4*8);
    }
    else{
        overall_rating = m->rating;
    }

    return overall_rating;
}

void main(){
    int n,rating_count=0; // n is the number of movies to be entered
    float overall_rating_sum=0;

    printf("Enter the number of movies you want to rate: ");
    scanf("%d",&n);

    struct movie m[n]; // Creating array of movie structures

    // Getting user input for each movie
    for(int i=0;i<n;i++){
        printf("\nEnter details for Movie %d\n",i+1);
        get_input(&m[i]);
        rating_count++;
        overall_rating_sum += calculate_rating(&m[i]);
    }

    // Calculating average overall rating
    float average_overall_rating = overall_rating_sum/rating_count;

    printf("\n-----MOVIE RATINGS-----\n");

    // Displaying details for each movie along with overall rating
    for(int i=0;i<n;i++){
        printf("\nDetails for Movie %d:\n",i+1);
        display_movie(m[i]);
        printf("Overall rating for the movie (out of 10): %.2f\n",calculate_rating(&m[i]));
    }

    // Displaying average overall rating
    printf("\nAverage overall rating for all the movies: %.2f",average_overall_rating);

}