#include <stdio.h>

int main(){
//	FILE *in;
	int n, x, y, min1 = 20001, min2 = 20001, min3 = 20001;
	long int sum0 = 0, sum1 = 0;
//	in = fopen("input.txt");
//	fscanf(in, "%d", n);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
//		fscanf(in, "%d %d", &x, &y);
		sccanf("%d %d", x, y);
		if ((x % 2) == 1){
			if ( x > y ){
			sum1 += x;
			sum0 += y;
			if ( ((x % 2) == 1) && ((y % 2) == 1) && ((x + y) < min1) )
				min1 = x + y;
			if ( ((x % 2) == 0) && ((y % 2) == 1) && ((x + y) < min2) )
           	                min2 = x + y;
			if ( ((x % 2) == 1) && ((y % 2) == 0) && ((x + y) < min3) )
        	                min3 = x + y;
			}
			else{
			sum1 += y;
			sum0 += x;
			if ( ((x % 2) == 1) && ((y % 2) == 1) && ((x + y) < min1) )
                                min1 = x + y;
                        if ( ((x % 2) == 0) && ((y % 2) == 1) && ((x + y) < min2) )
                                min2 = x + y;
                        if ( ((x % 2) == 1) && ((y % 2) == 0) && ((x + y) < min3) )
                                min3 = x + y;

			}
		}
	}
	if ( (sum0 % 2 == 0) && (sum1 % 2 == 1)
		printf("%ld", sum0 + sum1);
	else if ( (sum0 % 2 == 1) && (sum1 % 2 == 0))
		if ( min1 < (min2 + min3))
			printf("%ld", sum0 + sum1 - min1);
		else
			printf("%ld", sum0 + sum1 - min2 - min3);
	else if ( (sum0 % 2 == 1) && (sum1 % 2 == 1))
                if ( min2 < (min1 + min3))
                        printf("%ld", sum0 + sum1 - min2);
                else
                        printf("%ld", sum0 + sum1 - min1 - min3);
	else if ( (sum0 % 2 == 0) && (sum1 % 2 == 0))
                if ( min3 < (min1 + min2))
                        printf("%ld", sum0 + sum1 - min3);
                else
                        printf("%ld", sum0 + sum1 - min1 - min2);
}
