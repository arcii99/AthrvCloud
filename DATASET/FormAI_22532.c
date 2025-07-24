//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void convert_date(char* input_date, char* output_date) {
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));

    char* format;
    time_t t = time(NULL);

    // Check the input format
    if (strstr(input_date, "th") || strstr(input_date, "st") || strstr(input_date, "nd") || strstr(input_date, "rd")) {
        format = "%B %d %Y";
    } else {
        format = "%d %B %Y";
    }

    // Parse the input date
    strptime(input_date, format, &tm);

    // Convert to desired output format
    strftime(output_date, 100, "%A %B %d, %Y", &tm);

    // Print the output date
    printf("Converted Date: %s\n", output_date);
}

int main() {
    char input_date[100];
    char output_date[100];

    // Prompt the user for input
    printf("Enter a date: ");
    fgets(input_date, 100, stdin);
    input_date[strcspn(input_date, "\n")] = 0;

    // Call the asynchronous date converter function
    printf("Converting date...\n");
    sleep(1); // simulate asynchronous processing
    convert_date(input_date, output_date);

    return 0;
}