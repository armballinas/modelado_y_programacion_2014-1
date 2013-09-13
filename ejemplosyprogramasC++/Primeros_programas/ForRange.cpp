#include<iostream>

using namespace std;

struct Vector{
	int size;
	double *elems;
};

/*Usameos Vector& para indicar que v no es constante y se puede modificar*/
void vector_init(Vector& v ,int s){
	v.elems = new double[s]; //creamos arreglos dinámicos a difrerencia de C
	v.size = s;
}

/*función que lee s enteros de entrada estándar y los suma, se supone s positivo*/
double read_and_sum(int s){
	Vector v;
	vector_init(v,s);
	for(int i=0;i<s;i++){
		cin>>v.elems[i];
	}
	double sum = 0.0;
	for(i=0;i<s;i++){
		sum+=v.elems[i];
	}
	return sum;
}

int main(){
	cout<<"dame el tamaño\n";
	int s = 0;
	cin >> s;
	cout<<read_and_sum(s);	
	
}
