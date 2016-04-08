#include "Box.h"
#include <algorithm>


template<class T, typename enable_if<is_same<string, T>::value>::Type>
Box::Box(T str)
{
	if (is_same<string, T>::value)
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

	//sort(begin(m_lines), end(m_lines), [](string a, string b) {return b.length() < a.length(); });
}

template<class T, typename enable_if<is_base_of<ICombo, T>::value>::Type>
Box::Box(T container)
{

}

template<class T, typename enable_if<is_base_of<ICombo, T>::value || is_same<string, T>::value>::Type>
using Box = Box<T, typename enable_if<is_base_of<ICombo, T>::value || is_same<string, T>::value>::Type>

Box::~Box()
{
}

Box::Box(const Box & other)
{
	m_lines = other.m_lines;
}

unique_ptr<Box> Box::clone() const
{
	return unique_ptr<Box>(new Box(*this));
}

Vec2<int> Box::getExtent()const
{
	auto width = max_element(begin(m_lines), end(m_lines), [](const std::string& s1, const std::string& s2)
	{
		return s1.size() < s2.size();
	});
	return Vec2<int>(width != end(m_lines) ? width->size() : 0, m_lines.size());
}


string Box::drawLine(int line, const Box * parent) const
{
	string temp;
	if (line < m_lines.size())
		temp = m_lines[line];
	temp.resize(getExtent().X, ' ');
	return temp;
}

void Box::draw(ostream & stream) const
{
	stream << "+" << string(getExtent().X, '-') << "+" << endl;
	for (auto i = 0; i < getExtent().Y; ++i)
	{
		// Should draw the "|" with stream formating 
		stream << "|" << drawLine(i, nullptr) << "|" << endl;
	}
	stream << "+" << string(getExtent().X, '-') << "+" << endl;
}
