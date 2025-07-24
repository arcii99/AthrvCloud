//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include<stdio.h>
#include<math.h>

#define MAX_NODES 1000
#define MAX_DEVICES 2000

typedef struct Device{
    int dev_type;  // 0 - resistor, 1 - capacitor, 2 - inductor
    int n1,n2;     // nodes connected
    double value;  // resistance/capacitance/inductance value
    double v0;     // initial voltage
    double i0;     // initial current
} Device;

int nodes[MAX_DEVICES*2][2];  // array to store nodes
int num_devices = 0;          // count of devices
Device devices[MAX_DEVICES];  // array to store devices

// function to add device to circuit
void add_device(int dev_type, int n1, int n2, double value, double v0, double i0){
    if(num_devices >= MAX_DEVICES){
        printf("Error: device limit exceeded.");
        return;
    }
    devices[num_devices].dev_type = dev_type;
    devices[num_devices].n1 = n1;
    devices[num_devices].n2 = n2;
    devices[num_devices].value = value;
    devices[num_devices].v0 = v0;
    devices[num_devices].i0 = i0;
    nodes[num_devices*2][0] = n1;
    nodes[num_devices*2][1] = num_devices;
    nodes[num_devices*2+1][0] = n2;
    nodes[num_devices*2+1][1] = num_devices;
    num_devices++;
}

// function to print circuit details
void print_circuit(){
    int i,j;
    printf("\nCircuit Details:\n");
    printf("-------------------------------------------------------------------\n");
    printf("Device Type\tNode 1\tNode 2\tValue\tInitial Voltage\tInitial Current\n");
    printf("-------------------------------------------------------------------\n");
    for(i=0;i<num_devices;i++){
        printf("%d\t\t%d\t%d\t%lf\t%lf\t\t%lf\n",devices[i].dev_type,devices[i].n1,devices[i].n2,devices[i].value,devices[i].v0,devices[i].i0);
    }
    printf("-------------------------------------------------------------------\n");
    printf("Node Details:\n");
    printf("-------------------------------------------------------------------\n");
    printf("Node\tDevices Connected\n");
    printf("-------------------------------------------------------------------\n");
    for(i=0;i<num_devices*2;i++){
        int node = nodes[i][0];
        printf("%d\t",node);
        for(j=0;j<num_devices*2;j++){
            if(nodes[j][0]==node){
                printf("%d ",nodes[j][1]);
            }
        }
        printf("\n");
    }
    printf("-------------------------------------------------------------------\n");
}

int main(){
    // add devices to circuit
    add_device(0,1,2,100.0,0.0,0.0);
    add_device(0,2,3,200.0,0.0,0.0);
    add_device(0,1,3,50.0,0.0,0.0);
    add_device(1,2,3,10.0,0.0,1.0);
    add_device(2,1,3,0.2,0.0,0.0);

    // print circuit details
    print_circuit();

    return 0;
}