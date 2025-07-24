//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 4096

// Check if a character is a valid URL character
bool is_valid_url_character(char c) {
    return (isalpha(c) || isdigit(c) || c == '.' || c == '-' || c == '_' || c == '~');
}

// Sanitize a URL by removing all invalid characters
char *sanitize_url(const char *url) {
    int len = strlen(url);
    char *sanitized_url = calloc(len + 1, sizeof(char));
    char *current_char = sanitized_url;

    for (int i = 0; i < len; i++) {
        if (is_valid_url_character(url[i])) {
            *current_char++ = url[i];
        }
    }

    return sanitized_url;
}

// Asynchronously sanitize a URL and write it to a file descriptor
void sanitize_url_async(int input_fd, int output_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t read_amount;

    while ((read_amount = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < read_amount; i++) {
            if (!is_valid_url_character(buffer[i])) {
                buffer[i] = '_';
            }
        }

        if (write(output_fd, buffer, read_amount) < 0) {
            perror("Error writing to output file descriptor");
            return;
        }
    }

    if (read_amount < 0) {
        if (errno != EINTR) {
            perror("Error reading from input file descriptor");
        }
    }

    close(input_fd);
    close(output_fd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 0;
    }

    const char *input_file_path = argv[1];
    const char *output_file_path = argv[2];

    int input_fd = open(input_file_path, O_RDONLY);
    if (input_fd < 0) {
        perror("Error opening input file");
        return 1;
    }

    int output_fd = open(output_file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) {
        perror("Error opening output file");
        return 1;
    }

    sanitize_url_async(input_fd, output_fd);

    return 0;
}