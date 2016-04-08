#pragma once
#include <ostream>
#include <memory>
#include <string>
#include <vector>
#include "ICombo.h"

using namespace std;

template<typename T>
struct Vec2
{
	Vec2(T x, T y) :X(x), Y(y)
	{}
	T X;
	T Y;
};

class ComboHorizontal;
class ComboVertical;
template<class T, typename enable_if<is_base_of<ICombo,T>::value || is_same<string, T>::value>::Type>
class Box
{
	T m_item;
public:
	Box(T item) :m_item(item) {};
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

/*
template<class T,typename enable_if<is_same<string,T>::value>::Type>
class Box
{
	vector<string> m_lines;
public:
	Box(string str = "");
	{
		auto previous = begin(str);
		while (previous != end(str))
		{
			auto found = find(previous, end(str), '\n');
			m_lines.emplace_back(previous, found);
			if (found != end(str))
				++found;
			previous = found;
		}
	}
	~Box() = default;
	Box(const Box & other);

	virtual unique_ptr<Box> clone()const;


	virtual Vec2<int> getExtent()const;
	virtual string drawLine(int line, const Box * parent = nullptr) const;

	virtual void draw(ostream & stream) const;

	friend ostream& operator<<(ostream & stream, const Box& container)
	{
		container.draw(stream);
		return stream;
	}



};*/

