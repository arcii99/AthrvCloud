//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

/*
 * This program demonstrates the implementation of a digital watermarking technique
 * where the text is embedded in an irregular pattern of spaces and tabs
 */

int main()
{
    char text[100], watermarked_text[100], temp_char;
    int i, j, k, num_tabs, num_spaces, toggle;

    // take input text from user
    printf("Enter the text to be watermarked: ");
    fgets(text, 100, stdin);

    // initialize variables
    i = j = k = num_tabs = num_spaces = toggle = 0;

    // iterate through the text and embed in the irregular pattern
    while (text[i] != '\0') {
        temp_char = text[i++];
        if (temp_char == ' ' || temp_char == '\t') {
            // do not embed in consecutive spaces or tabs
            if (toggle == 1) {
                toggle = 0;
            } else {
                toggle = 1;
                if (num_tabs <= num_spaces) {
                    for (j = 0; j < num_tabs; j++) {
                        watermarked_text[k++] = '\t';
                    }
                    for (j = 0; j < num_spaces; j++) {
                        watermarked_text[k++] = ' ';
                    }
                } else {
                    for (j = 0; j < num_spaces; j++) {
                        watermarked_text[k++] = ' ';
                    }
                    for (j = 0; j < num_tabs; j++) {
                        watermarked_text[k++] = '\t';
                    }
                }
                num_tabs = num_spaces = 0;
            }
            watermarked_text[k++] = temp_char;
        } else {
            if (toggle == 0) {
                toggle = 1;
                if (num_tabs <= num_spaces) {
                    for (j = 0; j < num_tabs; j++) {
                        watermarked_text[k++] = '\t';
                    }
                    for (j = 0; j < num_spaces; j++) {
                        watermarked_text[k++] = ' ';
                    }
                } else {
                    for (j = 0; j < num_spaces; j++) {
                        watermarked_text[k++] = ' ';
                    }
                    for (j = 0; j < num_tabs; j++) {
                        watermarked_text[k++] = '\t';
                    }
                }
                num_tabs = num_spaces = 0;
            }
            watermarked_text[k++] = temp_char;
            if (temp_char == ' ') {
                num_spaces++;
            } else if (temp_char == '\t') {
                num_tabs++;
            }
        }
    }

    // print the watermarked text
    printf("Watermarked text:\n%s", watermarked_text);

    return 0;
}