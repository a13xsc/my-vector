#include<iostream>
using namespace std;
template <typename T>
class MyVector{
	T* v;
	int size,capacity;
	
	void reducesize(){
		T* aux;
		aux=v;
		v=new T[capacity/2];
		for(int i=0;i<size;i++){
			v[i]=aux[i];
		}
		delete[] aux;
		capacity/=2;
	}
	
public:
	MyVector(){
		v =new T[10];
		size=0;
		capacity=10;
	}
	MyVector(int k){
		v =new T[k];
		size=0;
		capacity=k;
	}
	~MyVector(){
		delete[] v;
	}
	int getSize(){
		return size;
	}
	int getCapacity(){
		return capacity;
	}
	void add(T x){//add
		if(size==capacity){
			T* aux;
			aux=v;
			v=new T[2*capacity];
			for(int i=0;i<size;i++){
				v[i]=aux[i];
			}
			delete[] aux;
			capacity*=2;
		}
		v[size]=x;
		size++;
	}
	//int operator[](int i) const{return p[i];}
	T & operator[](int i){
		return v[i];
	}
	void remove(int x){//remove
		if(x<size){
			for(int i=x;i<size-1;i++){
				v[i]=v[i+1];
			}
			size--;
			if(size<capacity/2){
				reducesize();
			}
		}
	}
	void removeElement(T x){//removeElement
		for(int i=0;i<size;i++){
			if(v[i]==x){
				for(int j=i;j<size-1;j++){
					v[j]=v[j+1];
				}
				size--;
				break;
			}
		}
		if(size<capacity/2){
			reducesize();
		}
	}
	void operator=(MyVector& vect){//assignment operator
		size=vect.size;
		capacity=vect.capacity;
		delete[] v;
		v=new T[size];
		for(int i=0;i<vect.getSize();i++){
			v[i]=vect[i];
		}	
	}
	friend std::ostream& operator<<(std::ostream& out,const MyVector<T>& vect);//output
};

template<typename T>
std::ostream& operator<<(std::ostream& out, MyVector<T>& vect){//output
		for(int i=0;i<vect.getSize();i++){
			out<<vect[i]<<" ";
		}
		return out;
	}