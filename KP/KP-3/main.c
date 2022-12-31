#include <stdio.h>
#include <float.h>
#include <stdint.h>
#include <math.h>

int64_t factorial(int64_t n) {
    int64_t res = 1;

    for (int64_t i = 1; i <= n; ++i)
        res *= i;

    return res;
}

long double taylor_series(uint64_t n, long double x){
    long double result = 0;
    for (int i = 0; i <= n; ++i){
        result += powl(-1, (long double) i - 1) * (((long double) (i - 1)) / ((long double) factorial(i))) * powl(x , (long double) i);
    }
    return result;
}

long double function(long double x){
    return (1 + x) * expl(-x);
}

int main(){
    long double a = 0.0;
    long double b = 1.0;

    uint64_t n;

    printf("Input N:");
    scanf_s("%lld", &n);
    printf("N = %lld\n", n);
    printf("Machine epsilon is equal to: %Lg\n\n", LDBL_EPSILON);

    printf("        Table of values of Taylor series and standard function\n");
    printf("___________________________________________________________________________\n");
    printf("|  x  | sum of Taylor series | f(x) function value | number of iterations |\n");
    printf("___________________________________________________________________________\n");

    long double x = 0;
    long double step = (b - a) / n;
    long double func = 1;
    int i = 0;
    while (fabsl(func) > LDBL_EPSILON && (i < 100) && (i < n)){
        i += 1;
        x += step;
        func = function(x);

        printf("|%.3Lf|%.20Lf|%.19Lf|           %d          |\n", x, taylor_series(i, x), func, i);
    }

    printf("___________________________________________________________________________\n");

    return 0;
}
