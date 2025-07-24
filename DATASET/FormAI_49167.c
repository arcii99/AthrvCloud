//FormAI DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_tree() {
    printf("    *\n");
    printf("   ***\n");
    printf("  *****\n");
    printf(" *******\n");
    printf("*********\n");
    printf("   ***\n");
}

void draw_cloud() {
    printf("   (     )\n");
    printf(" (         )\n");
    printf("(           )\n");
    printf("(           )\n");
    printf(" (         )\n");
    printf("   (     )\n");
}

int main() {
    srand(time(NULL)); //Seed the random number generator
    int score = 0; //Initialize the score to 0
    int distance_to_cloud = rand() % 10 + 1; //Randomize the distance to the cloud between 1 and 10 meters
    int tree_distance = 15; //Initialize the distance to the tree
    
    printf("Welcome to the Peaceful Cloud Jumping game!\n");
    printf("Your goal is to jump on the cloud and reach the tree without falling.\n");
    printf("Press enter to start.\n");
    getchar(); //Wait for the user to press enter
    
    while (1) { //Infinite loop until the game is over
        printf("\nScore: %d\n", score);
        printf("Jump distance: %d\n", distance_to_cloud);
        printf("Distance to the tree: %d\n", tree_distance);
        draw_cloud(); //Draw the cloud
        
        //Ask the user if they want to jump or quit
        printf("Press 'j' to jump or 'q' to quit: ");
        char input = getchar(); //Read one character from the user
        
        if (input == 'q') { //If the user quits, end the game
            printf("\nGame over. Your final score is %d.\n", score);
            break; //Exit the infinite loop
        }
        else if (input == 'j') { //If the user jumps, move to the next cloud and update the score
            distance_to_cloud = rand() % 10 + 1; //Randomize the distance to the next cloud
            tree_distance -= distance_to_cloud; //Subtract the distance to the next cloud from the distance to the tree
            
            //If the user jumps too far, they miss the cloud and fall
            if (tree_distance < 0) {
                printf("\nYou missed the cloud and fell. Game over. Your final score is %d.\n", score);
                break; //Exit the infinite loop
            }
            else if (tree_distance == 0) { //If the user reaches the tree, they win the game
                printf("\nCongratulations, you made it to the tree! Your final score is %d.\n", score+10); //Add 10 points for reaching the tree
                break; //Exit the infinite loop
            }
            else { //If the user reaches the next cloud, update the score
                score += 5; //Add 5 points for reaching the cloud
                draw_cloud(); //Draw the next cloud
                printf("You jumped on the cloud! Keep going!\n");
            }
        }

        //Clear the input buffer
        while (getchar() != '\n');
    }
    
    return 0;
}