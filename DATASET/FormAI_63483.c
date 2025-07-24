//FormAI DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUESTIONS 10
#define MAX_PLAYERS 5
#define TIME_LIMIT 60

typedef struct {
    char question[100];
    char options[4][50];
    int correct_option;
} question_t;

typedef struct {
    char name[20];
    int score;
} player_t;

void load_questions(question_t *questions) {
    // Load questions from file/database/etc.
    // For this example, we'll use hardcoded questions
    
    // Question 1
    sprintf(questions[0].question, "What is the capital of France?");
    sprintf(questions[0].options[0], "A. Rome");
    sprintf(questions[0].options[1], "B. Paris");
    sprintf(questions[0].options[2], "C. Madrid");
    sprintf(questions[0].options[3], "D. Berlin");
    questions[0].correct_option = 1;
    
    // Question 2
    sprintf(questions[1].question, "What is the smallest planet in our solar system?");
    sprintf(questions[1].options[0], "A. Jupiter");
    sprintf(questions[1].options[1], "B. Venus");
    sprintf(questions[1].options[2], "C. Earth");
    sprintf(questions[1].options[3], "D. Mercury");
    questions[1].correct_option = 3;
    
    // Question 3
    sprintf(questions[2].question, "Who was the first person to walk on the Moon?");
    sprintf(questions[2].options[0], "A. Buzz Aldrin");
    sprintf(questions[2].options[1], "B. Neil Armstrong");
    sprintf(questions[2].options[2], "C. Yuri Gagarin");
    sprintf(questions[2].options[3], "D. Alan Shepard");
    questions[2].correct_option = 1;
    
    // Add more questions here
}

void shuffle_questions(question_t *questions) {
    // Shuffle questions using Fisher-Yates algorithm
    srand(time(NULL));
    for (int i = QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        question_t temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

void shuffle_options(question_t *question) {
    // Shuffle options using Fisher-Yates algorithm
    srand(time(NULL));
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[50];
        sprintf(temp, "%s", question->options[i]);
        sprintf(question->options[i], "%s", question->options[j]);
        sprintf(question->options[j], "%s", temp);
    }
}

int get_player_count() {
    int player_count = 0;
    
    do {
        printf("How many players? (max %d) ", MAX_PLAYERS);
        scanf("%d", &player_count);
    } while (player_count <= 0 || player_count > MAX_PLAYERS);
    
    return player_count;
}

void get_player_names(player_t *players, int player_count) {
    for (int i = 0; i < player_count; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
    }
}

void start_game(question_t *questions, int player_count, player_t *players) {
    int total_questions = QUESTIONS * player_count;
    int current_question = 0;
    
    while (current_question < total_questions) {
        question_t *question = &questions[current_question % QUESTIONS];
        printf("Question %d: %s\n", current_question + 1, question->question);
        shuffle_options(question);
        for (int i = 0; i < 4; i++) {
            printf("%s\n", question->options[i]);
        }
        int chosen_option;
        do {
            printf("Choose an option (1-4): ");
            scanf("%d", &chosen_option);
        } while (chosen_option < 1 || chosen_option > 4);
        int is_correct = (chosen_option == question->correct_option);
        printf("You chose option %d. %s\n", chosen_option, is_correct ? "Correct!" : "Incorrect.");
        players[current_question % player_count].score += is_correct ? 1 : 0;
        current_question++;
    }
}

void display_scores(player_t *players, int player_count) {
    printf("\n========================\n");
    printf("         Scores\n");
    printf("========================\n");
    for (int i = 0; i < player_count; i++) {
        printf("%d. %s - %d\n", i + 1, players[i].name, players[i].score);
    }
}

int main() {
    int player_count = get_player_count();
    player_t players[player_count];
    get_player_names(players, player_count);
    
    question_t questions[QUESTIONS];
    load_questions(questions);
    shuffle_questions(questions);
    
    printf("\nLet the game begin!\n");
    printf("Each game has %d questions and a time limit of %d seconds.\n", QUESTIONS, TIME_LIMIT);
    
    time_t start_time = time(NULL);
    start_game(questions, player_count, players);
    time_t end_time = time(NULL);
    
    int elapsed_time = end_time - start_time;
    if (elapsed_time > TIME_LIMIT) {
        printf("\nTime's up!\n");
    } else {
        printf("\nGame over!\n");
    }
    
    display_scores(players, player_count);
    
    return 0;
}