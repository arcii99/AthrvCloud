//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
// This program simulates the baggage handling system in an airport. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100 // maximum number of bags that could be processed at a station
#define MAX_STATIONS 5 // maximum number of stations in the system
#define MAX_EVENTS 10000 // maximum number of events in the event queue

// struct to hold information about a single bag
typedef struct Bag {
    int id; // unique identifier for the bag
    int arrival_time; // time at which the bag enters the system
    int station_num; // station number to which the bag is assigned
    int departure_time; // time at which the bag is removed from the system
} Bag;

// struct to hold information about a station in the baggage handling system
typedef struct Station {
    int id; // unique identifier for the station
    int is_open; // flag to indicate if the station is currently open for processing bags
    int num_bags; // number of bags currently being processed at the station
    Bag bags[MAX_BAGS]; // array to hold bags currently being processed at the station
} Station;

// struct to hold information about an event in the event queue
typedef struct Event {
    int time; // time at which the event occurs
    int type; // type of event: 1 = bag arrival, 2 = station open, 3 = station close
    int station_num; // station number associated with the event
    Bag bag; // bag associated with the event (NULL for station open/close events)
} Event;

// function to compare two events based on their time
int compare_events(const void* a, const void* b) {
    const Event* event_a = (const Event*)a;
    const Event* event_b = (const Event*)b;
    return event_a->time - event_b->time;
}

int main() {
    // initialize stations
    Station stations[MAX_STATIONS];
    for (int i = 0; i < MAX_STATIONS; i++) {
        stations[i].id = i;
        stations[i].is_open = 1;
        stations[i].num_bags = 0;
    }
    
    // initialize event queue
    Event events[MAX_EVENTS];
    int num_events = 0;
    
    // add initial events to event queue
    for (int i = 0; i < MAX_STATIONS; i++) {
        Event event;
        event.time = 0;
        event.type = 2;
        event.station_num = i;
        events[num_events++] = event;
    }
    
    // process events in event queue
    while (num_events > 0) {
        // sort events by time
        qsort(events, num_events, sizeof(Event), compare_events);
        
        // get next event from event queue
        Event event = events[0];
        for (int i = 1; i < num_events; i++) {
            events[i-1] = events[i];
        }
        num_events--;
        
        // process event
        if (event.type == 1) {
            // bag arrival event
            printf("Bag %d arrived at station %d at time %d\n", event.bag.id, event.station_num, event.time);
            Station* station = &stations[event.station_num];
            if (station->is_open) {
                if (station->num_bags < MAX_BAGS) {
                    station->bags[station->num_bags++] = event.bag;
                    printf("Bag %d added to station %d's queue at time %d\n", event.bag.id, event.station_num, event.time);
                } else {
                    printf("Station %d's queue is full, bag %d redirected to another station at time %d\n", event.station_num, event.bag.id, event.time);
                    // find an open station
                    int found_open_station = 0;
                    for (int i = 0; i < MAX_STATIONS; i++) {
                        if (stations[i].is_open && stations[i].num_bags < MAX_BAGS) {
                            found_open_station = 1;
                            event.station_num = i;
                            break;
                        }
                    }
                    if (!found_open_station) {
                        printf("No open station available, bag %d lost at time %d\n", event.bag.id, event.time);
                    } else {
                        events[num_events++] = event;
                    }
                }
            } else {
                printf("Station %d is closed, bag %d redirected to another station at time %d\n", event.station_num, event.bag.id, event.time);
                // find an open station
                int found_open_station = 0;
                for (int i = 0; i < MAX_STATIONS; i++) {
                    if (stations[i].is_open && stations[i].num_bags < MAX_BAGS) {
                        found_open_station = 1;
                        event.station_num = i;
                        break;
                    }
                }
                if (!found_open_station) {
                    printf("No open station available, bag %d lost at time %d\n", event.bag.id, event.time);
                } else {
                    events[num_events++] = event;
                }
            }
        } else if (event.type == 2) {
            // station open event
            printf("Station %d opened at time %d\n", event.station_num, event.time);
            Station* station = &stations[event.station_num];
            station->is_open = 1;
        } else if (event.type == 3) {
            // station close event
            printf("Station %d closed at time %d\n", event.station_num, event.time);
            Station* station = &stations[event.station_num];
            station->is_open = 0;
            station->num_bags = 0;
        }
    }
    
    return 0;
}