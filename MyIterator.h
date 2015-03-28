#include<iostream>
using namespace std;
template<typename T>
class MyVector;
template<typename T>
class MyIterator{
	T* it;
	int index;
	MyVector<T>* vector;
public:
	int getIndex(){//intoarce indexul curent
		return index;
	}
	T* getIt(){//intoarce adresa de care este legat iteratorul
		return it;
	}
	T & operator*(){//operatorul *
		return *it;
	}
	bool operator!=(const MyIterator& x){//operatorul !=
		if((this->index==x.index)&&(this->it==x.it))
			return 0;
		else
			return 1;
	}
	MyIterator& operator++(){//operatorul pre-incrementare
		index++;
		it++;
		return *this;
	}
	MyIterator operator++(int){//operatorul post-incrementare
		MyIterator x;
		x.it=it;
		x.index=index;
		index++;
		it++;
		return x;
	}
	MyIterator& operator--(){//operatorul pre-decrementare
		index--;
		it--;
		return *this;
	}
	MyIterator operator--(int){//operatorul post-decrementare
		MyIterator x;
		x.it=it;
		x.index=index;
		index--;
		it--;
		return x;
	}
	void operator<<(int x){//operatorul <<
		index-=x;
		it-=x;
	}
	void operator>>(int x){//operatorul >>
		index+=x;
		it+=x;
	}	
	void operator~(){//operatorul ~
		vector->remove(index);
	}
	friend class MyVector<T>;
};