//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Open the file to extract metadata
    FILE *file = fopen("love.mp3", "r");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Failed to open file!");
        exit(1);
    }

    // Extract metadata using fseek and fread functions
    fseek(file, -128, SEEK_END);

    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[29];
    char genre;

    fread(tag, sizeof(char), 3, file);
    fread(title, sizeof(char), 30, file);
    fread(artist, sizeof(char), 30, file);
    fread(album, sizeof(char), 30, file);
    fread(year, sizeof(char), 4, file);
    fread(comment, sizeof(char), 29, file);
    fread(&genre, sizeof(char), 1, file);

    // Print the extracted metadata
    printf("Title : %s\n", title);
    printf("Artist : %s\n", artist);
    printf("Album : %s\n", album);
    printf("Year : %s\n", year);
    printf("Comment : %s\n", comment);

    // Close the file
    fclose(file);

    // End the program with a romantic message
    printf("\n\nMy love, just like this program extracted metadata from a file, I extracted you from the world. You are the title that defines me, the artist that colors my life, and the album that's worth my soul. The year we met is engraved in my heart and our love is the comment that feels every space. You are the genre that gives my life meaning. I love you more than words can express. Always yours, my love.\n");

    return 0;
}