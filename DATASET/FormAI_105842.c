//FormAI DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20
#define MAX_DIGITS 2

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int cards[MAX_CARDS];
    int visited[MAX_CARDS] = {0};
    int score = 0;
    int attempts = 0;
    
    for (int i = 0; i < MAX_CARDS; i++) {
        cards[i] = i/2 + 1;
    }
    
    shuffle(cards, MAX_CARDS);
    
    printf("Welcome to the Memory Game!\n");
    printf("There are 10 pairs of cards face down.\n"); 
    printf("You have to match each pair of cards.\n");
    printf("Enter the position of the card to flip the card.\n");
    
    while (score < MAX_CARDS/2) {
        int pos1, pos2;
        do {
            printf("Enter position of card 1: ");
            scanf("%d", &pos1);
        } while (pos1 < 0 || pos1 >= MAX_CARDS || visited[pos1]);
        
        do {
            printf("Enter position of card 2: ");
            scanf("%d", &pos2);
        } while (pos2 < 0 || pos2 >= MAX_CARDS || visited[pos2]);
        
        printf("\n");
        visited[pos1] = 1;
        visited[pos2] = 1;
        attempts++;
        
        if (cards[pos1] == cards[pos2]) {
            score++;
            for (int i = 0; i < MAX_CARDS; i++) {
                if (visited[i]) {
                    printf("[ %*d ] ", MAX_DIGITS, cards[i]);
                } else {
                    printf("[ %*c ] ", MAX_DIGITS, '-');
                }
                
                if ((i+1) % 5 == 0) {
                    printf("\n\n");
                }
            }
            printf("Good job! You matched a pair of cards.\n");
        } else {
            for (int i = 0; i < MAX_CARDS; i++) {
                if (visited[i]) {
                    printf("[ %*d ] ", MAX_DIGITS, cards[i]);
                } else if (i == pos1 || i == pos2) {
                    printf("[ %*c ] ", MAX_DIGITS, 'X');
                } else {
                    printf("[ %*c ] ", MAX_DIGITS, '-');
                }
                
                if ((i+1) % 5 == 0) {
                    printf("\n\n");
                }
            }
            printf("Oops! Try again.\n");
            visited[pos1] = 0;
            visited[pos2] = 0;
        }
    }
    
    printf("Congratulations! You finished the game in %d attempts.\n", attempts);
    return 0;
}