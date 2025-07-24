//FormAI DATASET v1.0 Category: Image Classification system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 1000
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int label;
} Image;

Image images[MAX_IMAGES];
int num_images = 0;

int main() {
    // Read in filenames and labels from a file
    FILE* file = fopen("images.txt", "r");
    char filename[MAX_FILENAME_LENGTH];
    int label;
    while (fscanf(file, "%s %d", filename, &label) != EOF) {
        strcpy(images[num_images].filename, filename);
        images[num_images].label = label;
        num_images++;
    }
    fclose(file);

    // Classify each image
    for (int i = 0; i < num_images; i++) {
        char command[100];
        sprintf(command, "python classify.py %s", images[i].filename);
        FILE* process = popen(command, "r");
        char output[10] = {0};
        fgets(output, 10, process);
        images[i].label = atoi(output);
        pclose(process);
    }

    // Output the final results
    for (int i = 0; i < num_images; i++) {
        printf("%s was classified as label %d\n", images[i].filename, images[i].label);
    }

    return 0;
}