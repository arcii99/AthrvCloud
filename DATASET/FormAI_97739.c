//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char input[100];
    int len;
    int i, j;
    char ascii[10][100] = {
        {"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"},
        {"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"},
        {"@@@  @@@@   @@@@@@@   @@@@   @@@@@@@   @@@@"},
        {"@@@  @@@@  @@@  @@@@  @@@@  @@@  @@@@  @@@@"},
        {"@@@@@@@@@  @@@@@@@@@  @@@@  @@@@@@@@@  @@@@"},
        {"@@@@@@@@@  @@@    @@  @@@@  @@    @@@  @@@@"},
        {"@@@  @@@@  @@@@@@@@@  @@@@  @@@@@@@@@  @@@@"},
        {"@@@  @@@@  @@@    @@  @@@@  @@    @@@  @@@@"},
        {"@@@@@@@@@  @@@@@@@@@ @@@@@  @@@@@@@@@@@@@@@"},
        {"@@@@@@@@@  @@@@@@@@@  @@@@  @@@@@@@@@@@@@@@"}
    };

    printf("Enter a string: ");
    scanf("%s", input);

    len = strlen(input);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < len; j++) {
            if (input[j] >= 'a' && input[j] <= 'z') {
                printf("%s ", ascii[input[j] - 'a']);
            } else if (input[j] >= 'A' && input[j] <= 'Z') {
                printf("%s ", ascii[input[j] - 'A']);
            } else {
                printf("         ");
            }
        }
        printf("\n");
    }
    return 0;
}