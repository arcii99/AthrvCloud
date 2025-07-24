//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Questions {
    char question[200];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correctOption;
};

struct Student {
    char name[50];
    int score;
};

void printResult(struct Student student)
{
    printf("\nCongratulations %s, You scored %d out of 5!\n", student.name, student.score);
}

int askQuestion(int qNumber, struct Questions question)
{
    printf("\nQuestion %d: %s\n", qNumber, question.question);
    printf("1. %s\n", question.option1);
    printf("2. %s\n", question.option2);
    printf("3. %s\n", question.option3);
    printf("4. %s\n", question.option4);
    printf("Answer (1-4): ");
    int answer;
    scanf("%d", &answer);
    if(answer == question.correctOption)
    {
        printf("\nCorrect Answer!");
        return 1;
    }
    else
    {
        printf("\nWrong Answer!");
        return 0;
    }
}

void randomizeQuestions(struct Questions* questions)
{
    for(int i = 0; i < 5; i++)
    {
        int num1 = rand() % 20;
        int num2 = rand() % 20;
        struct Questions temp = questions[num1];
        questions[num1] = questions[num2];
        questions[num2] = temp;
    }
}

int main()
{
    printf("/////////////////////////\n");
    printf("//   ONLINE EXAMINATION SYSTEM   //\n");
    printf("/////////////////////////\n\n");
    printf("Welcome to this online examination system!\n");
    printf("You will be given 5 random objective type questions.\n");
    printf("Each question will have four options from which you have to choose the correct answer.\n");
    printf("The questions will be randomly selected for each student.\n");
    printf("Let's begin!\n\n");
    
    struct Questions questions[20];
    // Add Questions
    strcpy(questions[0].question, "What is the capital of India?");
    strcpy(questions[0].option1, "Mumbai");
    strcpy(questions[0].option2, "Delhi");
    strcpy(questions[0].option3, "Kolkata");
    strcpy(questions[0].option4, "Chennai");
    questions[0].correctOption = 2;
    
    strcpy(questions[1].question, "What is the largest planet in our solar system?");
    strcpy(questions[1].option1, "Earth");
    strcpy(questions[1].option2, "Saturn");
    strcpy(questions[1].option3, "Jupiter");
    strcpy(questions[1].option4, "Mars");
    questions[1].correctOption = 3;
    
    strcpy(questions[2].question, "Which is the longest river in the world?");
    strcpy(questions[2].option1, "Ganges");
    strcpy(questions[2].option2, "Yangtze");
    strcpy(questions[2].option3, "Mississippi");
    strcpy(questions[2].option4, "Nile");
    questions[2].correctOption = 4;
    
    strcpy(questions[3].question, "Which is the largest mammal in the world?");
    strcpy(questions[3].option1, "Elephant");
    strcpy(questions[3].option2, "Whale");
    strcpy(questions[3].option3, "Giraffe");
    strcpy(questions[3].option4, "Rhino");
    questions[3].correctOption = 2;
    
    strcpy(questions[4].question, "Which of the following gases is most abundant in the earth’s atmosphere");
    strcpy(questions[4].option1, "Hydrogen");
    strcpy(questions[4].option2, "Oxygen");
    strcpy(questions[4].option3, "Nitrogen");
    strcpy(questions[4].option4, "Carbon Dioxide");
    questions[4].correctOption = 3;
    
    strcpy(questions[5].question, "Who is the creator of the programming language Python?");
    strcpy(questions[5].option1, "Guido van Rossum");
    strcpy(questions[5].option2, "Bjarne Stroustrup");
    strcpy(questions[5].option3, "Anders Hejlsberg");
    strcpy(questions[5].option4, "James Gosling");
    questions[5].correctOption = 1;
    
    strcpy(questions[6].question, "Which of the following is not a browser?");
    strcpy(questions[6].option1, "Chrome");
    strcpy(questions[6].option2, "Firefox");
    strcpy(questions[6].option3, "Windows");
    strcpy(questions[6].option4, "Safari");
    questions[6].correctOption = 3;
    
    strcpy(questions[7].question, "What is the name of the computer protocol that allows files to be transferred over the Internet?");
    strcpy(questions[7].option1, "TCP/IP");
    strcpy(questions[7].option2, "WiFi");
    strcpy(questions[7].option3, "HTTP");
    strcpy(questions[7].option4, "FTP");
    questions[7].correctOption = 4;
    
    strcpy(questions[8].question, "What was the first computer virus in the world called?");
    strcpy(questions[8].option1, "Trojan");
    strcpy(questions[8].option2, "Melissa");
    strcpy(questions[8].option3, "Code Red");
    strcpy(questions[8].option4, "Creeper");
    questions[8].correctOption = 4;
    
    strcpy(questions[9].question, "Which of the following is not a database management system?");
    strcpy(questions[9].option1, "MySQL");
    strcpy(questions[9].option2, "MongoDB");
    strcpy(questions[9].option3, "VBScript");
    strcpy(questions[9].option4, "Oracle");
    questions[9].correctOption = 3;
    
    strcpy(questions[10].question, "What is the name of the founder of Microsoft?");
    strcpy(questions[10].option1, "Bill Gates");
    strcpy(questions[10].option2, "Steve Jobs");
    strcpy(questions[10].option3, "Larry Page");
    strcpy(questions[10].option4, "Mark Zuckerberg");
    questions[10].correctOption = 1;
    
    strcpy(questions[11].question, "What does the term HTTP stand for?");
    strcpy(questions[11].option1, "Hypertext Transfer Protocol");
    strcpy(questions[11].option2, "Hyperlink Transfer Protocol");
    strcpy(questions[11].option3, "Hypertext Transmission Procedure");
    strcpy(questions[11].option4, "Hyper Transfer Protocol");
    questions[11].correctOption = 1;
    
    strcpy(questions[12].question, "What is the name of the first web browser ever created?");
    strcpy(questions[12].option1, "Netscape Navigator");
    strcpy(questions[12].option2, "Internet Explorer");
    strcpy(questions[12].option3, "Mosaic");
    strcpy(questions[12].option4, "Opera");
    questions[12].correctOption = 3;
    
    strcpy(questions[13].question, "Who is the creator of the popular programming language Java?");
    strcpy(questions[13].option1, "Bill Gates");
    strcpy(questions[13].option2, "James Gosling");
    strcpy(questions[13].option3, "Linus Torvalds");
    strcpy(questions[13].option4, "Donald Knuth");
    questions[13].correctOption = 2;
    
    strcpy(questions[14].question, "Which of the following is not a cloud storage service?");
    strcpy(questions[14].option1, "Google Drive");
    strcpy(questions[14].option2, "Amazon S3");
    strcpy(questions[14].option3, "Microsoft Office");
    strcpy(questions[14].option4, "Dropbox");
    questions[14].correctOption = 3;
    
    strcpy(questions[15].question, "Which of the following is not a popular scripting language?");
    strcpy(questions[15].option1, "JavaScript");
    strcpy(questions[15].option2, "Python");
    strcpy(questions[15].option3, "Perl");
    strcpy(questions[15].option4, "Swift");
    questions[15].correctOption = 4;
    
    strcpy(questions[16].question, "What does the term CSS stand for?");
    strcpy(questions[16].option1, "Cascading Style Sheets");
    strcpy(questions[16].option2, "Custom Style Sheets");
    strcpy(questions[16].option3, "Cascading Scripting Sheets");
    strcpy(questions[16].option4, "Custom Scripting Sheets");
    questions[16].correctOption = 1;
    
    strcpy(questions[17].question, "What is the name of the founder of Apple Inc?");
    strcpy(questions[17].option1, "Steve Jobs");
    strcpy(questions[17].option2, "Bill Gates");
    strcpy(questions[17].option3, "Tim Cook");
    strcpy(questions[17].option4, "Satya Nadella");
    questions[17].correctOption = 1;
    
    strcpy(questions[18].question, "What is the name of the world’s first computer programming language?");
    strcpy(questions[18].option1, "FORTRAN");
    strcpy(questions[18].option2, "COBOL");
    strcpy(questions[18].option3, "BASIC");
    strcpy(questions[18].option4, "Lisp");
    questions[18].correctOption = 1;
    
    strcpy(questions[19].question, "Which of the following is not a programming language?");
    strcpy(questions[19].option1, "C++");
    strcpy(questions[19].option2, "JSON");
    strcpy(questions[19].option3, "SQL");
    strcpy(questions[19].option4, "Ruby");
    questions[19].correctOption = 2;
    
    struct Student student;
    printf("\nEnter your name: ");
    scanf("%s", &student.name);
    randomizeQuestions(questions);
    student.score = 0;
    
    for(int i = 0; i < 5; i++)
    {
        student.score += askQuestion(i+1, questions[i]);
    }
    
    printResult(student);
    return 0;
}