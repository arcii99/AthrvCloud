//FormAI DATASET v1.0 Category: Smart home automation ; Style: decentralized
// include required libraries and define constants

#define MAX_DEVICES 10
#define DEVICE_STATUS_ON 1
#define DEVICE_STATUS_OFF 0

struct SmartDevice {
    int device_id;
    char device_type[20];
    float device_price;
    int device_status;
};

struct SmartHome {
    char owner_name[50];
    int num_of_devices;
    struct SmartDevice devices[MAX_DEVICES];
};

// create functions to be used in the program

void addDevice(struct SmartHome *home, int id, char type[], float price) {
    if (home->num_of_devices < MAX_DEVICES) {
        home->devices[home->num_of_devices].device_id = id;
        strcpy(home->devices[home->num_of_devices].device_type, type);
        home->devices[home->num_of_devices].device_price = price;
        home->devices[home->num_of_devices].device_status = DEVICE_STATUS_OFF;
        home->num_of_devices += 1;
    }
    return;
}

void switchDevice(struct SmartHome *home, int device_id, int status) {
    for (int i = 0; i < home->num_of_devices; i++) {
        if (home->devices[i].device_id == device_id) {
            if (status == DEVICE_STATUS_ON || status == DEVICE_STATUS_OFF) {
                home->devices[i].device_status = status;
            }
            break;
        }
    }
    return;
}

void printStatus(struct SmartHome home) {
    printf("Device\tType\tPrice\tStatus\n");
    for (int i = 0; i < home.num_of_devices; i++) {
        printf("%d\t%s\t%.2f\t%s\n", home.devices[i].device_id, home.devices[i].device_type, 
            home.devices[i].device_price, (home.devices[i].device_status == DEVICE_STATUS_ON) ? "ON" : "OFF");
    }
    return;
}

// implement the main function

int main() {
    // create a Smart Home object and initialize it
    struct SmartHome home;
    strcpy(home.owner_name, "John Smith");
    home.num_of_devices = 0;

    // let the user add devices to the Smart Home
    addDevice(&home, 1, "Smart Bulb", 10.99);
    addDevice(&home, 2, "Smart Thermostat", 89.99);
    addDevice(&home, 3, "Smart Lock", 129.99);

    // switch devices on and off
    switchDevice(&home, 1, DEVICE_STATUS_ON);
    switchDevice(&home, 2, DEVICE_STATUS_ON);
    switchDevice(&home, 1, DEVICE_STATUS_OFF);

    // print the status of all the devices in the Smart Home
    printStatus(home);

    return 0;
}