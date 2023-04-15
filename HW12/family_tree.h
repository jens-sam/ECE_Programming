
#ifndef FAMILY_TREE_H
#define FAMILY_TREE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct Person {
    char father[50];
    char mother[50];
    char name[20];
    struct Person *next;
    struct Person *prev;
};

struct Person *findHead(struct Person *n);
struct Person *findTail(struct Person *n);
struct Person *FindPerson(struct Person *n, const char *name);
struct Person *addToTail(struct Person *n, const char *name, const char *father, const char *mother);
const char *findFather(struct Person *n, const char *name);
const char *findMother(struct Person *n, const char *name);
void findAncestor(struct Person *n, const char *name, int gen);
void findDescendants(struct Person *n, const char *name, int depth);
void printAll(struct Person *n);

#endif //FAMILY_TREE_H
