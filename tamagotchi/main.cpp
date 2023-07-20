#include <iostream>
#include <string>
#include <unistd.h>
#include "Pet.h"
#include "interactionFunctions.h"

using namespace std;

int main()
{
    Pet MyPet;
    int choice, foodOption;

    MyPet.setName("MyPet");

    cout << "\nPet's name is " << MyPet.getName() << endl;

    for (int i = 0; i < 10; i++)
    {

        cout << "What should you do next? " << endl;
        cout << "\n1: Feed \n2: Play \n3: Sleep \n4: Clean \n5: Quit game\n ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            foodOption = chooseFood();
            PerformUserAction(MyPet, foodOption);
            break;
        case 5:
            return 0;
        }

        MyPet.timePasses();
        sleep(2);
    }

    return 0;
}