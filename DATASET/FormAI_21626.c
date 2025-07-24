//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

void convertToWords(char *date);

int main() {
    char date[11];
    printf("Enter a date in format DD/MM/YYYY: ");
    fgets(date, sizeof(date), stdin);
    convertToWords(date);
    return 0;
}

void convertToWords(char *date) {
    char *months[12] = {"January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};
    char day[3], month[10], year[5];
    int i = 0, j = 0, k = 0;
    while (date[i] != '/') {
        day[j++] = date[i++];
    }
    day[j] = '\0';
    i++;
    while (date[i] != '/') {
        month[k++] = date[i++];
    }
    month[k] = '\0';
    i++;
    while (date[i] != '\0') {
        year[k++] = date[i++];
    }
    year[k] = '\0';
    int dayInt = atoi(day);
    printf("%s %d, %s\n", months[atoi(month) - 1], dayInt, year);
}