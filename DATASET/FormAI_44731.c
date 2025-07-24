//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include<stdio.h>
#include<math.h>
#include<string.h>

/*Function to get the binary representation of a character*/
void getBinary(char c, char binary[]) {
    int val = (int) c;
    for (int i = 7; i >= 0; i--) {
        if (val >= pow(2, i)) {
            binary[7-i] = '1';
            val -= pow(2, i);
        }
        else
            binary[7-i] = '0';
    }
}

int main() {

    /*Original message*/
    char message[] = "The quick brown fox jumps over the lazy dog.";

    /*Watermark to be added*/
    char watermark[] = "This is a digital watermark.";

    /*Length of message*/
    int message_len = strlen(message);

    /*Length of watermark*/
    int watermark_len = strlen(watermark);

    /*Creating the binary representation of the watermark*/
    char binary_watermark[watermark_len*8];
    for (int i = 0; i < watermark_len; i++) {
        char binary[8] = "00000000";
        getBinary(watermark[i], binary);
        strcat(binary_watermark, binary);
    }

    /*Adding the watermark*/
    char new_message[message_len + watermark_len];
    int j = 0;
    for (int i = 0; i < message_len; i++) {
        /*If there are enough characters left in the message to add the watermark, add it*/
        if (i == message_len-watermark_len && j == 0) {
            strcat(new_message, watermark);
            break;
        }
        new_message[i+j] = message[i];
        /*Every 8 characters, add the binary watermark*/
        if ((i+1+j) % 8 == 0) {
            new_message[i+j+1] = binary_watermark[(i+1+j)/8 - 1];
            j++; //Increase j to account for the added character
        }
    }

    /*Printing the new message with the added watermark*/
    printf("Original message: %s\n", message);
    printf("Watermark added: %s\n", watermark);
    printf("New message with watermark: %s\n", new_message);

    return 0;
}