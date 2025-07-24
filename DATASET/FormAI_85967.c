//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>

typedef struct {
    char artist[50];
    char album[50];
    int year;
} Metadata;

void extract_metadata(FILE *file, Metadata *metadata) {
    fseek(file, -sizeof(Metadata), SEEK_END);
    fread(metadata, 1, sizeof(Metadata), file);
}

int main() {
    FILE *file = fopen("song.mp3", "rb");
    Metadata metadata;
    extract_metadata(file, &metadata);
    printf("Artist: %s\nAlbum: %s\nYear: %d\n", metadata.artist, metadata.album, metadata.year);
    fclose(file);

    return 0;
}