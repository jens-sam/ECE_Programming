
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw11_lib.h"


int main(void) {
    char command= '\0';
    char str[50];
    char name[50];

    float grade;
    while (command !='q') {
        printf("> ");
        fgets(str, sizeof(str),stdin);
        int n=sscanf(str,"%c%s",&command,name);
        switch(command) {
            case 'r':
                if (n == 2) {
                    //printf("got to remove funct\n");
                    studentRemove(name);
                }
                break;


            case 'g':
                if (n == 1) {
                    grade = studentGetAverage();
                    printf("%.2f\n", grade);
                } else if (n == 2) {
                    grade = studentGetGrade(name);
                    printf("%.2f\n", grade);
                } else {
                    printf("Invalid input\n");
                    break;



                    case 'p':
                        if (head == NULL) {
                            printf("List is empty\n");
                        } else {
                            studentPrintList();
                        }
                }
                break;


            case 'c':
                printf("%d\n", studentCount());
                break;


            case 'd':
                studentDeleteList();
                break;


            case 'l':
                studentLoad(name);
                break;


            case 'q':
                break;


                return 0;
        }
    }
}

