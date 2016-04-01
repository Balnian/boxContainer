#pragma once
#include "baseContainer.h"
class ComboVertical :
	public baseContainer
{
	unique_ptr<baseContainer> m_up;
	unique_ptr<baseContainer> m_down;
public:
	ComboVertical(baseContainer& up, baseContainer& down);
	~ComboVertical();
	ComboVertical(const ComboVertical & other);

	unique_ptr<baseContainer> clone()const override;


	Vec2<int> getExtent()const override;
	string drawLine(int line, const baseContainer * parent = nullptr) const override;

	virtual void draw(ostream & stream) const;

};

