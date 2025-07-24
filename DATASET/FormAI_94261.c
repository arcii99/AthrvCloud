//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, sum = 0;
    char name[20];

    time_t t;
    srand((unsigned) time(&t));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello %s! Let's generate your fortune...\n", name);

    printf("Pick a number between 1 and 10:\n");
    scanf("%d", &num);

    if (num <= 0 || num > 10) {
        printf("Invalid number input. Try again with a number between 1 and 10.\n");
    } else {
        sum += num;
        printf("Your lucky number is: %d\n", num);

        printf("Let's generate another lucky number! Pick a number between 1 and 5:\n");
        scanf("%d", &num);

        if (num <= 0 || num > 5) {
            printf("Invalid number input. Try again with a number between 1 and 5.\n");
        } else {
            sum += num;
            printf("Your second lucky number is: %d\n", num);

            printf("One last number! Pick a number between 1 and 3:\n");
            scanf("%d", &num);

            if (num < 1 || num > 3) {
                printf("Invalid number input. Try again with a number between 1 and 3.\n");
            } else {
                sum += num;
                printf("Your final lucky number is: %d\n", num);

                printf("Calculating your fortune...\n");

                switch (sum % 7) {
                    case 0:
                        printf("Bad news %s, things are not looking good for you.\n", name);
                        break;
                    case 1:
                        printf("Good news %s, fortune smiles upon you.\n", name);
                        break;
                    case 2:
                        printf("You will face some tough challenges %s, but you will succeed.\n", name);
                        break;
                    case 3:
                        printf("You will receive a windfall of good luck %s, enjoy it while it lasts.\n", name);
                        break;
                    case 4:
                        printf("Be careful %s, as danger is near.\n", name);
                        break;
                    case 5:
                        printf("Romance is in your future %s, look out for it.\n", name);
                        break;
                    case 6:
                        printf("Keep your eyes peeled %s, as opportunity is coming your way.\n", name);
                        break;
                }
            }
        }
    }

    return 0;
}