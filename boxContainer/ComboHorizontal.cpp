#include "ComboHorizontal.h"
#include <algorithm>

ComboHorizontal::ComboHorizontal(Box& left, Box& right)
{
	m_left = left.clone();
	m_right = right.clone();
}

ComboHorizontal::~ComboHorizontal()
{
}

ComboHorizontal::ComboHorizontal(const ComboHorizontal & other)
{
	m_left = other.m_left->clone();
	m_right = other.m_right->clone();
}

unique_ptr<Box> ComboHorizontal::clone() const
{
	return unique_ptr<Box>(new ComboHorizontal(*this));
}

Vec2<int> ComboHorizontal::getExtent() const
{
	return Vec2<int>{m_left->getExtent().X + m_right->getExtent().X + 1, max(m_left->getExtent().Y, m_right->getExtent().Y)};
}

string ComboHorizontal::drawLine(int line, const Box * parent) const
{
	string temp;
	temp += m_left->drawLine(line,this);
	temp += "|";
	temp += m_right->drawLine(line,this);
	temp.resize(getExtent().X, ' ');
	return temp;
}
