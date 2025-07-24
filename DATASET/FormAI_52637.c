//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char date[20];
    int day, year, month;

    printf("Hey there, I'm Date Converter Bot! Give me a date in natural language format, like 'June 19, 2022': ");
    scanf("%[^\n]", date);
    getchar();

    // parse the user input using string manipulation
    char *ptr;
    ptr = strtok(date, " ,");
    month = convert_to_number(ptr);

    ptr = strtok(NULL, " ,");
    day = atoi(ptr);

    ptr = strtok(NULL, " ,");
    year = atoi(ptr);

    // output the result in a funny way
    printf("\nCalculating...\n\n");
    printf("👉 Beep boop beep...converting natural language date to numerical format...\n");
    printf("👉 Beep boop beep...calculating the age of the universe in dog years...\n");
    printf("👉 Beep boop beep...finding a needle in a haystack...\n");
    printf("👉 Beep boop beep...solving world hunger...");
    printf("👉 Beep boop beep...Ok, I got it! Your date in numerical format is: %d-%02d-%02d\n\n", year, month, day);

    printf("Thank you for using Date Converter Bot! Have a great day! 🤖👋\n");

    return 0;
}

int convert_to_number(char *month_name) {
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(month_name, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}