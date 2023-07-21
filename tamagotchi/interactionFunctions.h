// PetFunctions.h

#ifndef PETFUNCTIONS_H
#define PETFUNCTIONS_H

#include "Pet.h" // Include the Pet class header
#include <map>

int chooseFood()
{
    int option;
    cout << "Choose what food to give to pet. (HP = hunger points) \n*****MENU****** " << endl;
    cout << "1: Brigadeiro.... 2HP \n2: Coxinha.... 3HP \n3: Pizza.... 4HP \n4: Whey.... 5HP \n5: Sandwich.... 6HP \n6: Picanha.... 8HP" << endl;

    cin >> option;

    return option;
}

void PerformUserAction(Pet &pet, int option)
{
    static const map<int, Foodtype> foodMap =
        {
            {1, Foodtype::BRIGADEIRO},
            {2, Foodtype::COXINHA},
            {3, Foodtype::PIZZA},
            {4, Foodtype::WHEY},
            {5, Foodtype::SANDWICH},
            {6, Foodtype::PICANHA}

        };

    // while the number read in chooseFood is not a valid option in the foodMap, prints that the choice is invalid and asks the user to choose again.
    while (foodMap.find(option) == foodMap.end())
    {
        cout << "Invalid food choice. Please try again." << endl;
        option = chooseFood();
    }

    pet.feedPet(foodMap.at(option));
}

#endif // PETFUNCTIONS_H
