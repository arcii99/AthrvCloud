//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ada Lovelace
// Weather Simulation Program
// By Ada Lovelace

// Define constants
const int TEMPERATURE_RANGE_MIN = -10;
const int TEMPERATURE_RANGE_MAX = 40;
const int HUMIDITY_RANGE_MIN = 0;
const int HUMIDITY_RANGE_MAX = 100;
const int PRECIPITATION_RANGE_MIN = 0;
const int PRECIPITATION_RANGE_MAX = 10;

// Define variables
int temperature;
int humidity;
int precipitation;

// Define functions
void generateWeather(int* temperature, int* humidity, int* precipitation) {
  *temperature = random(TEMPERATURE_RANGE_MIN, TEMPERATURE_RANGE_MAX);
  *humidity = random(HUMIDITY_RANGE_MIN, HUMIDITY_RANGE_MAX);
  *precipitation = random(PRECIPITATION_RANGE_MIN, PRECIPITATION_RANGE_MAX);
}

void printWeather(int temperature, int humidity, int precipitation) {
  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d percent\n", humidity);
  printf("Precipitation: %d mm/hour\n", precipitation);
}

// Main program
int main() {
  // Generate weather
  generateWeather(&temperature, &humidity, &precipitation);
  
  // Print weather
  printWeather(temperature, humidity, precipitation);
  
  return 0;
}