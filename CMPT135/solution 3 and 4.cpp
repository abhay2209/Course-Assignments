#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

//Solution 3
void findAndReplace(char *phrase, char find, char replace, int startPos){
	if(startPos==strlen(phrase)) //base case
		return;
	if(phrase[startPos]==find)
		phrase[startPos]==replace;
	findAndReplace(phrase,find,replace,++startPos);

}

//Solution 4
int main(){
	//part 1
	ifstream  inFile("oldFile.txt");
	ofstream outFile("newFile.txt");
	if(inFile.is_open()&&outFile.is_open())
	{
		while(inFile)
		{
			string copy; // As we did in slide15 of week 7
			getline(inFile,copy);
			outFile<<copy<<endl;
		}
		inFile.close();
		outFile.close();
	}
	else
		cout<<"Files could not be opened"<<endl;


	//part 2
	// as we have to double space the same file, so e have to save 
	// the data inside the file and then print it on the same file 
	// without using ios:app

	ifstream inFile("oldFile.txt");
	string temp;
	if(inFile.is_open()){
	while(inFile){
		string copy;
		getline(inFile,copy);
		temp = temp + copy;
		// now to double space it
		temp=temp+"\n\n";
	}
	inFile.close();
	}
	else
		cout<<"no such file"<<endl;
	ofstream outFile("oldFile.txt");
		if(outFile.is_open()){
		outFile<<temp;
		outFile.close();
		}
		else
			cout<<"no such file"<<endl;

		//as we saved the above data aboce for part 3
		// as we have to print alternatively
		// i will save first two lines and then save them in a third string alternatively
		// and then overwrite it 
		//part 3
		ifstream inFile("oldFile.txt");
		string temp;
			if(inFile.is_open()){
				while(inFile){
				string line1,line2;
				getline(inFile,line1);
				getline(inFile,line2);
				temp = temp+line2; // saving 2 first adn then going to next line
				temp=temp+"\n";
				temp=temp+line1;
				}
				inFile.close();
			}
			else
				cout<<"does not exist"<<endl;
			
		ofstream outFile("oldFile.txt");
			if(outFile.is_open()){	
			outFile<<temp;
			outFile.close();
			}
			else
				cout<<"no such file"<<endl;
}








			




