#pragma once
#include "Box.h"

using namespace std;

class ComboHorizontal :
	public Box
{
	unique_ptr<Box> m_left;
	unique_ptr<Box> m_right;
public:
	ComboHorizontal(Box& left, Box& right);
	~ComboHorizontal();
	ComboHorizontal(const ComboHorizontal & other);

	unique_ptr<Box> clone()const;


	Vec2<int> getExtent()const override;
	string drawLine(int line, const Box * parent = nullptr) const override;



};

