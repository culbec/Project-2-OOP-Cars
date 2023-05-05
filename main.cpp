#include <iostream>
#include "Headers/UI.h"
#include "Headers/Repository.h"
#include "Headers/Spalatorie.h"
#include "Headers/Service.h"
#include "Headers/tests.h"

int main() {
    runTests();
    std::cout << "Tests ok!\n";

    /*WashingList washingList;
    while (true) {
        int option;
        std::cout << "1. Memory Repository\n2. File Repository\n";
        std::cout << "Your option: ";
        std::cin >> option;

        if (option == 1) {
            RepoLab carRepo;
            Service carServiceMem(carRepo, washingList);
            UI uiMem(carServiceMem);
            uiMem.uiRun();
            break;
        } else if (option == 2) {
            try {
                FileRepository fileRepo("cars.txt");
                Service carServiceFile(fileRepo, washingList);
                UI uiFile(carServiceFile);
                uiFile.uiRun();
            } catch (RepositoryException &rE) {
                std::cout << rE.getMessage();
            }
            break;
        } else {
            std::cout << "Invalid option!\n";
            break;
        }
    }*/
    return 0;
}