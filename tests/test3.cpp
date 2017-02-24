#include "MyVector.h"
#include "MyIterator.h"

/**
	Deletion of elements. Both methods, with getSize shrinking.
*/

int main()
{
	const int NR_ELEM = 100;
	MyVector<int> a(100);
	for (int i = 0; i < NR_ELEM; ++i)
		a.add(i);
	
	for (int i = 0; i < NR_ELEM / 2; ++i)
		a.removeElement(2 * i);
	
	for (int i = 13; a.getSize() > NR_ELEM / 4; i = (i * 47) % a.getSize())
		a.remove(i);

	std::cout << "size = " << a.getSize() << ", capacity = " << a.getCapacity() << std::endl;
	for (int i = 0; i < a.getSize(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	return 0;	
}
