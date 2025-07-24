//FormAI DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>

// Function to get the movie rating based on audience response
char getRating(int rating) {
    if (rating >= 8) {
        return 'A';
    } else if (rating >= 6) {
        return 'B';
    } else if (rating >= 4) {
        return 'C';
    } else if (rating >= 2) {
        return 'D';
    } else {
        return 'F';
    }
}

// Medieval style greeting message
void greeting() {
    printf("Welcome to Castle Cineplex!\n");
    printf("May thou be pleased by our humble entertainment offerings.\n");
    printf("Prithee, enter thy rating for the movie after thou hast seen it.\n\n");
}

// Main function
int main() {

    // Introduce the movie and ratings
    int audienceRating;
    char movieTitle[50] = "The Quest for the Holy Grail";
    printf("Our feature presentation is \"%s\" - a tale of knights and a sacred artifact!\n", movieTitle);
    printf("Our movie ratings are as follows:\n");
    printf("A - Exceeds Expectations\n");
    printf("B - Above Average\n");
    printf("C - Satisfactory\n");
    printf("D - Needs Improvement\n");
    printf("F - Poor\n");

    // Greet the audience and get their rating
    greeting();
    printf("Please enter your audience rating (1-10): ");
    scanf("%d", &audienceRating);

    // Print the audience rating and corresponding letter grade
    printf("Your rating: %d\n", audienceRating);
    printf("Rating grade: %c\n", getRating(audienceRating));

    return 0;
}