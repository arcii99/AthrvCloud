//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
char* artist = ""; 
char* title = ""; 
char* album = ""; 
char* year = ""; 

// Function declaration
void extractMetaData(char* file);

int main() {
    char* song = "My Heart Will Go On.mp3";
    
    // Call function to extract metadata
    extractMetaData(song);

    // Print the extracted metadata
    printf("Artist: %s\n", artist);
    printf("Title: %s\n", title);
    printf("Album: %s\n", album);
    printf("Year: %s\n", year);

    return 0;
}

void extractMetaData(char* file) {
    printf("Extracting metadata from %s...\n", file);
    
    // Simulate reading file and extracting metadata
    artist = "Celine Dion";
    title = "My Heart Will Go On";
    album = "Titanic Soundtrack";
    year = "1997";
    
    printf("Metadata extracted!\n");
}