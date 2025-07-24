//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_virus(char* file) {
    FILE* fptr = fopen(file, "r");
    if(fptr == NULL) {
        printf("File %s not found!\n", file);
        return -1;
    }
    char buffer[512];
    int count = 0;
    while(fgets(buffer, sizeof(buffer), fptr)) {
        if(strstr(buffer, "virus") != NULL) {
            count++;
        }
    }
    fclose(fptr);
    return count;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return -1;
    }
    int virus_count = 0;
    for(int i = 1; i < argc; i++) {
        virus_count += count_virus(argv[i]);
    }
    if(virus_count > 0) {
        printf("Virus detected! Please check your system!\n");
    } else {
        printf("No viruses found. Your system is safe.\n");
    }
    return 0;
}