#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//calls the libraries

int main(void)
{
// the main method which is going to perform task
int a, b, c, s; s = 1; char o;

while(s > 0) {

    printf("1st nubmer input: \n");
    scanf("%d", &a);
    //takes 1st input value from keyboard and assign to variable
    printf("2nd number input: \n");
    scanf("%d", &b);
    //takes 2nd input value from keyboard and assign to variable
    c = a * b;
    printf("A mulitplication of 2 numbers is %d \n", c);

    getchar();
    //this prevents confusion by pressing return key which does buffering
    printf("Do you want to continue? lowercase [y/n]: \n");
    scanf("%c", &o); //takes decision input whether continue or not
    if (o == 'y') { continue; } //by continue statement, it goest back to initial process
    else if (o == 'n') { break; }//by break state, it quits programme

    else {while (o != 'y' && o != 'n') { //the case when user mistype decision to continue
        getchar();
        printf("Type only y or n!: \n");
        scanf("%c", &o);
        if(o == 'y')
        {break; main();}
        else if(o == 'n')
        {s = 0; break;}
        else{continue;}
    }
    }
}
}
