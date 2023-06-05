#include "fruit-shop.hpp"
#include "Apple.hpp"

#include <iostream>

FruitShop::FruitShop()
{
    state = FruitShopState::Welcome;
}

FruitShop::~FruitShop()
{
}

void FruitShop::Run()
{
    while (state != FruitShopState::Exit)
    {
        switch (state)
        {
        case FruitShopState::Welcome:
            Welcome();
            break;
        case FruitShopState::MainMenu:
            MainMenu();
            break;
        case FruitShopState::FruitMenu:
            FruitMenu();
            break;
        default:
            break;
        }
    }
}

void FruitShop::Exit()
{
    state = FruitShopState::Exit;
}

void FruitShop::Welcome()
{
    std::cout << "Welcome to the fruit shop!" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();
    state = FruitShopState::MainMenu;
}

void FruitShop::MainMenu()
{
    std::cout << "Main menu" << std::endl;
    std::cout << "1. Fruit menu" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        state = FruitShopState::FruitMenu;
        break;
    case 2:
        Exit();
        break;
    default:
        break;
    }
}

void FruitShop::FruitMenu()
{
    std::cout << "Fruit menu" << std::endl;
    std::cout << "1. Apple" << std::endl;
    std::cout << "2. Back" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Apple() << std::endl;
        break;
    case 2:
        state = FruitShopState::MainMenu;
        break;
    default:
        break;
    }
}
