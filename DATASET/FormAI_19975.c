//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for metadata
typedef struct {
    char* filename;
    char* filetype;
    int filesize;
    int width;
    int height;
    time_t date_created;
} metadata;

// Function to extract metadata from an image file
metadata extract_image_metadata(char* filename) {
    metadata image_metadata;
    image_metadata.filename = filename;
    image_metadata.filetype = "image";

    // Code to extract image dimensions and file size
    // ...

    return image_metadata;
}

// Function to extract metadata from a video file
metadata extract_video_metadata(char* filename) {
    metadata video_metadata;
    video_metadata.filename = filename;
    video_metadata.filetype = "video";

    // Code to extract video duration and file size
    // ...

    return video_metadata;
}

// Function to extract metadata from an audio file
metadata extract_audio_metadata(char* filename) {
    metadata audio_metadata;
    audio_metadata.filename = filename;
    audio_metadata.filetype = "audio";

    // Code to extract audio length and file size
    // ...

    return audio_metadata;
}

// Main function to test the metadata extractor
int main() {
    char* filename = "example_image.jpg";
    metadata extracted_metadata;

    // Extract metadata from the image file
    extracted_metadata = extract_image_metadata(filename);

    // Print out the extracted metadata
    printf("Filename: %s\n", extracted_metadata.filename);
    printf("File type: %s\n", extracted_metadata.filetype);
    printf("File size: %d\n", extracted_metadata.filesize);
    printf("Width: %d\n", extracted_metadata.width);
    printf("Height: %d\n", extracted_metadata.height);
    printf("Date created: %s\n", ctime(&extracted_metadata.date_created));

    return 0;
}