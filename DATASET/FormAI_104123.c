//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[100];
    char director[50];
    int year;
};

int main() {
    FILE *fp;
    struct movie mv;
    char *filename = "movies.dat";

    // create file and write data to it
    fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    strcpy(mv.title, "The Shawshank Redemption");
    strcpy(mv.director, "Frank Darabont");
    mv.year = 1994;
    fwrite(&mv, sizeof(struct movie), 1, fp);

    strcpy(mv.title, "The Godfather");
    strcpy(mv.director, "Francis Ford Coppola");
    mv.year = 1972;
    fwrite(&mv, sizeof(struct movie), 1, fp);

    strcpy(mv.title, "The Dark Knight");
    strcpy(mv.director, "Christopher Nolan");
    mv.year = 2008;
    fwrite(&mv, sizeof(struct movie), 1, fp);

    fclose(fp);

    // read data from file
    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    printf("%-30s%-30s%-10s\n", "Title", "Director", "Year");
    printf("--------------------------------------------------------\n");
    while(fread(&mv, sizeof(struct movie), 1, fp) == 1) {
        printf("%-30s%-30s%-10d\n", mv.title, mv.director, mv.year);
    }
    fclose(fp);
    return 0;
}