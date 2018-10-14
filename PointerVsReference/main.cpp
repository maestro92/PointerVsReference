
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
want to look at the how are pointer vs reference treated in the compiler level
https://stackoverflow.com/questions/21145171/c-references-and-pointers-at-the-compiler-level


Visaul studio comes with Microsoft C++ compiler by default. You can also optionally install Clant/C2 - version of clang adopted by Microsoft


https://www.quora.com/What-compiler-does-Visual-Studio-use-for-C++
*/


void passByValue(int i, char c, int* p, float f)
{
	cout << "i = " << i << "\n";
	cout << "c = " << c << "\n";

	cout << "p = " << p << "\n";
	cout << "f = " << f << "\n";
}


void passByReference(int& i, char& c, int* & p, float& f)
{
	cout << "i = " << i << "\n";
	cout << "c = " << c << "\n";

	cout << "p = " << p << "\n";
	cout << "f = " << f << "\n";
}


void passByPointer(int* i, char* c, int** p, float* f)
{
	cout << "*i = " << *i << "\n";
	cout << "*c = " << *c << "\n";

	cout << "*p = " << *p << "\n";
	cout << "*f = " << *f << "\n";
}



void PtrVsRef()
{
	int i = 10;
	int *ptrToI = &i;
	int &refToI = i;


	cout << "i = " << i << "\n";
	cout << "&i = " << &i << "\n";

	cout << "ptrToI = " << ptrToI << "\n";
	cout << "*ptrToI = " << *ptrToI << "\n";
	cout << "&ptrToI = " << &ptrToI << "\n";

	cout << "refToI = " << refToI << "\n";
	//cout << "*refToNum = " << *refToI << "\n";
	cout << "&refToI = " << &refToI << "\n";
}



int main(int argc, char *argv[])
{	
//	PtrVsRef();

	int i = 1;
	char c = 'a';
	int* p = &i;
	float f = 1.1;

	passByValue(i, c, p, f);
	passByReference(i, c, p, f);
	passByPointer(&i, &c, &p, &f);
	return 0;
}










/*
http://www.cs.virginia.edu/~evans/cs216/guides/x86.html

	int i = 10;
009859D8  mov         dword ptr [i],0Ah

	int *ptrToI = &i;
009859DF  lea         eax,[i]
009859E2  mov         dword ptr [ptrToI],eax

	int &refToI = i;
009859E5  lea         eax,[i]
009859E8  mov         dword ptr [refToI],eax


	dword ptr
size directive. here DWORD ptr indicates 4 bytes 


	mov         dword ptr [ptrToI], eax
move the 32-bit integer representation of eax into the 4 bytes starting in ptrToI



*/
