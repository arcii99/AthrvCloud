//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void hide_data(char*, char*, char*);
void recover_data(char*, char*);

//"magic" word to identify steganographically hidden data
const char magic_str[] = "k3nT";
const int magic_len = sizeof(magic_str); 

int main(int argc, char* argv[]) {

    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    char message[MAX_SIZE];

    //check command-line arguments
    if(argc < 2) {
        printf("Usage: %s <input file> <output file> <message>\n", argv[0]);
        return 1;
    } else if (argc == 3) {
        recover_data(argv[1], argv[2]);
        return 0;
    }

    //get input parameters
    strncpy(input_file, argv[1], MAX_SIZE);
    strncpy(output_file, argv[2], MAX_SIZE);

    //combine message into single string
    for (int i = 3; i < argc; i++) {
        strcat(message, argv[i]);
        strcat(message, " ");
    }

    //hide message in input file
    hide_data(input_file, output_file, message);
    
    return 0;
}

/*
Hide data in an image using LSB steganography.
The data is hidden by overwriting the least-significant bits of each byte of image data with 
the message bits. To identify the end of the message, the last 64 bytes are reserved for 
a "magic" string to be appended to the end of the message before it is hidden. If during 
extraction the "magic" string is found, it means the end of the message has been reached.
*/
void hide_data(char* input_file, char* output_file, char* message) {
    
    FILE* in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Could not open input file %s\n", input_file);
        exit(1);
    }

    FILE* out = fopen(output_file, "wb");
    if (out == NULL) {
        printf("Could not create output file %s\n", output_file);
        exit(1);
    }
    
    //position to end of input file
    fseek(in, 0, SEEK_END);
    long filesize = ftell(in);
    fseek(in, 0, SEEK_SET);
    
    //read magic string from end of file, if present
    int hidden_len = 0;
    char hidden_data[MAX_SIZE] = {0};
    if (filesize >= magic_len) {
        fseek(in, -magic_len, SEEK_END);
        fread(hidden_data, 1, magic_len, in);
        if (strncmp(hidden_data, magic_str, magic_len) == 0) {
            //magic string found; get length of hidden data
            fseek(in, -magic_len - sizeof(int), SEEK_END);
            fread(&hidden_len, sizeof(int), 1, in);
        }
    }

    if (hidden_len > 0) {
        //hidden data already present; write it back to output
        fwrite(hidden_data, 1, magic_len, out);

        fseek(in, -hidden_len - magic_len - sizeof(int), SEEK_END);
        for (int i = 0; i < hidden_len; i++) {
            char c;
            fread(&c, 1, 1, in);
            fwrite(&c, 1, 1, out);
        }
    } 

    //position to start of input file
    fseek(in, 0, SEEK_SET);

    //copy image header to output
    char header[54];
    fread(header, 1, 54, in);
    fwrite(header, 1, 54, out);

    //count number of bytes available for message
    fseek(in, 0, SEEK_END);
    long data_size = ftell(in) - 54 - magic_len - sizeof(int);
    if (hidden_len > 0) {
        data_size -= hidden_len;
    }
    fseek(in, 54, SEEK_SET);

    //convert message to binary
    char binary_message[MAX_SIZE * 8];
    int message_len = strlen(message);
    int binary_len = message_len * 8;
    for (int i = 0; i < message_len; i++) {
        int bits = 8;
        char c = message[i];
        while (bits--) {
            if (c & (1 << bits)) {
                strcat(binary_message, "1");
            } else {
                strcat(binary_message, "0");
            }
        }
    }

    //check if message is too long to be hidden
    if (binary_len > data_size) {
        printf("Message too large to be hidden in image\n");
        exit(1);
    }

    //hide message in image data
    int pos = 0;
    while (pos < binary_len) {
        char byte;
        fread(&byte, 1, 1, in);
        for (int i = 0; i < 8; i++) {
            if (pos < binary_len) {
                if (binary_message[pos] == '1') {
                    byte |= (1 << i);
                } else {
                    byte &= ~(1 << i);
                }
                pos++;
            }
        }
        fwrite(&byte, 1, 1, out);
    }

    //write "magic" string and length of message to end of file
    fwrite(magic_str, 1, magic_len, out);
    fwrite(&binary_len, sizeof(int), 1, out);
    fwrite(binary_message, 1, binary_len/8, out);

    fclose(in);
    fclose(out);
}

/*
Extract data hidden in an image using LSB steganography.
The hidden data is identified by searching for the "magic" string at the end of the file.
*/
void recover_data(char* input_file, char* output_file) {

    FILE* in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Could not open input file %s\n", input_file);
        exit(1);
    }

    FILE* out = fopen(output_file, "w");
    if (out == NULL) {
        printf("Could not create output file %s\n", output_file);
        exit(1);
    }

    //position to end of input file
    fseek(in, 0, SEEK_END);
    long filesize = ftell(in);
    fseek(in, 0, SEEK_SET);

    //read magic string from end of file, if present
    int hidden_len = 0;
    char hidden_data[MAX_SIZE] = {0};
    if (filesize >= magic_len) {
        fseek(in, -magic_len, SEEK_END);
        fread(hidden_data, 1, magic_len, in);
        if (strncmp(hidden_data, magic_str, magic_len) == 0) {
            //magic string found; get length of hidden data
            fseek(in, -magic_len - sizeof(int), SEEK_END);
            fread(&hidden_len, sizeof(int), 1, in);
        }
    }

    if (hidden_len > 0) {
        //hidden data found; extract it
        fseek(in, -hidden_len - magic_len - sizeof(int), SEEK_END);

        char hidden_binary[MAX_SIZE * 8];
        for (int i = 0; i < hidden_len; i++) {
            char c;
            fread(&c, 1, 1, in);
            for (int j = 7; j >= 0; j--) {
                hidden_binary[i*8 + (7-j)] = ((c & (1 << j)) ? '1' : '0');
            }
        }

        //convert binary data back to string
        char hidden_message[MAX_SIZE];
        for (int i = 0; i < hidden_len/8; i++) {
            char c = 0;
            for (int j = 0; j < 8; j++) {
                if (hidden_binary[i*8+j] == '1') {
                    c |= (1 << (7-j));
                }
            }
            hidden_message[i] = c;
        }

        //write hidden message to output
        fwrite(hidden_message, 1, hidden_len/8, out);
    } else {
        printf("No hidden data found in image\n");
    }

    fclose(in);
    fclose(out);
}