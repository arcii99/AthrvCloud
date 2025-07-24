//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
} image_dimensions;

typedef struct {
    char camera_make[20];
    char camera_model[20];
} camera_info;

typedef struct {
    char artist[50];
    char title[50];
    char album[50];
} music_metadata;

int main() {
    // Simulated image with metadata
    unsigned char image[] = {0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    image_dimensions dimensions = {640, 480};
    camera_info info = {"Canon", "EOS Rebel T7i"};

    // Simulated music file with metadata
    unsigned char music[] = {0xFF, 0xF3, 0x18, 0x40};
    music_metadata metadata = {"Led Zeppelin", "Stairway to Heaven", "Led Zeppelin IV"};

    // Extract image metadata
    printf("Image metadata:\n");
    printf("Dimensions: %dx%d\n", dimensions.width, dimensions.height);
    printf("Camera make: %s\n", info.camera_make);
    printf("Camera model: %s\n", info.camera_model);

    // Extract music metadata
    printf("Music metadata:\n");
    printf("Artist: %s\n", metadata.artist);
    printf("Title: %s\n", metadata.title);
    printf("Album: %s\n", metadata.album);

    return 0;
}