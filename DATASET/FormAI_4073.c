//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    // Define the XML string
    char xml[] = "<employees>"
                 "<employee>"
                 "<id>1</id>"
                 "<name>John Smith</name>"
                 "<position>Manager</position>"
                 "</employee>"
                 "<employee>"
                 "<id>2</id>"
                 "<name>Jane Doe</name>"
                 "<position>Assistant Manager</position>"
                 "</employee>"
                 "</employees>";

    // Count the number of employees in the XML string
    int count = 0;
    char* open = strstr(xml, "<employee>");
    while (open != NULL) {
        count++;
        open = strstr(open + 1, "<employee>");
    }

    // Print the number of employees
    printf("Number of employees: %d\n", count);

    // Parse the XML string and extract employee information
    char* ptr = xml;
    for (int i = 0; i < count; i++) {
        // Extract the employee ID
        ptr = strstr(ptr + 1, "<id>");
        char* end = strstr(ptr + 1, "</id>");
        char id[10];
        strncpy(id, ptr + 4, end - ptr - 4);
        id[end - ptr - 4] = '\0';

        // Extract the employee name
        ptr = strstr(ptr + 1, "<name>");
        end = strstr(ptr + 1, "</name>");
        char name[50];
        strncpy(name, ptr + 6, end - ptr - 6);
        name[end - ptr - 6] = '\0';

        // Extract the employee position
        ptr = strstr(ptr + 1, "<position>");
        end = strstr(ptr + 1, "</position>");
        char position[50];
        strncpy(position, ptr + 10, end - ptr - 10);
        position[end - ptr - 10] = '\0';

        // Print the employee information
        printf("Employee #%s:\n\tName: %s\n\tPosition: %s\n", id, name, position);
    }

    return 0;
}