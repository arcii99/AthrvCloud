//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main() {
    FILE *fileptr;
    char filename[50], ch, new_ch;

    printf("Enter filename: ");
    scanf("%s", filename);

    // Opening the file
    fileptr = fopen(filename, "r");

    if (fileptr == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    // Reversing the contents of file
    fseek(fileptr, -1L, SEEK_END);

    while (ftell(fileptr) > 0) {
        ch = fgetc(fileptr);

        // Conditional to skip newlines in the end
        if (ch == '\n') {
            fseek(fileptr, -2L, SEEK_CUR);
            continue;
        }

        printf("%c", ch);
        fseek(fileptr, -2L, SEEK_CUR);
    }

    // Printing the first character of the file
    fseek(fileptr, 0L, SEEK_SET);
    new_ch = fgetc(fileptr);
    printf("%c", new_ch);

    // Closing the file
    fclose(fileptr);

    return 0;
}