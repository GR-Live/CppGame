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