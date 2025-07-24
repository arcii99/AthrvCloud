//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1000
#define MAX_WATERMARK_LEN 50

// Function to generate a random alphanumeric string
void generateWatermark(char *watermark){
    int i, randNum;

    for(i=0; i < MAX_WATERMARK_LEN-1; i++){
        randNum = rand() % 62;  // Generate a random number from 0 to 61
        if(randNum < 26){
            watermark[i] = 'A' + randNum;  // For 0-25, map to A-Z
        }
        else if(randNum < 52){
            watermark[i] = 'a' + (randNum - 26);  // For 26-51, map to a-z
        }
        else{
            watermark[i] = '0' + (randNum - 52);  // For 52-61, map to 0-9
        }
    }
    watermark[MAX_WATERMARK_LEN-1] = '\0';  // Terminate the string with null character
}

// Function to embed watermark in the message
void embedWatermark(char *message, char *watermark){
    int i, j;

    for(i=0, j=0; message[i]!='\0' && watermark[j]!='\0'; i++){
        if(message[i] == ' ' || message[i] == '\n' || message[i] == '\t'){
            continue;  // Skip whitespace characters
        }
        message[i] = (message[i] & 0xFE) | ((watermark[j] >> 7) & 0x01);
        message[i+1] = (message[i+1] & 0x01) | ((watermark[j] << 1) & 0xFE);
        j++;
    }
}

// Function to extract watermark from the message
void extractWatermark(char *message, char *watermark){
    int i, j, k, bit;

    for(i=0, j=0, k=0; message[i]!='\0' && k < MAX_WATERMARK_LEN-1; i+=2){
        bit = ((message[i] & 0x01) << 7) | ((message[i+1] >> 1) & 0x7F);
        watermark[k++] = bit;
    }
    watermark[MAX_WATERMARK_LEN-1] = '\0';  // Terminate the string with null character
}

int main(){
    char message[MAX_MSG_LEN], watermark[MAX_WATERMARK_LEN];

    printf("Enter a text message (maximum length %d characters): ", MAX_MSG_LEN);
    fgets(message, MAX_MSG_LEN, stdin);

    generateWatermark(watermark);
    printf("\nGenerated watermark: %s\n", watermark);

    embedWatermark(message, watermark);

    printf("\nEmbedding watermark...\n");

    printf("\nWatermarked message: %s\n", message);

    char extractedWatermark[MAX_WATERMARK_LEN];
    extractWatermark(message, extractedWatermark);
    printf("\nExtracted watermark: %s\n", extractedWatermark);

    if(strcmp(extractedWatermark, watermark) == 0){
        printf("\nWatermark extraction successful\n");
    }
    else{
        printf("\nWatermark extraction failed\n");
    }

    return 0;
}