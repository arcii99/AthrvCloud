//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* getFortune(int i) {
    switch (i) {
        case 1: return "Today is your lucky day!";
        case 2: return "You will find success in your career!";
        case 3: return "Travel is in your future!";
        case 4: return "A new relationship is coming your way!";
        case 5: return "Your hard work will pay off soon!";
        case 6: return "Your health will improve!";
        case 7: return "A financial windfall is on the horizon!";
        case 8: return "You will find inner peace!";
        case 9: return "Someone will come into your life and change it forever!";
        default: return "Your future is uncertain, but don't worry - everything will work out in the end.";
    }
}

void main() {
    int num = 0;
    srand(time(NULL));
    
    printf("Welcome to the automated fortune teller! \n");
    while (num != -1) {
        printf("Enter any number from 1-9, or -1 to exit: ");
        scanf("%d", &num);
        if (num == -1) {
            printf("Goodbye!\n");
            break;
        } else if (num < 1 || num > 9) {
            printf("Invalid input.\n");
            continue;
        } else {
            int r = rand() % 4 + 1;
            printf("%s\n", getFortune(num));
            if (r == 1) printf("Lucky numbers for you: %d %d %d\n", rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1);
            printf("\n");
        }
    }   
}