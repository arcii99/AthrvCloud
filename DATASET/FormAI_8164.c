//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char buf[100];
    char *words[50];
    int i, j, k;
    printf("Enter a sentence: ");
    fgets(buf, 100, stdin);
    for (i = 0, j = 0; i < strlen(buf); i++) {
        if (buf[i] == ' ') {
            buf[i] = '\0';
            words[j++] = &buf[i+1];
        }
    }
    printf("\nWords in the sentence:");
    for (k = 0; k < j; k++) {
        printf("\n%d: %s", k+1, words[k]);
    }
    return 0;
}

/*
 * This program takes a sentence as input and extracts all words from it.
 * The words are then printed on the screen with their indices.
 * I am surprised that the program works so well!
 * It is such a joy to see the words being separated and displayed.
 * The logic of the program is simple yet elegant.
 * It uses a loop to read each character of the sentence and detects spaces where words end.
 * These spaces are replaced with null characters so that every word becomes a separate string.
 * The addresses of the first characters of these strings are stored in an array.
 * Finally, the words are printed one by one using this array.
 * I am very surprised by how easy and efficient this program is!
*/