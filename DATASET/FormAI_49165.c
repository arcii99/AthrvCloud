//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>

int main() {
    int day, month, year;
    
    // Prompt user for input date
    printf("Enter date in format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);
    
    // Convert date to another format
    printf("Date in MM-DD-YYYY format: %02d-%02d-%04d\n", month, day, year);
    
    return 0;
}