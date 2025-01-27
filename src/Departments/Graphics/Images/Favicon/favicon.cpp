/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------
|*************************************************************************************************************************************************************|
|***MADE BY ITS DOLPHIN / BYU163 2025. This class is responsible for handling the icon which I call the favicon. These classes are called in the main class.**|
|*************************************************************************************************************************************************************|
--------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "favicon.h"
#include <windows.h>
#include "../../../../cppgame.h"
namespace CGFavicon {
    favicon::favicon() {

    }
    char favicon::getFirstCharacter(std::string String){
        return String.empty() ? '\0' : String[0]; 
    }

    bool favicon::isCharacterNotBlank(char Character){
        std::vector<char> ValidCharacters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','/','1','2','3','4','5','6','7','8','9','0','-','_','.'};
        for (auto& validChar : ValidCharacters) {
            if (Character == validChar) {
                return true;
            }
        }
        return false;
    }

    void favicon::SetFavicon(const std::string& Path, void* hwnd){
        #ifdef _WIN32
            if (hwnd == nullptr) {
                std::cerr << "Error: hwnd is required on Windows.\n";
                return;
            }
            Windows(Path, static_cast<HWND>(hwnd));
        #elif __linux__
            Linux(Path); // Placeholder for Linux-specific icon logic
        #elif __APPLE__
            Mac(Path); // Placeholder for macOS-specific icon logic
        #else
            std::cerr << "Unsupported OS. Cannot set favicon.\n";
        #endif
    }
    void favicon::Windows(const std::string& Path, HWND hwnd) {
        HICON hIcon;
        hIcon = (HICON)LoadImageA(NULL, Path.c_str(), IMAGE_ICON,32,32,LR_LOADFROMFILE);    // Default application icon 
        if (!hIcon) {
            std::cerr << "Failed to load icon from path : " << Path << std::endl;
            return;
        } else {
            std::cout << "Loaded Icon : " << Path;
        }

        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    }
}