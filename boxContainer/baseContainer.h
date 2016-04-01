#pragma once

#include <ostream>

using namespace std;

template<typename T>
struct Vec2
{
	Vec2(T x, T y):X(x),Y(y)
	{}
	T X;
	T Y;
};

class baseContainer
{
public:
	baseContainer();
	~baseContainer();

	friend ostream& operator<<(ostream & stream, const baseContainer& container)
	{
		container.draw(stream);
		return stream;
	}
	// Entry Point
	virtual void draw(ostream & stream)const = 0;

private:
	virtual Vec2<int> getExtent()const = 0;

	// Subsequent Task
	virtual void drawLine(ostream & stream,int line) const =0;

};

//ostream& operator<<(ostream & stream, const baseContainer& container)

