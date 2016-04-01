#pragma once
#include "baseContainer.h"

using namespace std;

class ComboHorizontal :
	public baseContainer
{
	unique_ptr<baseContainer> m_left;
	unique_ptr<baseContainer> m_right;
public:
	ComboHorizontal(baseContainer& left, baseContainer& right);
	~ComboHorizontal();
	ComboHorizontal(const ComboHorizontal & other);

	unique_ptr<baseContainer> clone()const;


	Vec2<int> getExtent()const override;
	string drawLine(int line, const baseContainer * parent = nullptr) const override;



};

