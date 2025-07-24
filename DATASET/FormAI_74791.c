//FormAI DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANS_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char question[50];
    char answer[20];
} Question;

typedef struct {
    char username[20];
    int score;
    int current_question;
} Player;

void initialize_questions(Question *questions) {
    strcpy(questions[0].question, "Which of the following is NOT a programming language?");
    strcpy(questions[0].answer, "HTML");

    strcpy(questions[1].question, "What is the output of the following code: int x = 5; x++; printf(\"%d\", x);");
    strcpy(questions[1].answer, "6");

    // Add more questions here...
}

void clear_screen() {
    system("clear");
}

void wait_for_input() {
    printf("Press enter to continue...");
    while (getchar() != '\n');
}

void display_question(Question question) {
    clear_screen();
    printf("Question: %s\n", question.question);
    printf("Please enter your answer: ");
}

void get_player_username(Player *player) {
    clear_screen();
    printf("Please enter your username: ");
    scanf("%s", player->username);
}

void display_scoreboard(Player *players, int num_players) {
    clear_screen();
    printf("Scoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s:\t%d\n", players[i].username, players[i].score);
    }
}

void play_game(Question *questions, int num_questions) {
    clear_screen();
    printf("Welcome to the Online Examination System!\n");
    printf("Here are the rules:\n");
    printf("- You will be asked %d questions.\n", num_questions);
    printf("- Each question is worth 1 point.\n");
    printf("- You have to answer the question within 10 seconds.\n");
    printf("- If you answer incorrectly or take longer than 10 seconds, you lose.\n");
    wait_for_input();

    Player players[2];
    printf("Player 1, enter your username:\n");
    scanf("%s", players[0].username);
    players[0].score = 0;
    players[0].current_question = 0;

    printf("Player 2, enter your username:\n");
    scanf("%s", players[1].username);
    players[1].score = 0;
    players[1].current_question = 0;

    while (players[0].current_question < num_questions && players[1].current_question < num_questions) {
        Question current_question = questions[players[0].current_question];
        display_question(current_question);

        char answer[MAX_ANS_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, current_question.answer) == 0) {
            printf("Correct answer!\n");
            players[0].score++;
        } else {
            printf("Incorrect answer. You lose!\n");
            break;
        }

        players[0].current_question++;

        current_question = questions[players[1].current_question];
        display_question(current_question);

        scanf("%s", answer);

        if (strcmp(answer, current_question.answer) == 0) {
            printf("Correct answer!\n");
            players[1].score++;
        } else {
            printf("Incorrect answer. You lose!\n");
            break;
        }

        players[1].current_question++;
    }

    display_scoreboard(players, 2);
}

int main() {
    Question questions[MAX_QUESTIONS];
    initialize_questions(questions);
    play_game(questions, 3);  // Play a game with 3 questions
    return 0;
}