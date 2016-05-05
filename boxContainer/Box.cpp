#include "Box.h"
#include <algorithm>


Box::Box(string str):m_isText(true)
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

	//sort(begin(m_lines), end(m_lines), [](string a, string b) {return b.length() < a.length(); });
}
Box::Box(baseContainer & item) :m_isText(false)
{
	m_item = item.clone();
}

Box::~Box()
{
}

Box::Box(const Box & other)
{
	m_isText = other.m_isText;
	if (other.m_isText)
	{
		m_lines = other.m_lines;
	}
	else
	{
		m_item = other.m_item->clone();
	}

}

unique_ptr<baseContainer> Box::clone() const
{
	return unique_ptr<baseContainer>(new Box(*this));
}

Vec2<int> Box::getExtent()const
{
	if (m_isText)
	{
		auto width = max_element(begin(m_lines), end(m_lines), [](const std::string& s1, const std::string& s2)
		{
			return s1.size() < s2.size();
		});
		return Vec2<int>(width != end(m_lines) ? width->size() : 0, m_lines.size());

	}
	else
	{
		return m_item->getExtent();
	}
	
}

string Box::drawLine(int line, const baseContainer * parent) const
{
	if (m_isText)
	{
		string temp;
		if (line < m_lines.size())
			temp = m_lines[line];
		temp.resize(getExtent().X, ' ');
		return temp;
	}
	else
	{
		return m_item->drawLine(line, parent);
	}
}
