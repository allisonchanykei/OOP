#include <iostream>
#include <vector>
using namespace std;

class Animal{
public:
	Animal();
	Animal(const Animal&); //copy ctor
	virtual void noise();
	//void noise();
	int* agep;
	virtual ~Animal(); //destructor must be virtual and must exist, gets called when the object goes out of scope
					   //~ tilda (symbol for delete)
};

Animal::Animal(){
	cout<<"Animal ctor"<<endl;
	agep=new int;
}
Animal::Animal(const Animal& x){	//copy ctor
	cout<<"Animal copy ctor"<<endl;
	*agep=*(x.agep); //deep copy
}
Animal::~Animal(){
	delete agep;	//must delete in dtor if used new in ctor
}

void Animal::noise(){
	cout<<"grr"<<endl;
}

class Dog:public Animal{
public:
	Dog(); //constructor
	Dog(const Dog&);	//copy ctor
	virtual ~Dog(); //destructor
	static int count; //count does not exist for all instances of Dogs (only 1 copy for all Dogs)
	virtual void noise(); //no inline declaration in header is virtual cause base class noise is virtual
};

int Dog:: count=0; //initialize count (can't do this in the class decleration above)

Dog::Dog(){
	count++;
	cout<<"ctor: There are now "<<count<<" dogs"<<endl;
}

Dog::~Dog(){
	count--;
	cout<<"dtor: There are now "<<count<<" dogs"<<endl;
}
Dog::Dog(const Dog& x){
	*agep=*(x.agep);
	count ++;
	cout<<"Copy Ctor of Dog: There are now "<<endl;
}
inline void Dog::noise(){
	cout<<"ruf ruf"<<endl;
}


class Cat: public Animal{
public:
	virtual void noise(){ //inline since implementation in heade
		cout<<"meow"<<endl;
	}
};

void speak (Animal* ap){
	ap->noise();
}

void foo(Dog D){
	cout<<"call from foo "<<*(D.agep)<<endl;
	*(D.agep)=6;
}

int main(){
	Dog d;	//on stack but age is on the heap
	*(d.agep)=5;

	foo(d); //copy ctor called
	cout<< *(d.agep)<<endl;
	
	
	return 0;
}
