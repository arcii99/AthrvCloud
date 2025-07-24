//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    char question[100];
    char options[4][100];
    int answer;
};

struct question Set_Question(char ques[],char opt1[],char opt2[],char opt3[],char opt4[],int ans){
    //Function to set individual question
    struct question Set;
    strcpy(Set.question,ques);
    strcpy(Set.options[0],opt1);
    strcpy(Set.options[1],opt2);
    strcpy(Set.options[2],opt3);
    strcpy(Set.options[3],opt4);
    Set.answer = ans;
    return Set;
}

void Generate_Question_Paper(int num,struct question paper[]){
    //Function to set the question paper
    paper[0] = Set_Question("Which of the following is a low-level language?","Java","Python","C","SQL",3);
    paper[1] = Set_Question("Which of the following is not a Computer Peripheral?","Keyboard","Printer","Moniter","Bluetooth",4);
    paper[2] = Set_Question("Which of the following is the world's largest Operating System?","macOS","Linux","Windows","Unix",3);
    paper[3] = Set_Question("The latest version of C Programming Language is?","C89","C95","C11","C21",4);
    paper[4] = Set_Question("Which of the following is used to print a string?","printf()","scanf()","puts()","gets()",3);
}

int Display_Question_Paper(int num,struct question paper[]){
    //Function to display the question paper
    int score=0,ans=0,choice=0;

    printf("Enter your name: ");
    char name[50];
    scanf("%[^\n]", name);

    printf("\nWelcome to Online Exam System - C Language\n");
    printf("Name: %s\n",name);
    printf("Total Questions: %d\n",num);
    printf("---------------------------------------------\n");

    for(int i=0;i<num;i++){
        printf("%d. %s\n",i+1,paper[i].question);
        printf("\tA. %s\n",paper[i].options[0]);
        printf("\tB. %s\n",paper[i].options[1]);
        printf("\tC. %s\n",paper[i].options[2]);
        printf("\tD. %s\n",paper[i].options[3]);

        printf("Enter your answer: ");
        scanf("%d",&choice);

        if(choice==1)   ans=1;
        else if(choice==2)  ans=2;
        else if(choice==3)  ans=3;
        else if(choice==4)  ans=4;

        if(ans==paper[i].answer){
            printf("Correct Answer!\n");
            score++;
        }
        else{
            printf("Wrong Answer!\n");
            printf("Correct Answer is Option %d\n",paper[i].answer);
        }
        printf("---------------------------------------------\n");
    }

    printf("\nTotal Score: %d out of %d\n",score,num);
    printf("Percentage Score: %d %%\n",(score*100)/num);

    return score;
}

int main(){
    struct question paper[5];
    Generate_Question_Paper(5,paper);

    Display_Question_Paper(5,paper);

    return 0;
}