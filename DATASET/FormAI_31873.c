//FormAI DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 12
#define MAX_NUMBER 6

int cards[MAX_CARDS];

int playGame();
int selectCard(int);
int checkMatch();
void removeCards(int, int);

int main() {
    int score = 0;
    srand(time(NULL));

    printf("Welcome to the Romeo and Juliet Memory Game!\n");

    while (1) {
        printf("\nPress any key to continue or enter 'q' to quit the game: ");
        char key = getchar();

        if (key == 'q' || key == 'Q') {
            printf("\nThank you for playing. Your final score is %d.\n", score);
            break;
        }

        score += playGame();
    }

    return 0;
}

int playGame() {
    int turnCount = 0;
    int pairsFound = 0;

    for (int i = 0; i < MAX_CARDS; i++) {
        cards[i] = i % MAX_NUMBER + 1;
    }

    // Shuffle cards
    for (int i = 0; i < MAX_CARDS; i++) {
        int randomIndex = rand() % MAX_CARDS;
        int temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }

    printf("\nNew game started. Good luck!\n");

    while (pairsFound < MAX_NUMBER) {
        int firstCardIndex = selectCard(turnCount);
        int secondCardIndex = selectCard(turnCount);

        if (firstCardIndex == secondCardIndex) {
            printf("\nYou must select two different cards.\n");
            continue;
        }

        int match = checkMatch();

        if (match == 1) {
            printf("\nCongratulations! You have found a pair.\n");
            pairsFound++;
            removeCards(firstCardIndex, secondCardIndex);
        }
        else {
            printf("\nSorry, the cards do not match. Try again.\n");
        }

        turnCount++;
    }

    printf("You completed the game in %d turns!\n", turnCount);
    int score = MAX_CARDS * 2 - turnCount * 2;
    printf("Your score for this game is %d.\n", score);

    return score;
}

int selectCard(int turnCount) {
    int index;

    while (1) {
        printf("Turn: %d. Please select a card (1-%d): ", turnCount, MAX_CARDS);

        if (scanf("%d", &index) != 1) {
            printf("\nInvalid input. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }

        if (index < 1 || index > MAX_CARDS) {
            printf("\nInvalid input. Please select a card between 1 and %d.\n", MAX_CARDS);
            continue;
        }

        if (cards[index-1] == -1) {
            printf("\nCard has already been matched. Please select another card.\n");
            continue;
        }

        return index - 1;
    }
}

int checkMatch() {
    int firstCard, secondCard;

    for (int i = 0; i < MAX_CARDS-1; i++) {
        if (cards[i] != -1) {
            firstCard = cards[i];
            for (int j = i+1; j < MAX_CARDS; j++) {
                if (cards[j] != -1) {
                    secondCard = cards[j];
                    if (firstCard == secondCard) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

void removeCards(int firstIndex, int secondIndex) {
    cards[firstIndex] = -1;
    cards[secondIndex] = -1;
}