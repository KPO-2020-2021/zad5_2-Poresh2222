#include <stdlib.h>
#include <iostream>
#include <thread>

#include "../inc/helpers/Menu.hh"
#include "../inc/Core.hh"
#include "../inc/helpers/lacze_do_gnuplota.hh"

int main() {

    char option = ' ', choiseOne = ' ', choiseTwo = ' ', choiseTre = ' ';

    bool tipsMode = true;

    int example, ObjectIndex = 0, objectIndex;


    Menu Menu;

    Core Core;

    Vector3I startCorner, sizeTab;
    
    Vector3I destination;


    PzG::LaczeDoGNUPlota Lacze;

    Lacze.Inicjalizuj();

    Lacze.ZmienTrybRys(PzG::TR_3D);
    
    Lacze.UstawZakresY(0, 500);
    Lacze.UstawZakresX(0, 500);
    Lacze.UstawZakresZ(0, 500);

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

                                            std::cout << "\n** Enter size values -> W L H **\n" << std::endl;
                                            std::cin >> sizeTab;

                                            Core.NewDrone(startCorner, sizeTab, Lacze);

                                            std::cout << ObjectIndex << " --> Drone Index" << std::endl;

                                            ObjectIndex +=1;

                                        break;

                                        case '2':

                                            //DLC

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

                            case '4':

                                std::cout << "*** Give number for object ***\n" << std::endl;
                                std::cin >> objectIndex;

                                Core.DelDrone(objectIndex - 1);

                                ObjectIndex = objectIndex - 1;

                                std::cout << ObjectIndex << " --> Drone Index (Dell)" << std::endl;

                            break;

                            case '5':

                                std::cout << "*** Give number for object ***\n" << std::endl;
                                std::cin >> objectIndex;

                                Core.GetDrone(objectIndex - 1);

                            break;

                        }

                    }

                break;

                case '4':

                    choiseTwo = ' ';

                    while(choiseTwo != '0') {

                        Menu.MenuLau();

                        std::cin >> choiseTwo;

                        switch(choiseTwo) {

                            case '0':

                                choiseTwo = '0';

                            break;

                            case '1':

                                std::cout << "*** Give number for Drone ***\n" << std::endl;
                                std::cin >> objectIndex;
                                std::cout << "*** Give destination for object ***\n" << std::endl;
                                std::cin >> destination;

                                Core.GetDrone(objectIndex).targetPosition = destination;

                            break;

                            case '2':

                                while(true)
                                { 
                                    Core.Update(0.1f);

                                    Lacze.Rysuj();

                                    using namespace std::chrono_literals;

                                    std::this_thread::sleep_for(100ms);

                                }

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