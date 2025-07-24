//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>

// Define movie struct to contain movie details
typedef struct {
    char title[100];
    char director[100];
    int year;
    int rating;
} Movie;

// Initialize array of movies
Movie movies[10];

// Function to rate a movie
void rateMovie(int index) {
    int rating;
    printf("Enter a rating out of 10 for the movie \"%s\": ", movies[index].title);
    scanf("%d", &rating);
    if (rating < 0 || rating > 10) {
        printf("Invalid rating entered. Please enter a rating between 0 and 10.\n");
        rateMovie(index);
    } else {
        movies[index].rating = rating;
        printf("Rating of \"%s\" updated to %d out of 10.\n", movies[index].title, movies[index].rating);
    }
}

// Function to print details of a movie
void printMovie(int index) {
    printf("Title: %s\n", movies[index].title);
    printf("Director: %s\n", movies[index].director);
    printf("Year: %d\n", movies[index].year);
    printf("Rating: %d out of 10\n", movies[index].rating);
}

// Function to print all movies in the database
void printMovies() {
    printf("\n*** MOVIE DATABASE ***\n");
    for (int i = 0; i < 10; i++) {
        printf("MOVIE %d:\n", i+1);
        printMovie(i);
        printf("\n");
    }
}

int main() {
    // Initialize movies array
    strcpy(movies[0].title, "The Dark Knight");
    strcpy(movies[0].director, "Christopher Nolan");
    movies[0].year = 2008;
    movies[0].rating = 0;
    
    strcpy(movies[1].title, "Inception");
    strcpy(movies[1].director, "Christopher Nolan");
    movies[1].year = 2010;
    movies[1].rating = 0;
    
    strcpy(movies[2].title, "Fight Club");
    strcpy(movies[2].director, "David Fincher");
    movies[2].year = 1999;
    movies[2].rating = 0;
    
    strcpy(movies[3].title, "The Shawshank Redemption");
    strcpy(movies[3].director, "Frank Darabont");
    movies[3].year = 1994;
    movies[3].rating = 0;
    
    strcpy(movies[4].title, "Forrest Gump");
    strcpy(movies[4].director, "Robert Zemeckis");
    movies[4].year = 1994;
    movies[4].rating = 0;
    
    strcpy(movies[5].title, "The Godfather");
    strcpy(movies[5].director, "Francis Ford Coppola");
    movies[5].year = 1972;
    movies[5].rating = 0;
    
    strcpy(movies[6].title, "Pulp Fiction");
    strcpy(movies[6].director, "Quentin Tarantino");
    movies[6].year = 1994;
    movies[6].rating = 0;
    
    strcpy(movies[7].title, "The Matrix");
    strcpy(movies[7].director, "The Wachowskis");
    movies[7].year = 1999;
    movies[7].rating = 0;
    
    strcpy(movies[8].title, "Star Wars: Episode IV - A New Hope");
    strcpy(movies[8].director, "George Lucas");
    movies[8].year = 1977;
    movies[8].rating = 0;
    
    strcpy(movies[9].title, "The Lord of the Rings: The Fellowship of the Ring");
    strcpy(movies[9].director, "Peter Jackson");
    movies[9].year = 2001;
    movies[9].rating = 0;
    
    // Print welcome message
    printf("Welcome to the Movie Rating System!\n\n");
    
    // Loop until user chooses to exit
    char choice;
    do {
        // Print options
        printf("Enter one of the following options:\n");
        printf("1. Rate a movie\n");
        printf("2. View a movie's details\n");
        printf("3. View all movies in the database\n");
        printf("4. Exit the program\n");
        printf("> ");
        scanf(" %c", &choice);
        
        int index;
        switch(choice) {
            case '1': // Rate a movie
                printf("\nEnter the number of the movie you want to rate:\n");
                scanf("%d", &index);
                rateMovie(index-1);
                break;
            case '2': // View a movie's details
                printf("\nEnter the number of the movie you want to view:\n");
                scanf("%d", &index);
                printMovie(index-1);
                break;
            case '3': // View all movies in the database
                printMovies();
                break;
            case '4': // Exit the program
                printf("\nThank you for using the Movie Rating System!\n");
                return 0;
            default:
                printf("\nInvalid input. Please enter 1, 2, 3, or 4.\n");
        }
    } while (choice != '4');
    
    return 0;
}