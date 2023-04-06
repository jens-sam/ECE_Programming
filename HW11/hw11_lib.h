
// hw11_lib.h
#ifndef HW11_LIB_H
#define HW11_LIB_H

typedef struct Student {
    char name[50];
    float grade;
    struct Student *next;
} Student;

void studentAdd(char *name, float grade);
void studentRemove(char *name);
Student *studentFind(char *name);
void studentPrint(Student *student);
void studentPrintList();
float studentGetGrade(char *name);
void studentLoad(char *filename);
int studentCount();
void studentDeleteList();
float studentGetAverage();

#endif // HW11_LIB_H
