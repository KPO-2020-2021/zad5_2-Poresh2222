#include <stdlib.h>
#include <iostream>

#include "../inc/helpers/Menu.hh"
#include "../inc/Core.hh"

int main() {

    char option = ' ', choiseOne = ' ', choiseTwo = ' ', choiseTre = ' ';

    bool tipsMode = true;

    int example;


    Menu Menu;

    Core Core;

    Vector3I startCorner, sizeTab;


    try {

        while(choiseOne != '0') {

            Menu.MenuDef();

            std::cin >> choiseOne;

            switch(choiseOne) {

                case '0':

                    choiseOne = '0';

                break;

                case '1':

                    choiseTwo = ' ';

                    while(choiseTwo != '0') {

                        Menu.MenuObj();

                        std::cin >> choiseTwo;

                        switch(choiseTwo) {

                            case '0':

                                choiseTwo = '0';

                            break;

                            case '1':

                                choiseTre = ' ';

                                while(choiseTre != '0') {

                                    Menu.MenuObjC();

                                    std::cin >> choiseTre;

                                    switch(choiseTre) {

                                        case '0':

                                            choiseTre = '0';

                                        break;

                                        case '1':

                                            if (tipsMode == true) {option = 'C'; Menu.MenuTip(option);}

                                            std::cout << "** Enter start point -> X Y Z **\n" << std::endl;
                                            std::cin >> startCorner;

                                            std::cout << "\n** Enter size values -> L W H **\n" << std::endl;
                                            std::cin >> sizeTab;

                                            Core.NewDrone(startCorner, sizeTab);

                                        break;

                                        case '2':

                                            //coming soon

                                        break;

                                    }

                                }

                            break;

                            case '2':

                                if (tipsMode == true) {option = 'M'; Menu.MenuTip(option);}

                                std::cout << "*** Give number for object ***\n" << std::endl;
                                std::cin >> example;

                                std::cout << "*** Give vector -> X Y Z   ***\n" << std::endl;
                                std::cin >> example;

                                //core.move()

                            break;

                        }

                    }

                break;

            }

        }
    
    } catch(const std::runtime_error& e) {

        std::cerr << "Something go wrong" << e.what() << '\n';

        exit(1);
    
    }

}