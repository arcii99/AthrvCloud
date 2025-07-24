//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define MAX_WATERMARK_LENGTH 50
#define MAX_DIGITS 10

char* addWatermark(char* message, char* watermark){
    int counter = 0;
    char* newMessage = (char*)malloc(sizeof(char) * MAX_MESSAGE_LENGTH);

    for (int i=0; i<strlen(message); i++){
        if (message[i] == ' '){
            for (int j=0; j<strlen(watermark); j++){
                newMessage[counter++] = watermark[j];
            }
        } 
        newMessage[counter++] = message[i];
    }

    newMessage[counter] = '\0';

    return newMessage;
}

char* extractWatermark(char* message){
    int digitsCounter = 0;
    int watermarkCounter = 0;
    char* watermark = (char*)malloc(sizeof(char) * MAX_WATERMARK_LENGTH);
    char* digits = (char*)malloc(sizeof(char) * MAX_DIGITS);

    for (int i=0; i<strlen(message); i++){
        if (message[i] >= '0' && message[i] <= '9'){
            digits[digitsCounter++] = message[i];
        } else if (digitsCounter > 0) {
            digits[digitsCounter] = '\0';
            i = i - digitsCounter;

            digitsCounter = 0;
            int index = atoi(digits);

            for (int j=0; j<index; j++){
                watermark[watermarkCounter++] = message[++i];
            }
        }
    }

    watermark[watermarkCounter] = '\0';

    free(digits);

    return watermark;
}

int main(){
    char* message = "The future is now";
    char* watermark = "CYBERPUNK";
    char* newMessage = addWatermark(message, watermark);

    printf("Message with watermark: %s\n", newMessage);

    char* extractedWatermark = extractWatermark(newMessage);

    printf("Extracted watermark: %s\n", extractedWatermark);

    free(newMessage);
    free(extractedWatermark);
    
    return 0;
}