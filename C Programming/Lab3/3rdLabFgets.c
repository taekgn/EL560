#include<stdio.h>
#include<stdlib.h> //for character to float conversion
#include<string.h>
#define MAX 100
struct cg { // structure to hold x and y co-ordinates and mass
    float x, y, mass;
} masses[MAX];

int readin(void) {
    FILE *fp = NULL;
    char buffer[10];
    int i = 0;
    fp = fopen("lab3.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
    } 
	else {
        while (!feof(fp)) {
            fgets(buffer, 10, fp);
			float flob; int k; k = 0;
            char delim[] = " "; char *ptr = strtok(buffer, delim);
            while(ptr != NULL)
	        {
		    flob = atof(ptr);
		    switch(k){
		    case 0: masses[i].x = flob; break;
			case 1: masses[i].y = flob; break;
            case 2: masses[i].mass = flob; break; }
            k++; ptr = strtok(NULL, delim);
			} 
            i++; k = 0;
        	}
        fclose(fp);
    }
    return i;
}

void computecg(int n_masses) { //to prevent computation error of multiplication of integer & float, parameters set as double
    double sum_of_xmass, sum_of_ymass, sum_of_mass;
    int j;
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

void main(void) {
    int number;
    if ((number = readin()) > 0)
        computecg(number);
}
