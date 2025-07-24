//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>

int main() {
    char c_color_code[8];
    printf("Enter a valid C color code (e.g. #FF5733): ");
    scanf("%s", c_color_code);

    // Separating the hexadecimal values from the C color code
    int r = (int)strtol(&c_color_code[1], NULL, 16);
    int g = (int)strtol(&c_color_code[3], NULL, 16);
    int b = (int)strtol(&c_color_code[5], NULL, 16);

    printf("The RGB values of %s are R:%d, G:%d, B:%d\n", c_color_code, r, g, b);

    // Converting RGB values to hex
    char r_hex[3], g_hex[3], b_hex[3];
    snprintf(r_hex, 3, "%02X", r);
    snprintf(g_hex, 3, "%02X", g);
    snprintf(b_hex, 3, "%02X", b);

    printf("The hex code of %s is #%s%s%s\n", c_color_code, r_hex, g_hex, b_hex);

    return 0;
}