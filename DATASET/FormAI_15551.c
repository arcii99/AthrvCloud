//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 75

int main() {
    int bingo[MAX], temp, i, j, num;
    srand(time(NULL));
    for(i=0;i<MAX;i++) {
        bingo[i] = i+1;
    }
    for(i=0;i<MAX;i++) {
        j = rand()%MAX;
        temp = bingo[i];
        bingo[i] = bingo[j];
        bingo[j] = temp;
    }
    printf("Welcome to the Bingo Simulator!\n");
    printf("Here are your randomly generated bingo numbers:\n");
    for(i=0;i<MAX;i++) {
        if(i%5==0) {
            printf("\n");
        }
        printf("%d\t", bingo[i]);
    }
    printf("\n\n");
    printf("Enter 1 to start simulating bingo or -1 to quit:\n");
    scanf("%d", &num);
    while(num != -1) {
        int check[MAX];
        for(i=0;i<MAX;i++) {
            check[i] = 0;
        }
        int count = 0;
        while(count < MAX) {
            int randNum = rand()%MAX + 1;
            for(i=0;i<MAX;i++) {
                if(randNum == bingo[i]) {
                    if(check[i] == 0) {
                        count++;
                        check[i] = 1;
                    }
                    break;
                }
            }
            printf("Next call: %d\n", randNum);
            if(count >= 5) {
                int win = 1;
                for(i=0;i<5;i++) {
                    if(!check[i]) {
                        win = 0;
                        break;
                    }
                }
                if(win) {
                    printf("Hooray! You got a bingo!\n");
                    break;
                }
            }
            if(count >= 15) {
                int win = 1;
                for(i=5;i<10;i++) {
                    if(!check[i]) {
                        win = 0;
                        break;
                    }
                }
                if(win) {
                    printf("Hooray! You got a bingo!\n");
                    break;
                }
            }
            if(count >= 25) {
                int win = 1;
                for(i=10;i<15;i++) {
                    if(!check[i]) {
                        win = 0;
                        break;
                    }
                }
                if(win) {
                    printf("Hooray! You got a bingo!\n");
                    break;
                }
            }
            if(count >= 35) {
                int win = 1;
                for(i=15;i<20;i++) {
                    if(!check[i]) {
                        win = 0;
                        break;
                    }
                }
                if(win) {
                    printf("Hooray! You got a bingo!\n");
                    break;
                }
            }
            if(count >= 45) {
                int win = 1;
                for(i=20;i<25;i++) {
                    if(!check[i]) {
                        win = 0;
                        break;
                    }
                }
                if(win) {
                    printf("Hooray! You got a bingo!\n");
                    break;
                }
            }
            if(count >= 50) {
                int win = 1;
                for(i=0;i<50;i+=5) {
                    int sum = 0;
                    for(j=i;j<i+5;j++) {
                        if(!check[j]) {
                            sum = 1;
                            break;
                        }
                    }
                    if(!sum) {
                        win = 0;
                        break;
                    }
                }
                if(win) {
                    printf("Hooray! You got a bingo!\n");
                    break;
                }
            }
        }
        printf("\nEnter 1 to start simulating bingo or -1 to quit:\n");
        scanf("%d", &num);
    }
    return 0;
}