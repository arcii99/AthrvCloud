//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>

struct movie {
    char title[50];
    char director[50];
    char rating[10];
};

void main() {
    int n, i, j;
    printf("Enter the number of movies to rate: ");
    scanf("%d", &n);
    struct movie movies[n];
    char ratings[5][10] = {"Excellent", "Good", "Average", "Below Average", "Poor"};
    for (i = 0; i < n; i++) {
        printf("\nEnter the details for Movie %d", i+1);
        printf("\nEnter the title: ");
        scanf("%s", movies[i].title);
        printf("Enter the director: ");
        scanf("%s", movies[i].director);
        printf("Choose a rating between 1-5:\n1. Excellent\n2. Good\n3. Average\n4. Below Average\n5. Poor\n");
        scanf("%s", movies[i].rating);
        //validate rating
        while (atoi(movies[i].rating) < 1 || atoi(movies[i].rating) > 5) {
            printf("Please enter a rating between 1-5 only: ");
            scanf("%s", movies[i].rating);
        }
    }
    printf("\n\n-----------------------------------------------\n");
    printf("       Movie Rating System - Top %d Movies\n", n);
    printf("-----------------------------------------------\n\n");
    //sort based on rating
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (atoi(movies[i].rating) < atoi(movies[j].rating)) {
                struct movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
    //display results
    for (i = 0; i < n; i++) {
        printf("Movie %d\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Rating: %s\n", ratings[atoi(movies[i].rating)-1]);
        printf("\n");
    }
}