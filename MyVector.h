#include<iostream>
using namespace std;

template<typename T>
class MyIterator;

template<typename T>
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
	MyVector(){//constructor default
		v =new T[10];
		size=0;
		capacity=10;
	}
	MyVector(int k){//constructor
		v =new T[k];
		size=0;
		capacity=k;
	}
	MyVector(const MyVector& x){//copy constructor
		size=x.size;
		capacity=x.capacity;
		delete[] v;
		v=new T[capacity];
		for(int i=0;i<size;i++){
			v[i]=x[i];
		}
	}
	~MyVector(){//destructor
		delete[] v;
	}
	int getSize(){//getSize
		return size;
	}
	int getCapacity(){//getCapacity
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
	
	T & operator[](int i) const{return v[i];}

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
	MyVector& operator=(const MyVector& vect){//assignment operator
		size=vect.size;
		capacity=vect.capacity;
		delete[] v;
		v=new T[capacity];
		for(int i=0;i<size;i++){
			v[i]=vect[i];
		}
		return *this;	
	}
	MyVector operator+(MyVector& b){//adunare
		MyVector c(capacity+b.capacity);
		for(int i=0;i<size;i++){
			c.add(v[i]);
		}
		for(int i=0;i<b.size;i++){
			c.add(b[i]);
		}
		return c;
	}
	MyIterator<T> begin(){
		MyIterator<T> x;
		x.index=0;
		x.it=v;
		x.vector=this;
		return x;
	}
	MyIterator<T> end(){
		MyIterator<T> x;
		x.index=size;
		x.it=v+size;
		x.vector=this;
		return x;
	}
	
	template<typename J>
	friend std::ostream& operator<<(std::ostream& out,const MyVector<J>& vect);//output
};

template<typename J>
std::ostream& operator<<(std::ostream& out, MyVector<J>& vect){//output
		int i;
		for(i=0;i<vect.getSize();i++){
			out<<vect[i];
			if(i<vect.getSize()-1){
				out<<" ";
			}
		}
		return out;
	}