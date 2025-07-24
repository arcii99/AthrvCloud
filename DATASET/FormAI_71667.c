//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char* fortunes[] = {"A beautiful, smart, and loving person will be coming into your life.",
                    "A dubious friend may be an enemy in camouflage.",
                    "A faithful friend is a strong defense.",
                    "A fresh start will put you on your way.",
                    "A journey of a thousand miles begins with a single step.",
                    "A lifetime of happiness awaits you.",
                    "A pleasant surprise is in store for you.",
                    "A problem well stated is a problem half solved.",
                    "A thrilling time is in your immediate future.",
                    "Adversity is the parent of virtue."};
    int numfortunes = sizeof(fortunes) / sizeof(char*);
    time_t t;
    srand((unsigned) time(&t));
    int random = rand() % numfortunes;
    printf("Your fortune for today is: %s\n", fortunes[random]);
    return 0;
}