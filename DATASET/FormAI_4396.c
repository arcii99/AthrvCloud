//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

void simulate(int room_num, int door_num);

int main(){
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of the house...\n\n");

    simulate(1, 3);

    printf("\nYou have escaped the haunted house!\n");
    return 0;
}

void simulate(int room_num, int door_num){
    int choice = 0;
    int rand_num = 0;

    printf("You have entered room %d.\n", room_num);

    while(choice != door_num){
        printf("You see %d doors in front of you...\n", door_num);
        printf("Which door do you choose? (1-%d)\n", door_num);
        scanf("%d", &choice);

        if(choice != door_num){
            rand_num = rand() % 3;
            if(rand_num == 0){
                printf("The room is now shaking...\n");
            }else if(rand_num == 1){
                printf("You hear a loud scream...\n");
            }else{
                printf("Something is crawling on the floor...\n");
            }
        }
    }

    printf("You have opened the correct door!\n");
    if(room_num == 3){
        printf("You have found the exit...\n");
    }else{
        printf("You have entered room %d.\n", room_num+1);
        simulate(room_num+1, door_num+1);
    }
}