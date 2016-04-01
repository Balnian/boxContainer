#include <iostream>
#include"Box.h"
#include "ComboHorizontal.h"

using namespace std;

int main()
{
	Box b{ "allo \n sa vas?" };
	cout << b << endl;

	cout << endl << Box{ "" } << endl;

	cout << ComboHorizontal{ Box{ "asd \n asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } } << endl;

	cout << ComboHorizontal{ ComboHorizontal{ Box{ "asd \n asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } } , ComboHorizontal{ Box{ "asd \n asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } } } << endl;

}