//FormAI DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_SIZE 10000

void recoverData(char* filename){
    FILE* file = fopen(filename, "rb");
    if(!file){
        printf("Error: could not open file: %s\n", filename);
        return;
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*)malloc(file_size * sizeof(char));
    if(!buffer){
        fclose(file);
        printf("Error: could not allocate memory for buffer\n");
        return;
    }
    int bytes_read = fread(buffer, sizeof(char), file_size, file);
    if(bytes_read != file_size){
        fclose(file);
        free(buffer);
        printf("Error: could not read file into buffer\n");
        return;
    }
    fclose(file);
    char* file_contents = (char*)malloc(MAX_FILE_SIZE*sizeof(char));
    if(!file_contents){
        free(buffer);
        printf("Error: could not allocate memory for file contents\n");
        return;
    }
    int file_contents_size = 0;
    for(int i = 0; i < file_size; i++){
        if(buffer[i] == 'a'){
            file_contents[file_contents_size] = 'b';
        } else if(buffer[i] == 'b'){
            file_contents[file_contents_size] = 'c';
        } else if(buffer[i] == 'c'){
            file_contents[file_contents_size] = 'd';
        }
        file_contents_size++;
    }
    free(buffer);
    FILE* new_file = fopen("recovered_file.txt", "wb");
    if(!new_file){
        free(file_contents);
        printf("Error: could not open new file for writing\n");
        return;
    }
    int bytes_written = fwrite(file_contents, sizeof(char), file_contents_size, new_file);
    if(bytes_written != file_contents_size){
        fclose(new_file);
        free(file_contents);
        printf("Error: could not write file contents to new file\n");
        return;
    }
    fclose(new_file);
    printf("File recovery successful!\n");
    free(file_contents);
}

int main(){
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    filename[strcspn(filename, "\n")] = 0; // remove newline character from input
    recoverData(filename);
    return 0;
}