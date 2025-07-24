//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

struct metadata {
    char artist[MAX_LENGTH];
    char title[MAX_LENGTH];
    char album[MAX_LENGTH];
    char year[MAX_LENGTH];
    char genre[MAX_LENGTH];
};

void extract_metadata(FILE *file, struct metadata *meta) {
    char line[MAX_LENGTH];
    
    while (fgets(line, MAX_LENGTH, file)) {
        // Parsing ID3v2 tags
        if (strncmp(line, "TPE1", 4) == 0) {
            strncpy(meta->artist, line+4, MAX_LENGTH);
        } else if (strncmp(line, "TIT2", 4) == 0) {
            strncpy(meta->title, line+4, MAX_LENGTH);
        } else if (strncmp(line, "TALB", 4) == 0) {
            strncpy(meta->album, line+4, MAX_LENGTH);
        } else if (strncmp(line, "TYER", 4) == 0) {
            strncpy(meta->year, line+4, MAX_LENGTH);
        } else if (strncmp(line, "TCON", 4) == 0) {
            strncpy(meta->genre, line+4, MAX_LENGTH);
        }
    }
}

int main() {
    FILE *file = fopen("song.mp3", "rb");
    
    if (!file) {
        printf("Error opening file!");
        return 1;
    }
    
    struct metadata meta;
    memset(&meta, 0, sizeof(meta));
    
    fseek(file, -128, SEEK_END); // ID3v1 tag located at the end of the file
    
    char tag[3];
    fread(tag, sizeof(char), 3, file);
    
    if (strncmp(tag, "TAG", 3) == 0) {
        // Parsing ID3v1 tags
        char buffer[MAX_LENGTH];
        fread(buffer, sizeof(char), MAX_LENGTH, file);
        strncpy(meta.title, buffer, 30);
        strncpy(meta.artist, buffer+30, 30);
        strncpy(meta.album, buffer+60, 30);
        strncpy(meta.year, buffer+90, 4);
        strncpy(meta.genre, buffer+125, 1);
    }
    
    fseek(file, 0, SEEK_SET); // Resetting file pointer
    
    extract_metadata(file, &meta);
    
    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %s\nGenre: %s\n", meta.title, meta.artist, meta.album, meta.year, meta.genre);
    
    fclose(file);
    
    return 0;
}