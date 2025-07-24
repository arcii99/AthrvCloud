//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: puzzling
#include<stdio.h>
#include<math.h>

// Function to calculate distance between objects given their coordinates
// and return the resultant vector
float* calculate_distance(float x1, float y1, float z1, float x2, float y2, float z2) {
    float distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2) + pow((z2-z1),2));
    static float vector[3];
    vector[0] = (x2-x1)/distance;
    vector[1] = (y2-y1)/distance;
    vector[2] = (z2-z1)/distance;
    return vector;
}

int main() {
    // Initializing the data structure for each planet/object
    struct Planet {
        char name[10];
        float x,y,z;
        float vx,vy,vz;
        float mass;
    } 
    sun={"Sun",0,0,0,0,0,0},
    mercury={"Mercury",0,0,0,0,0,3.3*pow(10,23)},
    venus={"Venus",0,0,0,0,0,4.87*pow(10,24)},
    earth={"Earth",0,0,0,0,0,5.97*pow(10,24)},
    mars={"Mars",0,0,0,0,0,6.39*pow(10,23)},
    jupiter={"Jupiter",0,0,0,0,0,1.9*pow(10,27)},
    saturn={"Saturn",0,0,0,0,0,5.68*pow(10,26)},
    uranus={"Uranus",0,0,0,0,0,8.68*pow(10,25)},
    neptune={"Neptune",0,0,0,0,0,1.02*pow(10,26)};

    // Initializing time variables
    float dt = 0.01; // Time step
    float time = 0; // Current time
    float final_time = 100; // End time

    // Defining gravitational constant
    float G = 6.6743*pow(10,-11);

    // Running simulation for each time step
    while (time<final_time) {

        // Calculating gravitational forces acting on each planet/object
        float* force_sun_mercury = calculate_distance(sun.x,sun.y,sun.z,mercury.x,mercury.y,mercury.z);
        force_sun_mercury[0] = (force_sun_mercury[0]*G*sun.mass*mercury.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,mercury.x,mercury.y,mercury.z)[0],2);
        force_sun_mercury[1] = (force_sun_mercury[1]*G*sun.mass*mercury.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,mercury.x,mercury.y,mercury.z)[0],2);
        force_sun_mercury[2] = (force_sun_mercury[2]*G*sun.mass*mercury.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,mercury.x,mercury.y,mercury.z)[0],2);

        float* force_sun_venus = calculate_distance(sun.x,sun.y,sun.z,venus.x,venus.y,venus.z);
        force_sun_venus[0] = (force_sun_venus[0]*G*sun.mass*venus.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,venus.x,venus.y,venus.z)[0],2);
        force_sun_venus[1] = (force_sun_venus[1]*G*sun.mass*venus.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,venus.x,venus.y,venus.z)[0],2);
        force_sun_venus[2] = (force_sun_venus[2]*G*sun.mass*venus.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,venus.x,venus.y,venus.z)[0],2);

        float* force_sun_earth = calculate_distance(sun.x,sun.y,sun.z,earth.x,earth.y,earth.z);
        force_sun_earth[0] = (force_sun_earth[0]*G*sun.mass*earth.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,earth.x,earth.y,earth.z)[0],2);
        force_sun_earth[1] = (force_sun_earth[1]*G*sun.mass*earth.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,earth.x,earth.y,earth.z)[0],2);
        force_sun_earth[2] = (force_sun_earth[2]*G*sun.mass*earth.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,earth.x,earth.y,earth.z)[0],2);

        float* force_sun_mars = calculate_distance(sun.x,sun.y,sun.z,mars.x,mars.y,mars.z);
        force_sun_mars[0] = (force_sun_mars[0]*G*sun.mass*mars.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,mars.x,mars.y,mars.z)[0],2);
        force_sun_mars[1] = (force_sun_mars[1]*G*sun.mass*mars.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,mars.x,mars.y,mars.z)[0],2);
        force_sun_mars[2] = (force_sun_mars[2]*G*sun.mass*mars.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,mars.x,mars.y,mars.z)[0],2);

        float* force_sun_jupiter = calculate_distance(sun.x,sun.y,sun.z,jupiter.x,jupiter.y,jupiter.z);
        force_sun_jupiter[0] = (force_sun_jupiter[0]*G*sun.mass*jupiter.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,jupiter.x,jupiter.y,jupiter.z)[0],2);
        force_sun_jupiter[1] = (force_sun_jupiter[1]*G*sun.mass*jupiter.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,jupiter.x,jupiter.y,jupiter.z)[0],2);
        force_sun_jupiter[2] = (force_sun_jupiter[2]*G*sun.mass*jupiter.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,jupiter.x,jupiter.y,jupiter.z)[0],2);

        float* force_sun_saturn = calculate_distance(sun.x,sun.y,sun.z,saturn.x,saturn.y,saturn.z);
        force_sun_saturn[0] = (force_sun_saturn[0]*G*sun.mass*saturn.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,saturn.x,saturn.y,saturn.z)[0],2);
        force_sun_saturn[1] = (force_sun_saturn[1]*G*sun.mass*saturn.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,saturn.x,saturn.y,saturn.z)[0],2);
        force_sun_saturn[2] = (force_sun_saturn[2]*G*sun.mass*saturn.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,saturn.x,saturn.y,saturn.z)[0],2);

        float* force_sun_uranus = calculate_distance(sun.x,sun.y,sun.z,uranus.x,uranus.y,uranus.z);
        force_sun_uranus[0] = (force_sun_uranus[0]*G*sun.mass*uranus.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,uranus.x,uranus.y,uranus.z)[0],2);
        force_sun_uranus[1] = (force_sun_uranus[1]*G*sun.mass*uranus.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,uranus.x,uranus.y,uranus.z)[0],2);
        force_sun_uranus[2] = (force_sun_uranus[2]*G*sun.mass*uranus.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,uranus.x,uranus.y,uranus.z)[0],2);

        float* force_sun_neptune = calculate_distance(sun.x,sun.y,sun.z,neptune.x,neptune.y,neptune.z);
        force_sun_neptune[0] = (force_sun_neptune[0]*G*sun.mass*neptune.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,neptune.x,neptune.y,neptune.z)[0],2);
        force_sun_neptune[1] = (force_sun_neptune[1]*G*sun.mass*neptune.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,neptune.x,neptune.y,neptune.z)[0],2);
        force_sun_neptune[2] = (force_sun_neptune[2]*G*sun.mass*neptune.mass)/pow(calculate_distance(sun.x,sun.y,sun.z,neptune.x,neptune.y,neptune.z)[0],2);

        // Updating velocities and positions of each planet/object
        // using the calculated forces
        mercury.vx = mercury.vx + force_sun_mercury[0]/mercury.mass*dt;
        mercury.vy = mercury.vy + force_sun_mercury[1]/mercury.mass*dt;
        mercury.vz = mercury.vz + force_sun_mercury[2]/mercury.mass*dt;
        mercury.x = mercury.x + mercury.vx*dt;
        mercury.y = mercury.y + mercury.vy*dt;
        mercury.z = mercury.z + mercury.vz*dt;

        venus.vx = venus.vx + force_sun_venus[0]/venus.mass*dt;
        venus.vy = venus.vy + force_sun_venus[1]/venus.mass*dt;
        venus.vz = venus.vz + force_sun_venus[2]/venus.mass*dt;
        venus.x = venus.x + venus.vx*dt;
        venus.y = venus.y + venus.vy*dt;
        venus.z = venus.z + venus.vz*dt;

        earth.vx = earth.vx + force_sun_earth[0]/earth.mass*dt;
        earth.vy = earth.vy + force_sun_earth[1]/earth.mass*dt;
        earth.vz = earth.vz + force_sun_earth[2]/earth.mass*dt;
        earth.x = earth.x + earth.vx*dt;
        earth.y = earth.y + earth.vy*dt;
        earth.z = earth.z + earth.vz*dt;

        mars.vx = mars.vx + force_sun_mars[0]/mars.mass*dt;
        mars.vy = mars.vy + force_sun_mars[1]/mars.mass*dt;
        mars.vz = mars.vz + force_sun_mars[2]/mars.mass*dt;
        mars.x = mars.x + mars.vx*dt;
        mars.y = mars.y + mars.vy*dt;
        mars.z = mars.z + mars.vz*dt;

        jupiter.vx = jupiter.vx + force_sun_jupiter[0]/jupiter.mass*dt;
        jupiter.vy = jupiter.vy + force_sun_jupiter[1]/jupiter.mass*dt;
        jupiter.vz = jupiter.vz + force_sun_jupiter[2]/jupiter.mass*dt;
        jupiter.x = jupiter.x + jupiter.vx*dt;
        jupiter.y = jupiter.y + jupiter.vy*dt;
        jupiter.z = jupiter.z + jupiter.vz*dt;

        saturn.vx = saturn.vx + force_sun_saturn[0]/saturn.mass*dt;
        saturn.vy = saturn.vy + force_sun_saturn[1]/saturn.mass*dt;
        saturn.vz = saturn.vz + force_sun_saturn[2]/saturn.mass*dt;
        saturn.x = saturn.x + saturn.vx*dt;
        saturn.y = saturn.y + saturn.vy*dt;
        saturn.z = saturn.z + saturn.vz*dt;

        uranus.vx = uranus.vx + force_sun_uranus[0]/uranus.mass*dt;
        uranus.vy = uranus.vy + force_sun_uranus[1]/uranus.mass*dt;
        uranus.vz = uranus.vz + force_sun_uranus[2]/uranus.mass*dt;
        uranus.x = uranus.x + uranus.vx*dt;
        uranus.y = uranus.y + uranus.vy*dt;
        uranus.z = uranus.z + uranus.vz*dt;

        neptune.vx = neptune.vx + force_sun_neptune[0]/neptune.mass*dt;
        neptune.vy = neptune.vy + force_sun_neptune[1]/neptune.mass*dt;
        neptune.vz = neptune.vz + force_sun_neptune[2]/neptune.mass*dt;
        neptune.x = neptune.x + neptune.vx*dt;
        neptune.y = neptune.y + neptune.vy*dt;
        neptune.z = neptune.z + neptune.vz*dt;

        // Printing the positions of each planet/object
        printf("-----------------------------\n");
        printf("Current time: %f seconds\n\n",time);
        printf("Sun: (%f,%f,%f)\n",sun.x,sun.y,sun.z);
        printf("Mercury: (%f,%f,%f)\n",mercury.x,mercury.y,mercury.z);
        printf("Venus: (%f,%f,%f)\n",venus.x,venus.y,venus.z);
        printf("Earth: (%f,%f,%f)\n",earth.x,earth.y,earth.z);
        printf("Mars: (%f,%f,%f)\n",mars.x,mars.y,mars.z);
        printf("Jupiter: (%f,%f,%f)\n",jupiter.x,jupiter.y,jupiter.z);
        printf("Saturn: (%f,%f,%f)\n",saturn.x,saturn.y,saturn.z);
        printf("Uranus: (%f,%f,%f)\n",uranus.x,uranus.y,uranus.z);
        printf("Neptune: (%f,%f,%f)\n",neptune.x,neptune.y,neptune.z);

        // Incrementing time
        time += dt;
    }
    return 0;
}