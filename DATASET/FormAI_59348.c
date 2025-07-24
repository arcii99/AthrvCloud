//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_MSG_LEN 1024
#define BMP_HEADER_SIZE 54

// function to hide message into the given image
void hide_message(unsigned char *image_data, char *message, int message_len)
{
    int image_size = *((int*)&image_data[0x22]); // get image size from the header
    int i,j,k;

    // loop through image bytes and hide message in the LSB of every byte
    for(i=BMP_HEADER_SIZE,j=0,k=0; i<image_size && j<message_len; i+=3,j++,k=0)
    {
        // loop through message bits and hide them in the LSB of blue, green and red bytes
        for(; k<8 && j<message_len; k++,j++)
        {
            image_data[i] = (image_data[i]&0xFE) | ((message[j]>>k)&0x01);
            image_data[i+1] = (image_data[i+1]&0xFE) | ((message[j]>>k)&0x01);
            image_data[i+2] = (image_data[i+2]&0xFE) | ((message[j]>>k)&0x01);
        }
    }
}

// function to retrieve message hidden in the given image
void retrieve_message(unsigned char *image_data, char *message, int message_len)
{
    int image_size = *((int*)&image_data[0x22]); // get image size from the header
    int i,j,k;

    // loop through image bytes and retrieve message from the LSB of every byte
    for(i=BMP_HEADER_SIZE,j=0,k=0; i<image_size && j<message_len; i+=3,k=0)
    {
        // loop through message bits and retrieve them from the LSB of blue, green and red bytes
        for(; k<8 && j<message_len; k++,j++)
        {
            message[j] |= (image_data[i]&1)<<k;
            message[j] |= (image_data[i+1]&1)<<k;
            message[j] |= (image_data[i+2]&1)<<k;
        }
    }
}

// main function
int main()
{
    FILE *image_file = fopen("image.bmp", "rb"); // open image file
    if(!image_file)
    {
        printf("Error opening image file.\n");
        return 1;
    }

    // get file size
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    if(image_size <= BMP_HEADER_SIZE)
    {
        printf("Error: Not a valid BMP file.\n");
        fclose(image_file);
        return 1;
    }

    unsigned char *image_data = (unsigned char*)malloc(image_size); // allocate memory for image data
    if(!image_data)
    {
        printf("Error: Memory allocation failed.\n");
        fclose(image_file);
        return 1;
    }

    // read image data
    int bytes_read = fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    if(bytes_read != image_size)
    {
        printf("Error reading image file.\n");
        free(image_data);
        return 1;
    }

    char message[MAX_MSG_LEN] = "This is a secret message."; // message to be hidden
    int message_len = strlen(message); // get message length

    // hide message in the image
    hide_message(image_data, message, message_len);

    // save the modified image
    FILE *modified_image_file = fopen("modified_image.bmp", "wb");
    if(!modified_image_file)
    {
        printf("Error creating modified image file.\n");
        free(image_data);
        return 1;
    }

    fwrite(image_data, 1, image_size, modified_image_file);
    fclose(modified_image_file);

    printf("Message hidden successfully.\n");

    // retrieve hidden message from the modified image
    char retr_msg[MAX_MSG_LEN] = {0};
    retrieve_message(image_data, retr_msg, message_len);

    printf("Retrieved message: %s\n", retr_msg);

    free(image_data);
    return 0;
}