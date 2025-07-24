//FormAI DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(int err_num, const char* err_msg, const char* file_name) {
    fprintf(stderr, "%s in %s. Error code: %d\n", err_msg, file_name, err_num);
    exit(err_num);
}

int main() {
    FILE* fp;
    int* arr = NULL;

    // Open the file
    fp = fopen("nonexistent.txt", "r");
    if (fp == NULL) {
        handle_error(errno, "Unable to open file", __FILE__);
    }

    // Allocate memory for the array
    arr = (int*) malloc(10 * sizeof(int));
    if (arr == NULL) {
        handle_error(errno, "Memory Allocation Error", __FILE__);
    }

    // Access array element out of bounds
    int i;
    for (i = 0; i <= 10; i++) {
        arr[i] = i;
    }

    // Close the file
    if (fclose(fp) != 0) {
        handle_error(errno, "Unable to close file", __FILE__);
    }

    free(arr);

    return 0;
}