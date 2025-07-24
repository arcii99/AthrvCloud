//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define MAX_PEOPLE 20

typedef struct person {
    int id;
    int current_floor;
    int destination_floor;
} Person;

typedef struct elevator {
    int current_floor;
    Person occupants[MAX_PEOPLE];
    int num_occupants;
} Elevator;

void initialize_people(Person people[MAX_PEOPLE]) {
    int i;
    for (i = 0; i < MAX_PEOPLE; i++) {
        people[i].id = i+1;
        people[i].current_floor = rand() % FLOORS + 1;
        people[i].destination_floor = rand() % FLOORS + 1;
        while (people[i].current_floor == people[i].destination_floor) {
            people[i].destination_floor = rand() % FLOORS + 1;
        }
    }
}

void print_people(Person people[MAX_PEOPLE]) {
    int i;
    printf("People:\n");
    for (i = 0; i < MAX_PEOPLE; i++) {
        printf("Person %d: current floor %d, destination floor %d\n", people[i].id, people[i].current_floor, people[i].destination_floor);
    }
}

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 1;
    elevator->num_occupants = 0;
}

void print_elevator(Elevator *elevator) {
    int i;
    printf("Elevator: current floor %d, occupants: ", elevator->current_floor);
    for (i = 0; i < elevator->num_occupants; i++) {
        printf("Person %d ", elevator->occupants[i].id);
    }
    printf("\n");
}

int count_people_on_floor(Person people[MAX_PEOPLE], int floor) {
    int i, count = 0;
    for (i = 0; i < MAX_PEOPLE; i++) {
        if (people[i].current_floor == floor) {
            count++;
        }
    }
    return count;
}

int add_person_to_elevator(Elevator *elevator, Person person) {
    if (elevator->num_occupants == MAX_PEOPLE) {
        return 0;
    }
    elevator->occupants[elevator->num_occupants] = person;
    elevator->num_occupants++;
    return 1;
}

int remove_person_from_elevator(Elevator *elevator, int person_id) {
    int i, found = 0;
    for (i = 0; i < elevator->num_occupants; i++) {
        if (elevator->occupants[i].id == person_id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (i = i + 1; i < elevator->num_occupants; i++) {
            elevator->occupants[i-1] = elevator->occupants[i];
        }
        elevator->num_occupants--;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    Person people[MAX_PEOPLE];
    initialize_people(people);
    print_people(people);
    
    Elevator elevator;
    initialize_elevator(&elevator);
    print_elevator(&elevator);
    
    int i, j;
    for (i = 1; i <= FLOORS; i++) {
        int people_on_floor = count_people_on_floor(people, i);
        if (people_on_floor > 0) {
            printf("%d people on floor %d.\n", people_on_floor, i);
            for (j = 0; j < MAX_PEOPLE; j++) {
                if (people[j].current_floor == i) {
                    if (add_person_to_elevator(&elevator, people[j])) {
                        printf("Person %d added to elevator.\n", people[j].id);
                    } else {
                        printf("Elevator full!\n");
                        break;
                    }
                }
            }
            // elevator now goes to highest destination floor of the passengers inside
            int max_destination_floor = 0;
            for (j = 0; j < elevator.num_occupants; j++) {
                if (elevator.occupants[j].destination_floor > max_destination_floor) {
                    max_destination_floor = elevator.occupants[j].destination_floor;
                }
            }
            printf("Elevator going to floor %d.\n", max_destination_floor);
            elevator.current_floor = max_destination_floor;
            // passengers leave the elevator if this is their destination floor
            for (j = 0; j < elevator.num_occupants; j++) {
                if (elevator.occupants[j].destination_floor == max_destination_floor) {
                    printf("Person %d getting off elevator.\n", elevator.occupants[j].id);
                    remove_person_from_elevator(&elevator, elevator.occupants[j].id);
                    break;
                }
            }
            print_elevator(&elevator);
        } else {
            printf("No one on floor %d.\n", i);
        }
    }
    
    printf("Final elevator state:\n");
    print_elevator(&elevator);
    
    return 0;
}