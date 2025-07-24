//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

//Function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2){
    float dist = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return dist;
}

//Function to convert degrees into radians
float toRadians(float deg){
    float radians = deg * (3.1415/180);
    return radians;
}

int main(){

    //Initializing some constants
    const int MAX_LOCATIONS = 10;
    const float STARTING_X = 50.0;
    const float STARTING_Y = 50.0;
    const float MIN_DISTANCE = 5.0;
    
    //Initializing some variables
    int num_locations = 0;
    float locations[MAX_LOCATIONS][3];
    float current_x = STARTING_X;
    float current_y = STARTING_Y;
    int has_reached_destination = 0;
    int current_location_index = 0;

    //Getting input from user for number of locations, name and coordinates
    printf("Enter the number of locations you want to visit: ");
    scanf("%d",&num_locations);

    for(int i=0;i<num_locations;i++){
        printf("\nEnter the name of Location %d: ",i+1);
        scanf("%s",&locations[i][0]);
        printf("Enter the X-coordinate of Location %d: ",i+1);
        scanf("%f",&locations[i][1]);
        printf("Enter the Y-coordinate of Location %d: ",i+1);
        scanf("%f",&locations[i][2]);
    }

    printf("\n\nYou are currently at (%.2f,%.2f)\n\n",current_x,current_y);

    while(!has_reached_destination){

        //Printing the list of locations to visit
        printf("List of Locations to Visit:\n");
        for(int i=0;i<num_locations;i++){
            if(i!=current_location_index){
                printf("%d. %s\n",i+1,locations[i]);
            }
        }

        //Getting the user's choice for location to visit next
        int next_location_choice = 0;
        printf("\n\nWhich location do you want to visit next? Enter the corresponding number: ");
        scanf("%d",&next_location_choice);
        current_location_index = next_location_choice-1;

        //Calculating the distance to the next location
        float next_x = locations[current_location_index][1];
        float next_y = locations[current_location_index][2];
        float dist_to_next_location = distance(current_x,current_y,next_x,next_y);
        printf("\n\nThe distance to %s is %.2f kilometers.\n",locations[current_location_index],dist_to_next_location);

        //Simulating movement to the next location
        float current_to_next_angle = atan2(next_y-current_y,next_x-current_x)*(180/3.1415);
        printf("Head towards %.2f degrees.\n",current_to_next_angle);

        float radians = toRadians(current_to_next_angle);
        float movement_x = cos(radians)*MIN_DISTANCE;
        float movement_y = sin(radians)*MIN_DISTANCE;

        current_x+=movement_x;
        current_y+=movement_y;

        printf("You have arrived at (%.2f,%.2f).\n\n",current_x,current_y);

        //Checking if the user has reached the final destination
        if(current_location_index == num_locations-1){
            printf("\n\nCongratulations! You have reached your final destination!\n\n");
            has_reached_destination = 1;
        }
    }
    return 0;
}