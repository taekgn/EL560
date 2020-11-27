#define _CRT_SECURE_NO_WARNINGS 
#include<stdlib.h>
#include<stdio.h>
//calls libraries like input,output

int main(void)
{
	int a, b, c;

	printf("1st nubmer input: ");
	scanf("%d",&a);
	//takes 1st input value from keyboard and assign to variable
	printf("2nd number input: ");
	scanf("%d", &b);
    //takes 2nd input value from keyboard and assign to variable

	c = a * b;
	//multiplication happens at this line
	printf("The mulitplication of 2 numbers is %d", c);
	//prints the result
}
