//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct virus {
    char virus_name[20];
    char signature[20];
} virus;

void scan_file(const char* filename, virus* database, int num_viruses) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(&buffer, 1, MAX_FILE_SIZE, fp);
    if (bytes_read == 0) {
        printf("Error reading from file: %s\n", filename);
        fclose(fp);
        return;
    }

    for (int i = 0; i < num_viruses; i++) {
        if (strstr(buffer, database[i].signature) != NULL) {
            printf("File %s contains virus: %s\n", filename, database[i].virus_name);
        }
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    int num_viruses = 3;
    virus database[] = {
        {"Trojan", "454d4153"},    // HEX code for "MAS"
        {"Worm", "4a4f5943"},      // HEX code for "JOYC"
        {"Spyware", "424f5421"},   // HEX code for "BOT!"
    };

    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    scan_file(argv[1], database, num_viruses);

    return 0;
}