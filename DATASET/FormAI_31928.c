//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include <stdio.h>

// from Gregorian to Julian Date
int gregorian_to_julian(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
    return jdn;
}

// from Julian to Gregorian Date
void julian_to_gregorian(int jdn, int *day, int *month, int *year) {
    int a, b, c, d, e, m, y;
    jdn += 32044;
    a = (4 * jdn + 3) / 146097;
    b = jdn - (146097 * a) / 4;
    c = (4 * b + 3) / 1461;
    d = b - (1461 * c) / 4;
    e = (5 * d + 2) / 153;
    *day = d - (153 * e + 2) / 5 + 1;
    *month = e + 3 - 12 * (e / 10);
    *year = 100 * a + c - 4800 + (e / 10);
}

int main() {
    int day, month, year, jdn;
    printf("Enter date in format DD MM YYYY: ");
    scanf("%d %d %d", &day, &month, &year);
    jdn = gregorian_to_julian(day, month, year);
    printf("The Julian Date is: %d", jdn);
    julian_to_gregorian(jdn, &day, &month, &year);
    printf("\nThe converted Gregorian Date is: %d %d %d", day, month, year);
    return 0;
}