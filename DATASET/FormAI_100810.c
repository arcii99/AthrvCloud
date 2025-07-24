//FormAI DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>

void handleError() {
    printf("There was an error!\n");
    // Do some error handling here...
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 10; // Intentionally out of bounds

    // Try to access an element out of bounds
    if (index < 0 || index >= 5) {
        handleError();
        return 1;
    }

    // Access the element
    int result = arr[index];

    printf("The result is: %d\n", result);

    return 0;
}