#include "MyVector.h"
#include "MyIterator.h"

/**
	Concatenation via +
	By now you should have a rock solid basic implementation of MyVector.
*/
int main()
{
	const int NR_ELEM = 25;
	MyVector<int> a(NR_ELEM/2), b(NR_ELEM - 1);
	for (int i = 0; i < NR_ELEM; ++i) {
		a.add(i);
		b.add(NR_ELEM + i);
	}
	
	MyVector<int> c = a + b;
	
	std::cout << "size = " << c.getSize() << ", capacity = " << c.getCapacity() << std::endl;
	for (int i = 0; i < c.getSize(); ++i)
		std::cout << c[i] << " ";

	std::cout << std::endl;
	return 0;	
}
