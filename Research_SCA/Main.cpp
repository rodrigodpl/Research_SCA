#include <cstdio>
#include <string>
#include <time.h>

#include "Hero.h"

#define MAX_STR_LEN 50

// this is code solution has been left intentionally with bugs with the purpose of testing the functionality
// of the SCA tool CppCheck. Those errors are commented and listed below to ease their localization. 

// Error 1: Assign NONE, which is a signed int, to random class, which is an unsigned int
// Error 2: addHero() is called and allocates a new hero class, but deleteHero() is never called, causing a memory leak
// Error 3: Hero::getClass() could be const

// D&D hero creator

int main(int argc, char* args[])
{
	std::string hero_name;
	Hero* new_hero = nullptr;

	srand(time(NULL));

	printf("D&D Hero Creator: \n");

	while (hero_name.empty())
	{
		printf("Input your hero name\n");

		char name_buffer[MAX_STR_LEN];
		scanf_s("%s", name_buffer, MAX_STR_LEN);
		hero_name = name_buffer;
	}

	while (!new_hero)
	{
		printf("\nchoose your class: Warrior, Mage, Rogue, Random\n");

		char class_buffer[MAX_STR_LEN];
		scanf_s("%s", class_buffer, MAX_STR_LEN);
		std::string hero_class = class_buffer;
		
		if (hero_class == "Random" || hero_class == "Warrior" || hero_class == "Mage" || hero_class == "Rogue")
		{
			// Error 1: Assign NONE, which is a signed int, to random_class, which is an unsigned int
			unsigned int random_class = NONE;

			if (hero_class == "Random")
				random_class = rand() % 3;

			if (random_class == WARRIOR || hero_class == "Warrior")
				new_hero = new Hero(hero_name, WARRIOR);
			else if (random_class == MAGE || hero_class == "Mage")
				new_hero = new Hero(hero_name, MAGE);
			else if (random_class == ROGUE || hero_class == "Rogue")
				new_hero = new Hero(hero_name, ROGUE);
		}
		else
		{
			printf("\n invalid input!\n");
			hero_class.clear();
		}

	}

	new_hero->drawInfo();
	printf("\npress intro to quit");

	// Error 2: addHero is called and allocates a new hero class, but deleteHero is never called, causing a memory leak
	// delete new_hero;

	getchar();
	getchar();

	return 1;
}

