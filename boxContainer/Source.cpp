#include <iostream>
#include"Box.h"
#include "ComboHorizontal.h"
#include "ComboVertical.h"

using namespace std;

int main()
{
// Manière à la Patrice
	Box b;
	cout << b << endl;
	string texte = R"(Man! Hey!!!
ceci est un test
multiligne)";
	string aut_texte = "Ceci\nitou, genre";
	Box b0{ texte };
	Box b1{ aut_texte };
	cout << b0 << endl << b1 << endl;
	ComboVertical cv{ b0, b1 };
	cout << Box{ cv } << endl;
	ComboHorizontal ch{ b0, b1 };
	cout << Box{ ch } << endl;
	ComboVertical cvplus{ Box{ cv }, Box{ ch } };
	cout << Box{ cvplus } << endl;
	ComboHorizontal chplus{ Box{ cv }, Box{ ch } };
	cout << Box{ chplus } << endl;
	ComboVertical cvv{ Box{ chplus }, Box{ "coucou" } };
	cout << Box{ cvv } << endl;
	cout << Box{
		ComboHorizontal{
		Box{ "a\nb\nc\nd\ne" },
		Box{
		ComboVertical{
		Box{ "allo" }, Box{ "yo" }
	}
	}
	}
	} << endl;
	cout << Box{
		ComboHorizontal{ Box{ "Yo" }, Box{} }
	} << endl;
	cout << Box{
		ComboHorizontal{ Box{}, Box{ "Ya" } }
	} << endl;
	cout << Box{
		ComboHorizontal{ Box{}, Box{} }
	} << endl;
	cout << Box{
		ComboVertical{ Box{}, Box{} }
	} << endl;
	cout << Box{
		ComboVertical{ Box{ "Yip" }, Box{} }
	} << endl;
	cout << Box{
		ComboVertical{ Box{}, Box{ "Yap" } }
	} << endl;
	
	//Manière plus cool à la Francis (pas de Box inutile)
	/*
	Box b{ "allo \n sa vas?" };
	cout << b << endl;

	cout << endl << Box{} << endl;

	cout << ComboHorizontal{ Box{ "asd \n asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } } << endl;

	cout << ComboHorizontal{ ComboHorizontal{ Box{ "asd \n asdsdasddasadds\n sdsds \n sdfsdffsdds" } , Box{ "allo \n sa vas?" } } , ComboHorizontal{ Box{ "asd \n asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } } } << endl;
	
	cout << ComboVertical{ ComboVertical{ Box{ "asd  asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } } , ComboHorizontal{ Box{ "asd \n asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } } } << endl;

	cout << ComboHorizontal{ ComboVertical{ Box{ "asd \n asdsdasddasadds\n sdsds" } , Box{ "allo \n sa vas?" } },ComboHorizontal{ Box{ "asd \n asdsdasddasadds "} , Box{ "allo \n sa vas?" } } } << endl;
	*/
	
}