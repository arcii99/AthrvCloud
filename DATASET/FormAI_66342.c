//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Constants 
#define NUM_FLOORS 6 
#define NUM_ELEVATORS 3 

// Struct declarations 
typedef struct Request { 
  int floor; 
  int direction; //1: up , -1: down 
  int serviced_by; //-1: not defined yet 
} Request; 

typedef struct Elevator { 
  int current_floor; 
  int is_idle; 
  Request current_request; 
} Elevator; 

// Global variables 
Elevator elevators[NUM_ELEVATORS]; 
Request requests[NUM_FLOORS]; 

// Function prototypes 
void initialize_elevators(); 
void initialize_requests(); 
void print_state(); 
int get_random_direction(); 
void simulate_elevators(); 

int main() { 
  srand(time(NULL)); 

  initialize_elevators(); 
  initialize_requests(); 
  print_state(); 

  simulate_elevators(); 

  return 0; 
} 

// Function definitions 
void initialize_elevators() { 
  for (int i = 0; i < NUM_ELEVATORS; i++) { 
    elevators[i].current_floor = 0; 
    elevators[i].is_idle = 1; 
    elevators[i].current_request.floor = -1; 
    elevators[i].current_request.direction = 0; 
    elevators[i].current_request.serviced_by = -1; 
  } 
} 

void initialize_requests() { 
  for (int i = 0; i < NUM_FLOORS; i++) { 
    requests[i].floor = i; 
    requests[i].direction = get_random_direction(); 
    requests[i].serviced_by = -1; 
  } 
} 

void print_state() { 
  printf("Elevator status:\n"); 
  for (int i = 0; i < NUM_ELEVATORS; i++) { 
    printf("Elevator %d, current floor: %d\n", i, elevators[i].current_floor); 
    if (!elevators[i].is_idle) { 
      printf("Elevator %d en route to floor %d\n", i, elevators[i].current_request.floor); 
    } 
  } 
  printf("\n"); 

  printf("Request status:\n"); 
  for (int i = 0; i < NUM_FLOORS; i++) { 
    printf("Floor %d, direction: %d, serviced by: %d\n", i, requests[i].direction, requests[i].serviced_by); 
  } 
  printf("\n"); 
} 

int get_random_direction() { 
  int r = rand() % 2; // 0 or 1 
  return (r == 0) ? -1 : 1; 
} 

void simulate_elevators() { 
  int num_requests_serviced = 0; 

  while (num_requests_serviced < NUM_FLOORS) { 
    // Randomly assign requests to elevators 
    for (int i = 0; i < NUM_FLOORS; i++) { 
      if (requests[i].serviced_by == -1) { 
        int elevator_index = rand() % NUM_ELEVATORS; 
        elevators[elevator_index].current_request = requests[i]; 
        elevators[elevator_index].is_idle = 0; 
        requests[i].serviced_by = elevator_index; 
      } 
    } 

    // Move elevators towards their current requests and service them when they arrive 
    for (int i = 0; i < NUM_ELEVATORS; i++) { 
      if (!elevators[i].is_idle) { 
        if (elevators[i].current_floor == elevators[i].current_request.floor) { 
          printf("Elevator %d arrived at floor %d\n", i, elevators[i].current_floor); 
          elevators[i].is_idle = 1; 
          num_requests_serviced++; 
        } else if (elevators[i].current_floor < elevators[i].current_request.floor) { 
          elevators[i].current_floor++; 
          printf("Elevator %d moving up, now at floor %d\n", i, elevators[i].current_floor); 
        } else { 
          elevators[i].current_floor--; 
          printf("Elevator %d moving down, now at floor %d\n", i, elevators[i].current_floor); 
        } 
      } 
    } 
  } 
}