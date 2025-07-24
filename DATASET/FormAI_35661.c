//FormAI DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>

/* Function to display movie rating based on score */
void display_rating(int score){
    if(score < 0 || score > 100){
        printf("Invalid score!\n");
        return;
    }
    
    if(score >= 0 && score < 20){
        printf("Score: %d out of 100. Movie rating: Terrible\n", score);
    }
    else if(score >= 20 && score < 40){
        printf("Score: %d out of 100. Movie rating: Poor\n", score);
    }
    else if(score >= 40 && score < 60){
        printf("Score: %d out of 100. Movie rating: Average\n", score);
    }
    else if(score >= 60 && score < 80){
        printf("Score: %d out of 100. Movie rating: Good\n", score);
    }
    else{
        printf("Score: %d out of 100. Movie rating: Excellent\n", score);
    }
}

int main(){
    int score;
    printf("Enter movie score: ");
    scanf("%d", &score);
    display_rating(score);
    return 0;
}