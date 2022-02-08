#include "Glue.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Glue glue;

	glue.GetFirstWord();
	glue.TruncateWord();
	glue.GetSecondWord();
	glue.GLUEWORD();
}