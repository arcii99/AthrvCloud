//FormAI DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>

#define MAX_LENGTH 50

int main(){
    char message[MAX_LENGTH], key[MAX_LENGTH];
    printf("Enter message (50 characters or less): ");
    fgets(message, MAX_LENGTH, stdin);
    printf("Enter key (50 characters or less): ");
    fgets(key, MAX_LENGTH, stdin);

    for(int i=0; i<MAX_LENGTH; i++){
        if(message[i] == '\n'){ //Replace escape character with null character
            message[i] = '\0';
        }
        if(key[i] == '\n'){
            key[i] = '\0';
        }
    }

    FILE *img = fopen("image.bmp", "rb");
    FILE *stego_img = fopen("stego_image.bmp", "wb");
    if (img == NULL || stego_img == NULL){
        perror("Error opening file");
        return 1;
    }

    unsigned char header[54];
    unsigned char pixel_data[3];
    int key_index = 0;

    fread(header, sizeof(unsigned char), 54, img);
    fwrite(header, sizeof(unsigned char), 54, stego_img);

    while(fread(pixel_data, sizeof(unsigned char), 3, img) > 0){
        if(key[key_index] == '\0'){ //Loop key if it runs out of characters
            key_index = 0;
        }
        for(int i=0; i<3; i++){
            if(pixel_data[i]%2 == 0 && key[key_index]%2 == 1){ //Change pixel bit from 0 to 1
                pixel_data[i] += 1;
            } else if(pixel_data[i]%2 == 1 && key[key_index]%2 == 0){ //Change pixel bit from 1 to 0
                pixel_data[i] -= 1;
            }
            key_index++;
        }
        fwrite(pixel_data, sizeof(unsigned char), 3, stego_img);
    }

    fclose(img);
    fclose(stego_img);
    printf("Image steganography complete. Check the file stego_image.bmp.\n");

    return 0;
}