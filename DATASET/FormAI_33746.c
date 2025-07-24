//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multivariable
#include<stdio.h>
#include<math.h>

struct Node{
    float latitude, longitude; //coordinates of the node
    char name[50]; //name of the location
    struct Node *next; //next node in the linked list
};

typedef struct Node NODE;

NODE *head = NULL;

//function to add nodes to the linked list
void addNode(float lat, float lng, char n[]){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->latitude = lat;
    newNode->longitude = lng;
    strcpy(newNode->name, n);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        NODE *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//function to calculate the distance between two points using Haversine Formula
float distance(float lat1, float long1, float lat2, float long2){
    float dlat = (lat2 - lat1) * M_PI / 180.0;
    float dlong = (long2 - long1) * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;
    float a = pow(sin(dlat/2),2) + pow(sin(dlong/2),2) * cos(lat1) * cos(lat2);
    float c = 2 * atan2(sqrt(a),sqrt(1-a));
    float d = 6371 * c; //distance in km
    return d;
}

//function to display the linked list of locations
void display(){
    NODE *temp = head;
    while(temp != NULL){
        printf("%s: (%f, %f)\n", temp->name, temp->latitude, temp->longitude);
        temp = temp->next;
    }
}

int main(){
    addNode(28.7041, 77.1025, "Delhi");
    addNode(19.0760, 72.8777, "Mumbai");
    addNode(13.0827, 80.2707, "Chennai");
    addNode(22.5726, 88.3639, "Kolkata");
    addNode(12.9716, 77.5946, "Bangalore");
    addNode(18.5204, 73.8567, "Pune");
    display();
    float current_lat, current_long;
    printf("Enter your current location (latitude, longitude): ");
    scanf("%f%f", &current_lat, &current_long);
    NODE *temp = head;
    float minDist = 9999999;
    char name[50];
    while(temp != NULL){
        float dist = distance(current_lat, current_long, temp->latitude, temp->longitude);
        if(dist < minDist){
            minDist = dist;
            strcpy(name, temp->name);
        }
        temp = temp->next;
    }
    printf("The nearest location to you is %s, which is %f km away from your current location\n", name, minDist);
}