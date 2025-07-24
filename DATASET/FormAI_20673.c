//FormAI DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>

int main() {
    FILE *fp;
    int employeeId, age;
    char name[20], position[20];
    
    fp = fopen("employeeDetails.txt", "a");
    
    printf("Enter Employee ID: ");
    scanf("%d", &employeeId);
    
    printf("Enter Name: ");
    scanf("%s", name);
    
    printf("Enter Age: ");
    scanf("%d", &age);
    
    printf("Enter Position: ");
    scanf("%s", position);
    
    fprintf(fp, "Employee ID: %d\n", employeeId);
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Age: %d\n", age);
    fprintf(fp, "Position: %s\n", position);
    
    printf("\nDetails added to file successfully!\n");
    
    fclose(fp);
    
    return 0;
}