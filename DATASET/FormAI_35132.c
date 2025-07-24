//FormAI DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void recover_data(const char* filepath);

int main(int argc, char** argv) {

    if(argc < 2) {
        printf("Error: No input file specified.\n");
        exit(1);
    }
    
    for(int i = 1; i < argc; i++) {
        recover_data(argv[i]);
    }

    return 0;
}

void recover_data(const char* filepath) {
    FILE* fp = fopen(filepath, "rb");
    char buffer[BUFFER_SIZE];
    char filename[20];
    int file_count = 0;
    int bytes_read;
    int file_open = 0;
    FILE* output_file;

    if(fp == NULL) {
        printf("\nError: No such file found.\n");
        return;
    }

    while((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        for(int i = 0; i < bytes_read; i++) {
            if(!file_open) {
                if((buffer[i] == 0xff && buffer[i+1] == 0xd8) || (buffer[i] == 0x89 && buffer[i+1] == 0x50 && buffer[i+2] == 0x4e && buffer[i+3] == 0x47 && buffer[i+4] == 0x0d && buffer[i+5] == 0x0a && buffer[i+6] == 0x1a && buffer[i+7] == 0x0a)) {
                    sprintf(filename, "recovered_file_%d", file_count);
                    output_file = fopen(filename, "wb");
                    file_count++;
                    file_open = 1;
                }
            } else {
                if(buffer[i] == 0xff && buffer[i+1] == 0xd9) {
                    file_open = 0;
                    fclose(output_file);
                } else {
                    fwrite(&buffer[i], sizeof(char), 1, output_file);
                }
            }
        }
    }

    fclose(fp);
}