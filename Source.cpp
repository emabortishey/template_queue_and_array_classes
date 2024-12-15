//#include "Queue.h"
#include "Array.h"

int main()
{
	Array<int> obj;

	for (int i = 0; i < 4; i++)
	{
		obj.append(i);
	}

	Array<int> obj2;

	for (int i = 0; i < 4; i++)
	{
		obj2.append(i+4);
	}

	obj.Append(obj2);

	obj.print();

	obj.InsertAt(1, 1);

	/*obj.SetSize(8);

	obj.FreeExtra();

	obj.print();

	cout << obj.GetAt(1);*/

}