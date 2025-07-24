//FormAI DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

// Set the I2C address of the temperature sensor
#define TEMP_SENSOR_ADDR 0x48

// Set the register addresses for configuration and temperature readings
#define CONF_REG_ADDR 0x01
#define TEMP_REG_ADDR 0x00

// Set the value to configure the temperature sensor for continuous conversion mode
#define CONF_REG_VALUE 0x60

// Define the resolution of the temperature sensor in bits
#define TEMP_SENSOR_RESOLUTION 12

// Define the conversion factor from temperature sensor raw data to Celsius
#define TEMP_CONVERSION_FACTOR 0.0625

int main() {
    int fd;
    char *filename = "/dev/i2c-1";
    unsigned char data[2];
    int temp;
    
    // Open the I2C bus
    if ((fd = open(filename, O_RDWR)) < 0) {
        perror("Failed to open the I2C bus");
        return 1;
    }
    
    // Set the slave address of the temperature sensor
    if (ioctl(fd, I2C_SLAVE, TEMP_SENSOR_ADDR) < 0) {
        perror("Failed to set the I2C address");
        return 1;
    }
    
    // Configure the temperature sensor for continuous conversion mode
    data[0] = CONF_REG_ADDR;
    data[1] = CONF_REG_VALUE;
    if (write(fd, data, 2) != 2) {
        perror("Failed to write to the configuration register");
        return 1;
    }
    
    // Read the temperature and convert the raw data to Celsius
    while (1) {
        data[0] = TEMP_REG_ADDR;
        if (write(fd, data, 1) != 1) {
            perror("Failed to write to the temperature register");
            return 1;
        }
        if (read(fd, data, 2) != 2) {
            perror("Failed to read the temperature data");
            return 1;
        }
        temp = (data[0] << 8 | data[1]) >> (16 - TEMP_SENSOR_RESOLUTION);
        printf("Temperature: %.2f C\n", temp * TEMP_CONVERSION_FACTOR);
        sleep(1);
    }
    
    return 0;
}