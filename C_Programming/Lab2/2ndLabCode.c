#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *cat = "The cat sat on the mat TWO MORE WORDS";
int check = 0;
char code1[] = "abcdefghijklmnopqrstuvwxyz";
char code2[] = "bpduhijkaltxwmrzfoysvngeqc";
int cutcap;

void code(char *input) {
    char newcat[strlen(input)];
    while (*input) {
        if (islower(*input)) {
            cutcap = strlen(code1) - strlen(strchr(code1, *input));
            newcat[check] = code2[cutcap];
        } else { newcat[check] = *input; }
        input++;
        check++;
    }
    printf("String was: %s\n", cat);
    printf("String is: %s\n", newcat);
};

int main(void) {
	code(cat);
    return 0;
}
