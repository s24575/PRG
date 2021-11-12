#include <string>
#include <iostream>
#define Use(x) x.use_on(orc);

struct Creature
{
	std::string name;
	int hp;

	Creature(std::string n, int hp) : name(n), hp(hp) {}
};

struct Item
{
	virtual void use_on(Creature&) = 0;
	virtual int strenght() const = 0;
};

struct Weapon : Item
{
	Weapon() { int strenght(); }

	void use_on(Creature& x)
	{
		x.hp -= strenght();
		std::cout << x.name << " has " << x.hp << " HP left\n";
	}
};

struct Sword : Weapon
{
	int strenght() const
	{
		return 15;
	}
};

struct Axe : Weapon
{
	int strenght() const
	{
		return 20;
	}
};

struct Potion : Item
{
	int i;

	Potion() { int strenght(); i = 0; }

	void use_on(Creature& x)
	{
		if (i < 1)
		{
			x.hp += strenght();
			++i;
		}
		else
			std::cout << "I'm out of healing potions." << '\n';
		std::cout << x.name << " has " << x.hp << " HP left\n";
	}
};

struct Health_potion : Potion
{
	int strenght() const
	{
		return 30;
	}
};

int main()
{
	Creature orc("Grogg", 100);
	Sword Excalibur;
	Axe hatchet;
	Health_potion hp_potion;
	Use(Excalibur);
	Use(hatchet);
	Use(hp_potion);
	Use(hp_potion);
}