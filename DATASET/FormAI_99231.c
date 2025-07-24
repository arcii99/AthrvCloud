//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert C natural language date to standard YYYY-MM-DD format
char *cnld_to_iso(char *cnld) {
    char *months[] = {"january", "february", "march", "april", "may", "june",
                      "july", "august", "september", "october", "november", "december"};
    char *month;
    int day, year;
    char *token;

    // Replace commas and "th" suffixes in date string
    char *ptr = strtok(cnld, ",");
    char new_cnld[50];
    strcpy(new_cnld, "");
    while (ptr != NULL) {
        if (strstr(ptr, "th") != NULL) {
            char *suffix = "th";
            char *pos = strstr(ptr, suffix);
            int index = pos - ptr;
            ptr[index] = '\0';
            strcat(new_cnld, ptr);
            strcat(new_cnld, " ");
            strcat(new_cnld, suffix);
        } else {
            strcat(new_cnld, ptr);
        }
        strcat(new_cnld, ",");
        ptr = strtok(NULL, ",");
    }
    new_cnld[strlen(new_cnld) - 1] = '\0';

    // Extract day, month and year from modified date string
    token = strtok(new_cnld, " ");
    day = atoi(token);
    token = strtok(NULL, " ");
    month = token;
    token = strtok(NULL, " ");
    year = atoi(token);

    // Convert month to integer format
    int i;
    for (i = 0; i < 12; i++) {
        if (strcasecmp(month, months[i]) == 0) {
            break;
        }
    }
    i++; // Month indexing starts at 01
    char month_str[3];
    sprintf(month_str, "%02d", i);

    // Convert day to two-digit string
    char day_str[3];
    sprintf(day_str, "%02d", day);

    // Convert year to string
    char year_str[5];
    sprintf(year_str, "%04d", year);

    // Concatenate date components into ISO format string
    char *iso_date = malloc(sizeof(char) * 11);
    strcpy(iso_date, "");
    strcat(iso_date, year_str);
    strcat(iso_date, "-");
    strcat(iso_date, month_str);
    strcat(iso_date, "-");
    strcat(iso_date, day_str);

    return iso_date;
}

int main() {
    char *example_cnld = "June 18th, 2021";
    char *iso_date = cnld_to_iso(example_cnld);
    printf("C Natural Language Date: %s\n", example_cnld);
    printf("ISO Date: %s\n", iso_date);
    free(iso_date);
    return 0;
}