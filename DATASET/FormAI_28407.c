//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    OK = 0,
    ERROR_OUT_OF_MEMORY,
    ERROR_NULL_POINTER,
    ERROR_INVALID_PARAMETER,
} ErrorCode;

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(ERROR_OUT_OF_MEMORY);
    }
    return ptr;
}

void *safe_realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return safe_malloc(size);
    }
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(ERROR_OUT_OF_MEMORY);
    }
    return new_ptr;
}

char *safe_strdup(const char *s)
{
    char *new_s = strdup(s);
    if (new_s == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(ERROR_OUT_OF_MEMORY);
    }
    return new_s;
}

void safe_free(void *ptr)
{
    if (ptr == NULL) {
        fprintf(stderr, "Warning: Attempting to free null pointer\n");
        return;
    }
    free(ptr);
}

void draw_triangle(int height)
{
    if (height <= 0) {
        fprintf(stderr, "Error: Invalid parameter: height must be positive\n");
        exit(ERROR_INVALID_PARAMETER);
    }

    char **rows = safe_malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        rows[i] = safe_malloc((2 * height - 1) * sizeof(char));
        memset(rows[i], ' ', 2 * height - 1);
        rows[i][2 * height - 2] = '\0';
    }

    for (int row = 0; row < height; row++) {
        int center = height - 1;
        int offset = row;
        for (int k = 0; k < 2 * row + 1; k++) {
            rows[row][center + offset] = '*';
            offset--;
        }
    }

    for (int i = 0; i < height; i++) {
        printf("%s\n", rows[i]);
        safe_free(rows[i]);
    }
    safe_free(rows);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Error: Invalid number of arguments\n");
        fprintf(stderr, "Usage: %s <height>\n", argv[0]);
        return ERROR_INVALID_PARAMETER;
    }

    int height = atoi(argv[1]);

    draw_triangle(height);

    return OK;
}