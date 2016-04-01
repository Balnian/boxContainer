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

	void draw(ostream & stream)const;

private:
	Vec2<int> getExtent()const override;

	void drawLine(ostream & stream, int line) const override;
};

