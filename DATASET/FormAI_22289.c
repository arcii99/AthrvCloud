//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main() {
    char input[MAX_BUF_SIZE], output[MAX_BUF_SIZE];
    int freq[MAX_BUF_SIZE], encoding[MAX_BUF_SIZE];
    int len, i, j, k, c;

    // read input string from user and calculate frequency of each character
    printf("Enter the input string: ");
    fgets(input, MAX_BUF_SIZE, stdin);
    len = strlen(input);
    for(i = 0; i < len; i++) {
        freq[i] = 1;
        for(j = i+1; j < len; j++) {
            if(input[i] == input[j]) {
                freq[i]++;
                for(k = j; k < len; k++) {
                    input[k] = input[k+1];
                }
                len--;
                j--;
            }
        }
    }

    // sort frequency array in ascending order
    for(i = 0; i < len; i++) {
        for(j = i+1; j < len; j++) {
            if(freq[i] > freq[j]) {
                c = freq[i];
                freq[i] = freq[j];
                freq[j] = c;

                c = input[i];
                input[i] = input[j];
                input[j] = c;
            }
        }
    }

    // create encoding dictionary
    for(i = 0; i < len; i++) {
        encoding[i] = i+1;
    }

    // compress input string using Huffman encoding
    for(i = 0; i < len; i++) {
        for(j = 0; j < len; j++) {
            if(input[i] == input[j]) {
                for(k = i; k <= j; k++) {
                    output[k] = encoding[i] + '0';
                }
                i = j;
                break;
            }
        }
    }

    // print compressed output
    printf("Compressed output: %s\n", output);

    return 0;
}