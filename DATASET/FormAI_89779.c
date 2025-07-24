//FormAI DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(char *msg) {
    printf("Error: %s\n", msg);
    printf("Aborting program.\n");
    exit(1);
}

int main() {
    int num;
    char *str = malloc(sizeof(char) * 10);

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        handle_error("Invalid input.");
    }

    printf("Enter a string (max 10 characters): ");
    if (scanf("%s", str) != 1 || strlen(str) > 10) {
        handle_error("Invalid input.");
    }

    int *arr = malloc(sizeof(int) * num);
    if (arr == NULL) {
        handle_error("Memory allocation failed.");
    }

    printf("Enter %d numbers:\n", num);
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            handle_error("Invalid input.");
        }
    }

    printf("The numbers you entered are:\n");
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    free(str);
    return 0;
}