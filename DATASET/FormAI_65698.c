//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define FLOORS 10          // number of floors in the building
#define ELEVATORS 2        // number of elevators in the building
#define MAX_PERSONS 10     // maximum number of persons in the building

// elevator status
enum elevator_status {
  MOVE_UP,
  MOVE_DOWN,
  IDLE
};

// person structure
struct person {
  int current_floor;     // current floor of the person
  int destination_floor; // destination floor of the person
};

// elevator structure
struct elevator {
  int current_floor;             // current floor of the elevator
  enum elevator_status status;   // status of the elevator
  struct person passengers[4];   // person structures of the passengers
  int num_passengers;            // number of passengers currently in the elevator
};

// set initial values of the elevator structure
struct elevator elevators[ELEVATORS] = {
  { 0, IDLE, {}, 0 },
  { 0, IDLE, {}, 0 },
};

// array to hold the persons in the building
struct person persons[MAX_PERSONS];

// set person structures for initial configuration
void init_persons() {
  persons[0] = (struct person) {0, 5};
  persons[1] = (struct person) {2, 8};
  persons[2] = (struct person) {1, 6};
  persons[3] = (struct person) {3, 7};
  persons[4] = (struct person) {5, 0};
}

// check if a person is waiting on a floor
bool person_waiting(int floor) {
  for (int i = 0; i < MAX_PERSONS; i++) {
    if (persons[i].current_floor == floor) {
      return true;
    }
  }
  return false;
}

// check if the elevator has any passengers to pick up
bool elevator_has_passengers_to_pick_up(int e, int floor) {
  for (int i = 0; i < elevators[e].num_passengers; i++) {
    if (elevators[e].passengers[i].destination_floor == floor) {
      return true;
    }
  }
  return false;
}

// check if the elevator has any passengers in it
bool elevator_has_passengers(int e) {
  return elevators[e].num_passengers > 0;
}

// get the ID of an elevator that is on a floor and idle
int get_idle_elevator(int floor) {
  for (int i = 0; i < ELEVATORS; i++) {
    if (elevators[i].current_floor == floor && elevators[i].status == IDLE) {
      return i;
    }
  }
  return -1;
}

// get the ID of an elevator that can pick up passengers on the way
int get_elevator_with_space(int floor) {
  for (int i = 0; i < ELEVATORS; i++) {
    if (elevators[i].num_passengers < 4 && elevator_has_passengers_to_pick_up(i, floor)) {
      return i;
    }
  }
  return -1;
}

// get the ID of an elevator that is closest to a floor and idle
int get_closest_idle_elevator(int floor) {
  int min_dist = FLOORS + 1;
  int min_elevator = -1;

  for (int i = 0; i < ELEVATORS; i++) {
    if (elevators[i].status == IDLE) {
      int dist = abs(elevators[i].current_floor - floor);
      if (dist < min_dist) {
        min_dist = dist;
        min_elevator = i;
      }
    }
  }

  return min_elevator;
}

// get the ID of an elevator that is closest to a floor and moving towards it
int get_closest_moving_elevator(int floor) {
  int min_dist = FLOORS + 1;
  int min_elevator = -1;

  for (int i = 0; i < ELEVATORS; i++) {
    if (elevators[i].status == MOVE_UP && elevators[i].current_floor <= floor) {
      int dist = floor - elevators[i].current_floor;
      if (dist < min_dist) {
        min_dist = dist;
        min_elevator = i;
      }
    }
    else if (elevators[i].status == MOVE_DOWN && elevators[i].current_floor >= floor) {
      int dist = elevators[i].current_floor - floor;
      if (dist < min_dist) {
        min_dist = dist;
        min_elevator = i;
      }
    }
  }

  return min_elevator;
}

// move the elevator one floor up
void move_up(int e) {
  if (elevators[e].current_floor < FLOORS) {
    elevators[e].current_floor++;
  }
}

// move the elevator one floor down
void move_down(int e) {
  if (elevators[e].current_floor > 0) {
    elevators[e].current_floor--;
  }
}

// pick up waiting persons on a floor
void pick_up_persons(int e, int floor) {
  for (int i = 0; i < MAX_PERSONS; i++) {
    if (persons[i].current_floor == floor && elevators[e].num_passengers < 4) {
      elevators[e].passengers[elevators[e].num_passengers] = persons[i];
      elevators[e].num_passengers++;
      persons[i] = (struct person) {-1, -1};
    }
  }
}

// drop off passengers
void drop_off_passengers(int e) {
  for (int i = 0; i < elevators[e].num_passengers; i++) {
    if (elevators[e].passengers[i].destination_floor == elevators[e].current_floor) {
      elevators[e].passengers[i] = elevators[e].passengers[elevators[e].num_passengers - 1];
      elevators[e].num_passengers--;
    }
  }
}

// main loop of the simulation
int main() {
  init_persons();

  while (true) {
    // loop through elevators
    for (int e = 0; e < ELEVATORS; e++) {
      if (elevators[e].status == IDLE) {
        int idle_elevator = get_idle_elevator(elevators[e].current_floor);
        if (idle_elevator != -1) {
          elevators[e].status = MOVE_UP;
        }
        else {
          int closest_idle_elevator = get_closest_idle_elevator(elevators[e].current_floor);
          if (closest_idle_elevator != -1) {
            if (closest_idle_elevator == e) {
              elevators[e].status = IDLE;
            }
            else if (elevators[e].current_floor < elevators[closest_idle_elevator].current_floor) {
              elevators[e].status = MOVE_UP;
            }
            else if (elevators[e].current_floor > elevators[closest_idle_elevator].current_floor) {
              elevators[e].status = MOVE_DOWN;
            }
          }
          else {
            int elevator_with_space = get_elevator_with_space(elevators[e].current_floor);
            if (elevator_with_space != -1) {
              if (elevator_with_space == e) {
                elevators[e].status = IDLE;
              }
              else if (elevators[e].current_floor < elevators[elevator_with_space].current_floor) {
                elevators[e].status = MOVE_UP;
              }
              else if (elevators[e].current_floor > elevators[elevator_with_space].current_floor) {
                elevators[e].status = MOVE_DOWN;
              }
            }
            else {
              elevators[e].status = IDLE;
            }
          }
        }
      }
      else {
        if (elevators[e].status == MOVE_UP) {
          move_up(e);

          if (elevators[e].current_floor == FLOORS) {
            elevators[e].status = MOVE_DOWN;
          }

          if (person_waiting(elevators[e].current_floor)) {
            pick_up_persons(e, elevators[e].current_floor);
          }

          if (elevator_has_passengers(e)) {
            drop_off_passengers(e);
          }
        }
        else if (elevators[e].status == MOVE_DOWN) {
          move_down(e);

          if (elevators[e].current_floor == 0) {
            elevators[e].status = MOVE_UP;
          }

          if (person_waiting(elevators[e].current_floor)) {
            pick_up_persons(e, elevators[e].current_floor);
          }

          if (elevator_has_passengers(e)) {
            drop_off_passengers(e);
          }
        }
      }
    }
  }

  return 0; // unreachable code
}