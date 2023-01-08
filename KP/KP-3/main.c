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
    long double sum = 0.0;
    long double a = 0.0;
    long double b = 1.0;

    int64_t n;
    printf("Input N:");
    scanf_s("%lld", &n);
    printf("N = %lld\n", n);
    printf("Machine epsilon is equal to: %g\n", LDBL_EPSILON);

    printf("Table for values of Taylor series and of base function\n");
    printf("________________________________________________________________________\n");
    printf("|   x   |          sum       |        f(x)        |number of iterations |\n");
    printf("________________________________________________________________________\n");

    long double currentX;
    long double step = (b - a) / (long double) n;
    for (int64_t i = 1; i <= n; ++i) {
        currentX = a + step * (long double) i;
        sum = taylor_series(i, currentX);

        printf("| %.3Lf | %.16Lf | %.16Lf |      %lld       |\n", currentX, sum, function(currentX), i);
        printf("________________________________________________________________________\n");

        if (fabsl(function(currentX) - sum) < LDBL_EPSILON) break;
    }

    return 0;
}
