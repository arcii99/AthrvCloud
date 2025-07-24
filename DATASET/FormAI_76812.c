//FormAI DATASET v1.0 Category: Data validation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float height;
} Person;

int is_valid_name(char *name);
int is_valid_age(char *age);
int is_valid_height(char *height);

int main() {
    Person p;
    char input[50];
    int valid = 0;
    
    // Get and validate the name
    do {
        printf("Enter name: ");
        fgets(input, sizeof(input), stdin);
        if (is_valid_name(input)) {
            valid = 1;
            strcpy(p.name, input);
        } else {
            printf("Invalid name. Please try again.\n");
        }
    } while (!valid);
    
    valid = 0;
    
    // Get and validate the age
    do {
        printf("Enter age: ");
        fgets(input, sizeof(input), stdin);
        if (is_valid_age(input)) {
            valid = 1;
            p.age = atoi(input);
        } else {
            printf("Invalid age. Please try again.\n");
        }
    } while (!valid);
    
    valid = 0;
    
    // Get and validate the height
    do {
        printf("Enter height: ");
        fgets(input, sizeof(input), stdin);
        if (is_valid_height(input)) {
            valid = 1;
            p.height = atof(input);
        } else {
            printf("Invalid height. Please try again.\n");
        }
    } while (!valid);
    
    // Print the validated data
    printf("\nName: %s", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.2f\n", p.height);
    
    return 0;
}

// Validates that a name only contains letters and spaces
int is_valid_name(char *name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) {
            return 0;
        }
    }
    return 1;
}

// Validates that an age is a number between 1 and 120
int is_valid_age(char *age) {
    int num = atoi(age);
    if (num >= 1 && num <= 120) {
        return 1;
    }
    return 0;
}

// Validates that a height is a number between 1 and 8 feet
int is_valid_height(char *height) {
    float num = atof(height);
    if (num >= 1 && num <= 8) {
        return 1;
    }
    return 0;
}