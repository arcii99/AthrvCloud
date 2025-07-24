//FormAI DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct custom_string {
    char* data;
    size_t size;
};

/*
    Initializes a new custom_string with the given data.
*/
struct custom_string* new_custom_string(const char* data) {
    struct custom_string* str = (struct custom_string*) malloc(sizeof(struct custom_string));
    str->size = strlen(data) + 1; // Include space for the null terminator
    str->data = (char*) malloc(str->size * sizeof(char));
    strcpy(str->data, data);
    return str;
}

/*
    Deallocates memory for a custom_string.
*/
void delete_custom_string(struct custom_string* str) {
    free(str->data);
    free(str);
}

int main() {
    struct custom_string* hello = new_custom_string("Hello, world!");
    printf("%s\n", hello->data);
    delete_custom_string(hello);
    return 0;
}