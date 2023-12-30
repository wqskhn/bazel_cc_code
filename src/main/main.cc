#include <iostream>
#include "src/lib/solution.h"
#include <vector>

using namespace std;

int main()
{
    int choice;
    vector<Material> originalMaterial;
    vector<ProductionShareDropDown> productionShareDropDown;
    vector<Material> actualMaterial;

    bool lifeOfMine = true;

    while (lifeOfMine)
    {
        cout << "*******************************\n";
        cout << " 1 - Enter the Production Share Drop Down Rules.\n";
        cout << " 2 - Enter the Original Material.\n";
        cout << " 3 - Calculate actual according to rules.\n";
        cout << " 4 - Output result for Actual Material Production\n";
        cout << " 5 - Exit.\n";
        cout << " Enter your choice and press return: ";
        cin >> choice;

        Solution solution;

        switch (choice)
        {
        case 1:
            solution.rulesProductionShareDropDown(productionShareDropDown);
            break;

        case 2:
            solution.enterOriginalMaterial(originalMaterial);
            break;

        case 3:
            solution.calculateActualMaterial(originalMaterial, productionShareDropDown, actualMaterial);
            break;

        case 4:
            solution.outputResult(actualMaterial);
            break;

        case 5:
            cout << "End of Program.\n";
            lifeOfMine = false;
            break;

        default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            break;
        }
    }

    // cout << solution.printHelloWorld() << endl;

    return EXIT_SUCCESS;
}
