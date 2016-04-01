#pragma once
#include "Box.h"
class ComboVertical :
	public Box
{
	unique_ptr<Box> m_up;
	unique_ptr<Box> m_down;
public:
	ComboVertical(Box& up, Box& down);
	~ComboVertical();
	ComboVertical(const ComboVertical & other);

	unique_ptr<Box> clone()const override;


	Vec2<int> getExtent()const override;
	string drawLine(int line, const Box * parent = nullptr) const override;

	virtual void draw(ostream & stream) const;

};

