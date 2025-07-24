//FormAI DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char movie_name[50];
    float rating;
    char rating_type[10];

    printf("\t\t C Movie Rating System\n\n");

    printf("Enter the name of the movie: ");
    fgets(movie_name, 50, stdin);

    printf("Enter the rating of the movie: ");
    scanf("%f", &rating);

    printf("Enter the rating type (out of 10, 5, or 100): ");
    scanf("%s", rating_type);

    float converted_rating;

    if(strcmp(rating_type, "10") == 0){
        converted_rating = (rating/10)*100;
    }else if(strcmp(rating_type, "5") == 0){
        converted_rating = (rating/5)*100;
    }else if(strcmp(rating_type, "100") == 0){
        converted_rating = rating;
    }else{
        printf("Invalid rating type entered! Defaulting to out of 10. \n");
        converted_rating= (rating/10)*100;
    }

    printf("Thank you for rating %s. \n", movie_name);
    printf("The converted rating of %s is %0.1f%%. \n", movie_name, converted_rating);

    return 0;
}