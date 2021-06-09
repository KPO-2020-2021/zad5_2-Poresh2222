#pragma once

#include <stdlib.h>
#include <iostream>


class Menu {

    public:

        Menu();

        void MenuDef() {

            std::cout << "\n*****      Main Menu     *****\n" << std::endl;
            std::cout << "\n***** 1 - Object Manager *****\n" << std::endl;
            std::cout << "***** 2 - Scene Manager  *****\n" << std::endl;
            std::cout << "***** $ - Settings       *****\n" << std::endl;
            std::cout << "***** 4 - Launch Manager *****\n" << std::endl;
            std::cout << "\n***** 0 -   Exit         *****\n" << std::endl;

        }


        void MenuObj() {

            std::cout << "\n****    Object Menu    ****\n" << std::endl;
            std::cout << "**** 1 - Create Object ****\n" << std::endl;
            std::cout << "**** 2 - Move Object   ****\n" << std::endl;
            std::cout << "**** 3 - Rotate Object ****\n" << std::endl;
            std::cout << "**** 4 - Delete Object ****\n" << std::endl;
            std::cout << "\n**** 0 -   Back        ****\n" << std::endl;

        }

        void MenuObjC() {

            std::cout << "\n*** Select Object ***\n" << std::endl;
            std::cout << "*** 1 - Drone     ***\n" << std::endl;
            std::cout << "*** 2 - Car       ***\n" << std::endl;
            std::cout << "\n*** 0 - Back      ***\n" << std::endl;

        }


        void MenuSce();

        void MenuSet();

        void MenuLau();


        void MenuTip(char option) {

            if (option == 'C') {

                std::cout << "\n??? Star Point - Location of the first point of the object [0,0,0] ???" << std::endl;
                std::cout << "??? Object Size - Total maximum size                               ???\n" << std::endl;

            } else if (option == 'M') {

                std::cout << "\n??? Number - is a serial number of object ???" << std::endl;
                std::cout << "??? Vector - values for translate         ???\n" << std::endl;

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