//FormAI DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void copy_file(char *source_file, char *destination_file) {
    char buffer[BUFFER_SIZE];
    int source, destination, read_size;
    
    source = open(source_file, O_RDONLY);
    destination = open(destination_file, O_WRONLY | O_CREAT, 0644);
    
    while ((read_size = read(source, buffer, BUFFER_SIZE)) > 0) {
        write(destination, buffer, read_size);
    }
    
    close(source);
    close(destination);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: backup [source file] [destination file]\n");
        exit(EXIT_FAILURE);
    }
    
    copy_file(argv[1], argv[2]);
    
    printf("File backup successful!\n");
    return EXIT_SUCCESS;
}