#include "Queue.h"

int main()
{
	Queue<int> obj;

	for (int i = 0; i < 4; i++)
	{
		obj.append(i);
	}

	obj.print();
}