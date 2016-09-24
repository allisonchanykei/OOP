#include <iostream>
#include <vector>
using namespace std;

class Animal{
public:
	Animal();
	Animal(const Animal&); //copy ctor (by default, c++ copy directly. if there is a pointer, it would point to the same address)
	Animal& operator = (const Animal& rhs); //assignment operator
	virtual void noise();
	int* agep;
	virtual ~Animal(); //destructor must be virtual and must exist, gets called when the object goes out of scope
};

Animal::Animal(){
	cout<<"Animal ctor"<<endl;
	agep=new int;
}

Animal::Animal(const Animal& x){	//copy ctor
	//agep=x.agep;	//happens by default
	cout<<"Animal copy ctor"<<endl;
	agep=new int;
	*agep=*(x.agep); //deep copy
}

Animal& Animal::operator = (const Animal& rhs){
	if (this==&rhs) return *this; //for self assignment (pointer to itself)
	*agep=*(rhs.agep);
	return *this;
}


Animal::~Animal(){
	cout<<"Animal dtor"<<endl;
	delete agep;	//must delete in dtor if used new in ctor
}

void Animal::noise(){
	cout<<"grr"<<endl;
}

class Dog:public Animal{
public:
	Dog(); //constructor
	Dog(const Dog&);	//copy ctor
	Dog& operator=(const Dog& rhs);
	~Dog(); //destructor
	static int count; //count does not exist for all instances of Dogs (only 1 copy for all Dogs)
	bool shots;
	virtual void noise(); //no inline declaration in header is virtual cause base class noise is virtual
	friend ostream& operator<<(ostream& o, const Dog& x); //friend allows it to be part of animal without initializing it
};

int Dog:: count=0; //initialize count (can't do this in the class decleration above)

Dog::Dog():shots(false){
	count++;
	cout<<"ctor: There are now "<<count<<" dogs"<<endl;
}

Dog::~Dog(){
	count--;
	cout<<"dtor: There are now "<<count<<" dogs"<<endl;
}
Dog::Dog(const Dog& x):Animal(x){
	//*agep=*(x.agep);
	shots=x.shots;
	count ++;
	cout<<"Copy Ctor of Dog: There are now "<<count<<" dogs"<<endl;
}
Dog& Dog::operator = (const Dog& rhs){
	if (this==&rhs) return *this; //for self assignment (pointer to itself)
	cout<<"Dog assignment"<<endl;
	Animal::operator=(rhs);//explicitly call Animal assignment operator sending rhs by reference
	shots=rhs.shots;
	return *this; //so multiple assignment will work eg a=b=c
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

ostream& operator<<(ostream &o, const Dog& x){
	o<<"Age: "<<*(x.agep)<<" -- "<<"Shots: "<<x.shots;
	return o;
}

int main(){
	Dog d;	//on stack but age is on the heap
	*(d.agep)=5;

	foo(d); //copy ctor called
	
	if(1){
		Dog R;
		R=d; //needs overloaded operator =
		//cout<<R<<endl;
	}
	Animal* ap=&d;
	ap->noise(); 
	cout<< *(d.agep)<<endl;
	
	return 0;
}
