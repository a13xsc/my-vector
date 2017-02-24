#include "MyVector.h"
#include "MyIterator.h"

/**
	Iteration, deletion.
	Also, formatted output for MyVector.
*/
int main()
{
	const int NR_ELEM = 12;
	MyVector<int> a;
	for (int i = 0; i < NR_ELEM; ++i)
		a.add(i);
	
	MyIterator<int> it;
	it = a.begin();
	while (a.getSize() > 0) {
		~it;
		std::cout << a << std::endl;
	}
	return 0;	
}
