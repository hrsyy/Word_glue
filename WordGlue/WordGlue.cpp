#include "Glue.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (int i = 0; i < 5; i++)
	{
		Glue glue;
		glue.GLUEWORD();
	}
}