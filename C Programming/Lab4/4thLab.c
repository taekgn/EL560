#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

char buffer[256];
char delim[] = ";";
int choice;
int globalcount = -1;
int innercount;

struct disks {
    char singer[48], cd[48], ref[16];
    float cost;
    int year;
}
        disc[48];

int allprint(void) {
    FILE *fp;
    int j = 0;
    char vbuffer[128];
    char c;
    fp = fopen("lab4.txt", "rt");
    if (fp == NULL) {
        printf("File is not exist\n");
    } else {
        while ((c = fgetc(fp)) != EOF) {
            //
            fgets(vbuffer, 128, fp);
            //reads data one line by one line from file
            puts(vbuffer);
        }
        fclose(fp);
        /*after while bracket*/
    };
    return 0;
}

int save(void) {
    FILE *fp = NULL;
    char fbuffer[48];
    int j;
    int index = 1;
    fp = fopen("lab4.txt", "wt"); //write function is enabled to save a datum in text file.
    printf("\nStored!\n");
    j = 0;
    while (j < (globalcount + 1)) {
        fprintf(fp, "#%d. [Name]: %s [Album]: %s [Reference]: %s [$]: %.2f [Release]: %d\n", index, disc[j].singer,
                disc[j].cd, disc[j].ref, disc[j].cost, disc[j].year);
        j++;
        index++;
    }
    fclose(fp);
    return 0;
}

int main(void) {
    bool s = true;
    while (s == true) {
        printf("The following options are available:\nRead in data(press everytime before type) [1]\nPrint out catalogue to screen [2]\nSave data to file [3]\nExit Program [4]\nEnter your choice now:");
        scanf("%d", &choice);
        gets(buffer);
        char *ptr = strtok(buffer, delim);
        switch (choice) {
            case 1: {
                puts("-----------------------------------------------");
                puts("Type in format like below. \nName;Title;Ref;$;Released Year;\n It splits by semicolon");
                puts("-----------------------------------------------");
				
                while (ptr != NULL) {
                    switch (innercount) {
                        case 0:
                            globalcount += 1;
                            strcpy(disc[globalcount].singer, ptr);
                            ptr = strtok(NULL, delim);
                            innercount++;
                            break;
                        case 1:
                            strcpy(disc[globalcount].cd, ptr);
                            ptr = strtok(NULL, delim);
                            innercount++;
                            break;
                        case 2:
                            strcpy(disc[globalcount].ref, ptr);
                            ptr = strtok(NULL, delim);
                            innercount++;
                            break;
                        case 3:
                            disc[globalcount].cost = atof(ptr);
                            ptr = strtok(NULL, delim);
                            innercount++;
                            break;
                        case 4:
                            puts("Reading done!");
                            disc[globalcount].year = atoi(ptr);
                            innercount = 0;
                            ptr = NULL;
                            break;
                    }
                }
                break;
            }
                //Read keyboard input
            case 2:
                allprint();
                break;
                //print from file
            case 3:
                save();
                break;
                //save into file
            case 4:
                s = false;
                break;
                //exit
        }
    }
    return 0;
}
