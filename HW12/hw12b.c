#include <stdio.h>
#include "family_tree.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./hw12b <family csv filename> <name>\n");
        return 1;
    }

    List familyList = {NULL, NULL};

    if (!load(&familyList, argv[1])) {
        printf("Failed to load family data\n");
        return 1;
    }

    printf("Ancestors of %s:\n", argv[2]);
    printAncestors(&familyList, argv[2]);

    printf("\nDescendants of %s:\n", argv[2]);
    printDescendants(&familyList, argv[2]);

    // Uncomment these lines for the extra challenge
    // printf("\nSiblings of %s:\n", argv[2]);
    // printSiblings(&familyList, argv[2]);

    // printf("\nCousins of %s:\n", argv[2]);
    // printCousins(&familyList, argv[2]);

    return 0;
}
