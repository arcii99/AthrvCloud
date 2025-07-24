//FormAI DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random question numbers
int get_random_question_num(int num_questions) {
    srand(time(NULL));
    return rand() % num_questions;
}

// Function to load questions from file
void load_questions(char* file_name, char questions[][100]) {
    FILE* file = fopen(file_name, "r");
    if(file == NULL) {
        printf("ERROR: Unable to open file.\n");
        exit(1);
    }

    int i = 0;
    char line[100];
    while(fgets(line, 100, file) != NULL) {
        if(i >= 10) {
            break;
        }
        strcpy(questions[i], line);
        i++;
    }

    fclose(file);
}

// Function to ask and validate user's answer
int ask_question(char question[]) {
    printf("%s", question);
    char user_input[10];
    scanf("%s", user_input);

    // Validate answer
    if(user_input[0] == 'a') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Define and load questions
    char question_bank[10][100];
    load_questions("questions.txt", question_bank);

    // Get total number of players
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Declare and initialize score array
    int scores[num_players];
    for(int i = 0; i < num_players; i++) {
        scores[i] = 0;
    }

    // Set number of total rounds to 5
    int num_rounds = 5;
    for(int i = 0; i < num_rounds; i++) {
        printf("\n--- Round %d ---\n", i+1);
        // Each player takes turn to answer a question
        for(int j = 0; j < num_players; j++) {
            printf("\nPlayer %d's turn\n", j+1);
            int question_num = get_random_question_num(10);
            int is_correct = ask_question(question_bank[question_num]);
            if(is_correct) {
                printf("Correct answer!\n");
                scores[j]++;
            } else {
                printf("Wrong answer!\n");
            }
        }
    }

    // Display final scores
    printf("\n--- Final Scores ---\n");
    for(int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", i+1, scores[i]);
    }

    return 0;
}