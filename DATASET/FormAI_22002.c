//FormAI DATASET v1.0 Category: Image compression ; Style: bold
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

void compressImage(char **image, int row, int col) {
    int i, j, count;
    char curr_char;
    char *result = (char *) malloc(sizeof(char) * MAX_LEN);
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            curr_char = image[i][j];
            count = 1;
            while (j + 1 < col && image[i][j + 1] == curr_char) {
                count++;
                j++;
            }
            sprintf(result, "%s%d%c", result, count, curr_char);
        }
        sprintf(result, "%s\n", result);
    }
    printf("%s", result);
}

int main() {
    char *image[] = {"WWWBWWBWW", "BWWWWWWBW", "WWWBWWBWW", "BWBWWWWWW", "WWWWWWWWW", "WWWWWWWWW", "BWWWWBWWB"};
    int row = 7, col = 9;
    compressImage(image, row, col);
    return 0;
}