//FormAI DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    FILE *file_ptr;
    struct Person person1;
    struct Person person2 = {"John", 30};

    file_ptr = fopen("people.txt", "w");

    if (file_ptr == NULL) {
        printf("Error opening file");
    } else {
        printf("Enter your name: ");
        scanf("%s", person1.name);

        printf("Enter your age: ");
        scanf("%d", &person1.age);

        fprintf(file_ptr, "Name: %s, Age: %d\n", person1.name, person1.age);
        fprintf(file_ptr, "Name: %s, Age: %d\n", person2.name, person2.age);

        fclose(file_ptr);
    }

    file_ptr = fopen("people.txt", "r");

    if (file_ptr == NULL) {
        printf("Error opening file");
    } else {
        char buffer[50];

        while (fgets(buffer, sizeof(buffer), file_ptr)) {
            printf("%s", buffer);
        }

        fclose(file_ptr);
    }

    return 0;
}