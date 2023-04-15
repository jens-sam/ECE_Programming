#include "family_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *printList(struct Person *n) {
    n = findHead(n);
    while (n != NULL) {
        printf("%s %s %s\n", n->name, n->father, n->mother);
        n = n->next;
    }
}

struct Person *findHead(struct Person *n) {
    while (n->prev != NULL) {
        n = n->prev;
    }
    return n;
}

struct Person *findTail(struct Person *n) {
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}

struct Person *FindPerson(struct Person *n, const char *name) {
    n = findHead(n);
    while (n != NULL) {
        if (strcmp(n->name, name) == 0) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

struct Person *addToTail(struct Person *n, const char *name, const char *father, const char *mother) {
    struct Person *NewPerson = malloc(sizeof(struct Person));
    strncpy(NewPerson->name, name, sizeof(NewPerson->name));
    strncpy(NewPerson->father, father, sizeof(NewPerson->father));
    strncpy(NewPerson->mother, mother, sizeof(NewPerson->mother));
    NewPerson->prev = findTail(n);
    NewPerson->next = NULL;
    if (NewPerson->prev == NULL) {
        return NewPerson;
    }
    NewPerson->prev->next = NewPerson;
    return NewPerson;
}

const char *findFather(struct Person *n, const char *name) {
    n = FindPerson(n, name);
    if (n == NULL) {
        printf("%s is robin \n", name);
        return NULL;
    }
    return n->father;
}

const char *findMother(struct Person *n, const char *name) {
    n = FindPerson(n, name);
    if (n == NULL) {
        printf("%s is robin \n", name);
        return NULL;
    }
    return n->mother;
}

void findAncestor(struct Person *n, const char *name, int gen) {
    n = FindPerson(n, name);
    char dad[10] = "NULL";
    if (strcmp(n->father, dad) == 0) {
        return;
    } else {
        if (gen > 1) {
            printf("great ");
        }
        if (gen >= 1) {
            printf("grand");
        }
        printf("father %s\n", n->father);
        findAncestor(n, n->father, gen + 1);
        if (gen > 1) {
            printf("great ");
        }
        if (gen >= 1) {
            printf("grand");
        }
        printf("mother %s\n", n->mother);
        findAncestor(n, n->mother, gen + 1);
    }
}


void findDescendants(struct Person *n, const char *name, int gen) {
    n = findHead(n);
    // going through the list
    while (n != NULL) {
        // if the person's father is the given name then print as the child
        if (strcmp(n->father, name) == 0) {
            // printing out the great grand and child
            if (gen > 2) {
                printf("great ");
            }
            if (gen > 1) {
                printf("great ");
            }
            if (gen >= 1) {
                printf("grand");
            }
            printf("child ");
            printf("%s\n", n->name);
            // recursive to find the descendants
            findDescendants(n, n->name, gen + 1);
        }
        // if the mom is the given name then print as the child
        if (strcmp(n->mother, name) == 0) {
            // going through generations to print great grand and child
            if (gen > 2) {
                printf("great ");
            }
            if (gen > 1) {
                printf("great ");
            }
            if (gen >= 1) {
                printf("grand");
            }
            printf("child ");
            printf("%s\n", n->name);
            findDescendants(n, n->name, gen + 1);
        }
        n = n->next;
    }
    return;
}


void printAll(struct Person *n) {
    n = findHead(n);
    while (n->next != NULL) {
        n = n->next;
        printf("name %s, father %s, mother %s\n", n->name, n->father, n->mother);
    }
}

/// V3- almost working
//void findDescendants(struct Person *n, const char *name, int gen) {
//    n = findHead(n);
//    while (n != NULL) {
//        if (strcmp(n->father, name) == 0) {
//            printf("child ");
//            for (int i = 0; i < gen - 1; i++) {
//                printf("great ");
//            }
//            printf("grand%s\n", n->name);
//            findDescendants(n, n->name, gen + 1);
//        }
//        if (strcmp(n->mother, name) == 0) {
//            printf("child ");
//            for (int i = 0; i < gen - 1; i++) {
//                printf("great ");
//            }
//            printf("grand%s\n", n->name);
//            findDescendants(n, n->name, gen + 1);
//        }
//        n = n->next;
//    }
//    return;
//}

/// V2 - need to print out great and grands
//void findDescendants(struct Person *n, const char *name, int gen) {
//    n = findHead(n);
//    while (n != NULL) {
//        if (strcmp(n->father, name) == 0 || strcmp(n->mother, name) == 0) {
//            if (gen >= 1) {
//                printf("%*s", "");
//            }
//            printf("child %s\n", n->name);
//            findDescendants(n, n->name, gen + 1);
//        }
//        n = n->next;
//    }
//}

/// V1- working on printing out great, grand, and child
//void findDescendants(struct Person *n, const char *name, int gen) {
//    if (strcmp(n->name, name) == 0) {
//        if (gen > 0) {
//            printf("child %s\n", n->name);
//        }
//        return;
//    }
//    if (n->father != NULL && FindPerson(n, n->father) != NULL) {
//        printf("child %s\n", n->name);
//        findDescendants(FindPerson(n, n->father), name, gen + 1);
//    }
//    if (n->mother != NULL && FindPerson(n, n->mother) != NULL) {
//        printf("child %s\n", n->name);
//        findDescendants(FindPerson(n, n->mother), name, gen + 1);
//    }
//}
