//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store metadata information
typedef struct {
    char* artist;
    char* song_title;
    char* album_title;
    int year;
} metadata;

metadata extract_metadata(const char* file_path) {
    metadata meta = {"", "", "", 0};
    // Extract metadata from file
    // ...
    // Example code to parse file name for metadata information
    char* file_name = strrchr(file_path, '/');
    if (file_name == NULL)
        file_name = (char*)file_path; // If no directories in file path
    else
        file_name++; // Move past '/'
    char* dot = strrchr(file_name, '.');
    if (dot == NULL)
        return meta; // No file extension, cannot determine metadata
    char* hyphen = strchr(file_name, '-');
    if (hyphen == NULL)
        return meta; // No hyphen, cannot determine metadata
    *dot = '\0'; // Remove file extension from file name
    hyphen++; // Move past hyphen
    int year = atoi(hyphen);
    if (year <= 0)
        return meta; // Invalid year, cannot determine metadata
    meta.year = year;
    *hyphen = '\0'; // Null terminate year
    char* album_title = hyphen + 1;
    hyphen = strchr(album_title, '-');
    if (hyphen == NULL)
        return meta; // No second hyphen, cannot determine metadata
    *hyphen = '\0'; // Null terminate album title
    char* song_title = hyphen + 1;
    hyphen = strchr(song_title, '-');
    if (hyphen == NULL)
        return meta; // No third hyphen, cannot determine metadata
    *hyphen = '\0'; // Null terminate song title
    char* artist = file_name;
    meta.artist = artist;
    meta.song_title = song_title;
    meta.album_title = album_title;
    return meta;
}

int main() {
    const char* file_path = "/music_library/Imagine-Dragons-2013-Night-Visions-Radioactive.mp3";
    metadata meta = extract_metadata(file_path);
    printf("Artist: %s\n", meta.artist);
    printf("Song title: %s\n", meta.song_title);
    printf("Album title: %s\n", meta.album_title);
    printf("Year: %d\n", meta.year);
    return 0;
}