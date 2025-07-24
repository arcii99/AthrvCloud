//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to print the digital watermark
void printWatermark(char* message) {
    printf("********************************************\n");
    printf("*                                          *\n");
    printf("*  %s  *\n", message);
    printf("*                                          *\n");
    printf("********************************************\n");
}

//Function to generate random numbers for the digital watermark
int generateRandom(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    char message[] = "RETRO DIGITAL WATERMARKING";
    int i, j, k, random;

    //Printing the original message
    printf("\nOriginal Message:\n");
    printWatermark(message);

    //Generating and printing the digital watermark by changing ASCII values of characters
    for(i=0; message[i]!='\0'; i++) {
        random = generateRandom(1, 3);
        if(random == 1) {
            message[i] = message[i] - 1;
        }
        else if(random == 2) {
            message[i] = message[i] + 1;
        }
        else {
            message[i] = message[i] - 2;
        }
    }
    printf("\nWatermarked Message:\n");
    printWatermark(message);

    //Decrypting the digital watermark to get back the original message
    for(j=0; message[j]!='\0'; j++) {
        random = generateRandom(1, 3);
        if(random == 1) {
            message[j] = message[j] + 1;
        } 
        else if(random == 2) {
            message[j] = message[j] - 1;
        }
        else {
            message[j] = message[j] + 2;
        }
    }
    printf("\nDecrypted Message:\n");
    printWatermark(message);

    return 0;
}