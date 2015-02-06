// a example of  'c' varargs
#include <stdio.h>
#include <stdarg.h>

void var_fun(int start, ...)
{
	va_list list;
	va_start(list, start);
	int num;
	do
	{
		num = va_arg(list, int);
		printf("%d\n", num);
	} while (num);
	va_end(list);
}

//int main(int argc, char *argv[])
//{
//	var_fun("start", 3, 4, 5, 6, 7, 8, 9, 0);
//	getchar();
//	return 0;
//}