#include<iostream>
using namespace std;
class Weapon
{
protected:
	int strength;
	char type;
public:
	Weapon(){
		strength = 0;
	}
	int modified;
	virtual void setPower(const int &power);
	virtual char return_type()const = 0;
	virtual int return_strength()const;
};

class Rock:public Weapon{
public:
	Rock()
	{
		type = 'r';
	}
	char return_type()const;
	bool battle(Weapon &input);
};

class Paper:public Weapon{
public:
	Paper(){
		type ='p';
	}
	char return_type()const;
	bool battle(Weapon &input);
};

class Scissor:public Weapon{
public:
	Scissor(){
		type = 's';
	}
	char return_type()const;
	bool battle(Weapon &input);
};

void Weapon::setPower(const int&power){
	strength = power;
}

int Weapon::return_strength()const{
	return strength;
}

char Paper::return_type()const{
	return type;
}

char Scissor::return_type()const{
	return type;
}

char Rock::return_type()const{
	return type;
}

bool Rock::battle(Weapon &input){
	if(input.return_type() == 'p'){
		modified =strength/2;
		input.modified=input.return_strength()*2;
	}

	else if(input.return_type()=='s'){
		modified =strength*2;
		input.modified=input.return_strength()/2;
	}
	return modified>input.modified;
}

bool Paper::battle(Weapon &input){
	if(input.return_type() == 's'){
		modified =strength/2;
		input.modified=input.return_strength()*2;
	}

	else if(input.return_type()=='r'){
		modified =strength*2;
		input.modified=input.return_strength()/2;
	}
	return modified>input.modified;
}

bool Scissor::battle(Weapon &input){
	if(input.return_type() == 'r'){
		modified =strength/2;
		input.modified=input.return_strength()*2;
	}
	else if(input.return_type()=='p'){
		modified =strength*2;
		input.modified=input.return_strength()/2;
	}
	return modified>input.modified;
}

int main(){
	system("pause");
	return 0;
}