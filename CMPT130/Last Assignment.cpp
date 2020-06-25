#include <iostream> 
 
using namespace std; 
 
typedef char* charPointer; 
 
int stringLength(const charPointer s) 
{  
	int length = 0;
	while(s[length] != '\0')
	{
		length++;
	}
	return length;
    //returns the number of printable characters in s 
} 
 
int countChars(const charPointer s, const char ch)
{
	int count = 0, size = stringLength(s);
	for(int i= 0;i<size;i++)
	{
		if(s[i]==ch)
	    count++;
	}
	return count;
   //returns the number of times the character ch is found in s 
} 
 
int findChar(const charPointer s, const char ch, const int startIndex, const int lastIndex) 
{
	/* returns the first index where the character ch is found in s starting from startIndex (inclusive)
  upto lastIndex (exclusive)  If ch is not found in s in the interval, it returns -1  
  This function must first validate both the startIndex and lastIndex. 
  That is, if lastIndex > stringLength(s) or startIndex < 0 it must return -1 */
	if(lastIndex > stringLength(s) || startIndex < 0)
		return -1;
	for(int i = 0;i<lastIndex;i++)
{		
	if(s[i]==ch)
	return i ;
}
	return -1;

} 
 
void rotateString(charPointer s, const int r)
{  /* Rotate the characters of s by r units  
   If r > 0, rotate the characters of s to the left  
   If r < 0, rotate the characters of s to the right  
   Please note the value of r can be any integer even larger than the length of s  
   For example,   
   "asmara" rotated to the left by 0 becomes "asmara"   
   "asmara" rotated to the left by 1 becomes "smaraa"   
   "asmara" rotated to the left by 2 becomes "maraas"   
   "asmara" rotated to the left by 3 becomes "araasm"   
   "asmara" rotated to the left by 4 becomes "raasma"    
   "asmara" rotated to the left by 5 becomes "aasmar"    
   "asmara" rotated to the left by 6 becomes "asmara"    
   "asmara" rotated to the left by 7 becomes "smaraa"    
   "asmara" rotated to the left by 8 becomes "maraas"    
   and etc…
   */ 
	int sign,r2 ;
	char temp;
	if(r>0)
	sign=1;
	else
	{
		sign= -1;
		r2=-1*r;
	}
	int size = stringLength(s);
	if(sign==1)
	{
		for(int i=0;i<r;i++)
		{
			temp=s[0];
			for(int j = 1;j<size;j++)
			{
				s[j-1]=s[j];
			}
			s[size-1]=temp;
		}
	}
	else
	{
		for(int i=0;i<r2;i++)
		{
			temp=s[size-1];
			for(int j = size - 1;j>0;j--)
			{
				s[j]=s[j-1];
			}
			s[0]=temp;
		}
	}

} 
void append(charPointer &s, const char ch) 
{ 
	int size = stringLength(s)+2;
	charPointer M = new char[size];
	for(int i= 0;i<size-2;i++)
	{
		M[i]=s[i];
	}
	M[size-2]=ch;
	M[size-1]='\0';
	s=M;

   /* Appends the character ch to the c-string s.  
   That is ch is added to the end of s  
   The parameter s is assumed to be a dynamic array (NOT a static one) */
} 
 
void append(charPointer &s1, const charPointer s2)
{  int sizeS1=stringLength(s1), sizeS2=stringLength(s2);
  int sizeTotal = sizeS1 + sizeS2 + 1, k =0;
  charPointer M = new char [sizeTotal];
  for(k=0;k<sizeS1;k++)
  {
	 M[k]=s1[k];
  }
  for(;k<sizeTotal-1;k++)
  {
	  M[k]=s2[k];
  }
  M[k]='\0';
  s1=M;

 /* Appends all the characters of s2 to s1  
   The parameter s1 is assumed to be a dynamic array (NOT a static one) */
} 
 
void removeAll(charPointer &s, const char ch)
{ 
	int countch=countChars(s,ch);
	int NewSize= stringLength(s) - countch + 1;
	int size=stringLength(s), k =0;
	charPointer M= new char[size];
	for(int i = 0;i< NewSize-1;i++)
    {
	for(int j=i+k;j<size;j++)
	{
		if(s[j]!=ch)
		{
		M[i]=s[j];
		break;
		}
		k++;
	}
	}
	M[NewSize-1]='\0';
	s=M;
	/* remove all the occurences of the character ch from the c-string s  
   The parameter s is assumed to be a dynamic array (NOT a static one) */
} 
 
