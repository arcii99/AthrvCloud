//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//define a structure called Baggage
struct Baggage {
  int id; //id of the luggage
  int weight; //weight of the luggage
};

//define a structure called Flight
struct Flight {
  int number; //flight number
  int numOfBags; //number of bags in the flight
  struct Baggage *bags; //pointer to an array of bags
};

//recursive function to handle the luggage
void handleLuggage(int flightIndex, int bagIndex, struct Flight flights[], int numFlights) {
  //base case
  if(flightIndex == numFlights) {
    printf("All luggage handled successfully! Have a nice flight!\n");
    return;
  }
  struct Flight currentFlight = flights[flightIndex];
  if(bagIndex == currentFlight.numOfBags) {
    //all bags in the current flight have been handled
    printf("All luggage for flight %d handled successfully!\n", currentFlight.number);
    handleLuggage(flightIndex+1, 0, flights, numFlights); //move on to the next flight
  } else {
    //handle the next bag in the current flight
    struct Baggage currentBag = currentFlight.bags[bagIndex];
    printf("Handling luggage ID %d, weighing %d pounds, for flight %d \n", currentBag.id, currentBag.weight, currentFlight.number);
    handleLuggage(flightIndex, bagIndex+1, flights, numFlights); //handle the next bag in the same flight
  }   
}

//main function
int main() {
  //define three flights with some bags
  struct Baggage bags1[] = {{1, 50}, {2, 70}, {3, 45}};
  struct Flight flight1 = {123, 3, bags1};
  
  struct Baggage bags2[] = {{4, 30}, {5, 40}, {6, 60}, {7, 55}};
  struct Flight flight2 = {456, 4, bags2};
  
  struct Baggage bags3[] = {{8, 65}, {9, 55}, {10, 75}};
  struct Flight flight3 = {789, 3, bags3};
  
  struct Flight flights[] = {flight1, flight2, flight3}; //create an array of flights
  
  int numFlights = sizeof(flights)/sizeof(struct Flight); //get the number of flights
  
  handleLuggage(0, 0, flights, numFlights); //start handling the luggage
  return 0;
}