//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdio.h>

int main() {
    float temp, cel, fah;
    char scale;

    printf("Enter a temperature: ");
    scanf("%f %c", &temp, &scale);

    switch(scale) {
        case 'C': {
            cel = temp;
            fah = (cel * 9/5) + 32;
            break;
        }
        case 'F': {
            fah = temp;
            cel = (fah - 32) * 5/9;
            break;
        }
        default: {
            fprintf(stderr, "Invalid scale. Use 'C' or 'F'\n");
            return 1;
        }
    }

    printf("%.2f %c is %.2f %c\n", temp, scale, (scale == 'C' ? fah : cel), (scale == 'C' ? 'F' : 'C'));
    return 0;
}