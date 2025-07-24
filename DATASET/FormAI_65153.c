//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4

/* Structure for holding a question */
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int answer;
} Question;

/* Function to display a question */
void display_question(Question q) {
    printf("\n%s\n", q.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
}

/* Function to get a random question */
Question get_random_question(Question* questions, int num_questions, int* selected_questions) {
    int idx;
    do {
        idx = rand() % num_questions;
    } while (selected_questions[idx]);
    selected_questions[idx] = 1;
    return questions[idx];
}

int main() {
    /* Seed the random number generator */
    srand(time(0));

    /* Initialize the questions */
    Question questions[MAX_QUESTIONS] = {
        {"What is the capital city of India?", {"Mumbai", "New Delhi", "Kolkata", "Chennai"}, 2},
        {"Which planet is closest to the Sun?", {"Venus", "Mars", "Mercury", "Earth"}, 3},
        {"Who is the author of The Great Gatsby?", {"F. Scott Fitzgerald", "J.D. Salinger", "Ernest Hemingway", "William Faulkner"}, 1},
        {"What do we call a collection of stars?", {"Galaxy", "Cluster", "Nebula", "Solar System"}, 1},
        {"In which country is the Great Wall of China located?", {"Japan", "China", "Korea", "Taiwan"}, 2},
        {"What is the highest mountain in the world?", {"Mount Kilimanjaro", "Mount Everest", "Mount Fuji", "Mount K2"}, 2},
        {"What is the largest mammal on Earth?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 2},
        {"Which of these countries does NOT use the Euro as currency?", {"Germany", "France", "Italy", "Sweden"}, 4},
        {"Who is the current CEO of Microsoft?", {"Jeff Bezos", "Mark Zuckerberg", "Tim Cook", "Satya Nadella"}, 4},
        {"What is the chemical symbol for Gold?", {"Au", "Ag", "Cu", "Fe"}, 1},
        {"What is the smallest country in the world?", {"Vatican City", "Monaco", "San Marino", "Liechtenstein"}, 1},
        {"What was the first smartphone?", {"iPhone", "BlackBerry", "Nokia Communicator", "Palm Treo"}, 3},
        {"Which country is famous for the Kangaroo?", {"New Zealand", "South Africa", "Australia", "India"}, 3},
        {"What is the name of the fastest land animal?", {"Leopard", "Cheetah", "Lion", "Tiger"}, 2},
        {"Who discovered Penicillin?", {"Louis Pasteur", "Alexander Fleming", "Robert Koch", "Antonie van Leeuwenhoek"}, 2},
        {"What is the name of the tower in Paris that is a famous landmark?", {"Eiffel Tower", "Tokyo Tower", "Leaning Tower of Pisa", "Burj Khalifa"}, 1},
        {"Which of these animals is NOT a fish?", {"Salmon", "Shark", "Squid", "Whale"}, 4},
        {"What is the name of the river that flows through Egypt?", {"Tigris", "Nile", "Ganges", "Yangtze"}, 2},
        {"What is the name of the sea that is bordered by Europe, Asia and Africa?", {"Black Sea", "Red Sea", "Mediterranean Sea", "Caspian Sea"}, 3},
        {"Who is the current Prime Minister of Japan?", {"Emmanuel Macron", "Angela Merkel", "Shinzo Abe", "Theresa May"}, 3},
    };

    /* Initialize the selected_questions array to all 0's */
    int selected_questions[MAX_QUESTIONS] = {0};

    int num_questions = sizeof(questions) / sizeof(Question);
    int num_correct = 0;

    printf("Welcome to the Online Examination System!\n\n");

    for (int i = 0; i < 10; i++) {
        Question q = get_random_question(questions, num_questions, selected_questions);
        display_question(q);
        int choice;
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        if (choice == q.answer) {
            printf("\nCorrect!\n");
            num_correct++;
        } else {
            printf("\nIncorrect. The correct answer is %d.\n", q.answer);
        }
    }

    printf("\nThank you for taking the exam.\n");
    printf("You answered %d out of 10 questions correctly.\n", num_correct);

    return 0;
}