//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Define the maximum length of each field
#define MAX_FIELD_LEN 100

// Define the maximum number of fields in each row
#define MAX_FIELDS 10 

// Define the maximum number of rows in the CSV file
#define MAX_ROWS 1000 

// Define the error codes
#define INVALID_CSV_FILE_FORMAT -1 // when the CSV file is not in the correct format
#define MAX_ROWS_EXCEEDED -2 // when the number of rows exceed the predefined limit

// Main function where the CSV reader module is implemented
int main() {
    char csv_data[MAX_ROWS][MAX_FIELDS][MAX_FIELD_LEN]; // Array to store the CSV data   
    int row_count = 0, field_count = 0; // Variable to keep track of the row and field count

    FILE *csv_file = fopen("sample.csv", "r"); // Open the CSV file in read mode
    if (csv_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char csv_line[MAX_ROWS][MAX_FIELDS][MAX_FIELD_LEN]; // Array to store each CSV line
    char buffer[MAX_FIELD_LEN]; // Temporary buffer to hold each field

    // Loop through each line in the CSV file and store in csv_line array
    while (fgets(buffer, MAX_FIELD_LEN, csv_file)) {
        char *field = strtok(buffer, ",\n"); // Tokenize the first field
        while (field != NULL) {
            strcpy(csv_line[row_count][field_count], field); // Copy the field to csv_line array
            field = strtok(NULL, ",\n"); // Tokenize the next field
            field_count++; // Increment the field count
        }
        
        if (field_count > MAX_FIELDS) {
            printf("Error: Invalid CSV file format!\n");
            return INVALID_CSV_FILE_FORMAT; // Invalid CSV file format error
        }
        row_count++; // Increment the row count
        field_count = 0; // Reset the field count for the next row
        
        if (row_count > MAX_ROWS) {
            printf("Error: Maximum number of rows exceeded!\n");
            return MAX_ROWS_EXCEEDED; // Maximum number of rows exceeded error
        }
    }
    
    // Copy the csv_line array to csv_data array
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < field_count; j++) {
            strcpy(csv_data[i][j], csv_line[i][j]);
        }
    }
    
    fclose(csv_file); // Close the CSV file after reading
    
    // Print the CSV data from csv_data array
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < field_count; j++) {
            printf("%s\t", csv_data[i][j]);
        }
        printf("\n");
    }
    
    return 0; // Successful program execution
}