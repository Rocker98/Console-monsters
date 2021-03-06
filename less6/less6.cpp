// less6.cpp: определяет точку входа для консольного приложения.
//



#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;




class Monster
{
public:
	enum MonsterType
	{
		DRAGON,
		GOBLINE,
		OGRE,
		ORC,
		SCELLETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONTERS_TYPES
	};
private:
	MonsterType m_type;
	string m_name;
	int m_HP;
public:
	Monster(MonsterType type, string name, int HP) : m_type{ type }, m_name{ name }, m_HP{ HP }
	{

	}
	std::string getTypeString() const
	{
		switch (m_type)
		{
		case MonsterType::DRAGON: return "dragon";
		case MonsterType::GOBLINE: return "goblin";
		case MonsterType::OGRE: return "ogre";
		case MonsterType::ORC: return "orc";
		case MonsterType::SCELLETON: return "skeleton";
		case MonsterType::TROLL: return "troll";
		case MonsterType::VAMPIRE: return "vampire";
		case MonsterType::ZOMBIE: return "zombie";
		}

		return "Error!";
	}

	void print() const
	{
		std::cout << m_name << " is the " << getTypeString() << " that has " << m_HP << " health points." << '\n';
	}

};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		static string names[6] = { "Chak","Bill","Jack","Eddie","Smith","Bob" };
		Monster::MonsterType tempType = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONTERS_TYPES - 1));
		
		string tempName = names[getRandomNumber(0, 5)];
		int tempHP = getRandomNumber(1, 100);

		Monster jack(tempType, tempName, tempHP);
		return jack;
	}

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // используем static, так как это значение нужно вычислить только один раз
																					 // равномерно распределяем вычисление числа в нашем диапазоне
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}


};


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	
		Monster m = MonsterGenerator::generateMonster();
		m.print();
		Monster b = MonsterGenerator::generateMonster();
		b.print();
		Monster c = MonsterGenerator::generateMonster();
		c.print();
		Monster d = MonsterGenerator::generateMonster();
		d.print();

	return 0;
}

