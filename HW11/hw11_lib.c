// hw11_lib.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw11_lib.h"

// Declaring *head as my pointer for the first element in my linked list
Student *head = NULL;


// Adding a student to the list
void studentAdd(char *name, float grade) {
    Student *new_student = (Student *) malloc(sizeof(Student));
    strcpy(new_student->name, name);
    new_student->grade = grade;
    new_student->next = NULL;

    if (head == NULL) {
        head = new_student;
    } else {
        Student *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
}


// Removing a student from the list. iterates through list using strcmp. as long as they difference is 0, i.e they are the same. else statement establishes new directions and frees the node.
void studentRemove(char *name) {
    Student *current = head;
    Student *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}


//Find a student by name. strcmp compares and when the difference is zero, returning address of student
Student *studentFind(char *name) {
    Student *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Return NULL if the student is not found
}


//{Print one student's name and grade
void studentPrint(Student *student) {
    if (student == NULL) {
        printf("Error: NULL student\n");
        return;
    }
    printf("%s\t%.2f\n", student->name, student->grade);
}


//Print all the students names and grades from the list
void studentPrintList() {
    Student *current = head;
    while (current != NULL) {
        studentPrint(current);
        current = current->next;
    }
}


// Return the grade for the given student name
float studentGetGrade(char *name) {
    Student *found = studentFind(name);
    if (found != NULL) {
        return found->grade;
    }
    return -1; // Return -1 if the student is not found
}


// Loading File
void studentLoad(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    char name[50];
    float grade;

    while (fscanf(file, "%49s\t%f", name, &grade) == 2) {
        studentAdd(name, grade);
    }
    fclose(file);
}


//Counting number of students in the list
int studentCount() {
    int count = 0;
    Student *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


//Remove all students from list. Make sure to free memory once removed
void studentDeleteList() {
    Student *current = head;
    Student *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

//get average of all students from a list
float studentGetAverage() {
    //printf("got to average");
    int count = 0;
    float sum = 0;
    Student *current = head;
    while (current != NULL) {
        count++;
        sum += current->grade;
        current = current->next;
    }
    return (count == 0) ? 0 : sum / count;
}
