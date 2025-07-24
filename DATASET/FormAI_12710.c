//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>    //for directory operations
#include <ctype.h>     //for file type operations
#include <sys/stat.h>  //for file information
#include <string.h>    //for string functions

//function to check if the file is a binary file
int is_binary_file(FILE* fp) {
    int block_size = 512;
    char buffer[block_size];
    int num_blocks = 10;
    
    //read the first few blocks of the file and check for non-text characters
    for(int i=0; i<num_blocks; i++) {
        size_t size = fread(buffer, 1, block_size, fp);
        if(size < block_size) memset(buffer+size, 0, block_size-size);
        
        for(int j=0; j<size; j++) {
            if(!isprint(buffer[j]) && !isspace(buffer[j])) {
                return 1;
            }
        }
    }
    return 0;
}

//function to scan the file and check for malicious code
void scan_file(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }
    
    int is_binary = is_binary_file(fp);
    if(is_binary) {
        printf("%s is a binary file and cannot be scanned\n", filename);
        fclose(fp);
        return;
    }
    
    //read the file contents into a buffer
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = malloc(file_size+1);
    if(buffer == NULL) {
        printf("Error: Unable to allocate memory\n");
        fclose(fp);
        return;
    }
    fread(buffer, file_size, 1, fp);
    buffer[file_size] = '\0';
    
    //check for malicious code
    char* virus_signature = "somerandomstring12345";
    if(strstr(buffer, virus_signature) != NULL) {
        printf("%s is infected with virus %s!\n", filename, virus_signature);
    } else {
        printf("%s is clean\n", filename);
    }
    
    free(buffer);
    fclose(fp);
}

int main() {
    struct dirent *dir_entry;
    DIR *dir = opendir(".");
    if(dir == NULL) {
        printf("Error: Unable to open directory\n");
        return 1;
    }
    
    while((dir_entry = readdir(dir)) != NULL) {
        struct stat file_stat;
        stat(dir_entry->d_name, &file_stat);
        if(S_ISREG(file_stat.st_mode)) {
            //only scan regular files
            scan_file(dir_entry->d_name);
        }
    }
    
    closedir(dir);
    return 0;
}