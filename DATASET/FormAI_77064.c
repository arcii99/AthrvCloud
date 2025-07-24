//FormAI DATASET v1.0 Category: QR code reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Usage: %s <path_to_qrcode_image>\n", argv[0]);
        return -1;
    }

    char * path = argv[1];
    char command[BUFFER_SIZE];

    // Assemble the command to be executed
    snprintf(command, BUFFER_SIZE, "zbarimg --raw -q %s", path);

    // Execute the command and read the output
    FILE * output = popen(command, "r");
    if (output == NULL) {
        printf("Could not open pipe for command: %s\n", command);
        return -1;
    }

    char result[BUFFER_SIZE];
    fgets(result, BUFFER_SIZE, output);

    // Close the pipe
    pclose(output);

    // Parse the result and output the QR code content
    if (strlen(result) > 0) {
        char * newline_pos = strchr(result, '\n');
        if (newline_pos != NULL) {
            *newline_pos = '\0';
        }

        printf("QR Code content:\n%s\n", result);
    } else {
        printf("Could not read QR code from image: %s\n", path);
    }

    return 0;
}