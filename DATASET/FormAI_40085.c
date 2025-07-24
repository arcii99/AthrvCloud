//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>

void print_triangle(int size);

int main() {
    int size = 5;
    print_triangle(size);
    return 0;
}

void print_triangle(int size) {
    if (size <= 0) {
        return;
    }
    print_triangle(size - 1);
    for (int i = 0; i < size; i++) {
        printf("*");
    }
    printf("\n");
}