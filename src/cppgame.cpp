/*
---------------------------------------------------------------------------------------------------------------------------------------------------
|*************************************************************************************************************************************************|
|***MADE BY ITS DOLPHIN / BYU163 2025. ONLY INCLUDE THE .h FILE. DO NOT INCLUDE THIS CLASS. THIS GENERATES A WINDOW AND ACCESES THE OTHER FILES.**|
|*************************************************************************************************************************************************|
---------------------------------------------------------------------------------------------------------------------------------------------------
*/

// Includes
#include "cppgame.h"
#include <windows.h>

namespace cppgame{
    // Get the Current User's Operating System. Different operating systems (oses) have different APIs you need to use. This code is trying to be made to be universal.
    std::string CPPGAME::getOperatingSystem()
    {
        #ifdef _WIN32
            return "Windows";
        #elif __linux__
            return "Linux";
        #elif __APPLE__
            return "Apple";
        #else
            return "blank";
        #endif
        return "blank";
    }

    // Operating System APIs
    void CPPGAME::Windows(std::string Name, int sizeX, int sizeY, HINSTANCE hInstance) {
        // This will use the complex and well integrated Win32 API.
        // https://learn.microsoft.com this is the source I used for this function
        
        const wchar_t CLASS_NAME[]  = L"CPPGame_Class";
        const wchar_t* WindowName = std::wstring(Name.begin(),Name.end()).c_str();

        WNDCLASS wc = { };

        wc.lpfnWndProc   = WindowProc;
        wc.hInstance     = hInstance;
        wc.lpszClassName = CLASS_NAME;

        RegisterClass(&wc);
        HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            CLASS_NAME,                     // Window class
            WindowName,    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT/*Location*/, sizeX, sizeY/*Actual window*/,

            NULL,       // Parent window    
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
        );

        if (!hwnd) {
            return;
        }

        ShowWindow(hwnd,SW_SHOWNORMAL);
        UpdateWindow(hwnd);

        MSG msg;
        while (GetMessage(&msg,NULL,0,0)>0){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void CPPGAME::Linux(std::string Name, int sizeX, int sizeY) {

    }

    void CPPGAME::Mac(std::string Name, int sizeX, int sizeY) {

    }

    // Generate Window based on the result from getOperatingSystem()
    void CPPGAME::GenerateWindow(std::string Name, int sizeX, int sizeY,HINSTANCE hInstance){
        os = getOperatingSystem();

        // Checks the Operating System and sends it to their respective APIs
        // This pains me. I'm not like YendereDev. 
        if (os == "Windows"){
            Windows(Name,sizeX,sizeY, hInstance);
        } else if (os == "Linux"){
            Linux(Name,sizeX,sizeY);
        } else if (os == "Apple"){
            Mac(Name,sizeX,sizeY);
        } else {
            std::cerr << "GRCG01: The current operating system can't be identified." << std::endl;
            return;
        }
    }
}

#ifdef _WIN32
LRESULT CALLBACK cppgame::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        // Handle other cases if necessary
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);  // Default handling for unhandled messages
}
#endif
