#include <iostream>
#include <vector>
using namespace std;

class Animal{
public:
	virtual void noise();
	//void noise();
	int age;
};

void Animal::noise(){
	cout<<"grr"<<endl;
}

class Dog:public Animal{ //inheritance sub-class of animal
public:
	virtual void noise(); //no inline declaration in header is virtual cause base class noise is virtual
};
//noise method is virtual whether or not we declare it as virtual because base class noise is virtual

inline void Dog::noise(){ //for very short function, better performance
	cout<<"ruf ruf"<<endl;
}

class Cat:public Animal{
public:
	virtual void noise(){ //inline function since implementation in header
		cout<<"meow"<<endl;
	}
};

void speak(Animal* ap){
	ap->noise(); //(*ap).noise();
}

int main(){
	Dog d;
	
	Animal *ap=&d;//using base class pointer
	Dog* dp=&d; //pointer and object match
	Cat* cp= new Cat; //on the heap
	ap->noise(); //animal pointer points to a dog object
	dp->noise(); //dog pointer points to a dog object
	cp->noise();
	cout<<endl<<endl;
	
	//speak(ap);
	//speak(dp); //polymorphism
	//speak(cp);
	
	cout<<endl<<endl;
	vector <Animal*>aptrs={dp,cp};
	for (size_t x=0;x<aptrs.size();++x){
		speak(aptrs[x]);
	}
	delete cp;
	cp=0;
	return 0;
}
