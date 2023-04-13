#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "family_tree.h"

bool load(List *list, const char *filename) {
    FILE *fp;
    char line[128];
    char name[32], father[32], mother[32];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return false;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %s %s\n", name, father, mother);

        Person *p = findPerson(list, name);
        if (p == NULL) {
            // person not found, create new node and add to list
            p = (Person*)malloc(sizeof(Person));
            strcpy(p->name, name);
            p->father = NULL;
            p->mother = NULL;

            List *node = (List*)malloc(sizeof(List));
            node->head = p;
            node->next = list->next;
            list->next = node;
        }

        if (strcmp(father, "NULL") != 0) {
            Person *f = findPerson(list, father);
            if (f == NULL) {
                // father not found, create new node and add to list
                f = (Person*)malloc(sizeof(Person));
                strcpy(f->name, father);
                f->father = NULL; // pointer of f to father
                f->mother = NULL;

                List *node = (List*)malloc(sizeof(List));
                node->head = f;
                node->next = list->next;
                list->next = node;
            }
            p->father = f;
        }

        if (strcmp(mother, "NULL") != 0) {
            Person *m = findPerson(list, mother);
            if (m == NULL) {
                // mother not found, create new node and add to list
                m = (Person*)malloc(sizeof(Person));
                strcpy(m->name, mother);
                m->father = NULL;
                m->mother = NULL;

                List *node = (List*)malloc(sizeof(List));
                node->head = m;
                node->next = list->next;
                list->next = node;
            }
            p->mother = m;
        }
    }

    fclose(fp);
    return true;
}

Person *findPerson(List *list, const char *name) {
    List *node = list->next;
    while (node != NULL) {
        if (strcmp(node->head->name, name) == 0) {
            return node->head;
        }
        node = node->next;
    }
    return NULL;
}

// prints all descendants of a given person recursively
void printDescendantsHelper(Person *p, int depth) {
    List *node = p->father ? p->father->head->next : NULL;
    if (node != NULL) {
        printf("%*schild %s\n", depth * 4, "", node->head->name);
        printDescendantsHelper(node->head, depth + 1);
    }
    node = p->mother ? p->mother->head->next : NULL;
    if (node != NULL) {
        printf("%*schild %s\n", depth * 4, "", node->head->name);
        printDescendantsHelper(node->head, depth + 1);
    }
}

// prints all descendants of given person
void printDescendants(List *list, const char *name) {
    Person *p = findPerson(list, name);
    if (p == NULL) {
        printf("Person not found: %s\n", name);
        return;
    }
    printf("Descendants of %s:\n", p->name);
    printDescendantsHelper(p, 1);
}


void printAncestorsHelper(Person *p, int depth) {
    if (p == NULL) {
        return;
    }
    printAncestorsHelper(p->father, depth + 1);
    printf("%*s%s %s\n", depth * 2, "", p->name, depth == 0 ? "(you)" : "");
    printAncestorsHelper(p->mother, depth + 1);
}

// prints all ancestors of given person
void printAncestors(List *list, const char *name) {
    Person *p = findPerson(list, name);
    if (p == NULL) {
        printf("Person not found: %s\n", name);
        return;
    }
    printf("Ancestors of %s:\n", p->name);
    printAncestorsHelper(p, 1);
}


