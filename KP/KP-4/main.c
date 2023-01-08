#include <stdio.h>
#include <math.h>
#include <float.h>


long double derive(long double (*f)(long double), long double x){
    long double inf = 1e-6;
    long double ans = (f(x + inf) - f(x)) / inf;
    return ans;
}

long double func_1(long double x) {
    return 1 / (3 + sinl(3.6 * x));
}

long double func_1_hands(long double x) {
    return -(18*cosl(3.6*x)/(5*powl((3+sinl(3.6*x)),2)));
}

int is_iteration(long double (*f)(long double), long double (*hands)(long double), long double a, long double b) {
    long double step = (b-a)/100000;
    for (long double x=a; x<=b; x+=step) {
        if (derive(f, x) >= 1 || hands(x) >= 1) {
            return 0;
        }
    }
    return 1;
}

long double iteration(long double (*f)(long double), long double a, long double b) {
    long double x = (a + b) / 2.0;
    long double x1 = f(x);
    while (fabsl(x1 - x) >= LDBL_EPSILON) {
        x = x1;
        x1 = f(x);
    }
    return x1;
}

long double func_2(long double x){
    return (0.1 * x * x) - (x * logbl(x));
}

long double first_derivative(long double x){
    return (0.2 * x) - logbl(x) - 1;
}

long double second_derivative(long double x){
    return 0.2 - (1 / x);
}

int check_convergence(long double a, long double b){
    long double step = (b - a) / 10000;
    for (long double x = a; x <= b; x += step){
        if (fabsl(func_2(x) * second_derivative(x)) < first_derivative(x) * first_derivative(x)){
            return 0;
        }
    }
    return 1;
}

long double find_x(long double x_0, long double x){
    while (fabsl(x - x_0) >= LDBL_EPSILON){
        printf("%Lf %Lf", x_0, x);
        x_0 = x;
        x = x_0 - func_2(x_0) / first_derivative(x_0);
    }
    return x;
}

int main() {
    //19
    long double a = 0.0, b = 0.85;
    printf("Function: x - 1 / (3 + sin(3.6x)) = 0\nMethod: iterations.\n");
    if (is_iteration(func_1, func_1_hands, a, b)) {
        printf("Method is convergent.\n");
        printf("x = %Lf", iteration(func_1, a, b));
    } else {
        printf("Method doesn't convergent.\n");
    }
    // 20
    a = 1;
    b = 2;

    long double x_0 = (a + b) / 2;
    long double x= x_0 - func_2(x_0) / first_derivative(x_0);

    printf("Function: (0.1 * x * x) - (x * logbl(x)) = 0\nMethod: Newton.\n");

    if (check_convergence(a, b) == 1){
        printf("Method is convergent\n");
        printf("x = %Lf", find_x(x_0, x));
        printf("The value of the function for such x: %Lf", func_2(x));
    }
    else{
        printf("Method doesn't convergent\n");
    }
    return 0;
}
