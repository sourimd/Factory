#include <iostream>

class Animal{
protected:
	int noOfLegs;
	bool hasTail;
public:
	virtual int getNoOfLegs() = 0;
	virtual bool getHasTail() = 0;

	virtual void setNoOfLegs(int l) = 0;
	virtual void setHasTail(bool b) = 0;

	Animal(int leg, bool tail): noOfLegs(leg), hasTail(tail) {}
};

class Tiger : public Animal{
public:
	int getNoOfLegs(){ return noOfLegs; }
	bool getHasTail(){ return hasTail; }

	void setNoOfLegs(int l){ noOfLegs = l; }
	void setHasTail(bool b){ hasTail = b; }

	Tiger(int leg, bool tail): Animal(leg, tail){}
	~Tiger(){}
};

class Ostrich : public Animal{
public:
	int getNoOfLegs(){ return noOfLegs; }
	bool getHasTail(){ return hasTail; }

	void setNoOfLegs(int l){ noOfLegs = l; }
	void setHasTail(bool b){ hasTail = b; }

	Ostrich(int leg, bool tail): Animal(leg, tail){}
	~Ostrich(){}
};

class FactoryFarm{
private:
	FactoryFarm(){}
public:
	static FactoryFarm * getInstance(){
		static FactoryFarm * instance = new FactoryFarm();
		return instance;
	}
	Animal * getAnimal(std::string type){
		if( type == "tiger"){
			return new Tiger(4, true);
		}
		else if(type == "ostrich"){
			return new Ostrich(2, false);
		}
		else{
			return NULL;
		}
	}
};

int main(){
	
	FactoryFarm * ff = FactoryFarm::getInstance();
	Animal * ani = ff->getAnimal("tiger");
	std::cout << "No of legs " << ani->getNoOfLegs() << std::endl; 
	Animal * ost = ff->getAnimal("ostrich");
	std::cout << "No of legs " << ost->getNoOfLegs() << std::endl;
	return 0;
}