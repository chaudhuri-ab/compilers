
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
//int myadd_fcn(int a, int b);

struct test {
    int val;
    int val2;
};

int main(int argc, char** argv) {
    struct test t1;
    struct test* ptest;
    ptest = &t1;
    ptest->val = 9 & 0xF | 0xE;

    long temp = 8;
    temp <<= 1;
    temp >>= 2;
    temp = 10 << 2;
    temp *= 2;
    temp /= 3;
    
    char temp2 = 9/2;
    temp2= 8 % 4;
    temp2%= 3;
    temp2 = 98^7;
    temp2 = 97 ^ 2;
    temp2 ^=9;

    if (ptest -> val > 100 || 1 > 0 || 1 >= 55&& 1!= 99) {
        printf("Stuff1 \n");
    } else if (1 <= 55 && 2 < 55) {
        printf("Stuff2 \n");
    } else if (10 == 10) {
        printf("Stuff3 \n");

    }


    int value = 100;
    t1. val = value++;
    t1.val = value--;
    t1.val = --value;
    t1.val = ++value;

    float e = 0.2;
    float f = .4;
    int c = 012;
    printf("Octal in Decimal = %d\n\n", c);
    int d = 0xFC;
    printf("Hex in Dec %d\n", d);
    int a = 10;
    int b = 20;
    int result = a * b;
    result = a - b;
    printf("Result %d\n", result);
    return (EXIT_SUCCESS);
}

/*
int myadd_fcn(int a, int b){
 
    return a+b;
}
 */