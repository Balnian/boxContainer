#pragma once
#include <string>
#include <vector>
#include "baseContainer.h"

using namespace std;

class Box :
	public baseContainer
{
	vector<string> m_lines;
public:
	Box(string str);
	~Box();

	unique_ptr<baseContainer> clone()const;


	Vec2<int> getExtent()const override;
	string drawLine(/*ostream & stream,*/ int line) const override;



};

