//FormAI DATASET v1.0 Category: Image Classification system ; Style: inquisitive
#include <stdio.h>

int main() {
    printf("Welcome to our Image Classification System!\n");
    printf("Please enter the name of the image you want to classify: ");

    char filename[100];
    scanf("%s", filename);

    // perform image classification here...

    printf("The image %s has been classified as a: ", filename);
    printf("dog"); // just a placeholder for the classification result

    return 0;
}