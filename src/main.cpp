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

    const std::wstring customProtocol = L"myapp";
    const std::wstring applicationPath = L"G:\\fruit.exe";

    // Create the registry key for the custom protocol
    HKEY hKey;
    LONG result = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Classes\\myapp", 0, nullptr,
                                  REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, nullptr, &hKey, nullptr);
    if (result == ERROR_SUCCESS) {
        // Set the default value for the protocol key
        const std::wstring protocolDescription = L"URL:Custom Protocol";
        result = RegSetValueExW(hKey, nullptr, 0, REG_SZ, (const BYTE*)protocolDescription.c_str(),
                                (DWORD)((protocolDescription.length() + 1) * sizeof(wchar_t)));
        if (result != ERROR_SUCCESS) {
            std::cerr << "Failed to set protocol description." << std::endl;
        }

        // Set the URL protocol value
        const std::wstring protocolValue = L"";
        result = RegSetValueExW(hKey, L"URL Protocol", 0, REG_SZ, (const BYTE*)protocolValue.c_str(),
                                (DWORD)(protocolValue.length() * sizeof(wchar_t)));
        if (result != ERROR_SUCCESS) {
            std::cerr << "Failed to set URL protocol." << std::endl;
        }

        // Create the command key for opening the application
        HKEY hCommandKey;
        result = RegCreateKeyExW(hKey, L"shell\\open\\command", 0, nullptr,
                                 REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, nullptr, &hCommandKey, nullptr);
        if (result == ERROR_SUCCESS) {
            // Set the default value for the command key
            const std::wstring commandValue = applicationPath + L" \"%1\"";
            result = RegSetValueExW(hCommandKey, nullptr, 0, REG_SZ, (const BYTE*)commandValue.c_str(),
                                    (DWORD)((commandValue.length() + 1) * sizeof(wchar_t)));
            if (result != ERROR_SUCCESS) {
                std::cerr << "Failed to set command value." << std::endl;
            }

            RegCloseKey(hCommandKey);
        } else {
            std::cerr << "Failed to create command key." << std::endl;
        }

        RegCloseKey(hKey);
    } else {
        std::cerr << "Failed to create protocol key." << std::endl;
    }
    #endif
    

    FruitShop fruitShop;
    fruitShop.Run();

    std::cout<<"try done";
    return 0;
}