/*
 ---------------------------------------------------------------------------------------------------------------------------------------------------
|*************This File is the only file that should be included. The rest are built in to this program. Just use the "CPPGAME::"" call.************|
|****************If you are tired of using the call you can include everything with "using namespace cppgame" but it's frowned upon.****************|
|*****************************************If you use the namespace you can directly type out each function******************************************|
 -----------------------------------------------------------------------------------------===-------------------------------------------------------
*/

#pragma once
#include <iostream>
#include <string>
#include <windows.h>

namespace cppgame
{
    class CPPGAME {
    private:
        std::string getOperatingSystem();
        void Windows(std::string Name, int sizeX, int sizeY, HINSTANCE hInstance);
        void Linux(std::string Name, int sizeX, int sizeY);
        void Mac(std::string Name, int sizeX, int sizeY);
    protected:
        std::string os = "";
    public:
        void GenerateWindow(std::string Name, int sizeX, int sizeY,HINSTANCE hInstance);
        std::string favicon =""/*= "Assets/DefaultIcon32"*/;
    };
    #ifdef _WIN32
    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    #endif
}