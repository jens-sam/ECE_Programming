
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

/// debugging this function, various versions commented out underneath

void findDescendants(struct Person *n, const char *name, int gen) {
    if (strcmp(n->name, name) == 0) {
        if (gen > 0) {
            printf("child %s\n", n->name);
        }
        return;
    }
    if (n->father != NULL && FindPerson(n, n->father) != NULL) {
        printf("child %s\n", n->name);
        findDescendants(FindPerson(n, n->father), name, gen + 1);
    }
    if (n->mother != NULL && FindPerson(n, n->mother) != NULL) {
        printf("child %s\n", n->name);
        findDescendants(FindPerson(n, n->mother), name, gen + 1);
    }
}

///

void printAll(struct Person *n) {
    n = findHead(n);
    while (n->next != NULL) {
        n = n->next;
        printf("name %s, father %s, mother %s\n", n->name, n->father, n->mother);
    }
}


/// V2- current working but double prints name.

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
///



/// v-5
//void findDescendants(struct Person *n, const char *name, int gen) {
//    n = FindPerson(n, name);
//    if (n == NULL) {
//        return;
//    }
//    if (strcmp(n->name, name) == 0) {
//        gen = 0;
//    }
//    if (n->father != NULL && strcmp(n->father, "NULL") != 0) {
//        printf("child %s\n", findFather(n, n->name));
//        findDescendants(n, n->father, gen + 1);
//    }
//    if (n->mother != NULL && strcmp(n->mother, "NULL") != 0) {
//        printf("child %s\n", findMother(n, n->name));
//        findDescendants(n, n->mother, gen + 1);
//    }
//}

///v- 4

//void findDescendants(struct Person *n, const char *name, int gen) {
//    if (strcmp(n->name, name) == 0) {
//        if (gen > 0) {
//            printf("child %s\n", n->name);
//        }
//        struct Person *child = findHead(n);
//        while (child != NULL) {
//            if (strcmp(child->father, name) == 0 || strcmp(child->mother, name) == 0) {
//                if (gen > 0) {
//                    printf("grandchild %s\n", child->name);
//                } else {
//                    printf("child %s\n", child->name);
//                }
//                findDescendants(child, name, gen + 1);
//            }
//            child = child->next;
//        }
//    }
//}

/// v3 - printing everything but descendants are blank for G but no segmentation fault

//void findDescendants(struct Person *n, const char *name, int gen) {
//    if (strcmp(n->name, name) == 0) {
//        if (n->next == NULL) {
//            return;
//        }
//        struct Person *child = n->next;
//        while (child != NULL) {
//            printf("child %s\n", child->name);
//            findDescendants(child, name, gen + 1);
//            child = child->next;
//        }
//        return;
//    }
//    if (n->father != NULL && FindPerson(n, n->father) != NULL) {
//        findDescendants(FindPerson(n, n->father), name, gen + 1);
//    }
//    if (n->mother != NULL && FindPerson(n, n->mother) != NULL) {
//        findDescendants(FindPerson(n, n->mother), name, gen + 1);
//    }
//}

/// v1

//void findDescendants(struct Person *n, const char *name, int gen) {
//    if (strcmp(n->name, name) == 0) {
//        if (gen > 0) {
//            printf("child %s\n", n->name);
//        }
//        return;
//    }
//    if (n->father != NULL) {
//        printf("child %s\n", n->name);
//        findDescendants(FindPerson(n, n->father), name, gen + 1);
//    }
//    if (n->mother != NULL) {
//        printf("child %s\n", n->name);
//        findDescendants(FindPerson(n, n->mother), name, gen + 1);
//    }
//    // check if both father and mother are NULL
//    if (n->father == NULL && n->mother == NULL) {
//        return;
//    }
//}
