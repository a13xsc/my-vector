#include<iostream>
template <typename T>
class MyVector{
	T* p;
	int size,capacity;
public:
	MyVector(){
		p =new T[10];
		size=0;
		capacity=10;
	}
	MyVector(int k){
		p =new T[k];
		size=0;
		capacity=k;
	}
	~MyVector(){
		delete[] p;
	}
	int getSize(){
		return size;
	}
	int getCapacity(){
		return capacity;
	}
	void add(T x){//De adaugat resize
		if(size==capacity){
			T* aux;
			aux=p;
			p=new T[2*capacity];
			for(int i=0;i<size;i++){
				p[i]=aux[i];
			}
			capacity*=2;
		}
		p[size]=x;
		size++;
	}
	//int operator[](int i) const{return p[i];}
	T & operator[](int i){
		return p[i];
	}
	/*void remove(int i){
		
	}
	void removeElement(T i){
		
	}*/
};