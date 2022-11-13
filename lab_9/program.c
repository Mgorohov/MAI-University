#include <stdio.h>
#include <time.h>

# define m 50

int abs(int n){
        if (n > 0)
                return n;
        else
                return -n;
}

int max(int n1, int n2){
        if (n1 > n2)
                return n1;
        else
                return n2;
}

int sign(int n){
        if (n > 0)
                return 1;
        else
                return -1;
}

int circle(int x, int y){
        int point = 0;
        point = (x - 10)*(x - 10) + (y - 10)*(y - 10);
        return point;
}

int main(){
        const int i0 = -1, j0 = -1, l0 = -9;// m = 50;
	double start, end;
        int I[m] = { 0 }, J[m] = { 0 }, L[m] = { 0 };
        I[0] = i0;
        J[0] = j0;
        L[0] = l0;
	start = time(NULL);
        for ( int k = 1; k < m; k++){
                I[k] = max(J[k - 1] - k - 1, L[k - 1] - k - 1) % 30 + max(I[k - 1] +L[k - 1], J[k - 1] + k -1) % 20;
                J[k] = (abs(I[k - 1] - L[k - 1]) * sign(J[k - 1] + k - 1) + abs(I[k -1] -k - 1) * (J[k - 1] + k - 1)) % 20;
                L[k] = (I[k - 1] + k - 1) * (J[k - 1] - k - 1) * (L[k - 1] + k - 1) % 25;
                if ((circle(I[k], J[k]) <= 100) && (circle(I[k], J[k]) >= 25)){
			end = time(NULL);
                        printf("Point has been in the area on the %d steps.\n", k);
			printf("The points coordinates: (%d; %d)\n", I[k], J[k]);
			printf("Movement parametr: %d\n", L[k]);
			printf("Runtime: %f seconds.\n", difftime(end, start));
			//printf("%f\n",(end - start) / (CLOCKS_PER_SEC));
			break;
                        // вывести точку, номер итерации и длину и завершить выполнение программы
                }
        }
        // вывести строку что за итераций точка не лежит в кольце
}