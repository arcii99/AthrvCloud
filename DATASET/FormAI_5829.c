//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define HEADER_SIZE 54

//Function Declarations
void hide_message(unsigned char image_data[], char message[]);
void extract_message(unsigned char image_data[]);

int main()
{
    FILE *image_file;
    unsigned char image_data[MAX_SIZE];
    char message[MAX_SIZE];

    //Opening the image file
    image_file = fopen("rose.bmp", "rb");
    if(image_file == NULL)
    {
        printf("Error: Unable to open the image file!");
        return 1;
    }

    //Reading the image data into the buffer
    fseek(image_file, HEADER_SIZE, SEEK_SET);
    fread(image_data, MAX_SIZE, 1, image_file);

    //Closing the file
    fclose(image_file);

    //Taking input message from the user
    printf("Enter a romantic message to be hidden in the image: ");
    fgets(message, MAX_SIZE, stdin);

    //Hiding the message in the image
    hide_message(image_data, message);

    //Extracting the hidden message from the image
    printf("Extracting the hidden message...\n");
    extract_message(image_data);

    return 0;
}

//Function to hide message in the image
void hide_message(unsigned char image_data[], char message[])
{
    int i = 0, j = 0;

    while(message[j] != '\0')
    {
        for(int bit = 7; bit >= 0; bit--)
        {
            if(i < MAX_SIZE * 8 && j < strlen(message))
            {
                image_data[i++] &= ~(1 << 0);
                image_data[i++] |= (message[j] & (1 << bit)) >> bit;
            }
        }
        j++;
    }
}

//Function to extract message from the image
void extract_message(unsigned char image_data[])
{
    int i = 0, j = 0;
    char message[MAX_SIZE];

    while(i < MAX_SIZE * 8)
    {
        char ch = 0;

        for(int bit = 0; bit < 8; bit++)
        {
            ch |= ((image_data[i++] & 1) << bit);
        }

        message[j++] = ch;

        if(ch == '\0')
            break;
    }

    printf("\nThe romantic message hidden in the image is: %s", message);
}