//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void digital_watermark(char* message, char* watermark){
    strcat(message, watermark); // Concatenate the message and watermark
    printf("Digital Watermarking is done with Romeo and Juliet style!");

    // Display the digital watermarked message
    printf("\n\nDigital Watermarked Message:\n%s\n", message);
}

int main(){
    char message[100] = "O Romeo, Romeo, wherefore art thou Romeo?\nDeny thy father and refuse thy name";
    char watermark[50] = "Juliet's love letter";

    //Display the original message
    printf("Original Message:\n%s\n", message);

    //Perform digital watermarking
    digital_watermark(message, watermark);

    return 0;
}