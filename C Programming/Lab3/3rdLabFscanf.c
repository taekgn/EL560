#include <stdio.h>
#include <stdlib.h> //for character to float conversion
#define MAX 100

struct cg { 
//structure to hold x and y co-ordinates and mass
    float x, y, mass;
} masses[MAX];

int readin(void) {
    FILE *fp = NULL;
    int i = 0;
    fp = fopen("lab3.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
    } else {
        while (!feof(fp)) { //reads entire text file until reached the last character
            fscanf(fp, "%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass);
            i++; //i indicates no of line in text file
        }
        fclose(fp); //Release the memory which has used
    }
    return i;
}

void computecg(int n_masses) {
    double sum_of_xmass, sum_of_ymass, sum_of_mass;
	//To prevent computation error from product of integer & float, parameters typed as double (larger range that can embrace)
    int j; //i indicates index no of objects(struct cg)
    for (j = 0; j < n_masses; j++) {
        sum_of_xmass += (masses[j].mass * masses[j].x);
        sum_of_ymass += (masses[j].mass * masses[j].y);
        sum_of_mass += masses[j].mass;
    }
    double cg_x = sum_of_xmass / sum_of_mass;
    double cg_y = sum_of_ymass / sum_of_mass;
    printf("Sum of mass: %.2f", sum_of_mass);
    printf("\nx = %.2f y = %.2f", cg_x, cg_y);
}

int main(void) {
    int number;
    if ((number = readin()) > 0)
        computecg(number);
}
