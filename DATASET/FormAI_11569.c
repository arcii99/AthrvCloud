//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <ctype.h>

#define DEVICE "/dev/ttyUSB0"    // Set the serial device to use
#define BAUDRATE B115200         // Set the baudrate for serial communication

// Function to open and set up the serial communication
int openSerialPort(const char* device, int baudrate){
    struct termios options;     // Structure to hold the port configuration options 
    int fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);   // Open the device

    if(fd == -1) {
        perror("openSerialPort: Unable to open device");
        return -1;
    }

    fcntl(fd, F_SETFL, FNDELAY);    // Set the port to non-blocking mode  
    tcgetattr(fd, &options);        // Get the current port configuration options  

    // Set the input and output baud rates     
    cfsetispeed(&options, baudrate);
    cfsetospeed(&options, baudrate);

    // Set the data format to 8-n-1  
    options.c_cflag &= ~PARENB;  
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;  
    options.c_cflag |= CS8;     

    // Apply the configuration
    tcsetattr(fd,TCSANOW,&options);

    return fd;  // Return the file descriptor for the open device
}

// Function to read the temperature from the device   
float readTemperature(){
    char buffer[256];   // Buffer to store the data read from the device
    int fd = openSerialPort(DEVICE, BAUDRATE);  // Open the serial port

    if(fd == -1) {
        return -9999;   // Return error code if unable to open device
    }

    usleep(500000);     // Wait for device to start up

    write(fd, "READTEMP\n", 9);   // Send command to read temperature

    usleep(2000000);    // Wait for device to respond

    int n = read(fd , buffer, 255); // Read the response from the device
    buffer[n] = '\0';   // Add null terminator to string

    float temperature = atof(buffer);  // Convert string to float

    close(fd);  // Close the serial port

    return temperature; // Return the temperature value
}

int main(){
    float temperature = readTemperature();  // Read the temperature from the device

    if(temperature == -9999) {
        printf("Unable to read temperature\n");
    }
    else {
        printf("Temperature: %.2fC\n", temperature);
    }

    return 0;
}