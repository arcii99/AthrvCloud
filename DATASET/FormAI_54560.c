//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_ALIEN_WORDS 10
#define MAX_ALIEN_WORD_LENGTH 20
#define MAX_TRANSLATION_LENGTH 50

char alienWords[MAX_ALIEN_WORDS][MAX_ALIEN_WORD_LENGTH] = {"frax", "mool", "shurm", "pleen", "qux", "zor", "glip", "mof", "trax", "zob"};
char englishWords[MAX_ALIEN_WORDS][MAX_ALIEN_WORD_LENGTH] = {"hello", "goodbye", "welcome", "thank you", "yes", "no", "sorry", "help", "please", "food"};

typedef struct {
    int playerId;
    int score;
    char translation[MAX_TRANSLATION_LENGTH];
} Player;

void displayAlienWords() {
    printf("\nList of Alien Words:");
    for (int i = 0; i < MAX_ALIEN_WORDS; i++) {
        printf("\n%s", alienWords[i]);
    }
}

int isValidAlienWord(char* alienWord) {
    for (int i = 0; i < MAX_ALIEN_WORDS; i++) {
        if (strcmp(alienWords[i], alienWord) == 0) {
            return 1;
        }
    }
    return 0;
}

int getIndexOfAlienWord(char* alienWord) {
    for (int i = 0; i < MAX_ALIEN_WORDS; i++) {
        if (strcmp(alienWords[i], alienWord) == 0) {
            return i;
        }
    }
    return -1;
}

void displayInstructions() {
    printf("\n\n***ALIEN LANGUAGE TRANSLATOR***\n");
    printf("\nINSTRUCTIONS:\n");
    printf("- The game can be played by %d players.\n", MAX_PLAYERS);
    printf("- Each player will be given a unique ID (1 to %d) for this game.\n", MAX_PLAYERS);
    printf("- The game will randomly select an alien word and display it on the screen.\n");
    printf("- Each player needs to take turns to translate the alien word into English and type their translation.\n");
    printf("- If the translation is correct, the player will get 1 point and the game will display the next alien word.\n");
    printf("- If the translation is incorrect, the player will not get any point and the game will display a message indicating that the translation is incorrect.\n");
    printf("- The game will end once all the words have been translated by the players or if a player types 'exit' as their translation.\n");
}

void displayPlayerScores(Player players[MAX_PLAYERS]) {
    printf("\n\nSCORES:");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("\nPlayer %d: %d", players[i].playerId, players[i].score);
    }
}

void displayIncorrectMessage() {
    printf("\nIncorrect translation. Please try again.");
}

void playAlienLanguageTranslator() {
    Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].playerId = i+1;
        players[i].score = 0;
    }
    int currentPlayerIndex = 0;
    int currentIndex = -1;
    char currentAlienWord[MAX_ALIEN_WORD_LENGTH];
    char currentTranslation[MAX_TRANSLATION_LENGTH];
    int isGameOver = 0;
    int numberOfWordsTranslated = 0;
    int randomNumber;
    srand(time(0));
    displayInstructions();
    displayAlienWords();
    while (!isGameOver) {
        randomNumber = rand() % MAX_ALIEN_WORDS;
        if (randomNumber == currentIndex) {
            randomNumber = (randomNumber + 1) % MAX_ALIEN_WORDS;
        }
        strcpy(currentAlienWord, alienWords[randomNumber]);
        currentIndex = randomNumber;
        printf("\n\nCurrent Alien Word: %s", currentAlienWord);
        printf("\nPlayer %d, please enter your translation or type 'exit': ", players[currentPlayerIndex].playerId);
        gets(currentTranslation);
        if (strcmp(currentTranslation, "exit") == 0) {
            isGameOver = 1;
            printf("\n\nGame Over. Player %d has exited the game.", players[currentPlayerIndex].playerId);
        } else {
            if (isValidAlienWord(currentTranslation)) {
                int index = getIndexOfAlienWord(currentTranslation);
                if (strcmp(englishWords[index], currentAlienWord) == 0) {
                    printf("\nTranslation is correct!\n");
                    players[currentPlayerIndex].score++;
                    numberOfWordsTranslated++;
                    if (numberOfWordsTranslated == MAX_ALIEN_WORDS) {
                        isGameOver = 1;
                        printf("\n\nGame Over. All Alien words have been translated.");
                    }
                } else {
                    displayIncorrectMessage();
                }
            } else {
                displayIncorrectMessage();
            }
            currentPlayerIndex = (currentPlayerIndex + 1) % MAX_PLAYERS;
            displayPlayerScores(players);
        }
    }
}

int main() {
    playAlienLanguageTranslator();
    return 0;
}