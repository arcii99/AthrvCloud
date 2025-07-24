//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BELTS 10
#define MAX_BAGS 50
#define MAX_WEIGHT 50
#define MAX_FLIGHTS 10

typedef enum {BAG_ARRIVAL, BAG_DEPARTURE} BagType;
typedef struct {
    int weight;
    char destination[3];
    BagType type;
} Baggage;
typedef struct {
    Baggage bags[MAX_BAGS];
    int count;
} Belt;
typedef struct {
    Belt belts[MAX_BELTS];
    int count;
} ConveyorSystem;
typedef struct {
    char flightNumber[8];
    char destination[3];
    int baggageCount;
    Baggage* bags;
} Flight;
typedef struct {
    Flight flights[MAX_FLIGHTS];
    int count;
} FlightSchedule;

void initConveyorSystem(ConveyorSystem* cs) {
    for(int i=0; i<MAX_BELTS; i++) {
        cs->belts[i].count = 0;
    }
    cs->count = 0;
}

void addBaggageToConveyorSystem(ConveyorSystem* cs, Baggage bag) {
    for(int i=0; i<MAX_BELTS; i++) {
        if(cs->belts[i].count + 1 <= MAX_BAGS) {
            cs->belts[i].bags[cs->belts[i].count] = bag;
            cs->belts[i].count++;
            break;
        }
    }
}

void displayConveyorSystem(ConveyorSystem* cs) {
    printf("Conveyor System:\n");
    for(int i=0; i<MAX_BELTS; i++) {
        printf("Belt %d:\t", i+1);
        for(int j=0; j<cs->belts[i].count; j++) {
            printf("%d ", cs->belts[i].bags[j].weight);
            if(cs->belts[i].bags[j].type == BAG_ARRIVAL) printf("(A) ");
            else printf("(D) ");
            printf("%s ", cs->belts[i].bags[j].destination);
        }
        printf("\n");
    }
}

void initFlightSchedule(FlightSchedule* fs) {
    fs->count = 0;
}

void addFlightToSchedule(FlightSchedule* fs, Flight flight) {
    if(fs->count + 1 <= MAX_FLIGHTS) {
        fs->flights[fs->count] = flight;
        fs->count++;
    }
}

void generateRandomBags(Baggage* bags, int count, BagType type, char* destination) {
    srand(time(NULL));
    for(int i=0; i<count; i++) {
        bags[i].weight = rand() % MAX_WEIGHT + 1;
        bags[i].type = type;
        if(destination == NULL) {
            char dest[3] = {rand() % 26 + 65, rand() % 26 + 65, rand() % 26 + 65};
            bags[i].destination[0] = dest[0];
            bags[i].destination[1] = dest[1];
            bags[i].destination[2] = dest[2];
        }
        else {
            bags[i].destination[0] = destination[0];
            bags[i].destination[1] = destination[1];
            bags[i].destination[2] = destination[2];
        }
    }
}

void initFlight(Flight* flight, char* flightNumber, char* destination, int baggageCount) {
    strncpy(flight->flightNumber, flightNumber, 8);
    strncpy(flight->destination, destination, 3);
    flight->baggageCount = baggageCount;
    flight->bags = (Baggage*) malloc(sizeof(Baggage) * baggageCount);
}

void generateRandomFlight(Flight* flight, char* destination) {
    srand(time(NULL));
    char flightNumber[8] = {rand() % 26 + 65, rand() % 26 + 65, rand() % 26 + 65, rand() % 26 + 65, rand() % 10 + 48, rand() % 10 + 48, rand() % 10 + 48, rand() % 10 + 48};
    initFlight(flight, flightNumber, destination, rand() % MAX_BAGS + 1);
    generateRandomBags(flight->bags, flight->baggageCount, BAG_DEPARTURE, destination);
}

void displayFlightSchedule(FlightSchedule* fs) {
    printf("Flight Schedule:\n");
    for(int i=0; i<fs->count; i++) {
        printf("%s:\t%s\t%d bags\n", fs->flights[i].flightNumber, fs->flights[i].destination, fs->flights[i].baggageCount);
    }
}

int main() {
    ConveyorSystem cs;
    initConveyorSystem(&cs);
    
    FlightSchedule fs;
    initFlightSchedule(&fs);
    
    for(int i=0; i<5; i++) {
        char destination[3] = {(char)(i + 65), (char)(i + 66), (char)(i + 67)};
        Flight flight;
        generateRandomFlight(&flight, destination);
        addFlightToSchedule(&fs, flight);
        for(int j=0; j<flight.baggageCount; j++) {
            addBaggageToConveyorSystem(&cs, flight.bags[j]);
        }
    }
    
    displayFlightSchedule(&fs);
    displayConveyorSystem(&cs);
    
    return 0;
}