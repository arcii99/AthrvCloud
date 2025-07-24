//FormAI DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hideMsgInImage(char* imagePath, char* message){
    //Open the image file in binary mode for reading and writing
    FILE * fp = fopen(imagePath, "rb+");
    if(fp == NULL){
        printf("Error opening image file!\n");
        return;
    }

    //Read the header of the image file to determine the size
    unsigned char header[54];
    size_t bytesRead = fread(header, 1, 54, fp);
    if(bytesRead < 54){
        printf("The header of the image file could not be read!\n");
        fclose(fp);
        return;
    }

    //Check if the image is a BMP file
    if(header[0] != 'B' || header[1] != 'M'){
        printf("The image file is not a BMP file!\n");
        fclose(fp);
        return;
    }

    //Calculate the size of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = width * height * 3;

    //Check if the message can be hidden in the image
    int messageSize = strlen(message);
    if(size / 8 < messageSize + 1){
        printf("The message is too large to be hidden in the image!\n");
        fclose(fp);
        return;
    }

    //Hide the message in the image
    int offset = *(int*)&header[10];
    int padding = (4 - (width * 3) % 4) % 4;
    unsigned char * imageData = malloc(size);
    fseek(fp, offset, SEEK_SET);
    fread(imageData, 1, size, fp);
    int index = 0;
    for(int i = 0; i < messageSize; i++){
        for(int j = 0; j < 8; j++){
            int bit = (message[i] >> j) & 1;
            imageData[index] = (imageData[index] & 0xFE) | bit;
            index++;
        }
    }
    for(int j = 0; j < 8; j++){
        int bit = (messageSize >> j) & 1;
        imageData[index] = (imageData[index] & 0xFE) | bit;
        index++;
    }
    fseek(fp, offset, SEEK_SET);
    fwrite(imageData, 1, size, fp);
    fclose(fp);
    free(imageData);
}

char* revealMsgInImage(char* imagePath){
    //Open the image file in binary mode for reading
    FILE * fp = fopen(imagePath, "rb");
    if(fp == NULL){
        printf("Error opening image file!\n");
        return NULL;
    }

    //Read the header of the image file to determine the size
    unsigned char header[54];
    size_t bytesRead = fread(header, 1, 54, fp);
    if(bytesRead < 54){
        printf("The header of the image file could not be read!\n");
        fclose(fp);
        return NULL;
    }

    //Check if the image is a BMP file
    if(header[0] != 'B' || header[1] != 'M'){
        printf("The image file is not a BMP file!\n");
        fclose(fp);
        return NULL;
    }

    //Calculate the size of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = width * height * 3;

    //Reveal the hidden message in the image
    int offset = *(int*)&header[10];
    int padding = (4 - (width * 3) % 4) % 4;
    unsigned char * imageData = malloc(size);
    fseek(fp, offset, SEEK_SET);
    fread(imageData, 1, size, fp);
    int messageSize = 0;
    for(int j = 0; j < 8; j++){
        int bit = imageData[size - 8 + j] & 1;
        messageSize = (messageSize << 1) | bit;
    }
    char * message = malloc(messageSize);
    int index = 0;
    for(int i = 0; i < messageSize; i++){
        char c = 0;
        for(int j = 0; j < 8; j++){
            int bit = imageData[index] & 1;
            c = (c << 1) | bit;
            index++;
        }
        message[i] = c;
    }
    fclose(fp);
    free(imageData);
    return message;
}

int main(){
    char* imagePath = "image.bmp";
    char* message = "This is a secret message!";
    hideMsgInImage(imagePath, message);
    char* revealedMessage = revealMsgInImage(imagePath);
    printf("The revealed message is: %s\n", revealedMessage);
    free(revealedMessage);
    return 0;
}