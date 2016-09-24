#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Vehicle{
	//private by default cannot be modified outsideeof class
	int xPos;
	int yPos;
	double fuel;
	
	public:
		Vehicle();
		Vehicle(double fl);
		Vehicle(double fl, int x, int y);
		vector<int> getPosition() const;
		bool driveTo(vector<int> place);
		double fuelLeft() const;
		void refuel();
		//ostream& operator<<(ostream& o, const Vehicle& v); //can't be in class
};

Vehicle::Vehicle(){
	xPos=0;
	yPos=0;
	fuel=100.0; //full tank
}

Vehicle::Vehicle(double fl){
	xPos=0;
	yPos=0;
	fuel=fl;
}

Vehicle::Vehicle(double fl, int x, int y){
	fuel=fl;
	xPos=x;
	yPos=y;
}

double Vehicle::fuelLeft() const{
	return fuel;
}

vector<int> Vehicle::getPosition() const{
	//vector<int>pos = {xPos,yPos};//c++11
	vector<int>pos;
	pos.push_back(xPos);
	pos.push_back(yPos);
	return pos;
}
	
bool Vehicle::driveTo(vector<int> place){
	vector <int> opos =getPosition();
	int xDis = place[0]-opos[0];
	int yDis = place[1]-opos[1];
	double dis = sqrt(pow(xDis,2)+pow(yDis,2));
	if (fuel>dis){
		cout<<"Too little fuel"<<endl;
		return false;
	}
	xPos = place[0];
	yPos = place[1];
	fuel = fuel - dis;
	cout<<"Able to get there"<<endl;
	return true;
}

void Vehicle::refuel(){
	fuel=100.0;
}

ostream& operator << (ostream& o, const Vehicle& v){
	vector<int> temp=(v.getPosition());
	o<< "x: "<<temp[0]<<endl<<"y: "<<temp[1]<<endl<<"Fuel: "<<v.fuelLeft()<<endl;
	return o;
}
int main(){
	//vector<int> temp = {5,5};
	Vehicle a;
	Vehicle b(25.0,10,10);
	if (a.driveTo({50,50})){
		cout<<"Great!"<<endl;
	}
	else{
		a.refuel();
		if (a.driveTo({50,50})){
			cout<<"Got there on a full tank"<<endl;
		}
		else{
			cout<<"even a full tank can't get you there"<<endl;
		}
	}
	//temp = a.getPosition();
	//cout<<temp[0]<<", "<<temp[1]<<endl;
	
	cout<<a<<endl;
	//a.xPos=10; //illegal (can't access private member
	return 0;
}
