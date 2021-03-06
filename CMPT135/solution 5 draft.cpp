//Consider the following C++ template class.

#include <iostream>
using namespace std;

template <typename T, int length>
class SortedList{
private:
	ostream& put(ostream& out) const;
	T list[length];
	int size;
public:
	SortedList()
	{size = 0;}
	void insert(T item);
	friend ostream& operator<<(ostream& out, const SortedList& list)
	{return list.put(out);}
};
template<typename T, int length>
void SortedList<T, length>::insert(T item){
	if (size == length){
		printf("List Full"); return; }
	int i = size - 1;
	while (i >= 0 && item < list[i]){
		list[i+1] = list[i];
		i--;
	}
	list[i+1] = item;
	size++;
}
template<typename T, int length>
ostream& SortedList<T, length>::put(ostream& out) const{
	for (int i = 0; i < size; i++)
		cout << list[i] << " " ;
	cout << endl;
	return out;
}
/*int main()
{
	int values[] = {5, 1, 7, 8, 11, 2};
	SortedList<int, 10> list;
	for (int i = 0; i < 6; i++)
		list.insert(values[i]);
	cout << list;
	return 0;
}
The class SortedList cannot be instantiated for any arbitrary type. For example, consider the following instantiation for a wrapper integer class.
*/
class Int{
public:
        Int(){}
	Int(int i) {this->i = i;}
	friend ostream& operator<<(ostream& out, const Int &ob);

	bool  operator<(const Int &ob)const{
		if(i<ob.i)
			return true;
		return false;
	}
		bool  operator>(const Int &ob)const{
		if(i>ob.i)
			return true;
		return false;
	}

    Int& operator=(const Int &ob){
		i=ob.i;
		return *this;
	}

private:
	int i;	
};


ostream& operator<<(ostream& out, const Int &ob){
		out <<ob.i<<endl;
		return out;
	}

int main(){
	Int values[] = {Int(5), Int(1), Int(7), Int(8), Int(11), Int(2)};
	SortedList<Int, 10> list;
	for (int i = 0; i < 6; i++)
		list.insert(values[i]);
	cout << list;
	return 0;
}
//Explain why the second implementation fails. What must be added to that class, so this program will compile? Provide the correct program.
// this is because of operators such as < > = which are not overloaded, hence overloading them will make the program work