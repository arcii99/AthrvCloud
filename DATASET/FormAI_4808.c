//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
/* Elevator Simulation */
/* By Claude Shannon */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define MAX_PEOPLE 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int id;
    int destination_floor;
} Person;

typedef struct {
    int id;
    int current_floor;
    int direction;
    int num_people;
    Person people[ELEVATOR_CAPACITY];
} Elevator;

int generate_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void initialize_people(Person* people, int num_people) {
    for(int i = 0; i < num_people; i++) {
        Person p = {i+1, generate_random(1, NUM_FLOORS)};
        people[i] = p;
    }
}

void initialize_elevators(Elevator* elevators, int num_elevators) {
    for(int i = 0; i < num_elevators; i++) {
        Elevator e = {i+1, 1, 1, 0, {0}};
        elevators[i] = e;
    }
}

void print_person(Person person) {
    printf("Person %d going to floor %d\n", person.id, person.destination_floor);
}

void print_people(Person* people, int num_people) {
    printf("People waiting on floor:\n");
    for(int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }
}

void print_elevator(Elevator elevator) {
    printf("Elevator %d on floor %d going %s with %d people:\n",
        elevator.id, elevator.current_floor, elevator.direction == 1 ? "up" : "down", elevator.num_people);
    for(int i = 0; i < elevator.num_people; i++) {
        print_person(elevator.people[i]);
    }
}

void print_elevators(Elevator* elevators, int num_elevators) {
    printf("Elevators:\n");
    for(int i = 0; i < num_elevators; i++) {
        print_elevator(elevators[i]);
    }
}

int find_elevator(Elevator* elevators, int num_elevators, int floor, int direction) {
    for(int i = 0; i < num_elevators; i++) {
        Elevator e = elevators[i];
        if(e.direction != direction) continue;
        if(e.current_floor == floor && e.num_people < ELEVATOR_CAPACITY) {
            return e.id;
        }
    }
    return -1;
}

void add_person_to_elevator(Elevator* elevator, Person person) {
    elevator->people[elevator->num_people++] = person;
}

void remove_person_from_floor(Person* people, int* num_people, int index) {
    for(int i = index; i < *num_people-1; i++) {
        people[i] = people[i+1];
    }
    (*num_people)--;
}

void remove_person_from_elevator(Elevator* elevator, int index) {
    for(int i = index; i < elevator->num_people-1; i++) {
        elevator->people[i] = elevator->people[i+1];
    }
    elevator->num_people--;
}

void move_elevator(Elevator* elevator) {
    if(elevator->direction == 1) {
        elevator->current_floor++;
        if(elevator->current_floor == NUM_FLOORS) {
            elevator->direction = -1;
        }
    } else {
        elevator->current_floor--;
        if(elevator->current_floor == 1) {
            elevator->direction = 1;
        }
    }
}

void simulate_elevator(Elevator* elevators, int num_elevators, Person* people, int num_people) {
    int num_iterations = 0;
    while(num_people > 0 && num_iterations < 1000) {
        printf("Iteration %d:\n", num_iterations+1);
        print_people(people, num_people);
        print_elevators(elevators, num_elevators);
        for(int i = 1; i <= NUM_FLOORS; i++) {
            for(int j = 1; j >= -1; j -= 2) {
                // Look for elevator going in the same direction with empty space on this floor
                int elevator_id = find_elevator(elevators, num_elevators, i, j);
                if(elevator_id != -1) {
                    printf("Elevator %d is on floor %d going %s and has room for more people.\n",
                        elevator_id, i, j == 1 ? "up" : "down");
                    // Add as many people as possible to elevator
                    int remaining_space = ELEVATOR_CAPACITY - elevators[elevator_id-1].num_people;
                    for(int k = 0; k < num_people && remaining_space > 0; k++) {
                        Person person = people[k];
                        if(person.destination_floor == i && j == 1) {
                            add_person_to_elevator(&elevators[elevator_id-1], person);
                            remove_person_from_floor(people, &num_people, k);
                            remaining_space--;
                        } else if(person.destination_floor == i && j == -1) {
                            add_person_to_elevator(&elevators[elevator_id-1], person);
                            remove_person_from_floor(people, &num_people, k);
                            remaining_space--;
                        }
                    }
                } else {
                    printf("No elevator found on floor %d going %s.\n", i, j == 1 ? "up" : "down");
                }
            }
        }
        // Move elevators one floor
        for(int i = 0; i < num_elevators; i++) {
            Elevator* elevator = &elevators[i];
            for(int j = 0; j < elevator->num_people; j++) {
                Person* person = &elevator->people[j];
                if(elevator->current_floor == person->destination_floor) {
                    remove_person_from_elevator(elevator, j);
                    num_people--;
                    j--;
                }
            }
            move_elevator(elevator);
        }
        num_iterations++;
    }
}

int main() {
    srand(time(NULL));
    Person people[MAX_PEOPLE];
    Elevator elevators[NUM_ELEVATORS];
    initialize_people(people, MAX_PEOPLE);
    initialize_elevators(elevators, NUM_ELEVATORS);
    simulate_elevator(elevators, NUM_ELEVATORS, people, MAX_PEOPLE);
    return 0;
}