//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 10

typedef enum {
  IDLE = 0,
  MOVING_UP,
  MOVING_DOWN,
  DOOR_OPENED,
} ElevatorState;

typedef enum {
  NO_ACTION = 0,
  PICK_UP,
  DROP_OFF,
} ElevatorAction;

typedef struct {
  int id;
  int current_floor;
  int dest_floor;
  ElevatorState state;
  ElevatorAction action;
  bool is_full;
  bool pickup_request[MAX_FLOORS];
} Elevator;

Elevator elevators[3];

void init_elevators() {
  int i, j;
  for (i = 0; i < 3; i++) {
    elevators[i].id = i;
    elevators[i].current_floor = 0;
    elevators[i].dest_floor = -1;
    elevators[i].state = IDLE;
    elevators[i].action = NO_ACTION;
    elevators[i].is_full = false;
    for (j = 0; j < MAX_FLOORS; j++) {
      elevators[i].pickup_request[j] = false;
    }
  }
}

void print_elevator_status() {
  int i, j;
  for (i = 0; i < 3; i++) {
    printf("Elevator %d - ", elevators[i].id);
    switch (elevators[i].state) {
      case IDLE: printf("IDLE     "); break;
      case MOVING_UP: printf("UP       "); break;
      case MOVING_DOWN: printf("DOWN     "); break;
      case DOOR_OPENED: printf("DOOR OPENED "); break;
    }
    printf("\tpickup requests: ");
    for (j = 0; j < MAX_FLOORS; j++) {
      if (elevators[i].pickup_request[j]) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}

void process_elevator_actions(int elevator_id) {
  Elevator *e = &elevators[elevator_id];
  if (e->action == PICK_UP) {
    e->pickup_request[e->dest_floor] = false;
    e->is_full = true;
    e->action = NO_ACTION;
  } else if (e->action == DROP_OFF) {
    e->is_full = false;
    e->action = NO_ACTION;
  }
}

int find_closest_elevator(int floor, bool up_direction) {
  int i;
  Elevator *e;
  int min_dist = MAX_FLOORS + 1;
  int closest_elevator = -1;
  for (i = 0; i < 3; i++) {
    e = &elevators[i];
    if (((e->state == MOVING_UP && up_direction) || 
        (e->state == MOVING_DOWN && !up_direction) ||
        (e->state == IDLE && e->current_floor == floor)) && 
        abs(e->current_floor - floor) < min_dist) {
      min_dist = abs(e->current_floor - floor);
      closest_elevator = i;
    }
  }
  return closest_elevator;
}

void set_elevator_state(int elevator_id, ElevatorState state) {
  elevators[elevator_id].state = state;
  printf("Elevator %d - changed state to ", elevator_id);
  switch (elevators[elevator_id].state) {
    case IDLE: printf("IDLE\n"); break;
    case MOVING_UP: printf("UP\n"); break;
    case MOVING_DOWN: printf("DOWN\n"); break;
    case DOOR_OPENED: printf("DOOR OPENED\n"); break;
  }
}

void move_elevator(int elevator_id) {
  Elevator *e = &elevators[elevator_id];
  if (e->dest_floor == e->current_floor) {
    e->action = DOOR_OPENED;
    set_elevator_state(elevator_id, DOOR_OPENED);
    return;
  }
  if (e->dest_floor > e->current_floor) {
    set_elevator_state(elevator_id, MOVING_UP);
    e->current_floor++;
  } else {
    set_elevator_state(elevator_id, MOVING_DOWN);
    e->current_floor--;
  }
}

void simulate_elevators() {
  int i, j;
  int next_event_time[3] = {0, 0, 0};

  while (true) {
    // Check for new pickup requests
    for (i = 0; i < MAX_FLOORS; i++) {
      for (j = 0; j < 3; j++) {
        if (elevators[j].state != IDLE) continue;
        if (!elevators[j].is_full && elevators[j].pickup_request[i]) {
          elevators[j].dest_floor = i;
          elevators[j].action = PICK_UP;
          printf("Elevator %d - pickup requested at floor %d\n", j, i);
          if (elevators[j].current_floor != i) {
            set_elevator_state(j, elevators[j].current_floor < i ? MOVING_UP : MOVING_DOWN);
          }
        }
      }
    }

    // Process elevator actions
    for (i = 0; i < 3; i++) {
      if (elevators[i].action != NO_ACTION) {
        process_elevator_actions(i);
      }
      if (elevators[i].state != IDLE) {
        move_elevator(i);
      }
      if (elevators[i].action == DOOR_OPENED) {
        printf("Elevator %d - door opened at floor %d\n", i, elevators[i].current_floor);
        if (elevators[i].pickup_request[elevators[i].current_floor]) {
          elevators[i].dest_floor = elevators[i].current_floor;
          elevators[i].action = PICK_UP;
        } else {
          elevators[i].action = DROP_OFF;
        }
      }
    }

    // Randomly generate new pickup requests
    for (i = 0; i < MAX_FLOORS; i++) {
      if (rand() % 20 == 0) {
        bool up_direction = rand() % 2 == 0;
        int closest_elevator = find_closest_elevator(i, up_direction);
        if (closest_elevator != -1) {
          elevators[closest_elevator].pickup_request[i] = true;
          printf("New pickup request at floor %d\n", i);
        }
      }
    }

    print_elevator_status();

    // Wait 1 second before next event
    for (i = 0; i < 3; i++) {
      if (elevators[i].state != IDLE || elevators[i].action != NO_ACTION) {
        next_event_time[i] = 1;
      }
    }
    for (i = 0; i < 3; i++) {
      if (next_event_time[i] > 0) {
        next_event_time[i]--;
      }
    }
    if (next_event_time[0] == 0 && next_event_time[1] == 0 && next_event_time[2] == 0) {
      break;
    }
  }

  printf("Simulation finished!");
}

int main() {
  init_elevators();
  simulate_elevators();
  return 0;
}