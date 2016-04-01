#pragma once

#include <ostream>
#include <string>
#include <memory>

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


	// Entry Point
	void draw(ostream & stream) const
	{
		stream << "+" << string(getExtent().X, '-') << "+" << endl;
		for (auto i = 0; i < getExtent().Y; ++i)
		{
			// Should draw the "|" with stream formating 
			stream << "|" << drawLine(i) << "|" << endl;
		}
		stream << "+" << string(getExtent().X, '-') << "+" << endl;
	}

	friend ostream& operator<<(ostream & stream, const baseContainer& container)
	{
		container.draw(stream);
		return stream;
	}

	virtual unique_ptr<baseContainer> clone()const = 0;

	virtual Vec2<int> getExtent()const = 0;
	// Subsequent Task
	virtual string drawLine(/*ostream & stream,*/ int line) const = 0;




};


