//FormAI DATASET v1.0 Category: Image Steganography ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// Function to retrieve the nth bit of a given byte
int get_nth_bit(int byte, int n) {
    return (byte >> n) & 1;
}

// Function to manipulate the nth bit of a given byte
void set_nth_bit(unsigned char *byte, int n, int value) {
    if(value == 0) {
        *byte &= ~(1 << n);
    } else {
        *byte |= 1 << n;
    }
}

// Function to hide a message in a picture
void hide_message_in_picture(char *file_path, char *message) {
    FILE *image_file = fopen(file_path, "r+b");

    if(image_file == NULL) {
        printf("Error: Could not open image file\n");
        return;
    }

    unsigned char byte;
    int num_bits = 8;
    int message_index = 0;
    int message_len = strlen(message);

    while(fread(&byte, sizeof(unsigned char), 1, image_file)) {
        if(message_index < message_len) { // If there are still message characters to hide
            for(int i=0; i<num_bits; i++) { // Loop through each bit in the byte
                int message_bit = get_nth_bit(message[message_index], i); // Get the ith bit from the current message character
                set_nth_bit(&byte, i, message_bit); // Set the ith bit of the byte to the message bit
            }
            message_index++;
        } else { // If message is fully hidden, terminate loop
            break;
        }

        fseek(image_file, -1, SEEK_CUR); // Move back one byte to write modified byte
        fwrite(&byte, sizeof(unsigned char), 1, image_file); // Write the modified byte back into the image file
    }

    printf("Message hidden in image!\n");
    fclose(image_file);
}

// Function to retrieve a hidden message from a picture
void retrieve_message_from_picture(char *file_path) {
    FILE *image_file = fopen(file_path, "rb");

    if(image_file == NULL) {
        printf("Error: Could not open image file\n");
        return;
    }

    unsigned char byte;
    int num_bits = 8;
    char message[1000];
    int index = 0;
    int message_len = 0;
    int message_complete = 0;

    while(fread(&byte, sizeof(unsigned char), 1, image_file)) {
        if(!message_complete) {
            char current_char = 0;
            for(int i=0; i<num_bits; i++) { // Loop through each bit in the byte
                int bit = get_nth_bit(byte, i); // Get the ith bit from the current byte
                set_nth_bit((unsigned char *)&current_char, i, bit); // Set the ith bit of the current character to the bit
            }

            if(isprint(current_char)) { // If the current character is printable, add it to the message string
                message[index++] = current_char;
                message_len++;
            } else { // If the current character is not printable, the message is complete
                message_complete = 1;
            }
        }
    }

    printf("Retrieved message from image: %s\n", message);
    fclose(image_file);
}

int main() {
    hide_message_in_picture("image.bmp", "This is a secret message!"); // Call function to hide message in image
    retrieve_message_from_picture("image.bmp"); // Call function to retrieve message from image
    return 0;
}