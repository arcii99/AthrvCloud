//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a range
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// Function to select a random fortune
char* selectFortune(int num) {
    switch (num) {
        case 1:
            return "The journey of a thousand miles begins with one step.";
            break;
        case 2:
            return "Happiness is not something ready made. It comes from your own actions.";
            break;
        case 3:
            return "Believe you can and you're halfway there.";
            break;
        case 4:
            return "The best way to predict the future is to create it.";
            break;
        case 5:
            return "Nothing is impossible, the word itself says 'I'm possible'!";
            break;
        case 6:
            return "In the end, it's not the years in your life that count. It's the life in your years.";
            break;
        case 7:
            return "You miss 100% of the shots you don't take.";
            break;
        case 8:
            return "The only way to do great work is to love what you do.";
            break;
        case 9:
            return "Success is not final, failure is not fatal: it is the courage to continue that counts.";
            break;
        case 10:
            return "The big secret in life is that there is no secret. Whatever your goal, you can get there if you're willing to work.";
            break;
        default:
            return "Unknown fortune.";
            break;
    }
}

int main() {
    int randomNumber = generateRandomNumber(1, 10);
    char *fortune = selectFortune(randomNumber);
    printf("The fortune teller says: \"%s\"\n", fortune);
    return 0;
}