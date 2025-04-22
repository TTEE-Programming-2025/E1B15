#include <stdio.h>
#include <stdlib.h>
void sum(int, int); //函式原型宣告
int main()
{
	sum(1, 100, 1-); //呼叫函式
	sum(1, 101, 2); //呼叫函式
	sum(4, 100, 3); //呼叫函式
	system("pause");
	return 0;
}
//函式定義
/********************************/
void sum(int m, int n, int add)
{
	int i, total=0;

	for (i = m; i <= n; i = i + add)
		total = total +i;
	printf("%d+%d+%d+…+",
			m, m+add, m+2*add);
	printf("%d= %d\n", n, total);
}    
