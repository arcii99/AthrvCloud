//FormAI DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>

int main() {
    float temp; 
    char unit;
    printf("Enter temperature followed by unit (C/F): ");
    scanf("%f%c", &temp, &unit);

    if(unit == 'F') {
        printf("%.2fF is equivalent to %.2fC", temp, (temp-32)*5/9);
    } else if(unit == 'C') {
        printf("%.2fC is equivalent to %.2fF", temp, (temp*9/5)+32);
    } else {
        printf("Invalid Input");
    }

    return 0;
}