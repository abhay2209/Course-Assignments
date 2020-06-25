#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand(time(0));
	int temp=0 ,ctot=0,htot=0,p;
	char choice = 'r';
	for(;(ctot<100)&&(htot<100);)
	{
	    cout<<"Human Playing..."<<endl;
		while(choice=='r')
		{
		p=rand()%6+1;
		cout<<"Rolling: "<<p<<endl;
		if(p==1)
		{
		cout<<"\tOpps!Got busted. No score on this turn"<<endl;
		choice='h';
		temp =  0;
		}
		else if(p>1)
		{
		temp= temp+p;
		cout<<"\tTurn total: "<<temp<<endl;
		cout<<"\tHuman Total Score (if opted to hold): "<<htot+temp<<endl;
			do
			{
			cout<<"Roll again or Hold> (r/h): ";
			cin>>choice;
			
		    }while((choice!=104)&&(choice!=114));
		}
		}
		htot=temp+htot;
		temp=0;
		p=7;
		cout<<endl<<endl;
		if(htot<100)
		{
			cout<<"Computer Playing..."<<endl;
		}
		while((temp<20)&&(p!=1)&&(htot<100))
		{
		p=rand()%6+1;
		cout<<"Rolling: "<<p<<endl;
		if(p==1)
		{
		cout<<"\tOpps! Got busted. No score on this turn"<<endl;
		temp=0;
		}
		else if(p>1)
		{
		temp=temp+p;
		cout<<"\tTurn total:"<<temp<<endl;
		cout<<"\tComputer Total Score (is opted to hold): "<<ctot+temp<<endl;
		}
		}
		ctot=ctot+temp;
		temp=0;
		cout<<endl<<endl;
		choice='r';
		}
		if(htot>=100)
		{
		cout<<"Human Player Won!"<<endl;
		}
		else
		{
		cout<<"Computer Player Won!"<<endl;
		}
		system("pause");
		return 0;
}





            




