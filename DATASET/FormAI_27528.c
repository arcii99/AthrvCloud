//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Elevator {
  int floor;
  int direction; // 1 for up, -1 for down, 0 for idle
  int capacity;
  int passengers;
} elevator;

void printElevator() {
  printf("Floor: %d\nDirection: %s\nCapacity: %d\nPassengers: %d\n", 
    elevator.floor, 
    elevator.direction == 1 ? "Up" : elevator.direction == -1 ? "Down" : "Idle", 
    elevator.capacity, 
    elevator.passengers
  );
}

void moveElevator() {
  if (elevator.direction == 0) {
    return;
  }

  printf("Moving %s!\n", elevator.direction == 1 ? "Up" : "Down");

  elevator.floor += elevator.direction;

  if (elevator.floor == 10) {
    elevator.direction = -1;
  } else if (elevator.floor == -1) {
    elevator.direction = 1;
  }
}

void addPassengers(int n) {
  int space = elevator.capacity - elevator.passengers;

  if (n <= space) {
    elevator.passengers += n;
    printf("%d passengers added.\n", n);
  } else {
    printf("%d passengers added. %d had to wait.\n", space, n - space);
    elevator.passengers = elevator.capacity;
  }
}

void removePassengers(int n) {
  if (n <= elevator.passengers) {
    elevator.passengers -= n;
    printf("%d passengers removed.\n", n);
  } else {
    printf("%d passengers removed. %d still need to exit.\n", elevator.passengers, n - elevator.passengers);
    elevator.passengers = 0;
  }
}

void checkRequests(char requests[]) {
  int n_up = 0;
  int n_down = 0;

  for (int i = 0; i < 10; i++) {
    if (requests[i] == 'u') {
      n_up++;
    } else if (requests[i] == 'd') {
      n_down++;
    }
  }

  if (n_up > n_down) {
    elevator.direction = 1;
  } else if (n_down > n_up) {
    elevator.direction = -1;
  }

  printf("%d up requests, %d down requests\n", n_up, n_down);
}

int main() {
  srand(time(0));

  elevator.floor = 0;
  elevator.direction = 0;
  elevator.capacity = 10;
  elevator.passengers = 0;

  char requests[10] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'};
  
  int t = 0;

  while (t < 100) {
    printf("\n\nTime: %d\n", t);

    printElevator();

    if (elevator.direction != 0) {
      moveElevator();
    }

    if (elevator.floor == 0) {
      addPassengers(rand() % 11);
    } else {
      char c = requests[elevator.floor];

      if (c == 'u' && elevator.direction == 1) {
        removePassengers(rand() % (elevator.passengers + 1));
        requests[elevator.floor] = '-';
      } else if (c == 'd' && elevator.direction == -1) {
        removePassengers(rand() % (elevator.passengers + 1));
        requests[elevator.floor] = '-';
      }
    }

    if (elevator.floor == 0 || elevator.passengers > 0) {
      int i = rand() % 10;
      if (i == elevator.floor) {
        requests[i] = '-';
      } else if (i < elevator.floor) {
        requests[i] = 'u';
      } else if (i > elevator.floor) {
        requests[i] = 'd';
      }
    }

    checkRequests(requests);

    t++;
  }

  return 0;
}