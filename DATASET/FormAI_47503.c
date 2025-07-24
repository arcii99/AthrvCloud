//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declaration for metadata extraction 
void extract_metadata(char* filename);

int main()
{
    char* filename = "song.mp3"; // change to your desired file name
    extract_metadata(filename);
    return 0;
}

void extract_metadata(char* filename)
{
    FILE* file = fopen(filename, "rb"); // open the file in binary mode
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    // read the first 128 bytes of the file
    char header[128];
    fseek(file, 0, SEEK_SET);
    fread(header, sizeof(char), 128, file);

    // extract the metadata from the header
    char title[31], artist[31], album[31], year[5], comment[31];
    int track, genre;
    strncpy(title, header + 3, 30);
    title[30] = '\0';
    strncpy(artist, header + 33, 30);
    artist[30] = '\0';
    strncpy(album, header + 63, 30);
    album[30] = '\0';
    strncpy(year, header + 93, 4);
    year[4] = '\0';
    strncpy(comment, header + 97, 30);
    comment[30] = '\0';
    track = header[126];
    genre = header[127];

    // print the extracted metadata to the console
    printf("Title: %s\n", title);
    printf("Artist: %s\n", artist);
    printf("Album: %s\n", album);
    printf("Year: %s\n", year);
    printf("Comment: %s\n", comment);
    printf("Track: %d\n", track);
    printf("Genre: %d\n", genre);

    fclose(file); // close the file
}