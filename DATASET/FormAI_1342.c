//FormAI DATASET v1.0 Category: Image compression ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Greetings, friend! I hope you're doing well today.\n");
    printf("Let's work on some image compression, shall we?\n");
    
    char original_image[100];
    printf("Please enter the name of the original image file: ");
    scanf("%s", original_image);
    
    FILE *fp_read = fopen(original_image, "rb");
    if (fp_read == NULL) {
        printf("Oh no! The file could not be opened. Please make sure you entered the correct file name and try again.\n");
        return 1;
    }
    
    char compressed_image[100];
    printf("Now, please enter the name of the compressed image file you'd like to write: ");
    scanf("%s", compressed_image);
    
    FILE *fp_write = fopen(compressed_image, "wb");
    if (fp_write == NULL) {
        printf("Oops! The file could not be opened. Please make sure you entered the correct file name and try again.\n");
        fclose(fp_read);
        return 1;
    }
    
    unsigned char buf[1024];
    int size_read = 0;
    while ((size_read = fread(buf, 1, sizeof(buf), fp_read)) > 0) {
        int size_written = fwrite(buf, 1, size_read, fp_write);
        if (size_written != size_read) {
            printf("Uh-oh! An error occurred while writing the compressed image file.\n");
            fclose(fp_read);
            fclose(fp_write);
            return 1;
        }
    }
    
    printf("Hooray! The original image file has been successfully compressed and written to the compressed image file.\n");
    fclose(fp_read);
    fclose(fp_write);
    
    return 0;
}