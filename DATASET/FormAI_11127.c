//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void do_something_risky(int risky_param) {
    // Simulating an error condition
    if (risky_param == 0) {
        errno = EINVAL;     // Set the error number
        perror("Invalid parameter: ");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int risky_param = 0;
    printf("Enter a non-zero value: ");
    scanf("%d", &risky_param);  // Read the risky parameter from user
    
    // Call the function that may generate error
    do_something_risky(risky_param);

    // If function returned without any error, do the rest of the program
    printf("You entered: %d\n", risky_param);
    return 0;
}