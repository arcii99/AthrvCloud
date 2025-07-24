//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define WATERMARK "Hello World"
#define LEN_WM strlen(WATERMARK)

int main()
{
    char message[MAX_LEN];
    char *wateredMessage;

    printf("Enter your message: ");
    fgets(message, MAX_LEN, stdin);

    wateredMessage = (char*) malloc(MAX_LEN + LEN_WM + 1);

    if(wateredMessage == NULL)
    {
        printf("Memory allocation error.");
        return 1;
    }

    strcpy(wateredMessage, message);
    strcat(wateredMessage, WATERMARK);

    printf("\nYour message with watermark: \n%s", wateredMessage);

    free(wateredMessage);

    return 0;
}