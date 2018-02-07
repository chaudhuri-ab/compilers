
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
//int myadd_fcn(int a, int b);

struct test{
    int val;
    int val2;
};

int main(int argc, char** argv) {
    struct test t1;
    struct test* ptest;
    ptest = &t1;
    
    int value = 100;
    t1.val = value++;
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
    int result = a + b;
    result = a -b;
    printf("Result %d\n", result);
    return (EXIT_SUCCESS);
}

/*
int myadd_fcn(int a, int b){
 
    return a+b;
}
*/