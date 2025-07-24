//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

// Function to rate the movie according to user input
void rateMovie(int rating) {
    if(rating >= 0 && rating <= 10) {
        if(rating < 5) printf("We are sorry, the movie rating is too low.\n");
        else if(rating < 7) printf("The movie rating is okay.\n");
        else if(rating < 9) printf("The movie rating is good.\n");
        else printf("The movie rating is excellent!\n");
    }
    else printf("Invalid rating entered. Please enter a number between 0-10.\n");
}

int main() {
    int rating;
    
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter a rating between 0-10: ");
    scanf("%d", &rating);
    
    rateMovie(rating);
    
    printf("Thank you for using the Unique C Movie Rating System.\n");
    
    return 0;
}