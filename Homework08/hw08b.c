#include <stdio.h>


int main() {
    // for loop to print numbers 1-5
    // for(init; stop condition; increment)

    int x; // declare variable first

    // for loop
    for(x=1; x<6; x=x+1){
        printf("%d\n", x);
    }

    // while loop
    x=1;
    while(x<=5){
        printf("%d\n",x);
        x++;
    }

    // do while loop
    x=1;
    do {
        printf("%d\n",x);
        x++;
    }while(x<=5);

    return 0;
}
