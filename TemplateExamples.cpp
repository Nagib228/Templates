#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>


template <typename HP, typename LVL>
class Enemy {
private:
	HP health;
	LVL level;
	std::string name;
public:
	Enemy(HP health, LVL level, std::string name) {
		if (level > 100 || level <= 0) throw std::exception("Incorect level\n");
		else if (health < 0) throw std::exception("Incorrect health points\n");
		this->health = health;
		this->level = level;
		this->name = name;
	}

	HP getHealth() const {
		return health;
	}

	LVL getLvl() const {
		return level;
	}

	std::string getName() const {
		return name;
	}

	void setHealth(HP a) {
		if (health < 0) return;
		this->health = a;
	}

	void setLvl(LVL a) {
		if (level > 100 || level <= 0) return;
		this->level = a;
	}

	virtual void print() const {
		std::cout << "\n--------------------\n";
		std::cout << "Enemy: " << name << "\n";
		std::cout << "Health: " << health << "\n";
		std::cout << "Level: " << level << "\n";
	}

};

enum Special_Abilities_Zombie {
	LIFESTEAL,
	REBORN,
	RAGE,
	SUMMON_ZOMBIES,
};

template <typename HP, typename LVL>
class Zombie : public Enemy<HP, LVL> {
private:
	Special_Abilities_Zombie ability;
public:
	Zombie(HP health, LVL level, std::string name, Special_Abilities_Zombie ability) : Enemy<HP, LVL>(health, level, name) {
		this->ability = ability;
	}

	std::string getAbility() const {
		if (ability == Special_Abilities_Zombie::LIFESTEAL) {
			return "LIFESTEAL";
		}
		else if (ability == Special_Abilities_Zombie::REBORN) {
			return "REBORN";
		}
		else if (ability == Special_Abilities_Zombie::RAGE) {
			return "RAGE";
		}
		else if (ability == Special_Abilities_Zombie::SUMMON_ZOMBIES) {
			return "SUMMON ZOMBIES";
		}
		else {
			return "NO SPECIAL ABILITY";
		}
	}

	void changeSpecialAbility(Special_Abilities_Zombie a) {
		this->ability = a;
	}

	void print() const override {
		Enemy<HP,LVL>::print();
		std::cout << "Special ability: " << getAbility() << "\n";
	}
};

enum Special_Abilities_Goblins {
	POISON_FLASK,
	HEALING_POTION,
	EVASION,
	MASS_ATTACK
};

template <typename HP, typename LVL>
class Goblin : public Enemy<HP, LVL> {
private:
	Special_Abilities_Goblins ability;
public:
	Goblin(HP health, LVL level, std::string name, Special_Abilities_Goblins ability) : Enemy<HP, LVL>(health, level, name) {
		this->ability = ability;
	}

	std::string getAbility() const {
		if (ability == Special_Abilities_Goblins::EVASION) {
			return "EVASION";
		}
		else if (ability == Special_Abilities_Goblins::POISON_FLASK) {
			return "POISON FLASK";
		}
		else if (ability == Special_Abilities_Goblins::HEALING_POTION) {
			return "HEALING POTION";
		}
		else if (ability == Special_Abilities_Goblins::MASS_ATTACK) {
			return "MASS ATTACK";
		}
		else {
			return "NO SPECIAL ABILITY";
		}
	}

	void print() const override {
		Enemy<HP, LVL>::print();
		std::cout << "Special ability: " << getAbility() << "\n";
	}
	
};

int main() {
	try {
		Enemy<float, int> someEnemy(500, 20, "Enemy");
		Zombie<int, int> monster(200, 5, "Zombie", Special_Abilities_Zombie::LIFESTEAL);
		Goblin<double, short> g(228.1488, 8, "Goblin", Special_Abilities_Goblins::HEALING_POTION);
		someEnemy.print();
		monster.print();
		g.print();
	}
	catch (std::exception err) {
		std::cout << err.what();
	}
}