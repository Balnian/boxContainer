#pragma once
#include <ostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct Vec2
{
	Vec2(T x, T y) :X(x), Y(y)
	{}
	T X;
	T Y;
};

class Box
{
	vector<string> m_lines;
public:
	Box(string str = "");
	~Box();
	Box(const Box & other);

	virtual unique_ptr<Box> clone()const;


	virtual Vec2<int> getExtent()const ;
	virtual string drawLine(int line, const Box * parent = nullptr) const ;

	virtual void draw(ostream & stream) const;

	friend ostream& operator<<(ostream & stream, const Box& container)
	{
		container.draw(stream);
		return stream;
	}



};

