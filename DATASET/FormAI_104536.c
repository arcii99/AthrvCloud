//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>  

//Defining a structure for the remote control vehicle  
struct rc_vehicle {  
    char vehicle_name[20];  
    int manufacture_year;  
    char color[20];  
    int velocity;  
};  

int main() {  
    //Creating an instance of the remote control vehicle  
    struct rc_vehicle my_vehicle;  

    printf("Enter your Vehicle Name: ");  
    scanf("%s", &my_vehicle.vehicle_name);  

    printf("Enter the Manufacture Year: ");  
    scanf("%d",&my_vehicle.manufacture_year);  

    printf("Enter the Vehicle Color: ");  
    scanf("%s", &my_vehicle.color);  

    printf("Enter the Velocity: ");  
    scanf("%d", &my_vehicle.velocity);  

    //Printing the details of the remote control vehicle  
    printf("\n\nVehicle Name: %s", my_vehicle.vehicle_name);  
    printf("\nManufacture Year: %d", my_vehicle.manufacture_year);  
    printf("\nColor: %s", my_vehicle.color);  
    printf("\nVelocity: %d", my_vehicle.velocity);  

    return 0;  
}