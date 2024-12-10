//#include "Queue.h"
#include "Array.h"

int main()
{
	Array<int> obj;

	for (int i = 0; i < 4; i++)
	{
		obj.append(i);
	}

	obj.SetSize(8);

	obj.FreeExtra();

	obj.print();


}