#include <stdio.h>

int max(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int min(int a, int b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}

int mod(int a,int b){
    return (b + a % b) % b;
}

int sign(int a){
    if (a > 0){
        return 1;
    }
    else if (a < 0){
        return -1;
    }
    else{
        return 0;
    }
}

int abs(int a){
    if (a < 0){
        return -a;
    }
    else{
        return a;
    }
}

int check_zone(int x, int y){
    if (((((x - 20) * (x - 20)) / 100) + ((y * y) / 25)) <= 1){
        return 1;
    }
    else{
        return 0;
    }
}

int i_move(int i0, int j0, int l0, int k){
    return mod(max(max(i0 * j0, i0 * l0), j0 * l0), 30) + k;
}

int j_move(int i0, int j0, int l0){
    return abs(j0 - l0) * sign(i0) - abs(i0 - l0) * sign(j0);
}

int l_move(int i0, int j0, int l0){
    return min(i0, max(j0, min(l0, max(i0 - l0, j0 - l0))));
}

int main(){
    int k, i, j, l, i0, j0, l0;
    scanf_s("%d %d %d", &i0, &j0, &l0);
    for (k = 0; k < 50 && check_zone(i, j) == 0; ++k){
        i = i_move(i0, j0, l0, k);
        j = j_move(i0, j0, l0);
        l = l_move(i0, j0, l0);
        i0 = i, j0 = j, l0 = l;
    }
    if (check_zone(i, j) == 1){
        printf("Hit in a given area\n");
        printf("Hit time: %d\n", k);
        printf("End coordinates of the point: %d %d\n", i, j);
        printf("Dynamic motion parameter value: %d\n", l);
    }
    else{
        printf("Miss\n");
        printf("Number of steps: %d\n", k);
        printf("End coordinates of the point: %d%d\n", i, j);
        printf("Dynamic motion parameter value: %d\n", l);
    }
    return 0;
}