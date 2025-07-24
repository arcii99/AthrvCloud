//FormAI DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

struct question{
    int num;
    char quest[100];
    char opt1[50];
    char opt2[50];
    char opt3[50];
    char opt4[50];
    char ans;
};

typedef struct question Ques;

void display_instructions(){
    printf("\t*********************************************************\n");
    printf("\t*                                                       *\n");
    printf("\t*   Welcome to the Online Examination System            *\n");
    printf("\t*                                                       *\n");
    printf("\t*********************************************************\n\n");
    
    printf("Instructions\n\n");
    printf("1. There will be 10 multiple choice questions.\n");
    printf("2. Each question carries 10 marks.\n");
    printf("3. There is no negative marking.\n");
    printf("4. Enter the alphabet corresponding to the answer (a/b/c/d).\n\n");
}

void set_questions(Ques *q)
{
    strcpy(q[0].quest,"C is a _____ language.");
    strcpy(q[0].opt1,"High Level");
    strcpy(q[0].opt2,"Low Level");
    strcpy(q[0].opt3,"Medium Level");
    strcpy(q[0].opt4,"None of the above");
    q[0].ans = 'a';

    strcpy(q[1].quest,"What is the output of 5+7/8 ?");
    strcpy(q[1].opt1,"5.875");
    strcpy(q[1].opt2,"5.14");
    strcpy(q[1].opt3,"5.76");
    strcpy(q[1].opt4,"5.635");
    q[1].ans = 'a';

    strcpy(q[2].quest,"What is the output of 12/6 ?");
    strcpy(q[2].opt1,"1.2");
    strcpy(q[2].opt2,"2");
    strcpy(q[2].opt3,"0.5");
    strcpy(q[2].opt4,"2.4");
    q[2].ans = 'b';

    strcpy(q[3].quest,"What is the size of int data type?");
    strcpy(q[3].opt1,"2 Bytes");
    strcpy(q[3].opt2,"4 Bytes");
    strcpy(q[3].opt3,"6 Bytes");
    strcpy(q[3].opt4,"8 Bytes");
    q[3].ans = 'b';

    strcpy(q[4].quest,"Which header file is used for input and output operation ?");
    strcpy(q[4].opt1,"stdbool.h");
    strcpy(q[4].opt2,"string.h");
    strcpy(q[4].opt3,"conio.h");
    strcpy(q[4].opt4,"stdio.h");
    q[4].ans = 'd';

    strcpy(q[5].quest,"Which of the following is not a keyword in C?");
    strcpy(q[5].opt1,"auto");
    strcpy(q[5].opt2,"up");
    strcpy(q[5].opt3,"if");
    strcpy(q[5].opt4,"volatile");
    q[5].ans = 'b';

    strcpy(q[6].quest,"Which of the following correctly represents the set of numbers used to represent characters in C?");
    strcpy(q[6].opt1,"ASCII");
    strcpy(q[6].opt2,"UNICODE");
    strcpy(q[6].opt3,"BINARY");
    strcpy(q[6].opt4,"SET");
    q[6].ans = 'a';

    strcpy(q[7].quest,"What is the output of the following program?\n\n#include <stdio.h>\n#define a 10\n\nvoid main()\n{\n    const int b = 20;\n    printf(\"%d\", a+b);\n}");
    strcpy(q[7].opt1,"10");
    strcpy(q[7].opt2,"20");
    strcpy(q[7].opt3,"30");
    strcpy(q[7].opt4,"Error");
    q[7].ans = 'c';

    strcpy(q[8].quest,"Which of the following operator takes only integer operands?");
    strcpy(q[8].opt1,"/");
    strcpy(q[8].opt2,"*");
    strcpy(q[8].opt3,"++");
    strcpy(q[8].opt4,"+");
    q[8].ans = 'c';

    strcpy(q[9].quest,"What is the output of the following program?\n\n#include <stdio.h>\nvoid main()\n{\n    for(int i=0;i<5;i++)\n    {\n        printf(\"%d \",i);\n        continue;\n        printf(\"2\");\n    }\n}");
    strcpy(q[9].opt1,"0 1 2 3 4");
    strcpy(q[9].opt2,"0 1 2 3 4 2");
    strcpy(q[9].opt3,"Runtime Error");
    strcpy(q[9].opt4,"None of the above");
    q[9].ans = 'a';
}

void display_question(Ques q)
{
    printf("%d) %s\n",q.num,q.quest);
    printf("a. %s\n",q.opt1);
    printf("b. %s\n",q.opt2);
    printf("c. %s\n",q.opt3);
    printf("d. %s\n",q.opt4);
}

void conduct_test(Ques *q)
{
    int score = 0;
    char ans;

    printf("Starting the test...\n\n");

    for(int i=0; i<10; i++)
    {
        display_question(q[i]);
        printf("\nEnter your answer: ");
        scanf(" %c",&ans);

        if(ans == q[i].ans)
            score += 10;

        printf("\n");
    }

    printf("Test completed.\n");
    printf("Your score: %d/100\n",score);
}

int main()
{
    Ques questions[10];
    set_questions(questions);

    display_instructions();

    char ch;
    printf("Are you ready to start the test? (y/n): ");
    scanf(" %c",&ch);

    if(ch == 'y')
        conduct_test(questions);
    else
        printf("Exiting the program...\n");

    return 0;
}