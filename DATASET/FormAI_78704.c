//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    double lat;
    double lng;
}Coords;

typedef struct {
    Coords curr_location;
    Coords destination;
    int distance;
    int eta;
}Navigation;

void* simulate_gps(void *arg) {
    Navigation *nav = (Navigation*)arg;
    double lat_diff = abs(nav->curr_location.lat - nav->destination.lat);
    double lng_diff = abs(nav->curr_location.lng - nav->destination.lng);
    double total_distance = sqrt(lat_diff*lat_diff + lng_diff*lng_diff);
    nav->distance = (int)total_distance;
    nav->eta = nav->distance / 30; //assuming avg speed of 30 km/hr

    //simulate progress
    srand(time(NULL));
    int steps = nav->distance / 5;
    double cur_lat = nav->curr_location.lat;
    double cur_lng = nav->curr_location.lng;
    for(int i=0; i<steps; i++) {
        printf("Current Location: (%.4lf,%.4lf)\tETA: %d mins\n", cur_lat, cur_lng, nav->eta-i);
        if(cur_lat < nav->destination.lat) {
            cur_lat += (rand()%100)/10000.0;
        }
        else {
            cur_lat -= (rand()%100)/10000.0;
        }
        if(cur_lng < nav->destination.lng) {
            cur_lng += (rand()%100)/10000.0;
        }
        else {
            cur_lng -= (rand()%100)/10000.0;
        }
        sleep(1);
    }
    printf("Destination Reached!\n");
    return NULL;
}

int main() {
    Navigation nav;
    nav.curr_location.lat = 12.9255;
    nav.curr_location.lng = 77.6719;
    nav.destination.lat = 12.9415;
    nav.destination.lng = 77.6651;
    pthread_t tid;
    pthread_create(&tid, NULL, simulate_gps, &nav);
    pthread_join(tid, NULL);
    return 0;
}