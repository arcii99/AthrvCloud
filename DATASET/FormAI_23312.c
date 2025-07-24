//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_OF_BAGS 50
#define NUM_OF_CONVEYORS 3
#define MAX_TIME 10

typedef struct {
    int bagNum;
    int conveyorNum;
    bool arrived;
} Bag;

Bag bags[NUM_OF_BAGS];
int arrivalTime;
bool isArriving;

void generateBags() {
    srand(time(NULL));
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        bags[i].bagNum = i+1;
        bags[i].conveyorNum = 0;
        bags[i].arrived = false;
    }
}

void printBagsOnConveyors() {
    printf("Current Bag Status on Conveyors:\n");
    for (int i = 1; i <= NUM_OF_CONVEYORS; i++) {
        printf("Conveyor %d: ", i);
        for (int j = 0; j < NUM_OF_BAGS; j++) {
            if (bags[j].conveyorNum == i && !bags[j].arrived) {
                printf("%d ", bags[j].bagNum);
            }
        }
        printf("\n");
    }
}

void moveBagsOnConveyors() {
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        if (bags[i].conveyorNum > 0 && bags[i].conveyorNum < NUM_OF_CONVEYORS && !bags[i].arrived) {
            bags[i].conveyorNum++;
        } else if (bags[i].conveyorNum == NUM_OF_CONVEYORS && !bags[i].arrived) {
            bags[i].arrived = true;
            printf("Bag %d has arrived at the destination.\n", bags[i].bagNum);
        }
    }
}

void addBagsToConveyor(int conveyorNum) {
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        if (bags[i].conveyorNum == 0) {
            bags[i].conveyorNum = conveyorNum;
            printf("Bag %d added to conveyor %d.\n", bags[i].bagNum, conveyorNum);
            break;
        }
    }
}

void simulateArrivals() {
    if (isArriving) {
        if (arrivalTime == 0) {
            addBagsToConveyor(1);
            isArriving = false;
            arrivalTime = rand() % MAX_TIME + 1;
        } else {
            printf("Next bag will arrive in %d seconds.\n", arrivalTime);
            arrivalTime--;
        }
    } else {
        if (arrivalTime == 0) {
            addBagsToConveyor(1);
            isArriving = true;
            arrivalTime = rand() % MAX_TIME + 1;
        } else {
            printf("Next bag will arrive in %d seconds.\n", arrivalTime);
            arrivalTime--;
        }
    }
}

int main() {
    generateBags();
    printBagsOnConveyors();
    arrivalTime = rand() % MAX_TIME + 1;
    isArriving = true;
    for (int i = 0; i < 50; i++) {
        printf("\nTime %d\n", i+1);
        simulateArrivals();
        moveBagsOnConveyors();
        printBagsOnConveyors();
    }
    return 0;
}