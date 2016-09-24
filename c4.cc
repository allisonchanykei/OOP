#include <iostream>
#include <vector>
using namespace std;

class Animal{
public:
	Animal();
	virtual void noise();
	//void noise();
	int* agep;
	virtual ~Animal(); //destructor must be virtual and must exist, gets called when the object goes out of scope
					   //~ tilda (symbol for delete)
};

Animal::Animal(){
	agep=new int;
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
	~Dog(); //destructor
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

int main(){
	Dog d;	//on stack but age is on the heap
	//~ Animal* ap1 = new Dog;	//heap
	
	Animal *ap=&d;//using base class pointer
	Dog* dp=&d; //pointer and object match
	//~ Cat* cp= new Cat; //on the heap
	ap->noise(); //animal pointer points to a dog object
	dp->noise(); //dog pointer points to a dog object
	//~ cp->noise();
	//~ cout<<endl<<endl;
	
	//~ speak(ap);
	//~ speak(dp); //polymorphism
	//~ speak(cp);
	
	
	//~ delete cp;
	//~ cp=0;
	//~ delete ap1; //dog destructor called
	//~ ap1=0;
	return 0;
}	//age is deleted from d
