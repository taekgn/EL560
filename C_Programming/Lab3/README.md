# Assignment: Calculate Centre of Gravity
We are concerned with calculating the centre of gravity of a number of weights. Each weight has a x coordinate, a y coordinate and a mass. The data for a set of weights is kept in a file, arranged one weight per line.
You are required to write two functions to complete a program which will read this data from the file and
calculate the resultant centre of gravity.
1) Using the code given in the previous pages, read in data from a file. Use formatted input (hint: fscanf) to
read the data from your file. You must use the following structure for the x and y co-ordinates and mass:
```C
struct cg {
float x, y, mass;
};
```
and an array:
```
struct cg masses[ MAX ];
```
to hold the data.
2) In the second function, compute:
```
sum_of_xmass = sum of the ( masses[i].x * masses[i].mass )
sum_of_ymass = sum of the ( masses[i].y * masses[i].mass )
sum_of_mass = sum of the ( masses[i].mass )
```
for all i (ie for all the masses).
Now calculate and print the centre of gravity, found from
```
cg_x = sum_of_xmass / sum_of_mass
cg_y = sum_of_ymass / sum_of_mass.
```
### Template
Use the following template for your program:
```C
#include <stdio.h>
#define MAX 100
struct cg { // structure to hold x and y co-ordinates and mass
float x, y, mass;
}masses[MAX];
int readin(void)
{
/* Write this function to read in the data from a file */
/* into the array masses */
/* note that this function should return the number of */
/* masses read in from the file */
}
void computecg(int n_masses)
{
/* Write this function to compute the C of G */
/* and print the result */
}
void main(void)
{
int number;
if((number = readin()) > 0)
computecg(number);
}
```
Testing your work
Typical input in file:
```
0 0 1
0 1 1
1 0 1
1 1 1
```
Typical Output to screen:
```
x = 0.50 y = 0.50
```
