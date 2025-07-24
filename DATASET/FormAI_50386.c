//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random_number(int max_value) {
    srand(time(NULL));
    return rand() % max_value;
}

char *get_fortune(int index) {
    switch (index) {
        case 0:
            return "A great fortune awaits you in the coming days";
        case 1:
            return "Today is your lucky day! Expect good news";
        case 2:
            return "Kindness will come your way from an unexpected source";
        case 3:
            return "Success is on the horizon for you";
        case 4:
            return "Your future is bright, keep pushing forward";
        case 5:
            return "You will find love and happiness sooner than you expect";
        case 6:
            return "A major change is coming your way, be prepared";
        case 7:
            return "Good things come to those who wait, stay patient";
        case 8:
            return "Your creativity will lead you to new opportunities";
        case 9:
            return "Luck is on your side, take a chance on something new";
        default:
            return "Could not generate fortune, please try again";
    }
}

int main() {
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please input your name: ");
    char name[100];
    fgets(name, 100, stdin);
    printf("\nHello %s", name);
    printf("Press any key to generate your fortune...\n");
    getchar();
    printf("\n");
    int index = generate_random_number(10);
    char* fortune = get_fortune(index);
    printf("Your fortune for today is: \n%s\n", fortune);
    printf("Thank you for using our automated fortune teller! Have a great day!\n");
    return 0;
}