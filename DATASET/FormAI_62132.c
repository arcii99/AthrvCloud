//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

struct coordinates{
    double lat;
    double lon;
};

double distance(struct coordinates a, struct coordinates b){
    double R = 6371e3;
    double lat1 = a.lat * M_PI/180;
    double lat2 = b.lat * M_PI/180;
    double dLat = (b.lat-a.lat) * M_PI/180;
    double dLon = (b.lon-a.lon) * M_PI/180;

    double a1 = sin(dLat/2) * sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a1), sqrt(1-a1));
    double d = R * c;
    return d;
}

void navigate(struct coordinates A, struct coordinates B, struct coordinates nav){
    double AB = distance(A,B);
    double AX = distance(A,nav);
    double BX = distance(B,nav);

    if( AX > AB || BX > AB ){
        printf("The point you entered does not lie on the line between A and B\n");
        return;
    }

    double AC = asin(sin(AB/6371e3)*sin(AX/6371e3))*6371e3;
    double theta = acos((cos(AX/6371e3)-(cos(AC/6371e3)*cos(AB/6371e3)))/(sin(AC/6371e3)*sin(AB/6371e3)));
    double bearingA = atan2(sin(B.lon-A.lon)*cos(B.lat), cos(A.lat)*sin(B.lat)-sin(A.lat)*cos(B.lat)*cos(B.lon-A.lon));
    double bearingB = atan2(sin(A.lon-B.lon)*cos(A.lat), cos(B.lat)*sin(A.lat)-sin(B.lat)*cos(A.lat)*cos(A.lon-B.lon));

    if(bearingA < 0) bearingA +=2*M_PI;
    if(bearingB < 0) bearingB +=2*M_PI;
    bearingA = bearingA * 180/M_PI;
    bearingB = bearingB * 180/M_PI;

    printf("The distance between A and B is %.2lf meters\n", AB);
    printf("The distance between point X and points A is %.2lf meters\n", AX);
    printf("The distance between point X and points B is %.2lf meters\n", BX);
    printf("The distance between point X and line AB is %.2lf meters\n", AC);
    printf("The bearing from A to X is %.2lf degrees\n", bearingA);
    printf("The bearing from B to X is %.2lf degrees\n", bearingB);
}

int main(){
    struct coordinates A = {32.715736, -117.161087}; // San Diego, CA
    struct coordinates B = {37.7749, -122.4194}; // San Francisco, CA

    srand(time(NULL)); // set the seed for random number generation
    double lat = (rand()/(double)RAND_MAX)*10 - 5 + 34; // generate a random latitude in the range [29, 39]
    double lon = (rand()/(double)RAND_MAX)*10 - 5 - 119; // generate a random longitude in the range [-114, -124]
    struct coordinates nav = {lat, lon};

    navigate(A, B, nav);

    return 0;
}