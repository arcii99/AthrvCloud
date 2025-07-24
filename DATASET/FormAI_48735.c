//FormAI DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <string.h>

void encryptFile(char* filename);

int main() {
    char filename[50];
    printf("Enter the name of the file to be encrypted:\n");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = 0; //removing new line character from file name
    encryptFile(filename);
    printf("File encrypted successfully!\n");
    return 0;
}

void encryptFile(char* filename) {
    FILE* file = fopen(filename, "r+"); //open file in read and write mode
    if(file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }
    int size = 0;
    fseek(file, 0, SEEK_END); //getting file size
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char buffer[size];
    fread(buffer, 1, size, file); //reading file content into buffer
    fclose(file);
    for(int i=0; i<size; i++) {
        buffer[i] = buffer[i] ^ 127; //XOR encryption with 127
    }
    file = fopen(filename, "w"); //open file in write mode
    if(file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }
    fwrite(buffer, 1, size, file); //writing encrypted content to file
    fclose(file);
    //recursively encrypting files in sub-directories
    char command[50];
    sprintf(command, "find %s -type d -exec sh -c 'cd {} && for i in *; do if [ -f $i ]; then encryptFile $i; fi; done' \\;", filename); //using "find" command to search for sub-directories and execute the "encryptFile" function on each file inside them
    system(command);
}