//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 100

struct Movie {
    char title[50];
    int year;
    int ratings[MAX_RATINGS];
    int num_ratings;
    float rating_avg;
};

int num_movies = 0;
struct Movie movies[MAX_MOVIES];

void add_movie(char title[], int year) {
    struct Movie new_movie;
    strcpy(new_movie.title, title);
    new_movie.year = year;
    new_movie.num_ratings = 0;
    new_movie.rating_avg = 0.0;
    movies[num_movies] = new_movie;
    num_movies++;
    printf("Movie added: %s (%d)\n", title, year);
}

int find_movie(char title[]) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

void rate_movie(char title[], int rating) {
    int index = find_movie(title);
    if (index >= 0) {
        struct Movie *movie = &movies[index];
        movie->ratings[movie->num_ratings] = rating;
        movie->num_ratings++;
        int sum = 0;
        int i;
        for (i = 0; i < movie->num_ratings; i++) {
            sum += movie->ratings[i];
        }
        movie->rating_avg = (float)sum / movie->num_ratings;
        printf("Rating added for %s: %d\n", title, rating);
    } else {
        printf("Movie not found: %s\n", title);
    }
}

void list_movies() {
    int i;
    for (i = 0; i < num_movies; i++) {
        struct Movie movie = movies[i];
        printf("%s (%d) - %d ratings, average rating %.1f\n", movie.title, movie.year, movie.num_ratings, movie.rating_avg);
    }
}

int main() {
    add_movie("The Matrix", 1999);
    add_movie("Forrest Gump", 1994);
    add_movie("The Shawshank Redemption", 1994);

    rate_movie("The Matrix", 5);
    rate_movie("The Matrix", 4);
    rate_movie("The Shawshank Redemption", 5);
    rate_movie("Forrest Gump", 5);
    rate_movie("Forrest Gump", 3);

    list_movies();

    return 0;
}