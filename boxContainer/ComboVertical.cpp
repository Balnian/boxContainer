#include "ComboVertical.h"
#include <algorithm>


ComboVertical::ComboVertical(baseContainer & up, baseContainer & down)
{
	m_up = up.clone();
	m_down = down.clone();
}


ComboVertical::~ComboVertical()
{
}

ComboVertical::ComboVertical(const ComboVertical & other)
{
	m_up = other.m_up->clone();
	m_down = other.m_down->clone();
}

unique_ptr<baseContainer> ComboVertical::clone() const
{
	return unique_ptr<baseContainer>(new ComboVertical(*this));
}

Vec2<int> ComboVertical::getExtent() const
{
	return Vec2<int>{max(m_up->getExtent().X, m_down->getExtent().X), m_up->getExtent().Y + m_down->getExtent().Y + 1};
}

string ComboVertical::drawLine(int line, const baseContainer * parent) const
{
	string temp;
	if (line <= m_up->getExtent().Y)
	{
		temp = m_up->drawLine(line, this);
	}
	else if (line == m_up->getExtent().Y + 1)
	{
		/*if (parent != nullptr)
		{
			temp = string(parent->getExtent().X , '-');
		}
		else
		{
			temp = string(getExtent().X, '-');
		}*/
		temp = string(parent != nullptr ? parent->getExtent().X : getExtent().X, '-');
	}
	else if (line > m_up->getExtent().Y + 1)
	{
		temp = m_down->drawLine(line - (m_up->getExtent().Y + 1),this);
	}
	temp.resize(parent != nullptr ? parent->getExtent().X : getExtent().X, ' ');

	return temp;
}

void ComboVertical::draw(ostream & stream) const
{
	stream << "+" << string(getExtent().X, '-') << "+" << endl;
	for (auto i = 0; i < getExtent().Y; ++i)
	{
		// Should draw the "|" with stream formating 
		stream << "|" << drawLine(i, this) << "|" << endl;
	}
	stream << "+" << string(getExtent().X, '-') << "+" << endl;
}
