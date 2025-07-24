//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
    char name[20], address[50], result[100];
    int age;
    float height;

    printf("Enter your name: ");
    fgets(name, 20, stdin);
    strtok(name, "\n"); // remove newline character

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your address: ");
    getchar(); // consume newline character left by previous scanf
    fgets(address, 50, stdin);
    strtok(address, "\n"); // remove newline character

    // concatenate information into a single string
    sprintf(result, "%s is %d years old, %.2f meters tall, and lives at %s.", name, age, height, address);

    printf("%s", result);

    // reverse the name string
    char reversed[20];
    int i, j;
    for (i = strlen(name) - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = name[i];
    }
    reversed[j] = '\0';

    printf("\n%s", reversed);

    return 0;
}