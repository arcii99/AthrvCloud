//FormAI DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

#define BYTE_LIMIT 2000000 
#define HEADER_LENGTH 54 

void encode(FILE *image, const char *message) { 
    unsigned char data[BYTE_LIMIT], bit; 
    char *msg = (char*) message; 
    int size = strlen(msg), i, j, k = 0, a, b, c, index = HEADER_LENGTH * 8; 
    fseek(image, 0, SEEK_SET); 
    fread(data, BYTE_LIMIT, 1, image); 
    for (i = index; i < size * 8 + HEADER_LENGTH * 8; i += 3) { 
        a = msg[k++]; b = msg[k++]; c = msg[k++]; 
        for (j = 7; j >= 0; --j) { 
            bit = (a >> j) & 1; 
            data[i++] |= (bit << 0); 
            bit = (b >> j) & 1; 
            data[i++] |= (bit << 0); 
            bit = (c >> j) & 1; 
            data[i] |= (bit << 0);
            if ((i + 1) % 3 == 0) {index++;} 
        } 
    } 
    fseek(image, 0, SEEK_SET); 
    fwrite(data, BYTE_LIMIT, 1, image); 
} 

void decode(FILE *image) { 
    unsigned char data[BYTE_LIMIT], bit; 
    int i, j, index = HEADER_LENGTH * 8; 
    char message[BYTE_LIMIT], letter; 
    fseek(image, 0, SEEK_SET); 
    fread(data, BYTE_LIMIT, 1, image); 
    for (i = index; i < BYTE_LIMIT; i += 8) { 
        letter = 0; 
        for (j = 7; j >= 0; --j) { 
            bit = (data[i++] >> 0) & 1; 
            letter |= bit << j; 
            bit = (data[i++] >> 0) & 1; 
            letter |= bit << j + 1; 
            bit = (data[i] >> 0) & 1; 
            letter |= bit << j + 2; 
            index++; 
        } 
        message[(i - index) / 8] = letter; 
        if (letter == '\0') { 
            break; 
        } 
    } 
    printf("The hidden message is: %s\n", message);
}

int main() { 
    FILE *in_file = fopen("example.bmp", "rb");
    if (in_file == NULL) { 
        printf("Could not open image file.\n"); 
        return 1; 
    } 
    char message[500]; 
    printf("Enter your message: "); 
    fgets(message, 500, stdin); 
    encode(in_file, message);
    printf("Message encoded successfully.\n");
    fclose(in_file); 
    in_file = fopen("example.bmp", "rb"); 
    decode(in_file); 
    fclose(in_file); 
    return 0; 
}