//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BUFFER_LENGTH 1024

int main(int argc, char **argv) {
    char filename[MAX_FILE_NAME_LENGTH];
    char command[MAX_BUFFER_LENGTH];
    char buffer[MAX_BUFFER_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    sprintf(command, "grep -ao '[\\]x[0-9a-fA-F]\\{2\\}' %s", filename);

    FILE *output = popen(command, "r");

    if (!output) {
        printf("Failed to execute command.\n");
        return 1;
    }

    while (fgets(buffer, MAX_BUFFER_LENGTH, output) != NULL) {
        printf("Possible virus found in %s: %s", filename, buffer);
    }

    pclose(output);

    return 0;
}