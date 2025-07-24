//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
// C Natural Language Date Converter Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void date_conversion(char *input_date) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char *output_date = malloc(sizeof(char) * 11);
    int year, month, day;
    char delimiter[2];

    sscanf(input_date, "%d%s%d%s%d", &day, delimiter, &year, delimiter, &month);

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        printf("Invalid date format. Please enter a valid date.\n");
        return;
    }

    sprintf(output_date, "%02d-%s-%04d", day, months[month - 1], year);
    printf("Converted date: %s\n", output_date);
    free(output_date);
}

int main() {
    char input_date[30];

    printf("Please enter a date in natural language format (e.g. '20th August 2019'): ");
    fgets(input_date, 30, stdin);
    input_date[strcspn(input_date, "\n")] = '\0';

    date_conversion(input_date);
    return 0;
}