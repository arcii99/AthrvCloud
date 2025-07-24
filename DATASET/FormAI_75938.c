//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 20  //maximum number of cars on the road 
#define LANES 4 //number of lanes on the road 

int main() {
    srand(time(NULL));  //initialize random seed

    //configure the parameters for the simulation
    int speed[LANES] = {80, 70, 60, 50}; //speed limit for each lane
    int distance[MAX] = {0}; //distance of each car from the start of the road
    int position[LANES] = {0}; //position of the front car in each lane
    int lane[MAX] = {0}; //lane on which each car is
    int acceleration[MAX]; //acceleration of each car
    int braking[MAX]; //braking of each car
    int v[MAX]; //velocity of each car
    int time[MAX] = {0}; //time at which each car entered the road
    int count[MAX] = {0}; //number of cars between each car and the traffic jam
    int jam_distance[MAX] = {0}; //distance of each car from the traffic jam
    int jam_time[MAX] = {0}; //time at which each car encountered the traffic jam
    int jam_location = -1; //distance from the start of the road where the traffic jam occurs
    int jam_duration = -1; //duration of the traffic jam

    //initialize the distance and position of each car randomly
    for(int i=0; i<MAX; i++) {
        distance[i] = rand()%1000;  //random value from 0 to 999
        lane[i] = rand()%LANES;  //random lane from 0 to 3
        if(distance[i] > position[lane[i]]) {  //if the car is ahead of the front car in the current lane 
            position[lane[i]] = distance[i];
        }
        v[i] = speed[lane[i]];  //initialize the velocity of each car to the speed limit of its lane
        time[i] = rand()%3600;  //random value from 0 to 3599 seconds
    }

    //simulate the traffic flow
    while(1) {
        //determine the location of the traffic jam randomly at the start of the simulation or after the previous jam has been cleared
        if(jam_duration == 0) {
            jam_location = rand()%4000+5000;  //random distance from 5000 to 8999 meters
            jam_duration = rand()%600+600; //random duration from 600 to 1199 seconds
        }

        //calculate the acceleration and braking of each car based on the car-following model and update the velocity and distance
        for(int i=0; i<MAX; i++) {
            int d = position[lane[i]] - distance[i];
            int j = count[i] > 0 ? count[i] : MAX;  //if there is no car ahead of it, consider the traffic jam as the front car
            int dj = jam_distance[i] - distance[i];
            int t_star = 1.2;  //minimum safe time gap
            int a = 1;  //constant acceleration
            int b = 1;  //constant deceleration
            int delta = 4;  //delta exponent coefficient
            int s_star = 2*t_star*v[i];  //minimum safe distance
            acceleration[i] = a*(1-pow(v[i]/speed[lane[i]], delta)-pow(s_star/(d-t_star*v[i]), 2));
            if(i < j-1 && lane[i] == lane[i+1]) {  //if there is a car ahead of it in the same lane
                int d1 = position[lane[i]] - distance[i+1];
                int v1 = v[i+1];
                int s_star1 = 2*t_star*v1;
                acceleration[i] = a*(1-pow(v[i]/speed[lane[i]], delta)-pow(s_star/(d-t_star*v[i]-v[i]*(v[i]-v1)/(2*sqrt(a*b))), 2));
                braking[i+1] = b*pow(s_star1/(d1-t_star*v1), 2);
            }
            else if(d <= s_star) {  //if it is too close to the front car
                braking[i] = b*pow(s_star/d, 2);
            }
            if(distance[i] >= jam_location && distance[i] < jam_location+jam_duration && dj <= s_star) {  //if it is inside the traffic jam and too close to the front car 
                braking[i] = b*pow(s_star/dj, 2);
            }
            if(v[i]+acceleration[i] > speed[lane[i]]) {  //if it exceeds the speed limit of its lane
                acceleration[i] = (speed[lane[i]]-v[i])/1.2;
            }
            v[i] = v[i]+acceleration[i]-braking[i];
            if(v[i] < 0) {
                v[i] = 0;
            }
            distance[i] = distance[i]+v[i];
            if(distance[i] > position[lane[i]]) {  //if it passes the front car in the current lane
                position[lane[i]] = distance[i];
            }
            if(distance[i] >= jam_location && distance[i] < jam_location+jam_duration) {  //if it encounters the traffic jam
                count[i] = 0;
                jam_distance[i] = distance[i];
                jam_time[i] = time[i];
                for(int j=0; j<MAX; j++) {
                    if(j == i) {
                        continue;
                    }
                    if(lane[j] == lane[i] && distance[j] >= jam_location && distance[j] < jam_location+jam_duration && distance[j] < distance[i]) {  //if there is a car ahead of it inside the traffic jam
                        count[i]++;
                    }
                }
            }
            else if(distance[i] < jam_location) {  //if it is behind the traffic jam
                count[i] = 0;
            }
        }

        //output the current state of the simulation
        for(int i=0; i<LANES; i++) {
            printf("Lane %d:\t", i+1);
            for(int j=0; j<=position[i]/100; j++) {
                if(j == jam_location/100) {  //output the traffic jam with an underline
                    printf("\033[4m*\033[0m");
                }
                else {
                    printf("-");
                }
            }
            printf("\n");
        }
        printf("Time elapsed: %d s\n", time[0]);

        //update the time and check if the simulation has ended
        time[0]++;
        if(distance[0] >= 10000) {  //if the first car reaches the end of the road
            break;
        }
        if(jam_duration > 0) {  //if there is a traffic jam
            jam_duration--;
            if(jam_duration == 0) {  //if the traffic jam has been cleared
                for(int i=0; i<MAX; i++) {
                    if(jam_distance[i] >= jam_location && jam_distance[i] < jam_location+jam_duration) {  //if the car is inside the traffic jam
                        count[i] = 0;
                    }
                }
            }
        }
    }

    return 0;
}