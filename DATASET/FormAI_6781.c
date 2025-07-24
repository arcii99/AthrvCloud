//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4

// Define player struct
struct Player {
    char* name;
};

// Function prototypes
void flipImage(int* image, int width, int height);
void adjustBrightness(int* image, int width, int height, int brightness);
void adjustContrast(int* image, int width, int height, float contrast);
void printImage(int* image, int width, int height);
void printPlayers(struct Player* players);
void playGame(struct Player* players, int* image, int width, int height);

int main() {
    int width = 8, height = 8;
    int image[64] = {0,0,1,1,1,0,0,0,
                     0,1,1,1,1,1,0,0,
                     1,1,1,1,1,1,1,1,
                     1,1,1,0,0,1,1,1,
                     1,1,1,0,0,1,1,1,
                     0,1,1,1,1,1,0,0,
                     0,0,1,1,1,0,0,0,
                     0,0,0,0,0,0,0,0};
    
    // Initialize players
    struct Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].name = malloc(sizeof(char) * 10);
        sprintf(players[i].name, "Player %d", i+1);
    }
    
    // Print starting image
    printf("Starting image:\n");
    printImage(image, width, height);
    
    // Play the game
    playGame(players, image, width, height);
    
    // Free player names
    for (int i = 0; i < MAX_PLAYERS; i++) {
        free(players[i].name);
    }
    
    return 0;
}

// Flip image horizontally and vertically
void flipImage(int* image, int width, int height) {
    int temp;
    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j < width; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + (height-i-1)*width + j);
            *(image + (height-i-1)*width + j) = temp;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + i*width + (width-j-1));
            *(image + i*width + (width-j-1)) = temp;
        }
    }
}

// Adjust brightness of image
void adjustBrightness(int* image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *(image + i*width + j) += brightness;
            if (*(image + i*width + j) > 255) {
                *(image + i*width + j) = 255;
            } else if (*(image + i*width + j) < 0) {
                *(image + i*width + j) = 0;
            }
        }
    }
}

// Adjust contrast of image
void adjustContrast(int* image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *(image + i*width + j) = factor * (*(image + i*width + j) - 128) + 128;
            if (*(image + i*width + j) > 255) {
                *(image + i*width + j) = 255;
            } else if (*(image + i*width + j) < 0) {
                *(image + i*width + j) = 0;
            }
        }
    }
}

// Print image
void printImage(int* image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(image + i*width + j));
        }
        printf("\n");
    }
    printf("\n");
}

// Print list of players
void printPlayers(struct Player* players) {
    printf("Players:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s\n", players[i].name);
    }
    printf("\n");
}

// Play the game
void playGame(struct Player* players, int* image, int width, int height) {
    int playerIndex = 0;
    int input;
    while (1) {
        // Print current player and image
        printf("%s's turn:\n", players[playerIndex].name);
        printImage(image, width, height);
        
        // Prompt player for action and execute it
        printf("Choose an action: 1) Flip image, 2) Adjust brightness, 3) Adjust contrast, 4) End turn\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                flipImage(image, width, height);
                break;
            case 2:
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%d", &input);
                adjustBrightness(image, width, height, input);
                break;
            case 3:
                printf("Enter contrast adjustment (0.0 to 5.0): ");
                scanf("%d", &input);
                adjustContrast(image, width, height, input);
                break;
            case 4:
                playerIndex++;
                if (playerIndex == MAX_PLAYERS) {
                    playerIndex = 0;
                }
                break;
            default:
                printf("Invalid input. Try again.\n");
        }
        
        // Check for winner
        if (*(image + (height/2)*width + (width/2)) == 255) {
            printf("%s won the game!\n", players[playerIndex].name);
            break;
        }
    }
}