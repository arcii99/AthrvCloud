//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
// Irregular C Compression Algorithm Example
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000
#define MAX_CONSEC 3

typedef struct {
    char symbol;
    int length;
} Run;

int main() {
    char str[MAX_LENGTH];
    printf("Enter string to compress: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character
    
    int len = strlen(str);
    Run runs[MAX_LENGTH/2];
    int num_runs = 0;
    int consec_count = 1; // consecutive count of same character
    
    for (int i = 1; i <= len; i++) {
        if (str[i] == str[i-1]) { // check for consecutive characters
            consec_count++;
            if (consec_count > MAX_CONSEC) { // limit consecutive characters
                str[i-1] = '+'; // replace with symbol indicating multiple characters
                consec_count = 1;
            }
        } else {
            runs[num_runs].symbol = str[i-1];
            runs[num_runs].length = consec_count;
            num_runs++;
            consec_count = 1;
        }
    }
    
    printf("Compressed string: ");
    for (int i = 0; i < num_runs; i++) {
        printf("%c%d", runs[i].symbol, runs[i].length); // print compressed format
    }
    printf("\n");
    
    return 0;
}