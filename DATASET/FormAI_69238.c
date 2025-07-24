//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    char genre[20];
    int rating;
} Movie;

void print_movie_details(Movie m){
    printf("Title: %s\n", m.title);
    printf("Genre: %s\n", m.genre);
    printf("Rating: %d\n", m.rating);
}

int main(){

    Movie movies[5];

    strcpy(movies[0].title, "The Shawshank Redemption");
    strcpy(movies[0].genre, "Drama");
    movies[0].rating = 9;

    strcpy(movies[1].title, "The Godfather");
    strcpy(movies[1].genre, "Drama");
    movies[1].rating = 10;

    strcpy(movies[2].title, "The Dark Knight");
    strcpy(movies[2].genre, "Action");
    movies[2].rating = 8;

    strcpy(movies[3].title, "Forrest Gump");
    strcpy(movies[3].genre, "Drama");
    movies[3].rating = 7;

    strcpy(movies[4].title, "Inception");
    strcpy(movies[4].genre, "Science Fiction");
    movies[4].rating = 8;

    int choice;
    printf("Welcome to Movie Rating System!\n");

    do{
        printf("\nSelect from the following:\n");
        printf("1. List all available movies\n");
        printf("2. List movies by genre\n");
        printf("3. Rate a movie\n");
        printf("4. Exit the program\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nList of Movies:\n");
                for(int i=0; i<5; i++){
                    print_movie_details(movies[i]);
                }
                break;
            
            case 2:
                char genre[20];
                printf("\nEnter the genre name: ");
                scanf("%s", genre);
                printf("\nList of movies with genre '%s':\n", genre);
                for(int i=0; i<5; i++){
                    if(strcmp(movies[i].genre, genre) == 0){
                        print_movie_details(movies[i]);
                    }
                }
                break;

            case 3:
                printf("\nEnter a movie title to rate: ");
                char title[50];
                scanf("%s", title);
                int found = 0;
                for(int i=0; i<5; i++){
                    if(strcmp(movies[i].title, title) == 0){
                        found = 1;
                        printf("\nEnter the new rating (1-10): ");
                        scanf("%d", &movies[i].rating);
                        printf("\nThe rating for '%s' has been updated to %d.\n", title, movies[i].rating);
                        break;
                    }
                }
                if(found == 0){
                    printf("\nNo movie found with title '%s'.\n", title);
                }
                break;

            case 4:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please select again.\n");
                break;
        }

    }while(choice != 4);

    return 0;
}