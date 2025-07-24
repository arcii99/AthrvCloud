//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include<stdio.h>

int main()
{
    char ascii[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int threshold[] = {0, 25, 50, 75, 100, 125, 150, 175, 200, 225};
    char img[20][20]; //Each pixel of image is represented by one character
    int i, j;

    //Code to read the image and store in img array
    printf("Enter the image details:\n");
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            scanf("%c", &img[i][j]);
        }
    }

    //Code to convert image to ASCII art
    printf("\nThe ASCII art of the image is:\n");
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            int pixel_value = (int)img[i][j];
            int index = 0;
            while(threshold[index] < pixel_value && index < 9)
            {
                index++;
            }
            printf("%c", ascii[index]);
        }
        printf("\n");
    }

    return 0;
}