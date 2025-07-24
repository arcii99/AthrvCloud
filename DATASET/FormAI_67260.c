//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void generate_art(int rows, int cols) {
    int i,j,k;
    char *ascii_art[7] = {"#####", "#    #", "#    #", "######", "#    #", "#    #", "#    #"};
    char *top_border = "   ";
    char *bottom_border = "   ";
    char *middle_line = "   ";

    for (i = 0; i < cols; i++) {
        top_border = strcat(top_border, "_");
        bottom_border = strcat(bottom_border, "-");
        middle_line = strcat(middle_line, " ");
    }

    printf("%s\n", top_border);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < 7; j++) {
            for (k = 0; k < cols; k++) {
                if (k == 0) {
                    printf("| ");
                }
                printf("%c ", ascii_art[j][i]);
                if (k == cols-1) {
                    printf("|\n");
                }
            }
        }
    }

    printf("%s\n", bottom_border);
}


int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    generate_art(rows, cols);

    return 0;
}