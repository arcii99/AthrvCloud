//FormAI DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    int year, month, day;
    char entry[1000];
    
    // Get user input for date and entry
    printf("Enter the date (yyyy/mm/dd): ");
    scanf("%d/%d/%d", &year, &month, &day);
    printf("Enter your entry for today:\n");
    getchar(); // Clear stdin buffer
    fgets(entry, 1000, stdin); // Read user input
    
    // Create file name based on date
    char file_name[100];
    sprintf(file_name, "diary_%04d-%02d-%02d.txt", year, month, day);
    
    // Open file for writing
    FILE *fptr;
    fptr = fopen(file_name, "w");
    
    // Write entry to file
    fprintf(fptr, "Date: %04d/%02d/%02d\nEntry: %s", year, month, day, entry);
    
    // Close file
    fclose(fptr);
    
    printf("\nSuccessfully added entry to diary!\n");
    
    return 0;
}