#include <iostream>
#include "DatabaseHandler.h"
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DatabaseHandler handler(1);

	handler.addDatabase(new Database("DB 1", 3));

	system("pause");
	return 0;
}