//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <math.h>

void colorCodeConverter(int colorCode[], int n);
int main() {
    int colorCode[6] = {0, 0, 0, 0, 0, 0};
    int n;
    printf("Enter the number of colors you want to convert: ");
    scanf("%d", &n);
    printf("Enter the color codes one by one:\n");
    colorCodeConverter(colorCode, n);
    printf("The equivalent decimal value of the color code is: ");
    int i, result = 0;
    for (i = 0; i < n; i++) {
        result += colorCode[i] * pow(16, n - i - 1);
    }
    printf("%d", result);
    return 0;
}

void colorCodeConverter(int colorCode[], int n) {
    if (n == 0) {
        return;
    }
    int color;
    printf("Enter the color code for index %d: ", 6 - n);
    scanf("%d", &color);
    if (color < 0 || color > 15) {
        printf("Invalid color code. Enter again.\n");
        colorCodeConverter(colorCode, n);
    } else {
        colorCode[6 - n] = color;
        colorCodeConverter(colorCode, n - 1);
    }
}