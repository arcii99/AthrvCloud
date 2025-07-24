//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100], output[10];
    int month, day, year;
    
    printf("Enter a date in natural language (e.g. October 31, 2022): ");
    fgets(input, 100, stdin);
    
    // Convert month to number
    if (strstr(input, "January")) { month = 1; }
    else if (strstr(input, "February")) { month = 2; }
    else if (strstr(input, "March")) { month = 3; }
    else if (strstr(input, "April")) { month = 4; }
    else if (strstr(input, "May")) { month = 5; }
    else if (strstr(input, "June")) { month = 6; }
    else if (strstr(input, "July")) { month = 7; }
    else if (strstr(input, "August")) { month = 8; }
    else if (strstr(input, "September")) { month = 9; }
    else if (strstr(input, "October")) { month = 10; }
    else if (strstr(input, "November")) { month = 11; }
    else if (strstr(input, "December")) { month = 12; }
    else { printf("Invalid month\n"); return 1; }
    
    // Get day and year
    sscanf(input, "%*s %d, %d", &day, &year);
    
    // Format output
    sprintf(output, "%02d/%02d/%04d", month, day, year);
    
    printf("Machine-readable format: %s\n", output);
    
    return 0;
}