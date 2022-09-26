#include "func_test.h"

int main(void)
{
	int	a, b;
	int	result;

	a = 5;
	b = 2;

	printf("라이브러리 테스트\n ");
	result = func1(a, b);
	printf("func1 TEST [%d]\n", result);

	result = func2(a,b);
	printf("func2  TEST [%d]\n", result);

	return 1;
}
