#include "MyVector.h"
#include "MyIterator.h"

int main()
{
	const int NR_ELEM = 128;
    const int MAX_ITER = 256;
    const double PI = 3.1415f;
	MyVector<double> *a = new MyVector<double>();
	for (int iter = 0; iter < MAX_ITER; ++iter) {
        for (int i = 0; i < NR_ELEM; ++i)
		    a->add(PI * i);
    
        for (int i = 0; i < NR_ELEM/2 + 4; ++i)
            a->remove(i);

        MyIterator<double> it = a->begin();
        for (; it != a->end(); ++it)
            *it = PI * (*it);
    }

	std::cout << (*a) << std::endl;
    delete a;

	return 0;	
}
