//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

//function to encode the message with watermark
void encode(char message[], char watermark[]) {
    int i, j = 0;
    int messageLength = strlen(message);
    int watermarkLength = strlen(watermark);
    
    //create a new string to store the result
    char result[MAX_SIZE];

    //iterate through the message string and add the watermark
    for (i = 0; i < messageLength; i++) {
        result[i] = message[i];
        
        //add the watermark, skipping any spaces
        if (j < watermarkLength && message[i] != ' ') {
            result[i] = watermark[j++];
        }

        //reset the watermark index once it has been completely added
        if (j == watermarkLength) {
            j = 0;
        }
    }

    //print the encoded message
    printf("Encoded Message: %s\n", result);
}

//function to decode the message and extract the watermark
void decode(char message[]) {
    int i, j = 0;
    int messageLength = strlen(message);
    
    //create a new string to store the extracted watermark
    char watermark[MAX_SIZE];
    
    //iterate through the message string and extract the watermark
    for (i = 0; i < messageLength; i++) {
        
        //add non-space characters to the watermark
        if (message[i] != ' ') {
            watermark[j++] = message[i];
        }
    }
    
    //terminate the watermark string with a null character
    watermark[j] = '\0';

    //print the extracted watermark
    printf("Extracted Watermark: %s\n", watermark);
}

//main function
int main() {

    //declare message and watermark strings
    char message[MAX_SIZE], watermark[MAX_SIZE];

    //get the message and watermark from user input
    printf("Enter Message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter Watermark: ");
    fgets(watermark, sizeof(watermark), stdin);
    
    //remove trailing newlines from user input
    message[strcspn(message, "\n")] = 0;
    watermark[strcspn(watermark, "\n")] = 0;

    printf("Message: %s\n", message);
    printf("Watermark: %s\n", watermark);

    //encode the message with the watermark and print the result
    encode(message, watermark);

    //decode the message and extract the watermark
    decode(message);

    return 0;
}