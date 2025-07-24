//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    //Initialize variables
    char message[100];
    char watermark[10];
    char encrypted_msg[200];

    //User input
    printf("Enter message to be watermarked: ");
    scanf("%[^\n]", message);
    printf("Enter watermark text (less than 10 characters): ");
    scanf("%s", watermark);

    //Watermark Encryption
    int message_length = strlen(message);
    int watermark_length = strlen(watermark);
    int encryption_key = message_length % watermark_length;
    int j = 0;
    for(int i=0; i<message_length; i++) {
        if(message[i] == ' ') {
            continue;
        }
        encrypted_msg[j] = message[i] + encryption_key;
        j++;
        if(j % watermark_length == 0) {
            for(int k=0; k<watermark_length; k++) {
                encrypted_msg[j] = watermark[k];
                j++;
            }
        }
    }
    encrypted_msg[j] = '\0';

    //Print encrypted message
    printf("Encrypted Watermarked message: %s", encrypted_msg);
    
    return 0;
}