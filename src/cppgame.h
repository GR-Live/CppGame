#pragma once
#include <stdio.h>
#include <string>

namespace cppgame
{
    class CPPGAME {
    private:
        std::string getOperatingSystem();
    public:
        void GenerateWindow(std::string Name, int sizeX, int sizeY);
    };
}