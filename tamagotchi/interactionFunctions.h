// PetFunctions.h

#ifndef PETFUNCTIONS_H
#define PETFUNCTIONS_H

#include "Pet.h" // Include the Pet class header

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
    switch (option)
    {
    case 1:
        pet.feedPet(Foodtype::BRIGADEIRO);
        break;
    case 2:
        pet.feedPet(Foodtype::COXINHA);
        break;
    case 3:
        pet.feedPet(Foodtype::PIZZA);
        break;
    case 4:
        pet.feedPet(Foodtype::WHEY);
        break;
    case 5:
        pet.feedPet(Foodtype::SANDWICH);
        break;
    case 6:
        pet.feedPet(Foodtype::PICANHA);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

#endif // PETFUNCTIONS_H
