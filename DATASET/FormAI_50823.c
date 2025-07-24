//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The following code implements a simple Intrusion detection system
 * that reads in a stream of characters and searches for a specific
 * pattern. If the pattern is found, it alerts the user. 
 * 
 * This program assumes that incoming data is not encrypted.
 */

int main(int argc, char *argv[]) {
    // Initialize variables
    int MAX_STRING_LENGTH = 1000;
    char input_line[MAX_STRING_LENGTH];
    int input_index = 0;
    char pattern[] = "hack";
    int pattern_index = 0;
    int match_index = -1;
    
    // Main loop
    while (fgets(input_line, MAX_STRING_LENGTH, stdin)) {
        // Loop through each character in input_line
        for (input_index = 0; input_index < strlen(input_line); input_index++) {
            // Check if current character matches the next character in the pattern
            if (input_line[input_index] == pattern[pattern_index]) {
                if (match_index == -1) {
                    match_index = input_index;
                }
                pattern_index++;
                // Check if pattern has been matched completely
                if (pattern_index == strlen(pattern)) {
                    printf("ALERT: Possible intrusion detected at index %d\n", match_index);
                    // Reset variables
                    pattern_index = 0;
                    match_index = -1;
                }
            } else {
                // Reset variables
                pattern_index = 0;
                match_index = -1;
            }
        }
    }
    return 0;
}