//FormAI DATASET v1.0 Category: Image compression ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to our Image compression program! Let's make your images extra small, because size DOES matter!\n");

    int original_size = 0;
    printf("Enter the original size of your image: ");
    scanf("%d", &original_size);

    if (original_size <= 0)
    {
        printf("Invalid image size. Please try again later.\n");
        return 0;
    }

    int compressed_size = original_size / 10;

    printf("Great news! We've compressed your image to %d bytes! Now you can fit even more images on your storage device, or impress your friends with your tiny, tiny photos!\n", compressed_size);

    printf("Would you like to see a comparison of the original and compressed image sizes? (y/n): ");

    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y')
    {
        printf("Original image size: %d bytes\n", original_size);
        printf("Compressed image size: %d bytes\n", compressed_size);

        if (compressed_size < original_size)
        {
            printf("See? Size DOES matter!\n");
        }
        else
        {
            printf("Oops, looks like our compression algorithm needs a little work...\n");
        }
    }
    else
    {
        printf("Okay, suit yourself. But just know that you're missing out on all the fun of comparing image sizes!\n");
    }

    printf("Thanks for using our Image compression program! And remember, it's not about the size of the image, it's about how you use it!\n");

    return 0;
}