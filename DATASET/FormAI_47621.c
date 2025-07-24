//FormAI DATASET v1.0 Category: Physics simulation ; Style: relaxed
#include<stdio.h>
#include<math.h>

#define MASS_OF_ALUMINUM 2.7 // in kg
#define SPECIFIC_HEAT_CAPACITY_OF_ALUMINUM 0.91 // in J/g*K
#define THERMAL_CONDUCTIVITY_OF_ALUMINUM 13 // in W/m*K
#define LENGTH_OF_ALUMINUM_BAR 0.5 // in meters
#define CROSS_SECTIONAL_AREA_OF_ALUMINUM_BAR 0.01 // in m^2

#define ROOM_TEMPERATURE 293 // in Kelvin

int main(){
    double initialTemperature, temperature, time;
    double heatEnergy, heatFlux;
    double deltaTemperature, deltaTime;
    double thermalConductivity;
    int i;

    initialTemperature = 773; // initial temperature of the aluminum bar in Kelvin
    time = 600; // time interval for simulation in seconds
    deltaTime = 0.1; // time step size for simulation in seconds

    temperature = initialTemperature;
    heatEnergy = MASS_OF_ALUMINUM * SPECIFIC_HEAT_CAPACITY_OF_ALUMINUM * temperature; 
    // calculation of initial heat energy in Joules
    
    for(i = 0; i < time/deltaTime; i++){
        heatFlux = THERMAL_CONDUCTIVITY_OF_ALUMINUM * CROSS_SECTIONAL_AREA_OF_ALUMINUM_BAR 
        * (temperature - ROOM_TEMPERATURE)/LENGTH_OF_ALUMINUM_BAR; 
        // calculation of heat flux using Fourier's Law
        
        thermalConductivity = THERMAL_CONDUCTIVITY_OF_ALUMINUM + 0.1 * temperature; 
        // thermal conductivity variation with temperature
        
        deltaTemperature = -heatFlux * deltaTime/MASS_OF_ALUMINUM/ SPECIFIC_HEAT_CAPACITY_OF_ALUMINUM; 
        // change in temperature for delta time
        
        temperature += deltaTemperature;
        heatEnergy += heatFlux * deltaTime; 
        // updating the heat energy
    }
    
    printf("Final temperature of the aluminum bar: %.2f K\n", temperature);
    printf("Change in heat energy: %.2f J\n", heatEnergy - MASS_OF_ALUMINUM * SPECIFIC_HEAT_CAPACITY_OF_ALUMINUM * initialTemperature);
    
    return 0;
}