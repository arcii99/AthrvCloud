//FormAI DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>

int main() {
    int R, G, B;

    printf("Enter the decimal values of R, G, and B between 0 and 255 separated by spaces: ");
    scanf("%d %d %d", &R, &G, &B);

    printf("RGB: (%d, %d, %d)\n", R, G, B);

    // Convert RGB to HEX and print the result
    printf("HEX: #%02X%02X%02X\n", R, G, B);

    // Convert RGB to CMYK and print the result
    int C = 255 - R;
    int M = 255 - G;
    int Y = 255 - B;
    int K = (C < M) ? ((C < Y) ? C : Y) : ((M < Y) ? M : Y);
    C = (C - K) * 100 / (255 - K);
    M = (M - K) * 100 / (255 - K);
    Y = (Y - K) * 100 / (255 - K);
    printf("CMYK: (%d%%, %d%%, %d%%, %d%%)\n", C, M, Y, K);

    return 0;
}