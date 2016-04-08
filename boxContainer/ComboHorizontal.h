#pragma once
#include "Box.h"
#include "ICombo.h"
using namespace std;

template<class T1,class T2>
class ComboHorizontal :
	public ICombo
{
	unique_ptr<Box<T1>> m_left;
	unique_ptr<Box<T2>> m_right;
public:
	ComboHorizontal(Box<T1>& left, Box<T2>& right);
	~ComboHorizontal();
	ComboHorizontal(const ComboHorizontal & other);

	unique_ptr<Box> clone()const;


	Vec2<int> getExtent()const override;
	string drawLine(int line, const Box * parent = nullptr) const override;



};

