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

namespace cppgame
{
    class CPPGAME {
    private:
        std::string getOperatingSystem();
        void Windows(std::string Name, int sizeX, int sizeY);
        void Linux(std::string Name, int sizeX, int sizeY);
        void Mac(std::string Name, int sizeX, int sizeY);

    public:
        void GenerateWindow(std::string Name, int sizeX, int sizeY);
    };
}