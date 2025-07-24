//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    char file_signature[10] = "VIRUS";
    int size = 10000;
    char file_buffer[size];
    int virus_found = 0;

    FILE *fp = fopen("sample_file.exe", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fread(file_buffer, size, 1, fp);

    for(int i = 0; i < strlen(file_buffer); i++) {
        if(file_buffer[i] == 'V' && file_buffer[i+1] == 'I'
            && file_buffer[i+2] == 'R' && file_buffer[i+3] == 'U'
            && file_buffer[i+4] == 'S') {
                virus_found = 1;
                break;
            }
    }

    if(virus_found) {
        printf("Virus found in file!\nPlease delete the file immediately.\n");
    } else {
        printf("File is safe.\n");
    }

    fclose(fp); 

    return 0;
}