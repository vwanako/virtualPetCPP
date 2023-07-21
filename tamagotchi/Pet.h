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
        cout << "\nInitial stats:" << endl;
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
        int currentHunger = getHunger();

        currentHunger += amount;
        setHunger(currentHunger);

        // doesn't allow hunger to be larger than 10.
        if (getHunger() > 10)
        {
            setHunger(10);
        }

        // if hunger is between 8 and 10, increases happiness by 1
        if (getHunger() >= 8 && getHunger() <= 10)
        {
            int currentHappiness = getHappiness();
            currentHappiness += 1;
            setHappiness(currentHappiness);
        }

        // displays a text that the pet is eating for 1.5 seconds before continuing the action
        cout << getName() << " is eating.";
        for (int i = 0; i < 2; i++)
        {
            sleep(1);
            cout << ".";
        }
        sleep(1);
        // sleep(1.5);

        cout << "\nYou fed " << getName() << " with ";

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
            break;
        case Foodtype::SANDWICH:
            cout << "a sandwich";
            break;
        default:
            cout << "ERROR: Feeding failed.";
            break;
        }
        cout << ".\nHunger level is now: " << getHunger() << endl;

        checkGameOver();
    }

    void playPet()
    {
        if (energy > 4)
        {
            cout << getName() << " is too tired to play!" << endl;
            return;
        }

        energy -= 2;
        happiness += 4;
    }

    void sleepPet()
    {
        int currentEnergy;

        // sets currentEnergy variable to the value of energy
        currentEnergy = getEnergy();
        // incrementes getEnergy variable and sets energy value through setEnergy
        currentEnergy += 5;
        setEnergy(currentEnergy);

        if (getEnergy() > 10)
        {
            setEnergy(10);
        }

        cout << getName() << " is sleeping.";
        for (int i = 0; i < 2; i++)
        {
            sleep(1);
            cout << ".";
        }

        sleep(2);

        cout << "\n"
             << getName() << " woke up!" << endl;

        sleep(1);

        if (getEnergy() <= 5)
        {
            cout << "\n"
                 << getName() << " is still tired. *Yawn*" << endl;
        }
        else if (getEnergy() >= 6 && getEnergy() <= 7)
        {
            cout << "\n"
                 << getName() << " feels fine." << endl;
        }
        else
        {
            cout << "\n"
                 << getName() << " feels well rested!!" << endl;
        }
    }

    // time passing and game over
    void timePasses()
    {
        int currHunger = getHunger(), currAge = getAge(), currHappiness = getHappiness(), currHygiene = getHygiene(), currEnergy = getEnergy();

        currHunger -= 2;
        currAge += 1;
        currHappiness -= 1;
        currHygiene -= 1;
        currEnergy -= 1;

        // hunger time based change
        if (currHunger > 10)
            setHunger(10);
        else if (currHunger < 0)
            setHunger(0);
        else
            setHunger(currHunger);

        // happiness time based change
        if (currHappiness > 10)
            setHappiness(10);
        else
            setHappiness(currHappiness);

        // energy time based change
        if (currEnergy > 10)
            setEnergy(10);
        else if (currEnergy < 0)
            setEnergy(0);
        else
            setEnergy(currEnergy);

        // hygiene time based change
        if (currHygiene > 10)
            setEnergy(10);
        else if (currHygiene < 0)
            setEnergy(0);
        else
            setEnergy(currHygiene);

        setAge(currAge);

        cout << "Time passes..." << endl;
        sleep(1);
        printStats();

        checkGameOver();
        checkEnergy();
    }

    void checkGameOver()
    {
        if (hunger == 0)
        {
            cout << "\nGame over! Your pet has starved to death. :(" << endl;
            cout << "\nYour pet lived for: " << getAge() << " years." << endl;
            exit(0);
        }
        if (happiness == 0)
        {
            cout << "\nGame over! Your pet was too sad and ran away!" << endl;
            cout << "\nYou had your pet for: " << getAge() << " years." << endl;
            exit(0);
        }
    }

    void checkEnergy()
    {
        if (getEnergy() <= 0)
        {
            cout << "\n"
                 << name << " has fainted due to exhaustion!\n"
                 << endl;
            sleepPet();
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