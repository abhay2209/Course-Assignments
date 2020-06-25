#include<iostream>
using namespace std;
int getSize(const char *B)
{
	int length = 0;
		while(B[length]!='\0'){
			length++;
		}
		return length;
}
class CMPT135_String{
	private:
	static const char NULL_TERMINATOR = '\0';// to avoid writing '\0'
	int length;
	int *buffer;  // length +1 characters including NULL
	private:
		char *getBuffer() const; //this one is to return the buffer itself
	public:
		//Constructors
		CMPT135_String();
		CMPT135_String( const char &c);
		CMPT135_String(const char *buffer);
		CMPT135_String(const CMPT135_String &s);
		//Destructor
		~CMPT135_String();
		//Getter Member function
		int getLength()const;
		char getCharAt( const int&index)const;
		//Setter member function
		void setCharAt(const int &index, const char&c);
		void append(const char &c); 


};


CMPT135_String::CMPT135_String(){
	length = 0;
	buffer =new char[length+1];
	buffer[length]=NULL_TERMINATOR;
}

CMPT135_String::CMPT135_String( const char &c){
	length = 1;
	buffer = new char[length+1];
	buffer[0]=c;
	buffer[1]=NULL_TERMINATOR;
}

CMPT135_String::CMPT135_String(const char *buffer){
	length = getSize(buffer);
	this->buffer=new char[length+1];
	for(int i=0;i<length;i++){
		this->buffer[i]=buffer[i]; 
	}   
	this->buffer[length]=NULL_TERMINATOR;
}

CMPT135_String::CMPT135_String(const CMPT135_String &s){
    length=s.length;
	buffer = new char[length+1];
	for(int i=0;i<length;i++){
		buffer[i]=s.buffer[i];
	}
	buffer[length]=NULL_TERMINATOR;
}

CMPT135_String::~CMPT135_String(){
if(buffer!=0)
delete[] buffer;
}

int CMPT135_String::getLength()const{
	return length;
}

char CMPT135_String::getCharAt(const int&index)const{
	if((index>=0)&&(index<length))
		return buffer[index];
	return NULL_TERMINATOR;
}

void CMPT135_String::setCharAt(const int &index, const char&c){
	if((index>=0)&&(index<length))
		buffer[index]= c;
}

char* CMPT135_String::getbuffer()const{
	return this->buffer;
}

void CMPT135_String::append(const char &c){  
	char* temp = new char[length+2];
	for(int i = 0;i<length;i++)
		temp[i]=buffer[i];
	temp[length]=c;
	temp[length+1]=NULL_TERMINATOR;
	delete[] buffer;
	length = length+1;
	buffer = new char[length+1];
	buffer=temp;
	delete[] temp;
}


int main() {
cout << "\tFraser International College, CMPT 135 2018-02" << endl;
cout << "\tAssignment 1 Test Bed" << endl;
cout << "\t==============================================" << endl;
cout << endl << endl;
cout << "Test: default constructor and output stream operator" << endl;
CMPT135_String s1, s2, s3;
cout << "s1 = " << s1 << ", s2 = " << s2 << ", and s3 = " << s3 << endl;
cout << endl;
cout << "Test: non-default constructor" << endl;
CMPT135_String s0 = 'Y';
cout << "CMPT135_String s0 = 'Y'; results to s0 = " << s0 << endl;
cout << endl;
cout << "Test: non-default constructor" << endl;
char *buffer = "CMPT135"; // might need to replace this with const char *buffer = "CMPT135";
CMPT135_String s4(buffer);
cout << "char *buffer = \"CMPT135\"; CMPT135_String s4(buffer); result to s4 = " << s4 << endl;
cout << endl;
cout << "Test: copy constructor" << endl;
CMPT135_String s5 = s4;
cout << "The statement CMPT135_String s5 = s4; results to s5 = " << s5 << endl;
cout << endl;
cout << "Test: length getter function" << endl;
CMPT135_String s6;
cout << "s6 is empty string with length = " << s6.getLength() << endl;
s6 = "Nice";
cout << "After the statement s6 = \"Nice\";, s6 now has length = " << s6.getLength() << endl;
cout << endl;
cout << "Test: getCharAt getter function" << endl;
cout << "The statement s6.getCharAt(0); gives the character " << s6.getCharAt(0) << endl;
cout << "The statement s6.getCharAt(s6.getLength()); gives the character "
 << s6.getCharAt(s4.getLength()) << endl;
cout << "The statement s6.getCharAt(s6.getLength()+10); gives the character "
 << s6.getCharAt(s4.getLength()+10) << endl;
cout << endl;
cout << "Test: setCharAt and append setter functions" << endl;
cout << "s4 is " << s4 << endl;
cout << "The statement s4.setCharAt(s4.getLength()-1, 'X');, results to:" << endl;
s4.setCharAt(s4.getLength()-1, 'X');
cout << "\ts4 = " << s4 << endl;
cout << "The statement s4.setCharAt(s4.getLength(), 'Y');, results to:" << endl;
s4.setCharAt(s4.getLength(), 'Y');
cout << "\ts4 = " << s4 << endl;
cout << "The statement s4.setCharAt(s4.getLength()+10, 'Y');, results to:" << endl;
s4.setCharAt(s4.getLength()+10, 'Y');
cout << "\ts4 = " << s4 << endl;
s4.append('?');
syste("pause");
return 0;
}

