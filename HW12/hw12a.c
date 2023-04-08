
#include <stdio.h>
#include <stdlib.h>

// recursive function making sure that 0 is 1 and then return factorial eq.
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// need at least two args
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid input\n");
        return 1;
    }

    // converts from string to int on the second arg
    int input = atoi(argv[1]);

    // make sure the input is between 0 and 10
    if (input < 0 || input > 10) {
        printf("Invalid input\n");
        return 1;
    }

    int result = factorial(input);
    printf("%d\n", result); //call function and print result in this format

    return 0;
}
