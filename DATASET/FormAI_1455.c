//FormAI DATASET v1.0 Category: Browser Plugin ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void print_tabs(int count) {
    for (int i = 0; i < count; i++) {
        printf("\t");
    }
}

void recursive_print(int depth, char *string) {
    print_tabs(depth);
    printf("%s\n", string);

    if (depth < 3) {
        recursive_print(depth + 1, "this is a child node");
    }
}

int main() {
    recursive_print(0, "this is the root node");
    return 0;
}