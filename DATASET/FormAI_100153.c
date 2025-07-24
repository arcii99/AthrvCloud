//FormAI DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_DATA 512

typedef struct {
    char title[MAX_DATA];
    char director[MAX_DATA];
    char year[MAX_DATA];
} Movie;

typedef struct {
    Movie rows[MAX_ROWS];
    int count;
} Database;

void initialize_database(Database *db) {
    db->count = 0;
}

void add_movie(Database *db, char *title, char *director, char *year) {
    if (db->count < MAX_ROWS) {
        Movie movie = { .title = title, .director = director, .year = year };
        db->rows[db->count] = movie;
        db->count++;
    } else {
        printf("Maximum number of movies reached\n");
    }
}

void list_movies(Database *db) {
    for (int i = 0; i < db->count; i++) {
        printf("%s\t%s\t%s\n", db->rows[i].title, db->rows[i].director, db->rows[i].year);
    }
}

int main() {
    Database db;

    initialize_database(&db);

    add_movie(&db, "Blade Runner", "Ridley Scott", "1982");
    add_movie(&db, "The Terminator", "James Cameron", "1984");

    list_movies(&db);

    return 0;
}