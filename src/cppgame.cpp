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

    return "blank";
}

// Generate Window based on the result from getOperatingSystem()

void GenerateWindow(std::string Name, int sizeX, int sizeY){
    std::string os = getOperatingSystem();
}