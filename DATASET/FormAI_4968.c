//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function declarations
void hideDataInImage(FILE* image, FILE* output, char* message);
char* extractDataFromImage(FILE* image);
void printImageHeader(unsigned char header[]);
void printData(char* data);

int main() {
    FILE* image = fopen("image.bmp", "rb");
    FILE* output = fopen("output.bmp", "wb");
    
    // Message to be hidden in the image
    char message[] = "This is a secret message!";
    printf("Message to be hidden: %s\n", message);
    
    // Hide the message in the image
    hideDataInImage(image, output, message);
    fclose(output);
    fclose(image);
    
    // Extract the message from the image
    FILE* outputImage = fopen("output.bmp", "rb");
    char* extractedMessage = extractDataFromImage(outputImage);
    printf("Extracted message: %s\n", extractedMessage);
    
    return 0;
}

void hideDataInImage(FILE* image, FILE* output, char* message) {
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    fwrite(header, sizeof(unsigned char), 54, output);
    
    // Get the size of the message to be hidden
    int messageLength = strlen(message);
    printf("Size of message to be hidden: %d\n", messageLength);
    
    srand(time(NULL));
    int start = rand() % (5000 - messageLength);
    printf("Starting index to hide message: %d\n", start);
    
    // Write the message length as a 4-byte integer
    fwrite(&messageLength, sizeof(int), 1, output);
    
    // Write the message to the image
    unsigned char pixelData;
    fseek(image, 54, SEEK_SET);
    for (int i = 0; i < start; i++) {
        fread(&pixelData, sizeof(unsigned char), 1, image);
        fwrite(&pixelData, sizeof(unsigned char), 1, output);
    }
    fwrite(message, sizeof(char), messageLength, output);
    for (int i = start + messageLength; i < 5000; i++) {
        fread(&pixelData, sizeof(unsigned char), 1, image);
        fwrite(&pixelData, sizeof(unsigned char), 1, output);
    }
}

char* extractDataFromImage(FILE* image) {
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    
    // Read the message length from the image
    int messageLength;
    fread(&messageLength, sizeof(int), 1, image);
    printf("Size of message extracted: %d\n", messageLength);
    
    // Allocate memory for the message
    char* message = malloc((messageLength + 1) * sizeof(char));
    
    // Extract the message from the image
    unsigned char pixelData;
    int index = 0;
    while (index < messageLength) {
        fread(&pixelData, sizeof(unsigned char), 1, image);
        message[index++] = pixelData;
    }
    message[messageLength] = '\0';
    
    return message;
}

void printImageHeader(unsigned char header[]) {
    printf("Signature: %c%c\n", header[0], header[1]);
    printf("File size: %d\n", *(int*)&header[2]);
    printf("Reserved1: %d\n", *(short*)&header[6]);
    printf("Reserved2: %d\n", *(short*)&header[8]);
    printf("Data offset: %d\n", *(int*)&header[10]);
    printf("Image width: %d\n", *(int*)&header[18]);
    printf("Image height: %d\n", *(int*)&header[22]);
    printf("Bits per pixel: %d\n", *(short*)&header[28]);
}

void printData(char* data) {
    printf("Data: %s\n", data);
}