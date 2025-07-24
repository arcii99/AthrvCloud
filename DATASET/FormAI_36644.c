//FormAI DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#define QUESTIONS 10 // Set the number of questions

int total_marks = 0; // Initialize the total marks to zero

char answers[QUESTIONS] = {'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B'}; // Set the correct answers

int main() {
    printf("Welcome to the online exam, dear Romeo and Juliet. %c \n", 1);
    printf("You have %d questions to answer, and each question carries 10 marks. \n", QUESTIONS);
    printf("Are you ready? Let's begin! %c \n", 1);
    
    // Loop through the questions and prompt the user for their answer
    for (int i = 1; i <= QUESTIONS; i++) {
        char answer;
        printf("Question %d: What is the answer? \n", i);
        scanf(" %c", &answer);
        
        if (answer == answers[i-1]) {
            printf("Correct! You get 10 marks. %c \n", 1);
            total_marks += 10;
        }
        else {
            printf("Incorrect. The correct answer is %c. %c \n", answers[i-1], 1);
        }
    }
    
    printf("Congratulations on finishing the exam, dear Romeo and Juliet! %c \n", 1);
    
    // Display the total marks and give a customized message based on the score
    printf("Your total marks is %d. %c \n", total_marks, 1);
    
    if (total_marks == 100) {
        printf("Wow, you scored a perfect score! You two must have studied together for this exam. %c \n", 1);
    }
    else if (total_marks >= 70) {
        printf("Great job! You both are quite smart. %c \n", 1);
    }
    else {
        printf("Better luck next time, dear Romeo and Juliet. %c \n", 1);
    }
    
    return 0;
}