//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to hold metadata information
typedef struct {
    char artist[128];
    char album[128];
    char title[128];
    int year;
    int track_num;
} metadata;

// Function to extract metadata
metadata extract_metadata(const char *path_to_file) {
    metadata data;
    // Open the file in binary mode
    FILE *f = fopen(path_to_file, "rb");
    if (f) {
        // Read the ID3v2 header
        char header[10];
        fread(header, sizeof(char), 10, f);
        if (strncmp(header, "ID3", 3) == 0) {
            // Get the version number
            int version = header[3];
            // Get the flags
            int flags = header[5];
            // Get the size of the ID3v2 tag
            int size = 0;
            for (int i=6; i<10; i++) {
                size = (size << 7) + (header[i] & 0x7F);
            }
            // Read the metadata
            while (size > 0) {
                // Read the tag header
                char tag_header[10];
                fread(tag_header, sizeof(char), 10, f);
                // Get the tag size
                int tag_size = 0;
                for (int i=4; i<8; i++) {
                    tag_size = (tag_size << 7) + (tag_header[i] & 0x7F);
                }
                // Read the tag data
                char tag_data[tag_size+1];
                fread(tag_data, sizeof(char), tag_size, f);
                tag_data[tag_size] = '\0';
                // Process the tag data
                if (strncmp(tag_header, "TPE1", 4) == 0) {
                    strcpy(data.artist, tag_data);
                } else if (strncmp(tag_header, "TALB", 4) == 0) {
                    strcpy(data.album, tag_data);
                } else if (strncmp(tag_header, "TIT2", 4) == 0) {
                    strcpy(data.title, tag_data);
                } else if (strncmp(tag_header, "TYER", 4) == 0) {
                    data.year = atoi(tag_data);
                } else if (strncmp(tag_header, "TRCK", 4) == 0) {
                    data.track_num = atoi(tag_data);
                }
                // Update the size
                size -= (10 + tag_size);
            }
        }
        // Close the file
        fclose(f);
    }
    return data;
}

int main() {
    metadata data = extract_metadata("example.mp3");
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Title: %s\n", data.title);
    printf("Year: %d\n", data.year);
    printf("Track number: %d\n", data.track_num);
    return 0;
}