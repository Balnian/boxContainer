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
	Box(const Box & other);

	unique_ptr<baseContainer> clone()const;


	Vec2<int> getExtent()const override;
	string drawLine(int line, const baseContainer * parent = nullptr) const override;



};

