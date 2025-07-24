//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>

// Define a struct for a person
struct person {
    char name[50];
    int age;
};

int main() {
    struct person p1;
    printf("Enter name: ");
    fgets(p1.name, 50, stdin);
    printf("Enter age: ");
    scanf("%d", &p1.age);
    printf("Hello, my name is %s and I am %d years old.\n", p1.name, p1.age);
    return 0;
}