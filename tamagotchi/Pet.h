// Pet.h

#ifndef PET_H
#define PET_H

#include <string.h>
#include <iostream>
#include <unistd.h>
#include "Foods.h"
#include "Play.h"

using namespace std;

// reminder to later on add MOODS!

class Pet
{
private:
    string name;
    int age, hunger, happiness, energy, hygiene;

public:
    // constructor

    Pet()
    {
        setHunger(10);
        setHappiness(10);
        setEnergy(10);
        setHygiene(10);
        setAge(0);

        cout << "New pet created" << endl;
        cout << "\nStatus:" << endl;
        cout << "Age: " << getAge() << "\nHunger: " << getHunger() << " \nEnergy: " << getEnergy()
             << " \nHappiness: " << getHappiness() << " \nHygiene: " << getHygiene() << endl;
    }

    // setters

    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setHunger(int hunger)
    {
        this->hunger = hunger;
    }

    void setHappiness(int happiness)
    {
        this->happiness = happiness;
    }

    void setEnergy(int energy)
    {
        this->energy = energy;
    }

    void setHygiene(int hygiene)
    {
        this->hygiene = hygiene;
    }
    // getters
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    int getHunger()
    {
        return hunger;
    }
    int getHappiness()
    {
        return happiness;
    }
    int getEnergy()
    {
        return energy;
    }

    int getHygiene()
    {
        return hygiene;
    }

    // actions

    void feedPet(Foodtype foodType)
    {
        int amount = static_cast<int>(foodType);
        hunger += amount;

        // doesn't allow hunger to be larger than 10.
        if (hunger > 10)
        {
            hunger = 10;
        }

        // if hunger is between 8 and 10, increases happiness by 1
        if (hunger >= 8 && hunger <= 10)
        {
            happiness += 1;
        }

        // displays a text that the pet is eating for 1.5 seconds before continuing the action
        cout << name << " is eating.";
        for (int i = 0; i < 2; i++)
        {
            sleep(1);
            cout << ".";
        }
        sleep(1);
        // sleep(1.5);

        cout << "\nYou fed " << name << " with ";

        // display food given by player
        switch (foodType)
        {
        case Foodtype::BRIGADEIRO:
            cout << "some brigadeiro";
            break;
        case Foodtype::COXINHA:
            cout << "a coxinha";
            break;
        case Foodtype::WHEY:
            cout << "some whey";
            break;
        case Foodtype::PICANHA:
            cout << "a picanha";
            break;
        case Foodtype::PIZZA:
            cout << "some pizza";
        case Foodtype::SANDWICH:
            cout << "a sandwich";
        }
        cout << ".\nHunger level is now: " << hunger << endl;

        checkGameOver();
    }

    void playPet()
    {
        if (energy > 4)
        {
            cout << name << " is too tired to play!" << endl;
            return;
        }

        energy -= 2;
        happiness += 4;
    }

    void sleepPet()
    {
    }

    // time passing and game over
    void timePasses()
    {
        hunger -= 2;
        age += 1;
        happiness -= 1;
        hygiene -= 1;
        energy -= 1;

        if (hunger < 0)
        {
            hunger = 0;
        }

        printStats();

        checkGameOver();
    }

    void checkGameOver()
    {
        if (hunger == 0)
        {
            cout << "\nGame over! Your pet has starved to death. :(" << endl;
            cout << "\nYour pet lived for: " << age << " years." << endl;
            exit(0);
        }
        if (happiness == 0)
        {
            cout << "\nGame over! Your pet was too sad and ran away!" << endl;
            cout << "\nYou had your pet for: " << age << " years." << endl;
            exit(0);
        }
    }

    void printStats()
    {
        cout << "\n"
             << getName() << "'s stats: " << endl;
        cout << "\nHunger: " << getHunger() << "\nAge: " << getAge() << "\nHappiness: " << getHappiness() << "\nHygiene: " << getHygiene() << "\nEnergy: "
             << getEnergy() << endl;
    }
};

#endif // PET_H