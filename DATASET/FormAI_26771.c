//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>

int u_rating, m_rating, f_rating; // variables to store ratings
char movie_title[50];

int main() {

    printf("Welcome to the Unique C Movie Rating System\n");
    printf("Please enter the title of the movie: ");
    scanf("%[^\n]s", movie_title); // read input until a newline is encountered

    printf("Please enter the rating of the movie (out of 10) by our unique user group: ");
    scanf("%d", &u_rating); // read user group rating

    printf("Please enter the rating of the movie (out of 10) by our unique movie critics: ");
    scanf("%d", &m_rating); // read movie critic rating

    printf("Please enter the rating of the movie (out of 10) by our unique focus group: ");
    scanf("%d", &f_rating); // read focus group rating

    // calculate average rating
    double avg_rating = ((double) u_rating + m_rating + f_rating) / 3;

    printf("\n\n***The %s Movie Rating***\n", movie_title);
    printf("User Group Rating: %d\n", u_rating);
    printf("Movie Critic Rating: %d\n", m_rating);
    printf("Focus Group Rating: %d\n", f_rating);
    printf("Overall Rating: %.2f\n", avg_rating);

    return 0;
}