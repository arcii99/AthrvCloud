//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>

// function to calculate rating based on audience response and critic reviews
float calculate_rating(float audience_response, float critic_reviews) {
    float rating = (audience_response + critic_reviews) / 2;
    return rating;
}

int main() {
    // variable declarations
    float audience_response, critic_reviews, rating;
    
    // input from user
    printf("Enter audience response (out of 10): ");
    scanf("%f", &audience_response);
    printf("Enter critic reviews (out of 10): ");
    scanf("%f", &critic_reviews);
    
    // calculate rating
    rating = calculate_rating(audience_response, critic_reviews);
    
    // output the result
    printf("The rating is calculated as: (%.1f + %.1f) / 2 = %.1f\n", audience_response, critic_reviews, rating);
    
    // determine rating category
    if (rating >= 9) {
        printf("This is a blockbuster!\n");
    } else if (rating >= 7) {
        printf("This is a hit movie!\n");
    } else if (rating >= 5) {
        printf("This is an average movie.\n");
    } else {
        printf("This is a flop movie.\n");
    }
    
    return 0;
}