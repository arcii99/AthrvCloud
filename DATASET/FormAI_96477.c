//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include<stdio.h>
#include<math.h>

//function to calculate distance between two points on earth
double distance(double lat1, double lon1, double lat2, double lon2){
    double dlat, dlon, a, c, d;
    dlat = (lat2-lat1)*M_PI/180.0;
    dlon = (lon2-lon1)*M_PI/180.0;
    lat1 = lat1*M_PI/180.0;
    lat2 = lat2*M_PI/180.0;
    a = pow(sin(dlat/2),2)+cos(lat1)*cos(lat2)*pow(sin(dlon/2),2);
    c = 2*atan2(sqrt(a),sqrt(1-a));
    d = 6371000*c; //radius of earth in meters
    return d;
}

int main(){
    double start_lat, start_lon, end_lat, end_lon;
    printf("Enter starting latitude: ");
    scanf("%lf",&start_lat);
    printf("Enter starting longitude: ");
    scanf("%lf",&start_lon);
    printf("Enter destination latitude: ");
    scanf("%lf",&end_lat);
    printf("Enter destination longitude: ");
    scanf("%lf",&end_lon);
    double distance_travelled = distance(start_lat,start_lon,end_lat,end_lon);
    printf("You have travelled %lf meters from (%lf,%lf) to (%lf,%lf)\n",distance_travelled,start_lat,start_lon,end_lat,end_lon);
    return 0;
}