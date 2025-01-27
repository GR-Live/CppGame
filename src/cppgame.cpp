/*
---------------------------------------------------------------------------------------------------------------------------------------------------
|*************************************************************************************************************************************************|
|****MADE BY ITS DOLPHIN / BYU163 2025. ONLY INCLUDE THE .h FILE. DO NOT INCLUDE THIS CLASS. THIS GENERATES A WINDOW AND ACCESES THE OTHER FILES.*|
|*************************************************************************************************************************************************|
---------------------------------------------------------------------------------------------------------------------------------------------------
*/

// Includes
#include "cppgame.h"

// Get the Current User's Operating System. Different operating systems (oses) have different APIs you need to use. This code is trying to be made to be universal.

std::string getOperatingSystem()
{
    #ifdef _WIN32
        return "Windows";
    #elif __LINUX__
        return "Linux";
    #elif __APPLE__
        return "Apple";
    #endif
    return "blank";
}

// Operating System APIs

void Windows(std::string Name, int sizeX, int sizeY) {
    // This will use the complex and well integrated Win32 API.
}

void Linux(std::string Name, int sizeX, int sizeY) {

}

void Apple(std::string Name, int sizeX, int sizeY) {

}

// Generate Window based on the result from getOperatingSystem()
void GenerateWindow(std::string Name, int sizeX, int sizeY){
    std::string os = getOperatingSystem();

    // Checks the Operating System and sends it to their respective APIs
    // This pains me. I'm not like YendereDev. 
    if (os == "Windows"){
        Windows(Name,sizeX,sizeY);
    } else if (os == "Linux"){
        Linux(Name,sizeX,sizeY);
    } else if (os == "Apple"){
        Apple(Name,sizeX,sizeY);
    } else {
        std::cerr << "GRCG01: The current operating system can't be identified." << std::endl;
        return;
    }
}