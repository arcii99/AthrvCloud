//FormAI DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void async_handler(void *arg, int error_code) {
    char *error_msg = (char*) arg;
    printf("Error occurred: %s (%d)\n", error_msg, error_code);
    exit(1);
}

int main(){
    char *filename = "myfile.txt";
    FILE *fp = NULL;

    // Asynchronous error handling
    if ((fp = fopen(filename, "r")) == NULL) {
        char *error_msg = "Failed to open file";
        int error_code = 1;
        async_handler((void*) error_msg, error_code);
    }

    // Read file contents and print them
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    // Close the file
    if (fclose(fp) != 0) {
        char *error_msg = "Failed to close file";
        int error_code = 2;
        async_handler((void*) error_msg, error_code);
    }

    printf("Program completed successfully\n");

    return 0;
}