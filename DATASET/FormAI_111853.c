//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int rating;
    char movieName[50];
    char directorName[50];
    char genre[20];
} movie;

int main()
{
    int n;
    printf("Enter the number of movies you want to rate: ");
    scanf("%d", &n);

    movie* list;
    list = (movie*)calloc(n, sizeof(movie));

    for(int i=0; i<n; i++) {
        printf("\nEnter the movie name: ");
        scanf("%s", (list+i)->movieName);
        printf("Enter the director name: ");
        scanf("%s", (list+i)->directorName);
        printf("Enter the genre: ");
        scanf("%s", (list+i)->genre);
        printf("Enter the movie rating (0-100): ");
        scanf("%d", &(list+i)->rating);
    }

    printf("\n----------------------\n");
    printf("| Movie | Director | Genre | Rating |\n");
    printf("----------------------\n");
    for(int i=0; i<n; i++) {
        printf("| %s | %s | %s | %d |\n", (list+i)->movieName, (list+i)->directorName, (list+i)->genre, (list+i)->rating);
    }
    printf("----------------------\n");

    free(list);
    return 0;
}