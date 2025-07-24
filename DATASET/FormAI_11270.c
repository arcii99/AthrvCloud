//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_DEVICE_NAME "/dev/i2c-1"
#define TEMP_SENSOR_ADDR 0x4C
#define CMD_READ_TEMP 0xB4

int main() {
    int fd; // file descriptor for the I2C device
    char buf[2] = {0}; // buffer to store register addresses and data
    
    // open the I2C device
    fd = open(I2C_DEVICE_NAME, O_RDWR);
    if (fd == -1) {
        perror("Failed to open I2C device");
        exit(EXIT_FAILURE);
    }
    
    // set the I2C slave address to the temperature sensor
    if (ioctl(fd, I2C_SLAVE, TEMP_SENSOR_ADDR) == -1) {
        perror("Failed to set I2C slave address");
        exit(EXIT_FAILURE);
    }
    
    // send command to read temperature
    buf[0] = CMD_READ_TEMP;
    if (write(fd, buf, 1) != 1) {
        perror("Failed to send command to temperature sensor");
        exit(EXIT_FAILURE);
    }
    
    // wait for conversion to complete
    usleep(100000);
    
    // read temperature data
    if (read(fd, buf, 2) != 2) {
        perror("Failed to read temperature data from sensor");
        exit(EXIT_FAILURE);
    }
    
    // convert temperature data to degrees Celsius
    int temp_celsius = ((buf[0] << 8 | buf[1]) >> 3) * 0.125;
    
    // print temperature
    printf("Temperature: %d degrees Celsius\n", temp_celsius);
    
    // close the I2C device
    close(fd);
    
    return 0;
}