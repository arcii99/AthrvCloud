//FormAI DATASET v1.0 Category: Recursive ; Style: Dennis Ritchie
// This is a recursive program that prints all permutations of a given string
// It combines the approach used in Heap's algorithm and the recursive swap function
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int start, int end) {
    int i;
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (i = start; i <= end; i++) {
            swap((str + start), (str + i));
            permute(str, start + 1, end);
            swap((str + start), (str + i));
        }
    }
}

int main() {
    char str[] = "abc";
    int n = strlen(str);
    printf("Printing all permutations of 'abc':\n");
    permute(str, 0, n - 1);
    return 0;
}