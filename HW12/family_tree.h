#ifndef FAMILY_TREE_H
#define FAMILY_TREE_H

#include <stdbool.h>

typedef struct person {
    char name[32];
    struct person *father;
    struct person *mother;
} Person;

typedef struct list {
    Person *head;
    struct list *next;
} List;

Person *findPerson(List *list, const char *name);
bool load(List *list, const char *filename);
bool printAll(List *list);
bool printAncestors(List *list, const char *name);
bool printDescendants(List *list, const char *name);
bool printSiblings(List *list, const char *name);
bool printCousins(List *list, const char *name);

#endif
