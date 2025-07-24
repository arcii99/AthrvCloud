//FormAI DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
#include<stdio.h>

struct question {
    char questionBody[100];
    char options[4][50];
    int answer;
};

int main() {
    int answerSheet[10];
    struct question questions[10];
    int score = 0;
    
    //Initialize questions
    strcpy(questions[0].questionBody, "What year was C language invented?");
    strcpy(questions[0].options[0], "1972");
    strcpy(questions[0].options[1], "1985");
    strcpy(questions[0].options[2], "1995");
    strcpy(questions[0].options[3], "2002");
    questions[0].answer = 0;
    
    strcpy(questions[1].questionBody, "What is the syntax to declare an integer variable in C?");
    strcpy(questions[1].options[0], "char");
    strcpy(questions[1].options[1], "float");
    strcpy(questions[1].options[2], "int");
    strcpy(questions[1].options[3], "double");
    questions[1].answer = 2;
    
    strcpy(questions[2].questionBody, "What does the '==' operator do?");
    strcpy(questions[2].options[0], "It assigns a value to a variable");
    strcpy(questions[2].options[1], "It compares two values");
    strcpy(questions[2].options[2], "It prints a value to the console");
    strcpy(questions[2].options[3], "It creates a loop");
    questions[2].answer = 1;
    
    strcpy(questions[3].questionBody, "What is the output of the following code: \n int a = 5; \n printf(\"%d\", a++); ");
    strcpy(questions[3].options[0], "5");
    strcpy(questions[3].options[1], "6");
    strcpy(questions[3].options[2], "0");
    strcpy(questions[3].options[3], "1");
    questions[3].answer = 0;
    
    strcpy(questions[4].questionBody, "What is the syntax to declare a function in C?");
    strcpy(questions[4].options[0], "function void myFunction() {}");
    strcpy(questions[4].options[1], "myFunction () {}");
    strcpy(questions[4].options[2], "void myFunction() {}");
    strcpy(questions[4].options[3], "int myFunction(); {}");
    questions[4].answer = 2;
    
    strcpy(questions[5].questionBody, "What is the output of the following code: \n int a,b,c; \n a = 2, b = 5; \n c = (a>b) ? a : b ; \n printf(\"%d\", c); ");
    strcpy(questions[5].options[0], "2");
    strcpy(questions[5].options[1], "5");
    strcpy(questions[5].options[2], "0");
    strcpy(questions[5].options[3], "1");
    questions[5].answer = 1;
    
    strcpy(questions[6].questionBody, "What is the keyword used to exit a loop in C?");
    strcpy(questions[6].options[0], "stop");
    strcpy(questions[6].options[1], "exit");
    strcpy(questions[6].options[2], "break");
    strcpy(questions[6].options[3], "end");
    questions[6].answer = 2;
    
    strcpy(questions[7].questionBody, "What is the syntax to declare a string variable in C?");
    strcpy(questions[7].options[0], "string myString;");
    strcpy(questions[7].options[1], "char[] myString;");
    strcpy(questions[7].options[2], "string[] myString;");
    strcpy(questions[7].options[3], "char myString[];");
    questions[7].answer = 3;
    
    strcpy(questions[8].questionBody, "What is the output of the following code: \n int a = 5, b = 3; \n if(a>b) { \n printf(\"Yes\"); \n } else { \n printf(\"No\"); \n }");
    strcpy(questions[8].options[0], "Yes");
    strcpy(questions[8].options[1], "No");
    strcpy(questions[8].options[2], "0");
    strcpy(questions[8].options[3], "1");
    questions[8].answer = 0;
    
    strcpy(questions[9].questionBody, "What is the keyword used to define a constant variable in C?");
    strcpy(questions[9].options[0], "var");
    strcpy(questions[9].options[1], "constant");
    strcpy(questions[9].options[2], "const");
    strcpy(questions[9].options[3], "def");
    questions[9].answer = 2;
    
    //Take Input from user
    for(int i=0; i<10; i++){
        printf("Question %d: %s\n", i+1, questions[i].questionBody);
        for(int j=0; j<4; j++){
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }
        printf("Enter your answer (1-4): ");
        scanf("%d", &answerSheet[i]);
    }
    
    //Check answers and calculate score
    for(int i=0; i<10; i++){
        if(answerSheet[i] - 1 == questions[i].answer){
            score++;
        }
    }
    
    //Print Score
    printf("Your score is: %d", score);
    
    return 0;
}