//FormAI DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITSIZE 8

// This function convert a decimal number to a binary
char *dec2bin(int dec)
{
    char *bin = (char*)malloc(BITSIZE + 1);
    int i;
    for (i = BITSIZE - 1; i >= 0; i--)
    {
        if (dec % 2 == 0)
            *(bin + i) = '0';
        else
            *(bin + i) = '1';
        dec /= 2;
    }
    *(bin + BITSIZE) = '\0';
    return bin;
}

// This function convert a binary to a decimal number
int bin2dec(const char *bin, int index)
{
    int total = 0, i;
    for (i = 0; i < BITSIZE; i++)
    {
        total *= 2;
        if (*(bin + index) == '1')
            total += 1;
        index++;
    }
    return total;
}

// This function hide the secret message into the image
void hide(char *source, char *destination, char *message)
{
    FILE *fptrs, *fptrd;
    int i, j, c, len;
    char *messageToBinary;
    len = strlen(message);
    messageToBinary = (char*)malloc(len * BITSIZE + 1);
    for (i = 0; i < len; i++)
    {
        char *bin = dec2bin(*(message + i));
        strcat(messageToBinary, bin);
        free(bin);
    }
    *(messageToBinary + len * BITSIZE) = '\0';

    if ((fptrs = fopen(source, "rb")) == NULL)
    {
        printf("Source image not found.\n");
        return;
    }
    if ((fptrd = fopen(destination, "wb")) == NULL)
    {
        printf("Destination image not found.\n");
        return;
    }

    while ((c = fgetc(fptrs)) != EOF)
    {
        char *bin = dec2bin(c);
        if (len > 0) // Need to hide bits
        {
            for (j = 0; j < BITSIZE; j++)
            {
                if (*(messageToBinary + 0) != '\0')
                {
                    *(bin + j) = *(messageToBinary + 0);
                    messageToBinary++;
                }
                else
                    goto Outer;
            }
            len--;
        }
      Outer:
        fputc(bin2dec(bin, 0), fptrd);
        free(bin);
    }

    if (len > 0)
        printf("Destination image not large enough to hide the message. Try a larger image please.<br>");

    fclose(fptrs);
    fclose(fptrd);
}

// This function extract the secret message from the image
void extract(char *source, char *destination)
{
    FILE *fptrs, *fptrd;
    int i, j, c;
    char *message = (char*)malloc(1000);
    char *bin;
    int counter = 0;

    if ((fptrs = fopen(source, "rb")) == NULL)
    {
        printf("Source image not found.<br>");
        return;
    }
    if ((fptrd = fopen(destination, "w")) == NULL)
    {
        printf("Destination image not found.<br>");
        return;
    }

    while ((c = fgetc(fptrs)) != EOF)
    {
        bin = dec2bin(c);
        for (j = 0; j < BITSIZE; j++)
        {
            *(message + counter) = *(bin + j);
            counter++;
            if (counter % BITSIZE == 0)
            {
                int value = bin2dec(message, counter - BITSIZE);
                if (value == 0)
                    goto Outer;
                printf("%c", value);
                fprintf(fptrd, "%c", value);
            }
        }
        free(bin);
    }

  Outer:
    fclose(fptrs);
    fclose(fptrd);
}

// Main method
int main()
{
    char *source = "funny-cat.jpg";
    char *destination = "hidden-cat.jpg";
    char *message = "Hi, I'm a cat, and I hate dogs!";

    printf("Hiding message...\n");
    hide(source, destination, message);
    printf("Message hidden in image funny-cat.jpg successfuly!\n");

    printf("Extracting message...\n");
    extract(destination, "extracted-message.txt");
    printf("\n");

    return 0;
}