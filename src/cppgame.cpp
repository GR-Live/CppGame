/*
---------------------------------------------------------------------------------------------------------------------------------------------------
|*************************************************************************************************************************************************|
|***MADE BY ITS DOLPHIN / BYU163 2025. ONLY INCLUDE THE .h FILE. DO NOT INCLUDE THIS CLASS. THIS GENERATES A WINDOW AND ACCESES THE OTHER FILES.**|
|*************************************************************************************************************************************************|
---------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "cppgame.h"
#include <windows.h>

namespace cppgame {
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

    // Windows API Function
    void CPPGAME::Windows(std::string Name, int sizeX, int sizeY, HINSTANCE hInstance) {
        // Convert std::string to std::wstring for wide-character strings (wchar_t)
        std::wstring wideName(Name.begin(), Name.end());

        LPCWSTR CLASS_NAME = wideName.c_str();  // Use wide-character class name
        LPCWSTR WindowName = wideName.c_str();  // Use wide-character window name

        WNDCLASSW wc = { };  // Use WNDCLASSW for wide-character windows API

        wc.lpfnWndProc   = WindowProc;          // Set the WindowProc callback function
        wc.hInstance     = hInstance;           // Application instance
        wc.lpszClassName = CLASS_NAME;          // Assign the wide-character class name
        
        // Register the window class (ensure you're using the wide version)
        if (RegisterClassW(&wc) == 0) {
            return;  // Return if window class registration failed
        }

        // Create the window using CreateWindowExW (wide-character version)
        HWND hwnd = CreateWindowExW(
            0,                              // Optional window styles
            CLASS_NAME,                     // Window class
            WindowName,                     // Window text (title)
            WS_OVERLAPPEDWINDOW,            // Window style
            CW_USEDEFAULT, CW_USEDEFAULT,   // Location (default)
            sizeX, sizeY,                   // Size of the window
            NULL,                           // Parent window    
            NULL,                           // Menu
            hInstance,                      // Application instance handle
            NULL                            // Additional application data
        );

        if (!hwnd) {
            return;  // Return if window creation failed
        }

        // Display and update the window
        ShowWindow(hwnd, SW_SHOWNORMAL);
        UpdateWindow(hwnd);

        // Handle Windows messages
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void CPPGAME::Linux(std::string Name, int sizeX, int sizeY) {
        // For Linux-specific code here
    }

    void CPPGAME::Mac(std::string Name, int sizeX, int sizeY) {
        // For Mac-specific code here
    }

    // Function to generate the window for a specific OS
    void CPPGAME::GenerateWindow(std::string Name, int sizeX, int sizeY, HINSTANCE hInstance) {
        os = getOperatingSystem();

        if (os == "Windows") {
            Windows(Name, sizeX, sizeY, hInstance);
        } else if (os == "Linux") {
            Linux(Name, sizeX, sizeY);
        } else if (os == "Apple") {
            Mac(Name, sizeX, sizeY);
        } else {
            std::cerr << "GRCG01: The current operating system can't be identified." << std::endl;
        }
    }
}

// Window Procedure for Windows messages
#ifdef _WIN32
LRESULT CALLBACK cppgame::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        // Handle other messages if necessary
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);  // Default handling
}
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    cppgame::CPPGAME game;
    game.GenerateWindow("Test", 500, 500, hInstance);
    game.favicon = "Assets/DefaultIcon32.ico";
    return 0;
}