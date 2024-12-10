//#include "Queue.h"
#include "Array.h"

int main()
{
	Array<int> obj;

	for (int i = 0; i < 4; i++)
	{
		obj.append(i);
	}

	cout << obj.GetSize();

	obj.SetSize(2);

	cout << obj.GetSize();

	obj.print();
}