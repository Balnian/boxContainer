#include <iostream>
#include"Box.h"

using namespace std;

int main()
{
	Box b{ "allo \n sa vas?" };
	cout << b << endl;

	cout << endl << Box{ "" } << endl;
}