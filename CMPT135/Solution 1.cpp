#include<iostream>
#include<string>
using namespace std;

class Animal
{
protected:     // hiding name and age from main, s.t it can be accessed by child class
	string name;
	int age; 

public:  // creation of appriopriate member functions 
    Animal()
	{
		animalCount++;
	}
	~Animal()
	{
		animalCount--;
	}
	void setAge(const int age);
	void setName(const string name);
	int getAge()const;
	string getName()const;
	virtual void speak()const;
	static int animalCount; // to count the total number of objects of type animal
	static void count()
	{
		cout<<animalCount<<endl;
	}
	void birthday();
	void introduce()const;
};
int Animal::animalCount=0;
void Animal::speak()const // As i couldn't create abstract class until i reach part 5
{
	cout<<"I can't speak"<<endl;
	
}

class Cat:public Animal
{
public:
	Cat()
	{
		cout<<"Cat created"<<endl;
	}
	~Cat()
	{
		cout<<"Cat destroyed"<<endl;
	}
	void speak()const;
	
};

class Dog:public Animal
{
public:
	Dog()
	{
		cout<<"Dog created"<<endl;
	}
	~Dog()
	{
		cout<<"Dog destroyed"<<endl;
	}
	void speak()const;
	virtual void action()const;
};

class PetDog:public Dog
{
public:
	PetDog()
	{
		cout<<"Dog created"<<endl;
	}
	~PetDog()
	{
		cout<<"Dog destroyed"<<endl;
	}
	void speak()const;
	void action()const;
};

class StrayDog:public Dog
{
public:
	StrayDog()
	{
		cout<<"Dog created"<<endl;
	}
	~StrayDog()
	{
		cout<<"Dog destroyed"<<endl;
	}
	void speak()const;
	void action()const;
};

void Animal::setAge(const int age) //setter{
this->age = age;
}

void Animal::setName(const string name) //setter{
	this->name=name;
}

int Animal::getAge()const  //getter{
	return age;
}

string Animal::getName()const   //getter{
	return name;
}

void Animal::birthday()    //member function{
	age++;
	cout<<"Happy Birthday"<<endl;
}

void Animal::introduce()const //member functiion{
	cout<<"My name is "<<name<<" and age is "<<age<<endl;
}

void Cat::speak()const{
	cout<<"meow meow"<<endl;
}

void Dog::speak()const{
	cout<<"barks barks"<<endl; // dpg barks
}

void PetDog::speak()const{
	cout<<"bark bark"<<endl; // pet dog is same as parent dog
}

void StrayDog::speak()const{
	cout<<"woof woof"<<endl; // the Stray dog is different 
}

void Dog::action()const{
	cout<<"perform no action";
}

void PetDog::action()const{
	cout<<"fetch a stick"<<endl;
}

void StrayDog::action()const{
	cout<<"chase cars"<<endl;
}


//Answer to question1 part5 (by polymorphism) 
// Abstract class is created below

/*class Animal
{
protected:     // hiding name and age from main, s.t it can be accessed by child class
	string name;
	int age; 

public:  // creation of appriopriate member functions 
    Animal()
	{
		animalCount++;
	}
	~Animal()
	{
		animalCount--;
	}
	void setAge(const int age);
	void setName(const string name);
	int getAge()const;
	string getName()const;
	virtual void speak()const = 0;
	static int animalCount; // to count the total number of objects of type animal
	static void count()
	{
		cout<<animalCount<<endl;
	}
	void birthday();
	void introduce()const;
};
int Animal::animalCount=0;

class Cat:public Animal
{
public:
	Cat()
	{
		cout<<"Cat created"<<endl;
	}
	~Cat()
	{
		cout<<"Cat destroyed"<<endl;
	}
	void speak()const;
	
};

class Dog:public Animal
{
public:
	Dog()
	{
		cout<<"Dog created"<<endl;
	}
	~Dog()
	{
		cout<<"Dog destroyed"<<endl;
	}
	void speak()const;
	virtual void action()const=0;
};

class PetDog:public Dog
{
public:
	PetDog()
	{
		cout<<"Dog created"<<endl;
	}
	~PetDog()
	{
		cout<<"Dog destroyed"<<endl;
	}
	void speak()const;
	void action()const;
};

class StrayDog:public Dog
{
public:
	StrayDog()
	{
		cout<<"Dog created"<<endl;
	}
	~StrayDog()
	{
		cout<<"Dog destroyed"<<endl;
	}
	void speak()const;
	void action()const;
};

void Animal::setAge(const int age) //setter
{
this->age = age;
}
void Animal::setName(const string name) //setter
{
	this->name=name;
}
int Animal::getAge()const  //getter
{
	return age;
}
string Animal::getName()const   //getter
{
	return name;
}
void Animal::birthday()    //member function
{
	age++;
	cout<<"Happy Birthday"<<endl;
}
void Animal::introduce()const //member functiion
{
	cout<<"My name is "<<name<<" and age is "<<age<<endl;
}

void Cat::speak()const
{
	cout<<"meow meow"<<endl;
}
void Dog::speak()const
{
	cout<<"barks barks"<<endl; // dpg barks
}
void PetDog::speak()const
{
	cout<<"bark bark"<<endl; // pet dog is same as parent dog
}
void StrayDog::speak()const
{
	cout<<"woof woof"<<endl; // the Stray dog is different 
}

void PetDog::action()const
{
	cout<<"fetch a stick"<<endl;
}

void StrayDog::action()const
{
	cout<<"chase cars"<<endl;
}
*/


int main()
{ //I am able tocreate objects of animal and dog because 
  //they are not abstract classes but still have virtual funstions
	Animal** arr=new Animal*[7];
	Cat c1, c2 , c3;
	Dog d1,d2;
	PetDog pd1;
	StrayDog sd1;
	arr[0]= &c1;
	arr[1]= &c2;
	arr[2]= &c3;
	arr[3]= &d1;
	arr[4]= &d2;
	arr[5]= &pd1;
	arr[6]= &sd1;
	for(int i=0 ;i<7;i++)
	    arr[i]->speak();
	delete[] arr;
	 // works fine due to virtual functions but if i don't have a pointer type
	 // it prints the message of thespeak fnction in class Animal
system("pause");
return 0;
}