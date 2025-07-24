//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>

// Function to convert decimal to binary
void decToBin(int num, int binaryArr[]) {
    int index = 0;
    while (num > 0) {
        binaryArr[index] = num % 2;
        num /= 2;
        index++;
    }
}

// Function to convert binary to decimal
int binToDec(int binaryArr[]) {
    int num = 0, power = 1;
    for (int i = 0; i < 8; i++) {
        num += binaryArr[i] * power;
        power *= 2;
    }
    return num;
}

// Function to perform image steganography
void imageSteganography(char imagePath[], char message[]) {
    FILE *imageFile = fopen(imagePath, "r+b");
    
    // Check if file exists
    if (imageFile == NULL) {
        printf("Image file not found!");
        return;
    }
    
    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);
    
    // Calculate image size
    int imageSize = *(int*)&header[2];
    
    // Print image information
    printf("Image width: %d\n", *(int*)&header[18]);
    printf("Image height: %d\n", *(int*)&header[22]);
    printf("Image size: %d\n", imageSize);
    
    // Calculate message length
    int messageLength = 0;
    while (message[messageLength] != '\0') {
        messageLength++;
    }
    messageLength *= 8;
    
    // Check if message can fit in image
    if (messageLength > imageSize * 3) {
        printf("Message is too large to fit in the image!");
        return;
    }
    
    // Convert message length to binary
    int binaryMessageLength[32] = {0};
    decToBin(messageLength, binaryMessageLength);
    
    // Loop through message length and hide it in the image header
    int binaryIndex = 0;
    for (int i = 34; i <= 41; i++) {
        unsigned char byte = header[i];
        for (int j = 0; j < 8; j++) {
            if (binaryMessageLength[binaryIndex] == 1) {
                byte |= 1 << j;
            }
            else {
                byte &= ~(1 << j);
            }
            binaryIndex++;
        }
        header[i] = byte;
        if (binaryIndex >= 32) {
            break;
        }
    }
    
    // Write modified header back to image
    fseek(imageFile, 0, SEEK_SET);
    fwrite(header, sizeof(unsigned char), 54, imageFile);
    
    // Loop through message and hide it in the image pixels
    int pixelIndex = 0, bitIndex = 0;
    while (message[bitIndex] != '\0') {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, imageFile);
        for (int i = 0; i < 3; i++) {
            int binaryArr[8] = {0};
            decToBin(pixel[i], binaryArr);
            if (binaryArr[7] != (message[bitIndex] & 1)) {
                if (binaryArr[7] == 0) {
                    pixel[i]++;
                }
                else {
                    pixel[i]--;
                }
            }
            bitIndex++;
            if (bitIndex >= messageLength) {
                break;
            }
        }
        fwrite(pixel, sizeof(unsigned char), 3, imageFile);
        pixelIndex++;
        if (pixelIndex >= imageSize) {
            break;
        }
    }
    
    printf("Message hidden in image successfully!");
    fclose(imageFile);
}

// Main function
int main() {
    char imagePath[] = "image.bmp";
    char message[] = "This is a secret message.";
    imageSteganography(imagePath, message);
    return 0;
}