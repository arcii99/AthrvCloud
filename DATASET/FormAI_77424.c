//FormAI DATASET v1.0 Category: Data validation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Define lower and upper limits for data validation */
const int MIN_VALUE = 1;
const int MAX_VALUE = 100;

/* Function to validate user input */
int validateData(int data) {
    /* Check if data is within limits */
    if (data >= MIN_VALUE && data <= MAX_VALUE) {
        return data;
    } else {
        /* Display error message and ask for input again */
        printf("Error! Value must be between %d and %d. Please try again: ", MIN_VALUE, MAX_VALUE);
        scanf("%d", &data);
        return validateData(data); /* Call function recursively until correct input is provided */
    }
}

/* Main function */
int main() {
    int myData;

    /* Prompt user for input */
    printf("Please enter a value between %d and %d: ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &myData);

    /* Validate user input */
    myData = validateData(myData);

    /* Display validated data */
    printf("You entered: %d\n", myData);

    return 0;
}