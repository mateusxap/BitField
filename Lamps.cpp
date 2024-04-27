#include "Lamps.h"



unsigned int Lamps::MaskFormation(int rightBit)
{
	return (1 << (rightBit - 1));
	/*try
	{
		if (!(1 <= rightBit <= 32)) throw 123;
		unsigned int arrayk = 1;
		return (arrayk << (rightBit - 1));
	}
	catch (int x)
	{
		std::cout << "\nВведен неверный номер бита для создания маски. Номер бита должен быть в диапозоне от 1 до 32 включительно.";
	}*/
}

ElementIndexes Lamps::FindElement(int number)
{
	try
	{
		if (!(0 <= number <= countOfDevices)) throw 123;
		ElementIndexes result;
		result.indexInArray = number >> 5;
		result.indexInByte = number & 31;
		return result;
	}
	catch (int x)
	{
		std::cout << "\nВведен неверный номер устройства. Номер должен быть в диапозоне от 1 до " << countOfDevices << " включительно.";
	}

}

Lamps::Lamps()
{
	countOfDevices = 1;
	arraySize = (countOfDevices + 31) >> 5; //5 из 2^5
	array = new unsigned int[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = 0;
	}
}

Lamps::Lamps(int count) : countOfDevices(count)
{
	try
	{
		if (countOfDevices <= 0) throw 123;
		arraySize = (countOfDevices + 31) >> 5; //5 из 2^5
		array = new unsigned int[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			array[i] = 0;
		}
	}
	catch (int x)
	{
		std::cout << "\nОшибка! Количесвто лампоччек должно быть больше нуля";
	}

}

Lamps::~Lamps()
{
	delete[] array;
}

void Lamps::Show()
{
	for (int i = 1; i <= countOfDevices; i++)
	{
		ElementIndexes indexes = FindElement(i);
		std::cout << ((array[indexes.indexInArray] & ((this)->MaskFormation(indexes.indexInByte))) >> (indexes.indexInByte - 1)) << ' ';
	}
}




Lamps::Lamps(const Lamps& lmp)
{

	arraySize = lmp.arraySize;
	countOfDevices = lmp.countOfDevices;
	array = new unsigned int[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = lmp.array[i];
	}
}

Lamps& Lamps::operator=(const Lamps& lmp)
{
	if (this != &lmp)
	{
		if (arraySize != lmp.arraySize)
		{
			delete[] array;
			arraySize = lmp.arraySize;
			countOfDevices = lmp.countOfDevices;
			array = new unsigned int[arraySize];
		}
		else if (countOfDevices != lmp.countOfDevices)
			countOfDevices = lmp.countOfDevices;
		for (int i = 0; i < arraySize; i++)
		{
			array[i] = lmp.array[i];
		}
	}
	return (*this);
}

bool Lamps::operator==(const Lamps& lmp) const
{
	bool answer = true;
	if (countOfDevices != lmp.countOfDevices) return false;
	else
	{
		for (int i = 0; i < arraySize; i++)
		{
			if (array[i] != lmp.array[i])
			{
				answer = false;
				break;
			}
		}
	}
	return answer;
}

void Lamps::TurnOn(int rightBit)
{
	ElementIndexes indexes;
	indexes = FindElement(rightBit);
	array[indexes.indexInArray] = array[indexes.indexInArray] | this->MaskFormation(indexes.indexInByte);
}


void Lamps::TurnOff(int rightBit)
{
	ElementIndexes indexes;
	indexes = FindElement(rightBit);
	array[indexes.indexInArray] = (array[indexes.indexInArray]) & (~this->MaskFormation(indexes.indexInByte)); //  побитовой инвертирование ~this->MaskFormation(indexes.indexInByte)
}

bool Lamps::DeviceStatus(int rightBit)
{
	ElementIndexes indexes;
	indexes = FindElement(rightBit);
	return ((array[indexes.indexInArray] & this->MaskFormation(indexes.indexInByte)) >> indexes.indexInByte - 1);
}

void Lamps::Input()
{
	std::cout << "\nЛюбой символ кроме 0 и 1 - конец ввода\n";

	int answer;

	for (int i = 1; i <= countOfDevices; i++)
	{
		std::cout << "Введите состоние устройства номер " << i << ": ";
		std::cin >> answer;
		ElementIndexes indexes = FindElement(i);
		if (answer == 1) array[indexes.indexInArray] = array[indexes.indexInArray] | this->MaskFormation(indexes.indexInByte);
		else if (answer == 0) continue;
		else
		{
			break;
		}
	}


}


Lamps Lamps::operator&&(const Lamps& lmp)
{
	Lamps res;
	if (countOfDevices > lmp.countOfDevices)
	{
		res = lmp;
	}
	else
	{
		res = (*this);
	}
	for (int i = 0; i < res.arraySize; i++)
	{
		res.array[i] = array[i] & lmp.array[i];
	}
	return res;
}

Lamps Lamps::operator||(const Lamps& lmp)
{
	Lamps res;
	if (countOfDevices < lmp.countOfDevices)
	{
		res = lmp;
	}
	else
	{
		res = (*this);
	}
	int i = 0;
	for (i; i < std::min(arraySize, lmp.arraySize); i++)
	{
		res.array[i] = array[i] | lmp.array[i];
	}
	return res;
}
