//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void extractMetadata(char *filename, char *metadata[]);
void printMetadata(char *metadata[]);

int main() {
    char *filename = "example.mp3";
    char *metadata[10];
    
    extractMetadata(filename, metadata);
    printMetadata(metadata);
    
    return 0;
}

void extractMetadata(char *filename, char *metadata[]) {
    // Simulating metadata extraction from MP3 file by randomly generating strings
    char *title = "Example Song";
    char *artist = "John Doe";
    char *album = "My Album";
    char *year = "2021";
    char *genre = "Rock";
    
    // Storing metadata in array
    metadata[0] = title;
    metadata[1] = artist;
    metadata[2] = album;
    metadata[3] = year;
    metadata[4] = genre;
    
    // Printing message and returning
    printf("Metadata extracted successfully!\n");
    return;
}

void printMetadata(char *metadata[]) {
    // Printing each piece of metadata
    printf("Title: %s\n", metadata[0]);
    printf("Artist: %s\n", metadata[1]);
    printf("Album: %s\n", metadata[2]);
    printf("Year: %s\n", metadata[3]);
    printf("Genre: %s\n", metadata[4]);
    
    // Printing message indicating end of metadata
    printf("End of metadata.\n");
    return;
}