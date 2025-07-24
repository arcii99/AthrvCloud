//FormAI DATASET v1.0 Category: Image Classification system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Image Classification System\n");
    printf("----------------------------------------\n");
    printf("Please enter the image file name you want to classify: ");

    char* file_name = malloc(50 * sizeof(char));
    scanf("%s", file_name);

    int file_length = strlen(file_name);
    char file_ext[5];
    memcpy(file_ext, &file_name[file_length-3], 3);
    file_ext[3] = '\0';

    if(strcmp(file_ext, "jpeg") == 0 || strcmp(file_ext, "jpg") == 0 || strcmp(file_ext, "png") == 0) {
        printf("File %s is a valid image file.\n", file_name);
        printf("Please wait while the image is being classified...\n");

        // Perform image classification algorithm here

        printf("Classification complete.\n");
    } else {
        printf("File %s is not a valid image file.\n", file_name);
        printf("Please provide a valid image file.\n");
    }

    free(file_name);
    return 0;
}