#include "MyVector.h"
#include "MyIterator.h"

/**
	Destruction, addition with capacity-doubling.
*/
int main()
{
	const int NR_ELEM = 21;
	MyVector<int> *b = new MyVector<int>(20);
        for (int i = 0; i < NR_ELEM; ++i)
                b->add(i + 6);

       	std::cout << "size = " << b->getSize() << ", capacity = " << b->getCapacity() << std::endl;
        for (int i = 0; i < NR_ELEM; ++i)
                std::cout << ((*b)[i]) << " ";
        std::cout << std::endl;
        delete b;

	return 0;	
}
