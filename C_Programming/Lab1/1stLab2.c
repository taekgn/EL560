#define _CRT_SECURE_NO_WARNINGS 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct item
        { int c; int r; char d[10];
    //above lines are variable for code, quantity, discount rate, description
        };
int main(void)
{
    int f; int s;
    struct item list[2];

    list[0].c = 0; strcpy(list[0].d, "CD-R");
    list[1].c = 1; strcpy(list[1].d, "DVD+R");

    printf("Item code: ");
    scanf("%d", &f);
    getchar();
    printf("Quantity required: ");
    scanf("%d",&s);

    if((0 <s) && (s<10)){list[0].r = 3; list[1].r= 4;}
    else if((9<s) && (s<20)){list[0].r = 5; list[1].r = 7;}
    else if((19<s) && (s<=999)){list[0].r= 10; list[1].r = 11;}
    else{printf("Type integer range between 1 to 999!!! \n");}
    printf("%d of item %d, discount rate is %d%% \nDescription: %s", s, list[f].c, list[f].r, list[f].d);
}
