//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    /* check if filename is provided */
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* open the file for reading */
    FILE *fp = fopen(argv[1], "rb");

    /* check if file exists and can be opened */
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    /* read the file contents into memory */
    unsigned char buffer[MAX_SIZE];
    size_t num_bytes = fread(buffer, sizeof(unsigned char), MAX_SIZE, fp);

    /* close the file */
    fclose(fp);

    /* perform scan for virus signatures */
    const unsigned char* virus_signatures[] = {"0xC90B22", "0xBEEE27", "0xAAA123"};
    size_t num_virus_signatures = sizeof(virus_signatures) / sizeof(virus_signatures[0]);
    int is_virus = 0;
    for (size_t i = 0; i < num_virus_signatures; i++) {
        for (size_t j = 0; j < num_bytes - sizeof(char); j++) {
            if (*(unsigned int*)(buffer+j) == strtoul(virus_signatures[i], NULL, 16)) {
                printf("WARNING: %s is infected with Virus %zu\n", argv[1], i+1);
                is_virus = 1;
                break;
            }
        }
        if (is_virus) break;
    }
    if (!is_virus) printf("SUCCESS: %s is clean.\n", argv[1]);

    return 0;
}