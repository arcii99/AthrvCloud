//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Unable to open file: %s\n", filename);
        return 1;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char* buffer = (char*) malloc(file_size * sizeof(char));
    fread(buffer, 1, file_size, file);
    fclose(file);
    int num_viruses = 0;
    char* viruses[] = {"malware", "virus", "trojan", "rootkit"};
    for(int i=0; i<4; i++) {
        if(strstr(buffer, viruses[i])) {
            printf("Found %s in file: %s\n", viruses[i], filename);
            num_viruses++;
        }
    }
    if(num_viruses == 0) {
        printf("No viruses found in file: %s\n", filename);
    }
    free(buffer);
    return 0;
}