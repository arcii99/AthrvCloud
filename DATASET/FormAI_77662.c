//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to generate hash value of a given string
int hashString(char *str)
{
    int hashVal = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        hashVal = hashVal + str[i];
    }
    return hashVal;
}

int main()
{
    char message[100], watermark[20];

    // get message and watermark from user
    printf("Enter message: ");
    scanf("%[^\n]%*c", message);
    printf("Enter watermark: ");
    scanf("%[^\n]%*c", watermark);

    // generate hash value of watermark string
    int watermarkHash = hashString(watermark);

    // loop through each character in message and add watermark hash value
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        int charHash = hashString(&message[i]);
        message[i] = (char) (charHash ^ watermarkHash);
    }

    // display watermarked message
    printf("Watermarked message: %s\n", message);
    
    return 0;
}