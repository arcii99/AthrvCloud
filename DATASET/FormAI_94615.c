//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void convert_to_date(int julian_day);

int main() {
    int julian_day;

    printf("Enter the Julian Day: ");
    scanf("%d", &julian_day);

    convert_to_date(julian_day);

    return 0;
}

void convert_to_date(int julian_day) {
    int year, month, day;
    int a, b, c, d, e, f;

    a = julian_day + 32044;
    b = (4 * a + 3) / 146097;
    c = a - (146097 * b / 4);
    d = (4 * c + 3) / 1461;
    e = c - (1461 * d / 4);
    f = (5 * e + 2) / 153;
    day = e - ((153 * f + 2) / 5) + 1;
    month = f + 3 - 12 * (f / 10);
    year = 100 * b + d - 4800 + (f / 10);

    printf("The Julian Day %d converts to %d-%02d-%02d\n", julian_day, year, month, day);
}