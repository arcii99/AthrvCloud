//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input_date[11]; // This will hold the user input
    char output_date[11]; // This will hold the converted output
    char month_names[12][4] = {
        "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    }; // Array holding month names
    
    // Prompt the user for input
    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input_date, 11, stdin); // Read the input
    
    // Separate the input into day, month, and year
    int day = atoi(&input_date[0]);
    int month = atoi(&input_date[3]);
    int year = atoi(&input_date[6]);
    
    // Convert month number to a 3-letter month name
    char month_name[4];
    strcpy(month_name, month_names[month - 1]);
    
    // Format the output string
    sprintf(output_date, "%d-%s-%d", day, month_name, year);
    
    // Print the output
    printf("Converted date: %s\n", output_date);
    
    return 0;
}