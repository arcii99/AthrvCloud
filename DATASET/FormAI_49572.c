//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define MAX_LINE 255
#define MAX_FILENAME 50

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s input_file\n", argv[0]);
        exit(1);
    }
    
    char *input_file = argv[1];
    char output_file[MAX_FILENAME + 4];
    sprintf(output_file, "%s.asc", input_file);
    int fd_input, fd_output;
    struct stat input_stat;
    char input_buffer[MAX_WIDTH];
    int line_length = 0;
    char ascii[MAX_WIDTH * 6];
    int ascii_length = 0;

    fd_input = open(input_file, O_RDONLY);
    if(fd_input == -1){
        printf("Error: could not open input file %s\n", input_file);
        exit(1);
    }

    fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_output == -1){
        printf("Error: could not open output file %s\n", output_file);
        close(fd_input); 
        exit(1);
    }

    if(fstat(fd_input, &input_stat) == -1){
        printf("Error: could not retrieve file size\n");
        close(fd_input);
        close(fd_output);
        exit(1);
    }

    printf("Generating ASCII art...\n");
    printf("Reading file: %s\n", input_file);
    printf("Input file size: %ld\n", input_stat.st_size);
    printf("Output file: %s\n", output_file);

    while(1){
        int count = read(fd_input, input_buffer, MAX_WIDTH);
        if(count == -1){
            printf("Error: could not read input\n");
            break;
        }
        if(count == 0){
            break;
        }
        line_length = 0;
        for(int i = 0; i < count; i++){
            if(!isprint(input_buffer[i])){
                input_buffer[i] = ' ';
            }
            line_length++;
            ascii_length += sprintf(ascii + ascii_length, "%02X ", input_buffer[i]);
            if(line_length == MAX_WIDTH){
                ascii_length += sprintf(ascii + ascii_length, "\n");
                line_length = 0;
            }
        }
    }

    int count = write(fd_output, ascii, ascii_length);
    if(count != ascii_length){
        printf("Error: could not write output\n");
    }
    else{
        printf("Conversion complete!\n");
    }

    close(fd_input);
    close(fd_output);

    return 0;
}