//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the Digital Watermarking Program\n");

    //Declaration of Variables
    char message[] = "This is my secret message!";
    int key = 123456789;
    int encoded_message[1000];
    int decoded_message[1000];

    //Encoding the Message
    printf("Encoding the message...\n");

    for(int i=0; i<strlen(message); i++){
        encoded_message[i] = message[i] + key;
    }

    printf("Encoded Message: \n");

    for(int i=0; i<strlen(message); i++){
        printf("%d ", encoded_message[i]);
    }

    printf("\n");

    //Decoding the Message
    printf("Decoding the message...\n");

    for(int i=0; i<strlen(message); i++){
        decoded_message[i] = encoded_message[i] - key;
    }

    printf("Decoded Message: ");

    for(int i=0; i<strlen(message); i++){
        printf("%c", decoded_message[i]);
    }

    printf("\n");

    return 0;
}