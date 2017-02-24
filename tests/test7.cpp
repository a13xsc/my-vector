#include "MyVector.h"
#include "MyIterator.h"

/**
	Iteration done right. There's more to it than meets the eye.
*/
int main()
{
	const int NR_ELEM = 12;
	bool ping = false;

	MyVector<int> a;
	for (int i = 0; i < NR_ELEM; ++i)
		a.add(i + 5);
	
	std::cout << "size = " << a.getSize() << ", capacity = " << a.getCapacity() << std::endl;
	for (MyIterator<int> it = a.begin(); it != a.end(); ping = !ping) {
		std::cout << (*it) << " ";
		if (ping)
			++it;
		else
			it++;
	}
	std::cout << std::endl;
	return 0;	
}
