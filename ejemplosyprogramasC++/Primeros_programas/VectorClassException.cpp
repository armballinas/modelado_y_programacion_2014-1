#include<iostream>

using namespace std;

class Vector{
public:
	Vector(int size) : elem{new double[size]}, size{size} {} //construye un vector de tamaño s
	double& operator[] (int i){ //acceso a elementos del vector mediante indexación
		//si el índice es inválido, lanzo la excepción.
		if(i<0 || getSize()<=i) throw out_of_range{ "Vector::operator[]"};
		return elem[i];
	}
	
	int getSize(){
		return size;
	}
	
private:
	double *elem;
	int size;		
};

double read_and_sum(int s){
	Vector v(s);
	for(int i=0;i<v.getSize();i++){
		cin>>v[i];
	}
	double sum = 0;
	for(int i=0;i<v.getSize();i++){
		sum+=v[i];
	}
	return sum;
}

void f(Vector& v){
	try{
		v[v.getSize()] = 7; //ocurre la excepción
	}
	catch (out_of_range){
		cout<<"Error índice no válido\n";
	}
}

int main(){
	Vector v(6); //construyo un vector de tamaño 6;
	f(v);
}
