//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int day = 0, mercury = 0, venus = 0, earth = 0, mars = 0, jupiter = 0, saturn = 0, uranus = 0, neptune = 0;
  
  while (day < 365) { // For one year, or 365 days
    mercury++; // Let's start with Mercury, incrementing its days
    if (mercury == 88) { // If Mercury completes one orbit, reset days and increment next planet
      mercury = 0;
      venus++;
    }
    if (venus == 225) { // Same logic for Venus
      venus = 0;
      earth++;
    }
    if (earth == 365) { // Same for Earth
      earth = 0;
      mars++;
    }
    if (mars == 687) { // Same for Mars
      mars = 0;
      jupiter++;
    }
    if (jupiter == 4333) { // Same for Jupiter
      jupiter = 0;
      saturn++;
    }
    if (saturn == 10755) { // Same for Saturn
      saturn = 0;
      uranus++;
    }
    if (uranus == 30687) { // Same for Uranus
      uranus = 0;
      neptune++;
    }
    // And so on for Neptune, but we won't go that far in our simulation.
    
    day++; // Increment our day counter, printing out where each planet is at in its orbit
    printf("Day %d: Mercury is on day %d of its 88 day orbit. Venus is on day %d of its 225 day orbit. Earth is on day %d of its 365 day orbit. Mars is on day %d of its 687 day orbit. Jupiter is on day %d of its 4333 day orbit. Saturn is on day %d of its 10755 day orbit. Uranus is on day %d of its 30687 day orbit. Neptune is... who knows?\n", day, mercury, venus, earth, mars, jupiter, saturn, uranus);
  }
  
  printf("We've made it one full year in our simulation of the solar system!\n");
  
  return 0;
}