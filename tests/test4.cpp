#include "MyVector.h"
#include "MyIterator.h"

#define map(vector, lmbda) do {\
				for (int i = 0; i < vector.getSize(); i++)\
					vector[i] = lmbda(vector[i]);\
			} while(0)

#define MULTIPLIER 2

int multiply(int value) {
	return value * MULTIPLIER;
}

/**
	All about indexing.

	Also useful as a macro reminder :P
*/
int main()
{
	const int NR_ELEM = 12;
	MyVector<int> a;

	for (int i = 0; i < NR_ELEM; ++i)
		a.add(NR_ELEM * i);

	map(a, multiply);

	std::cout << "size = " << a.getSize() << ", capacity = " << a.getCapacity() << std::endl;	
	for (int i = 0; i < NR_ELEM; ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	return 0;	
}
