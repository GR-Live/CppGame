#pragma once
#include <vector>
#include <iostream>
#include <windows.h>

namespace CGFavicon {
    class favicon {
    public:
        favicon();
        char getFirstCharacter(std::string String);
        bool isCharacterNotBlank(char Character);
        void SetFavicon(const std::string& Path, void* hwnd = nullptr);
    private:
        #ifdef _WIN32
            void Windows(const std::string& Path, HWND hwnd);
        #elif __linux__
            void Linux(const std::string& Path); // Placeholder
        #elif __APPLE__
            void Mac(const std::string& Path);   // Placeholder
        #endif
    };
}