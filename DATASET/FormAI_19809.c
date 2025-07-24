//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants
#define MAX_INPUT_LEN 20
#define MAX_OUTPUT_LEN 100

// function to convert date from natural language to standard format
char* convert_date(char* input_date) {
    // define arrays for month names and abbreviations
    char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char* month_abbrs[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // get current year from system time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int current_year = tm.tm_year + 1900;

    // initialize variables
    char* output_date = malloc(MAX_OUTPUT_LEN * sizeof(char));
    int day = 0;
    int month = -1;
    int year = current_year;

    // tokenize input_date string to get day, month, and year
    char* token = strtok(input_date, " ");
    while (token != NULL) {
        if (atoi(token) != 0) {
            // token is a number, so it must be the day
            day = atoi(token);
        } else if (strstr(token, "th") != NULL || strstr(token, "st") != NULL || strstr(token, "nd") != NULL || strstr(token, "rd") != NULL) {
            // token contains an ordinal indicator, so it is the day
            day = atoi(strtok(token, "thstndrd"));
        } else if (strlen(token) <= 3 && strchr(token, '.') == NULL) {
            // token is an abbreviation for a month
            for (int i = 0; i < 12; i++) {
                if (strncasecmp(token, month_abbrs[i], strlen(token)) == 0) {
                    month = i;
                    break;
                }
            }
        } else if (strlen(token) > 3 && strchr(token, '.') == NULL) {
            // token is a full name for a month
            for (int i = 0; i < 12; i++) {
                if (strncasecmp(token, month_names[i], strlen(token)) == 0) {
                    month = i;
                    break;
                }
            }
        } else if (strlen(token) == 4 && atoi(token) > 1000) {
            // token is a year
            year = atoi(token);
        }

        token = strtok(NULL, " ");
    }

    // check if day and month were found, otherwise return NULL
    if (day == 0 || month == -1) {
        printf("Invalid input date format\n");
        free(output_date);
        return NULL;
    }

    // format output date string
    snprintf(output_date, MAX_OUTPUT_LEN, "%02d/%02d/%d", month + 1, day, year);

    return output_date;
}

int main() {
    // initialize variables
    char input_date[MAX_INPUT_LEN];
    char* output_date;

    // get input date from user
    printf("Enter a date in natural language (e.g. August 13th): ");
    fgets(input_date, MAX_INPUT_LEN, stdin);
    input_date[strcspn(input_date, "\n")] = '\0';

    // convert input date to standard format
    output_date = convert_date(input_date);

    // print result
    if (output_date != NULL) {
        printf("Standard date format: %s\n", output_date);
    }

    // free memory and exit program
    free(output_date);
    return 0;
}