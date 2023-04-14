#include "family_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Need three args: ./hw12 <family txt filename> <name>\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("get me the file or else...\n");
        return 1;
    }

    struct Person *head = NULL;
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        char *name = strtok(line, " ");
        char *father = strtok(NULL, " ");
        char *mother = strtok(NULL, " \n");
        if (head == NULL) {
            head = malloc(sizeof(struct Person));
            strncpy(head->name, name, sizeof(head->name));
            strncpy(head->father, father, sizeof(head->father));
            strncpy(head->mother, mother, sizeof(head->mother));
            head->prev = NULL;
            head->next = NULL;
        } else {
            addToTail(head, name, father, mother);
        }
    }
    fclose(file);

    char *name = argv[2];
    printf("ancestors of %s:\n", name);
    findAncestor(head, name, 0);

    printf("descendants of %s:\n", name);
    findDescendants(head, name, 0);

    /// Test to print out the names and mother father
//    struct Person *current = head;
//    while (current != NULL) {
//        printf("name: %s, father: %s, mother: %s\n", current->name, current->father, current->mother);
//        current = current->next;
//    }
    return 0;
}
