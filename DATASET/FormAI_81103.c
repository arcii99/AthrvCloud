//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    int age;
    srand(time(NULL));
    int year = rand() % 11 + 2021;
    char* fortunes[] = {"You will find success in your future endeavors.", 
                        "A new opportunity will present itself to you soon.", 
                        "You will meet someone special in the coming weeks.", 
                        "Your hard work will pay off in the near future.", 
                        "You will receive unexpected good news in the next few days.", 
                        "Travel is in your future.", 
                        "Your finances will improve this year.", 
                        "You will learn a new skill in the coming months.", 
                        "Luck is on your side.", 
                        "Something you have been waiting for will finally happen."};
    int index = rand() % 10;
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("\n");
    printf("Thank you, %s. Here is your fortune for the year %d:\n", name, year);
    printf("\n");
    printf("%s\n", fortunes[index]);
    printf("\n");
    return 0;
}