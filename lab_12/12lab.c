#include<stdio.h>
#include<assert.h>
//#include<math.h>

int count_digit(int number) {
	int counter = 0;
	if (number != 0) {
		while (number != 0)
		{
			number /= 10;
			counter ++;
		}
		return  counter;
	}
	else {
		return 0;
	}
}

int tenpow (int n) {
	int t = 1;
	for (int i = 0; i < n; ++i)
	{
		t *= 10;
	}
	return t;
}

void test_count_digit() {
	assert(count_digit(1));
	assert(count_digit(123456789));
}

void test_tenpow() {
	assert(tenpow(0));
	assert(tenpow(10));
}

void Tests() {
	test_count_digit();
	test_tenpow();
}

int main()
{
	Tests();

	int i = 1, num1, num2 = 0;
	scanf("%d", &num1);
	if (count_digit(num1) % 2 != 0)
	{
		while (num1 != 0)
		{
			if (i % 2 != 0)
			{
				num2 += (num1%10)*tenpow(i/2);
			}
			++i;
			num1 = num1/10;
		}
	}
	else
	{
		while (num1 != 0)
                {
                        if (i % 2 == 0)
                        {
                                num2 += (num1%10)*tenpow(i/2 - 1);
                        }
                        ++i;
                        num1 = num1/10;
                }
        }
	printf("%d\n", num2);
}


