#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *cat = "The cat sat on the mat any two words.";
int count = 0;
int check = 0;

void replace(char *input) {
    char newcat[strlen(input)];
    while (*input) {
        if (*input == ' ') {
            newcat[check] = '-';
            count++;
        }
        else { newcat[check] = *input; }
        input++;
        check++;
    }
    printf("String was: %s\n", cat);
    printf("String is: %s\n", newcat);
    printf("Num replaced:%d \n", count);
};

int main(void) {
	replace(cat);
    return 0;
}
