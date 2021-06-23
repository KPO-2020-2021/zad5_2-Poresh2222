#pragma once

#include <stdlib.h>
#include <iostream>


class Menu {

    public:

        Menu();

        void MenuDef() {

            std::cout << "\n*****      Main Menu     *****\n" << std::endl;
            std::cout << "\n***** 1 - Object Manager *****\n" << std::endl;
            //std::cout << "***** 2 - Scene Manager  *****\n" << std::endl;
            std::cout << "***** 4 - Launch Manager *****\n" << std::endl;
            //std::cout << "***** $ - Settings       *****\n" << std::endl;
            std::cout << "\n***** 0 -   Exit         *****\n" << std::endl;

        }


        void MenuObj() {

            std::cout << "\n****    Object Menu    ****\n" << std::endl;
            std::cout << "**** 1 - Create Object ****\n" << std::endl;
            //std::cout << "**** 2 - Move Object   ****\n" << std::endl;
            //std::cout << "**** 3 - Rotate Object ****\n" << std::endl;
            std::cout << "**** 4 - Delete Object ****\n" << std::endl;
            //std::cout << "**** 5 - Get Object Inf****\n" << std::endl;
            std::cout << "\n**** 0 -   Back        ****\n" << std::endl;

        }

        void MenuObjC() {

            std::cout << "\n*** Select Object ***\n" << std::endl;
            std::cout << "*** 1 - Drone     ***\n" << std::endl;
            //std::cout << "*** 2 - Car       ***\n" << std::endl;
            std::cout << "\n*** 0 - Back      ***\n" << std::endl;

        }


        void MenuSce();

        void MenuSet();

        void MenuLau() {

            std::cout << "\n***         Launch Menu            ***\n" << std::endl;
            std::cout << "*** 1 - Landing Point for Drone    ***" << std::endl;
            std::cout << "*** 2 - Launch                     ***\n" << std::endl;
            std::cout << "\n*** 0 - Back                     ***\n" << std::endl;

        }


        void MenuTip(char option) {

            if (option == 'C') {

                std::cout << "\n??? StarPoint - Location of the central point of the object (pivot) ???" << std::endl;
                std::cout << "??? Object Size:                                                    ???\n" << std::endl;
                std::cout << "??? L - Lenght Drone                                                ???" << std::endl;
                std::cout << "??? W - Width  Drone                                                ???" << std::endl;
                std::cout << "??? H - Height Drone                                                ???\n" << std::endl;
                std::cout << "??? Note: Recomend values for drone -> 50 50 30                     ???" << std::endl;
                std::cout << "??? Note: Recomend Start Point -> 100 100 0 (X, Y, Z)               ???\n" << std::endl;
                std::cout << "??? !!!Warning!!!: Z value most be -> 0                             ???\n" << std::endl;

            } else if (option == 'M') {

                std::cout << "\n??? Number - is a serial number of object ???" << std::endl;
                std::cout << "??? Vector - values for translate         ???\n" << std::endl;

            } else if (option == 'L') {

                std::cout << "\n??? !!!Warning!!!: In Landing Point Z value most be -> 0            ???" << std::endl;
                std::cout << "??? If you add Landing points --> press Launch                      ???" << std::endl;
                std::cout << "??? If you want stop this program pres Ctrl + C :)                   ???\n" << std::endl;

            }

        }

        ~Menu();

};

Menu::Menu() {

    std::cout << "\n******  Start  Program  ******\n" << std::endl;

}

Menu::~Menu() {

    std::cout << "\n******  Finish Program  ******\n" << std::endl;

}