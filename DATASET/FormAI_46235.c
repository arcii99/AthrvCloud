//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    int age, luckyNumber, currentYear, birthYear, diffYear, fortuneNumber;
    
    printf("Hello! I am the Automated Fortune Teller. What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! What is your age?\n", name);
    scanf("%d", &age);
    printf("Enter your lucky number:\n");
    scanf("%d", &luckyNumber);
    
    // Get the current year
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    currentYear = tm.tm_year + 1900;
    
    // Get the birth year
    printf("In what year were you born?\n");
    scanf("%d", &birthYear);
    diffYear = currentYear - birthYear;
    
    // Generate a random fortune number based on age and lucky number
    fortuneNumber = (age * luckyNumber) % diffYear;
    
    printf("Your fortune number is: %d\n", fortuneNumber);
    
    if (fortuneNumber <= 10) {
        printf("You will have a lucky day tomorrow!\n");
    } else if (fortuneNumber <= 20) {
        printf("You will receive some good news soon!\n");
    } else if (fortuneNumber <= 30) {
        printf("You will meet someone special in the near future!\n");
    } else if (fortuneNumber <= 40) {
        printf("You will soon embark on a new adventure!\n");
    } else if (fortuneNumber <= 50) {
        printf("You will achieve great success in your career!\n");
    } else {
        printf("Your future is bright!\n");
    }
    
    return 0;
}