//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include<stdio.h>

// Function to rate the movie based on user's inputs
void rateMovie(int rating1, int rating2, int rating3){
    float average_rating = (float)(rating1 + rating2 + rating3)/3;
    printf("\nThe average rating of the movie is %.2f\n\n", average_rating);
    
    // Displaying the final rating based on the average rating
    if(average_rating >= 8.0){
        printf("This movie is highly recommended!\n");
    }
    else if(average_rating >= 6.0 && average_rating < 8.0){
        printf("You can give this movie a try!\n");
    }
    else{
        printf("This movie doesn't seem to be worth it!\n");
    }
}

int main(){
    printf("\nWelcome to our movie rating system!\n");
    
    // Getting the user inputs for the movie ratings
    int rating1, rating2, rating3;
    printf("\nPlease rate the movie out of 10!\n");
    printf("Enter your rating for the Storyline: ");
    scanf("%d", &rating1);
    printf("Enter your rating for the Acting: ");
    scanf("%d", &rating2);
    printf("Enter your rating for the Cinematography: ");
    scanf("%d", &rating3);
    
    // Calling the 'rateMovie' function to get the final rating
    rateMovie(rating1, rating2, rating3);
    
    return 0;
}