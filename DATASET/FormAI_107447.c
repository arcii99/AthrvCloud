//FormAI DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include<stdio.h>

//Defining a structure to hold movie details
struct MovieDetails{
    char title[50];
    char genre[20];
    int year;
    float rating;
};

int main(){
    int n;
    printf("Enter the number of movies: ");
    scanf("%d",&n);

    //Declaring an array to hold the movie details
    struct MovieDetails movie[n];

    //Getting the movie details from the user
    for(int i=0; i<n; i++){
        printf("\nEnter the title of movie %d: ",i+1);
        scanf("%s",movie[i].title);

        printf("Enter the genre of movie %d: ",i+1);
        scanf("%s",movie[i].genre);

        printf("Enter the year of release of movie %d: ",i+1);
        scanf("%d",&movie[i].year);

        printf("Enter the rating of movie %d (out of 10): ",i+1);
        scanf("%f",&movie[i].rating);

        //Converting the rating out of 10 to out of 100
        movie[i].rating *= 10;

        //Checking if the rating is within acceptable range
        if(movie[i].rating > 100){
            printf("Invalid rating entered. Setting rating to 100.\n");
            movie[i].rating = 100;
        }else if(movie[i].rating < 0){
            printf("Invalid rating entered. Setting rating to 0.\n");
            movie[i].rating = 0;
        }
    }

    printf("\n---------------------------");
    printf("\nMOVIE RATING SYSTEM SUMMARY");
    printf("\n---------------------------\n\n");

    //Printing the movie details and rating
    for(int i=0; i<n; i++){
        printf("%d) %s\nGenre: %s\nYear of Release: %d\nRating (out of 100): %.0f\n",i+1,movie[i].title,movie[i].genre,movie[i].year,movie[i].rating);
        printf("Rating: ");

        //Printing stars for rating out of 100
        for(int j=0; j<movie[i].rating/10; j++){
            printf("*");
        }
        printf("\n\n");
    }

    return 0;
}