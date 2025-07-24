//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Struct for metadata extraction
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    double duration;
} Metadata;

// Function to extract metadata from a file
Metadata extractMetadata(char *filename) {
    Metadata metadata;
    metadata.title = "Unknown Title";
    metadata.artist = "Unknown Artist";
    metadata.album = "Unknown Album";
    metadata.year = 0;
    metadata.duration = 0.0;
    
    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return metadata;
    }
    
    // Read file line by line
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Look for metadata tags
        if (strncmp(line, "TITLE=", 6) == 0) {
            metadata.title = strdup(line + 6);
            metadata.title[strlen(metadata.title) - 1] = '\0';
        } else if (strncmp(line, "ARTIST=", 7) == 0) {
            metadata.artist = strdup(line + 7);
            metadata.artist[strlen(metadata.artist) - 1] = '\0';
        } else if (strncmp(line, "ALBUM=", 6) == 0) {
            metadata.album = strdup(line + 6);
            metadata.album[strlen(metadata.album) - 1] = '\0';
        } else if (strncmp(line, "DATE=", 5) == 0) {
            metadata.year = atoi(line + 5);
        } else if (strncmp(line, "DURATION=", 9) == 0) {
            metadata.duration = atof(line + 9);
        }
    }
    
    // Close file
    fclose(file);
    
    // Return extracted metadata
    return metadata;
}

int main() {
    // Test metadata extraction
    char *filename = "song.mp3";
    Metadata metadata = extractMetadata(filename);
    
    // Print extracted metadata
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);
    printf("Duration: %f\n", metadata.duration);
    
    return 0;
}