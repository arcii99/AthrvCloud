//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int i, j, num_correct = 0;
    char input[100];
    time_t start_t, end_t;
    double time_taken;

    // generate random string of characters
    char str[50] = "";
    srand(time(NULL));
    for (i = 0; i < 50; i++) {
        j = rand() % 26;
        str[i] = 'a' + j;
    }
    printf("Type the following string as fast as possible:\n");
    printf("%s\n", str);

    // get start time
    time(&start_t);

    // prompt user to type string
    printf("Type here: ");
    fgets(input, 100, stdin);

    // get end time and calculate time taken
    time(&end_t);
    time_taken = difftime(end_t, start_t);

    // check user input for correctness
    for (i = 0; i < 50; i++) {
        if (str[i] == input[i]) {
            num_correct++;
        }
    }

    // calculate accuracy and speed
    double accuracy = ((double) num_correct / 50) * 100;
    double speed = (double) num_correct / time_taken * 60;

    // print results
    printf("You typed %d characters correctly out of 50.\n", num_correct);
    printf("Your accuracy is %.2f%%\n", accuracy);
    printf("Your typing speed is %.2f characters per minute\n", speed);
    return 0;
}