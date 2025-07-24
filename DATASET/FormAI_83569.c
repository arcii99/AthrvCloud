//FormAI DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the frequency of each character
struct freq {
    int count;
    char letter;
};

// Function to compare the frequencies of two characters for sorting
int compare_freq(const void *a, const void *b) {
    struct freq *f1 = (struct freq *) a;
    struct freq *f2 = (struct freq *) b;
    return (f2->count - f1->count);
}

// Function to recursively build the Huffman tree
void build_tree(struct freq *freq_list, int size) {
    struct freq f1, f2;
    int i;

    // Sort the frequency list in descending order
    qsort(freq_list, size, sizeof(*freq_list), compare_freq);

    // If there are only two characters in the list, make them the left and right child of the root
    if (size == 2) {
        printf("Merge %c and %c to create root\n", freq_list[0].letter, freq_list[1].letter);
        return;
    }

    // Create a new node using the two characters with the lowest frequencies
    // Remove those characters from the frequency list and add the new node
    f1 = freq_list[size - 2];
    f2 = freq_list[size - 1];
    freq_list[size - 2].letter = '*';
    freq_list[size - 2].count = f1.count + f2.count;
    printf("Merge %c and %c to create %c with freq %d\n", f1.letter, f2.letter, freq_list[size - 2].letter, freq_list[size - 2].count);
    size--;
    build_tree(freq_list, size);
}

int main() {
    char input[100];
    int index[26] = { 0 };
    int i, j, count = 0;
    struct freq freq_list[26];

    printf("Enter the input string: ");
    fgets(input, 100, stdin);

    // Count the frequency of each character in the input string
    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            index[input[i] - 'a']++;
        }
    }

    // Add each distinct character and its frequency to the frequency list
    for (i = 0; i < 26; i++) {
        if (index[i] != 0) {
            freq_list[count].count = index[i];
            freq_list[count].letter = i + 'a';
            count++;
        }
    }

    // Recursively build the Huffman tree
    build_tree(freq_list, count);

    return 0;
}