#include "family_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "family_tree.h"

Person *findPerson(List *list, const char *name) {
    List *current = list;

    while (current) {
        if (strcmp(current->head->name, name) == 0) {
            return current->head;
        }
        current = current->next;
    }

    return NULL;
}

bool load(List *list, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        return false;
    }

    char name[32], father[32], mother[32];
    while (fscanf(file, "%31s %31s %31s", name, father, mother) == 3) {
        Person *new_person = (Person *)malloc(sizeof(Person));
        strcpy(new_person->name, name);
        new_person->father = findPerson(list, father);
        new_person->mother = findPerson(list, mother);

        List *new_list = (List *)malloc(sizeof(List));
        new_list->head = new_person;
        new_list->next = list->next;
        list->next = new_list;
    }

    fclose(file);
    return true;
}

bool printAll(List *list) {
    if (!list || !list->next) {
        return false;
    }

    List *current = list->next;
    while (current) {
        printf("%s, %s, %s\n", current->head->name,
               current->head->father ? current->head->father->name : "NULL",
               current->head->mother ? current->head->mother->name : "NULL");
        current = current->next;
    }

    return true;
}


bool printAncestors(List *list, const char *name) {
    Person *person = findPerson(list, name);

    if (!person) {
        return false;
    }

    printAncestorsHelper(person->father, "father");
    printAncestorsHelper(person->mother, "mother");

    return true;
}

bool printDescendants(List *list, const char *name) {
    Person *person = findPerson(list, name);

    if (!person) {
        return false;
    }

    List *current = person->child;
    while (current) {
        printDescendantsHelper(current->head, "child");
        current = current->next;
    }

    return true;
}

// Implement the extra challenge functions here

