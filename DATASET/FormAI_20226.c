//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice,n;
    char name[20];
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter your name to continue:");
    scanf("%s",name);
    printf("Hello %s\n",name);
    printf("Are you ready to enter the haunted house? (1 for yes; 2 for no):");
    scanf("%d",&choice);
    if(choice==1){
        printf("Great! Let's begin...\n\n");
        printf("You enter the haunted house and immediately feel a chill down your spine.\n");
        printf("You hear strange noises from different rooms.\n\n");
        int total_points=0;
        for(int i=1;i<=5;i++){
            printf("***********\n\n");
            printf("Room %d\n\n",i);
            printf("There are three doors. Choose 1, 2 or 3:\n");
            scanf("%d",&n);
            if(n==1){
                printf("Oops! You disturbed a ghost and lost 10 points...\n");
                total_points-=10;
            }
            else if(n==2){
                printf("You found a treasure worth 20 points!\n");
                total_points+=20;
            }
            else{
                printf("You move on to the next room...\n");
            }
            printf("***********\n\n");
        }
        printf("Congratulations %s! You completed the Haunted House Simulator...\n",name);
        printf("You earned %d points. Thanks for playing!!!\n",total_points);
    }
    else{
        printf("Okay %s, suit yourself. Maybe next time...\n",name);
    }
    return 0;
}