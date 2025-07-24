//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a program to digitally watermark your memes to prevent them from being stolen.

int main()
{
    printf("Welcome to Memewater! Your one-stop-shop for digital watermarking your memes to prevent them from being stolen!\n\n");
    printf("Please enter the filename of your meme: ");

    char filename[100];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Sorry, we couldn't find your file. Please double check the filename and try again.\n");
        return 1;
    }

    char *buffer = NULL;
    size_t size = 0;
    ssize_t num_bytes = getline(&buffer, &size, fp);

    printf("Perfect! We've located your meme and it's ready to be watermarked.\n\n");

    char watermark[50];
    printf("Now, please enter your desired watermark: ");
    scanf("%s", watermark);
    
    // The magic happens here- we run the watermarking algorithm to blend your watermark with your meme.
    for (int i = 0; i < strlen(watermark); i++) {
        buffer[i % num_bytes] ^= watermark[i];
    }
    
    // We write the watermarked data back into the file here!
    fp = fopen(filename, "wb");
    fwrite(buffer, sizeof(char), num_bytes, fp);

    printf("\nVoila! Your meme has successfully been watermarked with %s. Now it's safe from theft!\n", watermark);
    printf("Thank you for choosing Memewater. See you next time!\n");

    free(buffer);
    fclose(fp);

    return 0;
}