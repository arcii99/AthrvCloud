//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
/*
* C Movie Rating System
* Author: [Your Name Here]
* Date: [Current Date]
*/

#include<stdio.h>
#include<string.h>

// Structure for storing movie details
struct movie{
    char name[50];
    char genre[20];
    int year;
    float rating;
};

// Function to add movie details
void add_movie(struct movie m[], int n){
    printf("Enter movie name: ");
    scanf("%s", m[n].name);
    printf("Enter movie genre: ");
    scanf("%s", m[n].genre);
    printf("Enter movie release year: ");
    scanf("%d", &m[n].year);
    printf("Enter movie rating (out of 5): ");
    scanf("%f", &m[n].rating);
    printf("\nMovie added successfully!\n\n");
}

// Function to display movie details
void display_movie(struct movie m[], int n){
    printf("Movie Name: %s\n", m[n].name);
    printf("Movie Genre: %s\n", m[n].genre);
    printf("Movie Release Year: %d\n", m[n].year);
    printf("Movie Rating: %.2f\n\n", m[n].rating);
}

int main(){
    int choice, n=0;
    struct movie m[50];

    printf("Welcome to C Movie Rating System!\n");

    while(1){
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Display movies by genre\n");
        printf("4. Display movies by rating\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_movie(m, n);
                n++;
                break;
            case 2:
                if(n==0){
                    printf("\nNo movies added yet!\n\n");
                }
                else{
                    printf("\nAll Movies:\n");
                    for(int i=0; i<n; i++){
                        display_movie(m, i);
                    }
                }
                break;
            case 3:
                char genre[20];
                printf("\nEnter movie genre: ");
                scanf("%s", genre);
                printf("\nMovies by %s genre:\n", genre);
                for(int i=0; i<n; i++){
                    if(strcmp(m[i].genre, genre)==0){
                        display_movie(m, i);
                    }
                }
                break;
            case 4:
                float min_rating;
                printf("\nEnter minimum rating (out of 5): ");
                scanf("%f", &min_rating);
                printf("\nMovies with rating %.2f and above:\n", min_rating);
                for(int i=0; i<n; i++){
                    if(m[i].rating>=min_rating){
                        display_movie(m, i);
                    }
                }
                break;
            case 5:
                printf("\nExiting C Movie Rating System...thank you for using!\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again!\n\n");
        }
    }

    return 0;
}