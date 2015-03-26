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
	int getIndex(){
		return index;
	}
	T* getIt(){
		return it;
	}
	T & operator*(){
		return *it;
	}
	bool operator!=(const MyIterator& x){
		if((this->index==x.index)&&(this->it==x.it))
			return 0;
		else
			return 1;
	}
	MyIterator& operator++(){
		index++;
		it++;
		return *this;
	}
	MyIterator operator++(int){
		MyIterator x;
		x.it=it;
		x.index=index;
		index++;
		it++;
		return x;
	}
	void operator<<(int x){
		index-=x;
		it-=x;
	}
	void operator>>(int x){
		index+=x;
		it+=x;
	}	
	void operator~(){
		vector->remove(index);
	}
	friend class MyVector<T>;
};