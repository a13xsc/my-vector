#include "MyVector.h"
#include "MyIterator.h"
#include <string>

using namespace std;

/**
	Iterators are such cowboys. They never talk straight.
*/
int main()
{
	const int NR_ELEM = 11;
	string sentence[11] = {" how", " can", " a", " clean", " clam", " cram", " in", " a", " clean", " cream", " can?"};

	MyVector<string> a;
	for (int i = 0; i < NR_ELEM; ++i)
		a.add(sentence[i]);
	
	MyIterator<string> it = a.begin();
	for (int i = 0; i < NR_ELEM; i++) {
		std::cout << (*it);
		if (i == NR_ELEM / 2) {
			it << (NR_ELEM - 2);
		} else
			it >> 2;
	}
	std::cout << std::endl;
	return 0;	
}
