//FormAI DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <string.h>

struct Question{
    char ques[100];
    char ans[100];
    int score;
};

struct User{
    char name[50];
    int score;
};

int main(){

    //Creating questions
    struct Question ques_list[5];
    strcpy(ques_list[0].ques, "What is the capital of India?");
    strcpy(ques_list[0].ans, "New Delhi");
    ques_list[0].score = 10;

    strcpy(ques_list[1].ques, "What is the largest organ in the human body?");
    strcpy(ques_list[1].ans, "Skin");
    ques_list[1].score = 10;

    strcpy(ques_list[2].ques, "What is the highest mountain in the world?");
    strcpy(ques_list[2].ans, "Mount Everest");
    ques_list[2].score = 10;

    strcpy(ques_list[3].ques, "Who is the founder of Microsoft?");
    strcpy(ques_list[3].ans, "Bill Gates");
    ques_list[3].score = 10;

    strcpy(ques_list[4].ques, "What is 2+2?");
    strcpy(ques_list[4].ans, "4");
    ques_list[4].score = 5;

    //Creating users
    struct User user_list[3];
    strcpy(user_list[0].name, "John");
    user_list[0].score = 0;

    strcpy(user_list[1].name, "Jane");
    user_list[1].score = 0;

    strcpy(user_list[2].name, "David");
    user_list[2].score = 0;

    printf("Welcome to the Online Examination System!\n");

    //Loop through each question
    for(int i=0; i<5; i++){

        printf("\nQuestion %d: %s\n", i+1, ques_list[i].ques);

        //Loop through each user
        for(int j=0; j<3; j++){

            char ans[100];

            printf("%s, please enter your answer: ", user_list[j].name);
            scanf("%s", ans);

            if(strcmp(ans, ques_list[i].ans) == 0){
                printf("Correct answer!\n");
                user_list[j].score += ques_list[i].score;
            }
            else{
                printf("Wrong answer!\n");
            }
        }
    }

    printf("\nFinal Scores:\n");

    //Display the final scores
    for(int i=0; i<3; i++){
        printf("%s: %d\n", user_list[i].name, user_list[i].score);
    }

    return 0;
}