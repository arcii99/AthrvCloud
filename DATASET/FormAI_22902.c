//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_for_virus(char *filename);

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage: c_av [FILE]\n");
        exit(EXIT_FAILURE);
    }
    int result = check_for_virus(argv[1]);
    if(result == 1) {
        printf("WARNING: The file %s is infected with a virus!\n", argv[1]);
    } else {
        printf("The file %s is safe.\n", argv[1]);
    }
    return 0;
}

int check_for_virus(char *filename)
{
    FILE *file;
    file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char signature[] = { 0x33, 0xC0, 0x40, 0xE9 };
    char buffer[1024];
    fread(buffer, 1024, 1, file);
    fclose(file);
    for(int i = 0; i < 1024; i++) {
        if(memcmp(buffer+i, signature, sizeof(signature)) == 0) {
            return 1;
        }
    }
    return 0;
}