charPointer zigzagMerge(const charPointer s1, const charPointer s2)
{ int k = 0, l=0, sizeS1=stringLength(s1), sizeS2 = stringLength(s2), i = 0;
int totalSize = sizeS1+sizeS2+1;
charPointer m = new char[totalSize];
if(sizeS1>=sizeS2)
	for(i=0;i<totalSize-1;i++)
	{
		if(i%2==0 &&i<(2*sizeS2)
		{
			m[i]=s1[k];
			k++;
		}
		else if(i%2!=0 && i<(2*sizeS2))
		{
			m[i]=s2[l];
			l++;
		}
		else
		{
		m[i]=s1[k];
		k++;
		}
	}
else if(sizeS1<sizeS2)
for(i=0;i<totalSize-1;i++)
{
	if(i%2==0&& i<(28sizeS1))
	{
		m[i]=s1[k];
		k++;
	}
	else if(i%2!=0 && i<(2*sizeS2))
	{
		m[i]=s2[l];
		l++;
	}
	else
	{
		m[i]=s2[k];
		k++;
	}
}
m[i]='\0';
return m;
}
	
	
	/*  create and return a new c-string by merging (putting in one) s1 and s2 in zigzag form.  
   That is     
   first character of the new c-string is the first character of s1   
   second character of the new c-string is the first character of s2    
   third character of the new c-string is the second character of s1   
   fourth character of the new c-string is the second character of s2   
   fifth character of the new c-string is the third character of s1    
   sixth character of the new c-string is the third character of s2    
   etc When either s1 or s2 reaches to its end, the remaining characters of the other are appended to the new c-string   
   Example, zigzagMerge of "abc" and "defgh" will be "adbecfgh"  */ 






 
bool isAnagram(const charPointer s1, const charPointer s2)
{ 
	int sizeS1=stringLength(s1), sizeS2=stringLength(s2);
	if(sizeS1>sizeS2||sizeS1<sizeS2)
	return false;
	for(int i = 0; i<sizeS1;i++)
	{
		if(countChars(s1,s1[i])!=countChars(s2,s1[i]))
		return false;
	}
	return true;


	/* returns true if s1 and s2 contain same distinct characters appearing same number of times in both s1 and s2; 
  otherwise returns false That is, this function returns true if s1 and s2 are permutations (re-arrangements) of each other. 
  For example "CMPT" and "PCTM" are anagrams but "CPMT" and "CMPTM" are not anagrams */ 
} 
 
bool isSubString(const charPointer s1, const charPointer s2)
{  
	int sizeS1= stringLength(s1), sizeS2= stringLength(s2);
	if(sizeS1>sizeS2)
		return false;
	for(int i=0,j=0;(i<sizeS2&&j<sizeS1);i++)
	{
		if(s2[i]==s1[j])
		j++;
		else
			j=0;
		if(j==sizeS1)
			return true;
	}
	return false;

	/* returns true is s1 is a substring of s2 otherwise returns false  Definition: s1 is a substring of s2 if s1 is found in s2. 
   That is all characters of s1 are found TOGETHER in s2 in the SAME ORDER as they appear in s1 
   Example "set" is a substring of "massachussettes" But "ets" is not substring of "massachussettes" */ 
} 
 
int countWords(const charPointer s) 
{

	int wordCount = 0;
	int size = stringLength(s);
	if((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z'))
		wordCount++;
	for(int i = 0;i<size-1;i++)
	{
	if((s[i] == ' ')&&(s[i+1]!=' '))
			wordCount++;
	}
	return wordCount;

	/*   Given a c-string that contains some words separated by spaces,   
   return the number of words in the c-string.   
   In this case, a word means some characters with no space in between.   
   Example: If the c-string parameter is "What    a     nice           problem".    
   Then you see that there are FOUR words in this c-string, namely        
   1. What      2. a       3. nice      4. problem   
   Your function then must return 4 
 
  For simplicity, 
  1. Assume that there are no spaces at the beginning or at the end of the c-string 
  2. But a word can be separated from another word by one or more space   
  2. Assume the parameter does not contain any punctuation marks such      
  as comma, semicolon or full stop.  */ } 
 
int main() 
{  /*  This main program is designed to test the functions you need to implement.  
   You should NOT remove any line of code from this main program.  
   But you may add more test code in the main program if you like.  */ 
 
 //Test stringLength function  
	cout << endl;  
	char s1[] = "massachussettes";  
	cout << s1 << " has " << stringLength(s1) << " characters" << endl; 
 
 //Test countChars function  
	cout << endl;  
	char ch = 's';  
	int c = countChars(s1, ch);  
	cout << ch << " appears " << c << " times in " << s1 << endl; 
 
 //Test findChar function  
	cout << endl;  
	int index = findChar(s1, ch, 10, 14);  
	if (index == -1)   
	cout << ch << " is not found in " << s1 << " between indexes [10, 14)" << endl;  
	else   
	cout << ch << " is found at index " << index << " in " << s1 << " between indexes [10, 14)" << endl; 
 
 //Test rotateString function  
	cout << endl;  
	char temp1[] = "massachussettes";  
	rotateString(temp1, 2);  
	cout << s1 << " rotated 2 units to the left becomes " << temp1 << endl;  
	char temp2[] = "massachussettes";  
	rotateString(temp2, -19);  
	cout << s1 << " rotated 19 units to the right becomes " << temp2 << endl; 
//Test append function (appending a character to c-string)  
	cout << endl;  
	charPointer s2 = new char[1];  
	s2[0] = '\0';  
	cout << "Given the c-string " << s2 << endl;  
	ch = 'a';  
	append(s2, ch);  
	cout << "\tAppending " << ch << " results to " << s2 << endl;  
	ch = 'b';  
	append(s2, ch);  
	cout << "\tAppending " << ch << " results to " << s2 << endl; 
 
 //Test append function (appending a c-string to a c-string)  
cout << endl;  
cout << "Appending " << s1 << " to " << s2 << ", we get ";  
append(s2, s1);  
cout << s2 << endl; 
 
 //Test removeAll function  
cout << endl;  
ch = 'e';  
cout << "Removing all occurences of " << ch << " from " << s2 << ", we get ";  
removeAll(s2, ch);  cout << s2 << endl;  
ch = 't';  
cout << "Removing all occurences of " << ch << " from " << s2 << ", we get ";  
removeAll(s2, ch);  
cout << s2 << endl;  
ch = 's';  
cout << "Removing all occurences of " << ch << " from " << s2 << ", we get ";  
removeAll(s2, ch);  
cout << s2 << endl; 
 
//Test zigzagMerge function  
cout << endl;  
charPointer s3 = zigzagMerge(s1, s2);  
cout << "The zigzag merge of " << s1 << " and " << s2 << " is " << s3 << endl; 
 
//Test isAnagram function  
cout << endl;  
char s4[] = "htsemsaesuatscs";  
bool flag = isAnagram(s1, s4);  
if (flag)   
cout << s1 << " and " << s4 << " are anagrams" << endl;  
else   
cout << s1 << " and " << s4 << " are not anagrams" << endl; 
 
//Test isSubString function  
cout << endl;  
flag = isSubString(s1, s4);  
if (flag)   
cout << s1 << " is a substring of " << s4 << endl;  
else   
cout << s1 << " is not a substring of " << s4 << endl;    
char s5[] = "abort";  
char s6[] = "abcabodefaborhuhabortabunny";  
flag = isSubString(s5, s6);  
if (flag)   
cout << s5 << " is a substring of " << s6 << endl; 
else   
cout << s5 << " is not a substring of " << s6 << endl; 
 
 //Test countWords function  
cout << endl;  
char s7[] = "";  
c = countWords(s7);  
cout << "There are " << c << " words in " << s7 << endl;  
char s8[] = "Test";  
c = countWords(s8);  
cout << "There are " << c << " words in " << s8 << endl;  
char s9[] = "Nice       one";  
c = countWords(s9);  
cout << "There are " << c << " words in " << s9 << endl;  
char s10[] = "This      is a nice     assignment and    hopefully an interesting    as well";  
c = countWords(s10);  
cout << "There are " << c << " words in " << s10 << endl; 
 
 //Delete dynamically allocated memories  
delete[] s2;  
delete[] s3; 
 
system("Pause");  
return 0; 
} 
 