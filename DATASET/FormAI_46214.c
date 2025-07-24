//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char* file_scan(char* filename, char* virus_signature) {
    FILE* file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        return "File not found\n";
    }

    char* file_data = (char*)malloc(sizeof(char) * MAX_LENGTH);

    fread(file_data, sizeof(char), MAX_LENGTH, file_ptr);

    if (strstr(file_data, virus_signature) != NULL) {
        fclose(file_ptr);
        return "Virus Found\n";
    }

    fclose(file_ptr);
    return "File is safe\n";
}

int main() {
    char* filename = "document.txt";
    char* virus_signature = "malware";
    
    char* encrypted_file = file_scan(filename, virus_signature);

    printf("%s", encrypted_file);

    return 0;
}