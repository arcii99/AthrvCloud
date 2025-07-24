//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUMBER_OF_FLOORS 10
#define ELEVATOR_CAPACITY 15
#define FLOOR_WAIT_TIME 2 //Time in seconds for the elevator to stay idle on a floor
#define ELEVATOR_SPEED 3  //Time in seconds for the elevator to move from one floor to another

typedef struct Person {
    int id;
    int current_floor;
    int target_floor;
} Person;

typedef struct Elevator {
    int current_floor;
    int num_people;
    Person people[ELEVATOR_CAPACITY];
    int direction; //1 for up, -1 for down, 0 for stationary
} Elevator;

int get_random_floor(int exclude_floor){
    int random_floor = exclude_floor;
    while(random_floor==exclude_floor){
        random_floor = rand() % NUMBER_OF_FLOORS;
    }
    return random_floor;
}

void add_person(Person* people_list, int* num_people, int current_floor, int target_floor){
    Person new_person;
    new_person.id = *num_people + 1;
    new_person.current_floor = current_floor;
    new_person.target_floor = target_floor;
    people_list[*num_people] = new_person;
    (*num_people)++;
}

void move_elevator(Elevator* elevator){
    elevator->current_floor += elevator->direction;
    printf("Elevator is moving to floor %d\n", elevator->current_floor);
}

void check_people_in_elevator(Elevator* elevator, int floors_with_people[NUMBER_OF_FLOORS]){
    for(int i=0; i < elevator->num_people; i++){
        if(elevator->people[i].target_floor == elevator->current_floor){
            printf("Person %d exits the elevator at floor %d\n", elevator->people[i].id, elevator->current_floor);
            elevator->num_people--;
            for(int j=i; j < elevator->num_people; j++){
                elevator->people[j] = elevator->people[j+1];
            }
        }else{
            floors_with_people[elevator->current_floor] = 1;
        }
    }
}

void check_people_on_floor(Person* waiting_people, int* num_people, Elevator* elevator){
    for(int i=0; i< *num_people; i++){
        if(waiting_people[i].current_floor == elevator->current_floor){
            if(elevator->num_people < ELEVATOR_CAPACITY){
                printf("Person %d enters the elevator at floor %d\n", waiting_people[i].id, waiting_people[i].current_floor);
                elevator->people[elevator->num_people] = waiting_people[i];
                elevator->num_people++;
                (*num_people)--;
                for(int j=i; j < *num_people; j++){
                    waiting_people[j] = waiting_people[j+1];
                }
                i--;
            }else{
                break;
            }
        }
    }
}

int main(){
    srand(time(NULL)); //Seed rand with time

    Elevator elevator;
    elevator.current_floor = 0;
    elevator.num_people = 0;
    elevator.direction = 1;

    Person waiting_people[NUMBER_OF_FLOORS][ELEVATOR_CAPACITY];
    int num_people_on_floor[NUMBER_OF_FLOORS] = {0};

    int floors_with_people[NUMBER_OF_FLOORS] = {0};

    while(1){
        //Check if elevator has arrived at target floor
        if(floors_with_people[elevator.current_floor] || elevator.num_people > 0){
            check_people_in_elevator(&elevator, floors_with_people);

            check_people_on_floor(waiting_people[elevator.current_floor], &num_people_on_floor[elevator.current_floor], &elevator);

            if(elevator.num_people == 0 && floors_with_people[elevator.current_floor] == 0){
                printf("Elevator is idle on floor %d for %d seconds\n", elevator.current_floor, FLOOR_WAIT_TIME);
                sleep(FLOOR_WAIT_TIME);
            }else{
                printf("Elevator doors are closing on floor %d\n", elevator.current_floor);
                //Assuming the elevator needs some time to close its doors
                sleep(1);
            }
        }else{
            //No one is waiting on this floor and no one is in the elevator
            if(elevator.direction == 1 && elevator.current_floor == NUMBER_OF_FLOORS - 1){
                elevator.direction = -1;
            }else if(elevator.direction == -1 && elevator.current_floor == 0){
                elevator.direction = 1;
            }else{
                move_elevator(&elevator);
                sleep(ELEVATOR_SPEED);
            }
        }

        

        //Add new person on random floor
        if(rand()%2 == 0){
            int source_floor = get_random_floor(elevator.current_floor);
            int target_floor = get_random_floor(source_floor);
            if(num_people_on_floor[source_floor] < ELEVATOR_CAPACITY){
                add_person(waiting_people[source_floor], &num_people_on_floor[source_floor], source_floor, target_floor);
                printf("New person added to waiting list on floor %d, target floor is %d\n", source_floor, target_floor);
            }
        }
    }
    return 0;
}