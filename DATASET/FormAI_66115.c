//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("\n\t\t\tWelcome to the Unique C Movie Rating System\n");
    printf("\n\t\t\t----------------------------------------\n");

    float rating = 0;

    printf("\nEnter the rating for the movie (0-10) : ");
    scanf("%f", &rating);

    if(rating < 0 || rating > 10){
        printf("\nError: Invalid rating entered! Please enter rating between 0 and 10 only.\n");
    }
    else if (rating >= 0 && rating < 2) {
        printf("\nRating : %.2f Very Bad, Please Don't watch this movie, it's a waste of time and money!\n", rating);
    }
    else if (rating >= 2 && rating < 4) {
        printf("\nRating : %.2f Bad, It's not worth watching, there are much better movies out there!\n", rating);
    }
    else if (rating >= 4 && rating < 6) {
        printf("\nRating : %.2f Okay, It's an average movie, you can watch it if you have nothing else to do!\n", rating);
    }
    else if (rating >= 6 && rating < 8) {
        printf("\nRating : %.2f Good, It's a nice movie, you should watch it if you are a movie buff!\n", rating);
    }
    else if (rating >= 8 && rating < 10) {
        printf("\nRating : %.2f Very Good, It's an excellent movie, you must watch it!\n", rating);
    }
    else if (rating == 10) {
        printf("\nRating : %.2f Masterpiece, It's a legendary movie, you cannot miss it!\n", rating);
    }
    else {
        printf("\nError: Invalid rating entered! Please enter rating between 0 and 10 only.\n");
    }

    printf("\n\t\t\tThank you for using Unique C Movie Rating System. Have a nice day!\n\n");

    return 0;
}