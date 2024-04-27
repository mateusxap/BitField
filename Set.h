#pragma once
#include "Lamps.h"
class Set
{
	friend class Lamps;
	Lamps bitField;
	int size; //�������
public:

	Set(const Set& set);
	Set();
	Set(int sizeOfSet);
	Set(const Lamps& bitfield);
	operator Lamps();
	Set operator=(const Set& set);
	Set operator+(const Set& set);
	Set operator+(int element);
	Set operator*(const Set& set); //������ ������ ������� ������������ ������?
	Set operator~();
	bool operator==(const Set& set) const;
	void Input();
	void Show();

};

