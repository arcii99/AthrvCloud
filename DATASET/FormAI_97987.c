//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "VIRUS_123"

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Please specify the file to scan\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "rb");
    if(!file){
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    long int file_size = ftell(file);
    rewind(file);
    
    char *file_buffer = (char*) malloc(file_size);
    if(!file_buffer){
        printf("Could not allocate memory for file buffer\n");
        return 1;
    }
    
    fread(file_buffer, 1, file_size, file);
    fclose(file);
    
    if(strstr(file_buffer, VIRUS_SIGNATURE)){
        printf("The file \"%s\" is infected with virus \"%s\"\n", argv[1], VIRUS_SIGNATURE);
    } else {
        printf("The file \"%s\" is clean\n", argv[1]);
    }
    
    free(file_buffer);
    
    return 0;
}