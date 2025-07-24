//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>

int main() {
    int day, month, year;
    char entry[1000];

    // User inputs date
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // User inputs diary entry
    printf("Enter diary entry:\n");
    scanf(" %[^\n]s", entry);

    // Print formatted diary entry
    printf("\n\n**************************************************\n");
    printf("            Mathematical Digital Diary             \n");
    printf("**************************************************\n\n");
    printf("           Date: %02d/%02d/%d\n", day, month, year);
    printf("\n                Entry:\n\n%s\n\n", entry);
    printf("**************************************************\n");

    return 0;
}