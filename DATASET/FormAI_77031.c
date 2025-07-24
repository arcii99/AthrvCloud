//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

#define MAX_WORDS 10000      // Maximum number of words that can be counted
#define BUFFER_SIZE 200000   // Maximum file size

// Function for counting number of words in the read file
int count_words(char* buffer, int buffer_size) {
    int word_count = 1;    // Assuming that the file has at least one word
    for(int i=0; i<buffer_size; i++) {
        if(buffer[i] == ' ' || buffer[i] == '\n') {
            word_count++;
        }
    }
    return word_count;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Invalid usage!\nUsage: ./count_words <filename>\n");
        exit(1);
    }

    char* filename = argv[1];
    char buffer[BUFFER_SIZE];                    // Buffer to hold the contents of the read file
    int fd = open(filename, O_RDONLY);           // Open the file in read-only mode

    if(fd == -1) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int num_bytes = read(fd, buffer, BUFFER_SIZE);   // Read the contents of the file
    close(fd);

    if(num_bytes == -1) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    int word_count = count_words(buffer, num_bytes);   // Get the word count

    printf("Number of words in file %s: %d\n", filename, word_count);

    return 0;
}