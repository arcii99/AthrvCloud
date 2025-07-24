//FormAI DATASET v1.0 Category: Movie Rating System ; Style: brave
#include<stdio.h>

//function to calculate the rating
float calcRating(float rating) {
    float finalRating;
    if (rating >= 9) {
        finalRating = 5;
    } else if (rating >= 8) {
        finalRating = 4.5;
    } else if (rating >= 7) {
        finalRating = 4.0;
    } else if (rating >= 6) {
        finalRating = 3.5;
    } else if (rating >= 5) {
        finalRating = 3.0;
    } else if (rating >= 4) {
        finalRating = 2.5;
    } else if (rating >= 3) {
        finalRating = 2.0;
    } else if (rating >= 2) {
        finalRating = 1.5;
    } else if (rating >= 1) {
        finalRating = 1.0;
    } else {
        finalRating = 0.5;
    }
    return finalRating;
}

int main() {
    char movieName[50];
    float rating, finalRating;
    
    //Input
    printf("Enter the Movie Name:");
    scanf("%s", movieName); //Taking movie name as string
    
    printf("Enter the Rating (out of 10):");
    scanf("%f", &rating);
    
    //Calculating final rating
    finalRating = calcRating(rating);
    
    //Output
    printf("Your movie %s has been rated as %.1f stars\n", movieName, finalRating);
    
    return 0;
}