//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *file_name = "shape_shift.txt";
    char ch, new_ch, prev_ch;
    int count = 0, shift = 0;

    // Create and open a new file for writing
    FILE *file = fopen(file_name, "w");

    // Write some text to the file
    fputs("abcdefghijklmnopqrstuvwxyz", file);

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen(file_name, "r");

    // Read the first character from the file
    ch = fgetc(file);

    // Loop through the rest of the file
    while (ch != EOF) {
        // Determine the new character
        switch (count % 3) {
            case 0:
                new_ch = ch + shift;
                break;
            case 1:
                new_ch = ch - shift;
                break;
            case 2:
                new_ch = ch + (shift * 2);
                break;
        }

        // Print the new character
        printf("%c", new_ch);

        // Update the count and previous character
        prev_ch = ch;
        ch = fgetc(file);
        count++;

        // Determine the new shift value
        if (count % 5 == 0) {
            shift = prev_ch - 'a';
        }
    }

    // Close the file
    fclose(file);

    return 0;
}