//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Bingo Simulator!\n");

    // Generating random numbers
    srand(time(0));
    int numbers[75];
    for(int i=0; i<75; i++) {
        numbers[i] = i+1;
    }

    // Shuffling the numbers
    for (int i=0; i<75; i++) {
        int random = rand()%75;
        int temp = numbers[i];
        numbers[i] = numbers[random];
        numbers[random] = temp;
    }

    // Displaying the shuffled numbers
    printf("\nHere are your Bingo numbers:\n");
    int count = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<15; j++) {
            printf("%2d ", numbers[count]);
            count++;
        }
        printf("\n");
    }
    printf("\n");

    // Asking user to call out numbers
    int called_numbers[75] = {0};
    int bingo = 0;
    while (!bingo) {
        printf("Enter the number you want to call out (1-75): ");
        int called_number;
        scanf("%d", &called_number);
        if (called_number<1 || called_number>75) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        called_numbers[called_number-1] = 1;

        // Checking for bingo
        int row[5] = {0};
        int col[5] = {0};
        int diagonal1 = 0;
        int diagonal2 = 0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<15; j++) {
                if (numbers[i*15+j] == called_number) {
                    row[i]++;
                    col[j]++;
                    if (i == j) {
                        diagonal1++;
                    }
                    if (i+j == 4) {
                        diagonal2++;
                    }
                }
            }
        }
        if (row[0]==5 || row[1]==5 || row[2]==5 || row[3]==5 || row[4]==5 || col[0]==5 || col[1]==5 || col[2]==5 || col[3]==5 || col[4]==5
        || col[5]==5 || col[6]==5 || col[7]==5 || col[8]==5 || col[9]==5 || col[10]==5 || col[11]==5 || col[12]==5 || col[13]==5 || col[14]==5
        || diagonal1==5 || diagonal2==5) {
            bingo = 1;
        }
    }

    // Displaying the final result
    printf("\nBingo! You have won!\n");
    
    return 0;
}