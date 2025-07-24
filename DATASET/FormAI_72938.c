//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main()
{
    //The Solar System Simulation
    printf("The Solar System Simulation: A Mystery to Solve\n");

    //Initial conditions
    const float au = 149597870.7; //1 astronomical unit (AU) to meters
    const float G = 6.67e-11; //gravitational constant
    const float mSun = 1.989e30; //mass of the Sun
    const float mEarth = 5.972e24; //mass of the Earth
    const float mJupiter = 1.898e27; //mass of Jupiter
    const float mSaturn = 5.6834e26; //mass of Saturn

    //Variables to store the position and speed of each planet
    float rEarth[2] = {-1*au, 0}; //initial position of Earth
    float vEarth[2] = {0, -30300}; //velocity of Earth
    float rJupiter[2] = {5.2*au, 0}; //initial position of Jupiter
    float vJupiter[2] = {0, 13100}; //velocity of Jupiter
    float rSaturn[2] = {9.5*au, 0}; //initial position of Saturn
    float vSaturn[2] = {0, 9600}; //velocity of Saturn

    //Time step and simulation time
    float dt = 86400; //1 day
    float t = 0;
    float tmax = 365*5*24*3600; //5 years

    //Main simulation loop
    while(t < tmax)
    {
        //Calculate the distance and direction between Earth and the Sun
        float dEarthSun = sqrt(pow(rEarth[0], 2) + pow(rEarth[1], 2));
        float dirEarthSun[2] = {-1*rEarth[0]/dEarthSun, -1*rEarth[1]/dEarthSun};

        //Calculate the force on Earth due to the Sun and update its velocity and position
        float fEarthSun = G*mSun*mEarth/pow(dEarthSun, 2);
        float aEarth[2] = {fEarthSun/mEarth*dirEarthSun[0], fEarthSun/mEarth*dirEarthSun[1]};
        vEarth[0] += aEarth[0]*dt;
        vEarth[1] += aEarth[1]*dt;
        rEarth[0] += vEarth[0]*dt;
        rEarth[1] += vEarth[1]*dt;

        //Calculate the distance and direction between Jupiter and the Sun
        float dJupiterSun = sqrt(pow(rJupiter[0], 2) + pow(rJupiter[1], 2));
        float dirJupiterSun[2] = {-1*rJupiter[0]/dJupiterSun, -1*rJupiter[1]/dJupiterSun};

        //Calculate the force on Jupiter due to the Sun and update its velocity and position
        float fJupiterSun = G*mSun*mJupiter/pow(dJupiterSun, 2);
        float aJupiter[2] = {fJupiterSun/mJupiter*dirJupiterSun[0], fJupiterSun/mJupiter*dirJupiterSun[1]};
        vJupiter[0] += aJupiter[0]*dt;
        vJupiter[1] += aJupiter[1]*dt;
        rJupiter[0] += vJupiter[0]*dt;
        rJupiter[1] += vJupiter[1]*dt;

        //Calculate the distance and direction between Saturn and the Sun
        float dSaturnSun = sqrt(pow(rSaturn[0], 2) + pow(rSaturn[1], 2));
        float dirSaturnSun[2] = {-1*rSaturn[0]/dSaturnSun, -1*rSaturn[1]/dSaturnSun};

        //Calculate the force on Saturn due to the Sun and update its velocity and position
        float fSaturnSun = G*mSun*mSaturn/pow(dSaturnSun, 2);
        float aSaturn[2] = {fSaturnSun/mSaturn*dirSaturnSun[0], fSaturnSun/mSaturn*dirSaturnSun[1]};
        vSaturn[0] += aSaturn[0]*dt;
        vSaturn[1] += aSaturn[1]*dt;
        rSaturn[0] += vSaturn[0]*dt;
        rSaturn[1] += vSaturn[1]*dt;

        //Update simulation time
        t += dt;
    }

    //Print the final positions of the planets
    printf("After 5 years:\n");
    printf("Earth position: (%.2e, %.2e) m\n", rEarth[0], rEarth[1]);
    printf("Jupiter position: (%.2e, %.2e) m\n", rJupiter[0], rJupiter[1]);
    printf("Saturn position: (%.2e, %.2e) m\n", rSaturn[0], rSaturn[1]);

    //The Case Closed
    printf("The mystery of the Solar System Simulation solved!\n");
    return 0;
}