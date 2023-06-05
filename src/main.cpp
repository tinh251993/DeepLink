#include <iostream>
#include <string>


#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#endif

#include "fruit-shop/fruit-shop.hpp"

int main(int argc, char** argv){
    #ifdef _WIN32

        const std::string customProtocol = "fruit"; //app name
        const std::string appPath = "G:\fruit.exe"; //applink (later will take from registry)

        std::string registryKey = "HKEY_CLASSES_ROOT\\" + customProtocol;  //registry custom link
        RegSetKeyValueA(HKEY_CLASSES_ROOT, customProtocol.c_str(), nullptr, REG_SZ,
         "URL:Custom Protocol", customProtocol.length());
        RegSetKeyValueA(HKEY_CLASSES_ROOT, customProtocol.c_str(), "URL Protocol", REG_SZ, nullptr, 0);
        RegSetKeyValueA(HKEY_CLASSES_ROOT, customProtocol.c_str(), "shell\\open\\command", REG_SZ,
        (appPath + " \"%1\"").c_str(), (appPath + " \"%1\"").length());
    #endif
    

    FruitShop fruitShop;
    fruitShop.Run();

    return 0;
}