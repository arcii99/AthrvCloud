//FormAI DATASET v1.0 Category: Online Examination System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num_questions = 5; // number of questions in the exam
    int questions_attempted = 0; // number of questions attempted
    int correct_answers = 0; // number of correct answers
    
    // array of questions and answers
    char questions[][100] = {
        "What is the output of the following code?\nint a=10,b=7,c=5;\nprintf(\"%d\",a-b*c);\n",
        "Which of the following is not a valid data type in C?\nA. Double\nB. Float\nC. Char\nD. Int\n",
        "What is the value of x after the following code executes?\nint x=10;\nif(x>5 && x<15){\nx=5;\n}\nelse{\nx=10;\n}\nprintf(\"%d\",x);\n",
        "Which of the following is a correct way of declaring and initializing an array of integers in C?\nA. int a[] = {1, 2, 3};\nB. int a[3] = {1, 2};\nC. int a[3] = {1, 2, 3, 4};\nD. int a[3] = {1, 2, 'a'};\n",
        "What does the following code print?\nint i=0;\nwhile(i<5){\ni++;\nif(i==3) continue;\nprintf(\"%d \",i);\n}\n"
    };
    
    char answers[] = {'a', 'd', 'a', 'a', '1', 'c', 'c', 'a', '2', 'd'};
    
    // shuffle the questions to avoid predictability
    srand(time(NULL));
    for(int i=0; i<num_questions; i++){
        int j = rand()%num_questions;
        char temp[100];
        strcpy(temp, questions[i]);
        strcpy(questions[i], questions[j]);
        strcpy(questions[j], temp);
    }
    
    // start the exam
    printf("Welcome to the C Online Examination System!\n");
    printf("You have %d questions in this exam.\n", num_questions);
    printf("You have to answer each question by typing the option letter (A/B/C/D) and hitting enter.\n");
    printf("Let's begin!\n\n");
    
    for(int i=0; i<num_questions; i++){
        printf("Question %d:\n%s", i+1, questions[i]);
        char reply;
        do{
            printf("Your answer (A/B/C/D): ");
            scanf("%c", &reply);
            getchar(); // consume the newline character left in the buffer after scanf
        }while(reply!='a' && reply!='b' && reply!='c' && reply!='d');
        
        if(reply==answers[i]){
            printf("Correct answer!\n\n");
            correct_answers++;
        }
        else{
            printf("Incorrect answer!\n\n");
        }
        questions_attempted++;
    }
    
    // display the result
    printf("End of exam!\n");
    printf("You attempted %d questions.\n", questions_attempted);
    printf("Your score is %d out of %d.\n", correct_answers, num_questions);
    
    return 0;
}