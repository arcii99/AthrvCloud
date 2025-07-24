//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
#define PPL 20

int bag[MAX];
int top = -1;

int isFull() {
    if(top == MAX - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if(top == -1) {
        return 1;
    }
    return 0;
}

void push(int item) {
    if(isFull()) {
        printf("\nBaggage belt is full!");
        return;
    }
    bag[++top] = item;
}

int pop() {
    if(isEmpty()) {
        return -1;
    }
    return bag[top--];
}

void display() {
    if(isEmpty()) {
        printf("\nBaggage belt is empty!");
        return;
    }
    int i;
    printf("\nItems on the baggage belt:\n");
    for(i=0; i<=top; i++) {
        printf("%d ", bag[i]);
    }
}

int main() {
    srand(time(0));
    int i, j, k, luggage;
    printf("--------Airport Baggage Handling Simulation--------\n");
    printf("\nNumber of people: %d", PPL);
    printf("\nSize of the baggage belt: %d", MAX);
    printf("\nLuggage will be randomly added to the baggage belt.\n");
    printf("\nPress Enter to start...");
    getchar();
    for(i=1; i<=PPL; i++) {
        printf("\n--------------- Person %d ---------------\n", i);
        luggage = rand() % 5 + 1;
        printf("Number of luggage: %d", luggage);
        for(j=1; j<=luggage; j++) {
            printf("\nAdding luggage %d to the baggage belt...", j);
            if(isFull()) {
                printf("\nBaggage belt is full, waiting...");
                while(isFull());
                printf("\nAdding luggage %d to the baggage belt...", j);
            }
            push(j);
            printf("\n");
            display();
            printf("\n");
        }
        printf("\nPerson %d's luggage has been added to the baggage belt.\n", i);
        printf("--------------------------------------------------\n");
        if(i%5 == 0) {
            printf("\n-------- Baggage Belts are being processed... --------\n");
            for(k=1; k<=MAX; k++) {
                printf("\nProcessing luggage %d...", k);
                if(isEmpty()) {
                    printf("\nBaggage belt is empty!");
                    break;
                }
                printf("\nRemoving luggage %d from the baggage belt...", pop());
                printf("\n");
                display();
                printf("\n");
            }
            printf("\n-------- Baggage Belts have been processed. --------\n");
        }
    }
    printf("\nAll passengers' luggage have been added to the baggage belt.");
    printf("\n-------- Baggage Belts are being processed... --------\n");
    while(!isEmpty()) {
        printf("\nRemoving luggage %d from the baggage belt...", pop());
        printf("\n");
        display();
        printf("\n");
    }
    printf("\n-------- Baggage Belts have been processed. --------\n");
    printf("\nSimulation is over.");
    return 0;
}