#include<iostream>
using namespace std;
struct rational{
	int numerator; 
	int denominator; 
};
void reduce(rational* inputRational, rational* outputRational);
bool isEqual(rational &num1, rational& num2);
void reduce(rational* inputRational, rational* outputRational){
	//assuming that numerator is smaller than denominator
	// if it was bigger then i just need to add an if statement and run else for up until 'i' < denominator
	int numerator, denominator;
	numerator = inputRational->numerator;
	denominator=inputRational->denominator;
while(numerator>1){ // this is infinite loop

int count = 0; // this is the condition to break that loop as numerator will be reducable only if it is more than 1
  for(int i = 2;i<=numerator;i++) {  // if denominator is bigger, by adding just an if statement and running this same nested loop in else up until denominator will make it work
                                // i did't do it so i could give you space to understand in an ideal  case
	  if(numerator%i==0 && denominator%i==0) {// here i check all the possibilities that can divide

       numerator=numerator/i;
       denominator=denominator/i;
       break;
     }
     else
       count =1;
   }
     if(count==1)
        break;
}
outputRational->numerator=numerator;
outputRational->denominator=denominator;
      
}

bool isEqual(rational &num1, rational& num2){
	 rational num1copy, num2copy;
	 num1copy=num1;
	 num2copy=num2;
	 rational * num1p  = &num1;
	 rational* num2p = &num2;
	 reduce(num1p,&num1copy);
	 reduce(num2p,&num2copy);
	 if((num1copy.numerator==num2copy.numerator)&&(num1copy.denominator==num2copy.denominator))
		 return true;
	 return false;

}
int main() { 
bool result; rational num1, num2; cout << "Enter Details of Number 1 " << endl;
cout << "Enter Numerator :" << endl; cin >> num1.numerator; cout << "Enter Denominator :" << endl; cin >> num1.denominator; cout << "Enter Details of Number 2 " << endl;
cout << "Enter Numerator :" << endl; cin >> num2.numerator; cout << "Enter Denominator :" << endl; cin >> num2.denominator; result = isEqual(num1, num2); //to check rational 'num1' is equal to rational 'num2' 
if(result == true) 
cout << "Both rational numbers are equal" << endl; else cout << "Both rational numbers are not equal" << endl;
system("pause");
return 0;
}