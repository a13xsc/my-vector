#include "MyVector.h"
#include "MyIterator.h"

/**
	Iteration but not quite. Just the start.
*/
int main()
{
	const int NR_ELEM = 12;
	MyVector<int> a;
	for (int i = 0; i < NR_ELEM; ++i)
		a.add(i + 5);
	
	MyIterator<int> it = a.begin();
	
	std::cout << (*it) << std::endl;
	return 0;	
}