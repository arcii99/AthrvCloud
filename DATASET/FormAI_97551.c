//FormAI DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void encode(char *image, char *message){
    FILE *img, *msg, *output;
    img = fopen(image,"rb");
    msg = fopen(message,"rb");
    output = fopen("encoded_image.bmp","wb");

    //Read header information
    unsigned char header[54];
    for(int i=0;i<54;i++){
        header[i] = fgetc(img);
        fputc(header[i],output);
    }

    //Calculate number of bytes available for message embedding
    fseek(img,0,SEEK_END);
    int img_size = ftell(img) - 54;
    int msg_size = 0;
    fseek(msg,0,SEEK_END);
    msg_size = ftell(msg);
    fseek(msg,0,SEEK_SET);
    if(msg_size > (img_size/8)){
        printf("Message is too long to embed in the image.\n");
        exit(1);
    }

    //Embed message
    unsigned char pixel[3];
    for(int i=0;i<msg_size;i++){
        unsigned char byte = fgetc(msg);
        for(int j=0;j<8;j++){    
            fread(pixel,sizeof(pixel),1,img);
            unsigned char bit = ((byte >> j) & 1) << 2;
            pixel[0] = (pixel[0] & 0xFC) | bit;
            fputc(pixel[0],output);
            fputc(pixel[1],output);
            fputc(pixel[2],output);
        }
    }

    //Copy remaining pixels from the input image
    while(!feof(img)){
        fread(pixel,sizeof(pixel),1,img);
        fputc(pixel[0],output);
        fputc(pixel[1],output);
        fputc(pixel[2],output);
    }

    fclose(img);
    fclose(msg);
    fclose(output);
}

void decode(char *image){
    FILE *img, *output;
    img = fopen(image,"rb");
    output = fopen("decoded_message.txt","w");

    //Skip header information
    fseek(img,54,SEEK_SET);

    unsigned char pixel[3];
    int count = 0;
    while(!feof(img)){
        fread(pixel,sizeof(pixel),1,img);
        unsigned char bit = pixel[0] & 0x03;
        count++;
        if(count % 8 == 0){
            fputc(bit,output);
        }
    }
    fclose(img);
    fclose(output);
}

int main(){
    char input_image[] = "test_image.bmp";
    char input_message[] = "test_message.txt";
    encode(input_image,input_message);
    decode("encoded_image.bmp");
}