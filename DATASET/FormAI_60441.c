//FormAI DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 10000
#define BYTE_SIZE 8

char* messageToBinary(char* message, int messageLength);
char* binaryToMessage(char* binary, int binaryLength);
void encodeMessage(char* binaryImage, char* binaryMessage, int messageLength, int imageLength);
char* decodeMessage(char* binaryImage, int imageLength, int messageLength);

int main() {
    FILE* imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Error opening image file!");
        return 1;
    }

    char imageBytes[MAX_IMAGE_SIZE];
    int bytesRead = fread(imageBytes, sizeof(char), MAX_IMAGE_SIZE, imageFile);

    fclose(imageFile);

    if (bytesRead < 54) {
        printf("The image file is not a valid BMP file.");
        return 1;
    }

    char* imageHeader = (char*) malloc(54 * sizeof(char));
    memcpy(imageHeader, imageBytes, 54);

    char* binaryImage = (char*) malloc((bytesRead - 54) * BYTE_SIZE * sizeof(char));
    for (int i = 54; i < bytesRead; i++) {
        for (int j = 0; j < BYTE_SIZE; j++) {
            binaryImage[(i - 54) * BYTE_SIZE + j] = ((imageBytes[i] >> (BYTE_SIZE - 1 - j)) & 1) + '0';
        }
    }

    FILE* messageFile = fopen("message.txt", "r");
    if (messageFile == NULL) {
        printf("Error opening message file!");
        return 1;
    }

    char message[MAX_MESSAGE_SIZE];
    int messageLength = 0;
    char c = fgetc(messageFile);
    while (c != EOF && messageLength < MAX_MESSAGE_SIZE) {
        message[messageLength++] = c;
        c = fgetc(messageFile);
    }

    char* binaryMessage = messageToBinary(message, messageLength);

    if (strlen(binaryMessage) > strlen(binaryImage)) {
        printf("The message is too big to fit in the image!");
        return 1;
    }

    encodeMessage(binaryImage, binaryMessage, strlen(binaryMessage), strlen(binaryImage));

    FILE* encodedImageFile = fopen("encoded_image.bmp", "wb");
    fwrite(imageHeader, sizeof(char), 54, encodedImageFile);
    for (int i = 0; i < strlen(binaryImage) / BYTE_SIZE; i++) {
        char byte = 0;
        for (int j = 0; j < BYTE_SIZE; j++) {
            byte |= (binaryImage[i * BYTE_SIZE + j] - '0') << (BYTE_SIZE - 1 - j);
        }
        fwrite(&byte, sizeof(char), 1, encodedImageFile);
    }
    fclose(encodedImageFile);

    free(imageHeader);
    free(binaryImage);
    free(binaryMessage);

    FILE* encodedImageFile2 = fopen("encoded_image.bmp", "rb");
    if (encodedImageFile2 == NULL) {
        printf("Error opening encoded image file!");
        return 1;
    }

    int encodedImageBytesRead = fread(imageBytes, sizeof(char), MAX_IMAGE_SIZE, encodedImageFile2);
    fclose(encodedImageFile2);

    char* binaryImage2 = (char*) malloc((encodedImageBytesRead - 54) * BYTE_SIZE * sizeof(char));
    for (int i = 54; i < encodedImageBytesRead; i++) {
        for (int j = 0; j < BYTE_SIZE; j++) {
            binaryImage2[(i - 54) * BYTE_SIZE + j] = ((imageBytes[i] >> (BYTE_SIZE - 1 - j)) & 1) + '0';
        }
    }

    char* decodedMessage = decodeMessage(binaryImage2, strlen(binaryImage2), strlen(binaryMessage));
    printf("Decoded message: %s", binaryToMessage(decodedMessage, strlen(decodedMessage)));

    free(binaryImage2);
    free(decodedMessage);

    return 0;
}

char* messageToBinary(char* message, int messageLength) {
    char* binary = (char*) malloc(messageLength * BYTE_SIZE * sizeof(char));
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < BYTE_SIZE; j++) {
            binary[i * BYTE_SIZE + j] = ((message[i] >> (BYTE_SIZE - 1 - j)) & 1) + '0';
        }
    }
    return binary;
}

char* binaryToMessage(char* binary, int binaryLength) {
    char* message = (char*) malloc((binaryLength / BYTE_SIZE) * sizeof(char));
    for (int i = 0; i < binaryLength / BYTE_SIZE; i++) {
        char byte = 0;
        for (int j = 0; j < BYTE_SIZE; j++) {
            byte |= (binary[i * BYTE_SIZE + j] - '0') << (BYTE_SIZE - 1 - j);
        }
        message[i] = byte;
    }
    message[binaryLength / BYTE_SIZE] = '\0';
    return message;
}

void encodeMessage(char* binaryImage, char* binaryMessage, int messageLength, int imageLength) {
    for (int i = 0; i < messageLength; i++) {
        binaryImage[i * 8 + 7] = binaryMessage[i];
    }
}

char* decodeMessage(char* binaryImage, int imageLength, int messageLength) {
    char* binaryMessage = (char*) malloc(messageLength * sizeof(char));
    for (int i = 0; i < messageLength; i++) {
        binaryMessage[i] = binaryImage[i * 8 + 7];
    }
    return binaryMessage;
}