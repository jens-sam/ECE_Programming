#include <stdio.h>
#include <stdbool.h>

bool isEven(int y);
bool isPrime(int z);

int main() {
    int i;
    for (i = 1; i <= 20; i++) {
        /*
        printf("%d\t%s\t%s\n", i,
               isEven(i) ? "even" : "odd",
               isPrime(i) ? "prime" : "composite");
    }*/
    printf("%d\t", i);
    if (isEven(i)) {
        printf("even\t");
    } else {
        printf("odd\t");
    }
    if (isPrime(i)) {
        printf("prime\n");
    } else {
        printf("composite\n");

    }
}
    return 0;
}


bool isEven(int y){
    if (y%2==0) {
        return true;
    }
    else {
        return false;
    }
}
bool isPrime(int z) {
    int i;
    if (z == 1) {
        return true;
    }
    for (i = 2; i <= z / 2; i++) {
        if (z % i == 0) {
            return false;
        }
    }
    return true;
}
