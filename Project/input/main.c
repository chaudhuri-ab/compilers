
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
//int myadd_fcn(int a, int b);

int main(int argc, char** argv) {
    int c = 012;
    printf("Octal in Decimal = %d\n", c);
    int d = 0xF;
    printf("Hex in Dec %d\n", d);
    int a = 10;
    int b = 20;
    int result = a + b;
    printf("Result %d\n", result);
    return (EXIT_SUCCESS);
}

/*
int myadd_fcn(int a, int b){
 
    return a+b;
}
*/