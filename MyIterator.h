#include<iostream>
using namespace std;
template<typename T>
class MyVector;
template<typename T>
class MyIterator{
	T* it;
	int index;
public:
	int getIndex(){
		return index;
	}
	T* getIt(){
		return it;
	}
	T operator*(){
		return *(it);
	}
	friend class MyVector<T>;
};