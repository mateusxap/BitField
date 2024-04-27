#include "Set.h"
Set::Set(const Set& set)
{
	if (this != &set)
	{
		bitField = set.bitField;
		size = set.size;
	}
}

Set::Set() : bitField(), size(0)
{

}

Set::Set(int sizeOfSet) : size(sizeOfSet), bitField(sizeOfSet) //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
{
	/*size = sizeOfSet;
	Lamps field(sizeOfSet);
	bitField = field; */      //если так писать то создастьс€ конструктор по умолчанию
}

Set::Set(const Lamps& bitfield) : size(bitfield.countOfDevices), bitField(bitfield)
{

}

Set::operator Lamps()
{
	return (bitField);
}

Set Set::operator=(const Set& set)
{
	if (this != &set)
	{
		bitField = set.bitField;
		size = set.size;
	}
	return (*this);
}

Set Set::operator+(const Set& set)
{
	Set res;
	if (size == 0)
		res = set;
	else if (set.size == 0)
		res = *(this);
	else
	{
		res.size = std::max(size, set.size);
		res.bitField = bitField || set.bitField;
	}
	return res;
}

Set Set::operator+(int element)
{
	Set set;
	if (element > size)
		set.size = element;
	else
		set.size = size;
	Lamps tmpBitField(set.size);
	tmpBitField.TurnOn(element);
	set.bitField = (*this).bitField || tmpBitField;

	return set;
}

Set Set::operator*(const Set& set)
{
	Set setTmp;
	setTmp.size = std::min((*this).size, set.size);
	setTmp.bitField = (this)->bitField && set.bitField;
	return setTmp;
}

bool Set::operator==(const Set& set) const
{
	return ((this)->bitField == set.bitField);
}

Set Set::operator~()
{
	Set set(size);
	//Set set();
	//set.size = size;
	for (int i = 1; i <= size; i++)
	{
		if ((this)->bitField.DeviceStatus(i) == false)
			set.bitField.TurnOn(i);
	}
	return set;
}

void Set::Input()
{
	std::cout << "\n¬ведите размер юниверса: ";
	do
	{
		std::cin >> size;
		std::cout << "\n";
	} while (size < 0);
	Lamps bitF(size);
	int tmp = 0;
	std::cout << "\n-1 выход из ввода";
	while (true)
	{
		std::cout << "\n¬ведите элемент множества: ";
		std::cin >> tmp;
		if (tmp == -1) break;
		else if (tmp > size) break;
		bitF.TurnOn(tmp);
	}

	bitField = bitF;
}

void Set::Show()
{
	std::cout << "\n{  ";
	for (int i = 1; i <= size; i++)
	{
		if ((this)->bitField.DeviceStatus(i) == true)
		{
			std::cout << i << "  ";
		}
	}
	std::cout << "} ";
}

