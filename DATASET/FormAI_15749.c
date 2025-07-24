//FormAI DATASET v1.0 Category: Image Classification system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *image_file;
    char *image_name = "example.jpg";
   
    image_file = fopen(image_name , "r");
    
    if(image_file == NULL) {
        printf("Unable to open image %s\n", image_name);
        exit(1);
    }
    
    //Code to read image data into memory

    fclose(image_file);

    return 0;
}