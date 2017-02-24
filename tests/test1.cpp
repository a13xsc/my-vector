#include "MyVector.h"
#include "MyIterator.h"

/**
	Basic declaration, construction, simple element additions
	New: array-like indexing!
*/

int main()
{
	const int NR_ELEM = 9;
	MyVector<int> a;
	for (int i = 0; i < NR_ELEM; ++i)
		a.add(i + 5);
	
	std::cout << "size = " << a.getSize() << ", capacity = " << a.getCapacity() << std::endl;
	for (int i = 0; i < NR_ELEM; ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	
	return 0;	
}
