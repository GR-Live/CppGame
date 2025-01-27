/*
---------------------------------------------------------------------------------------------------------------------------------------------------
|*************************************************************************************************************************************************|
|***MADE BY ITS DOLPHIN / BYU163 2025. ONLY INCLUDE THE .h FILE. DO NOT INCLUDE THIS CLASS. THIS GENERATES A WINDOW AND ACCESES THE OTHER FILES.**|
|*************************************************************************************************************************************************|
---------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "cppgame.h"
#include <windows.h>
#include "Departments/Graphics/Images/Favicon/favicon.h"
#include <codecvt>
#include <locale>

namespace cppgame {
    // Get the Current User's Operating System.
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

    #ifdef _WIN32
    // Windows API Function
    HWND CPPGAME::Windows(std::string Name, int sizeX, int sizeY, HINSTANCE hInstance) {
        std::wstring wideName = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(Name);
        const wchar_t* CLASS_NAME = wideName.c_str();
        const wchar_t* WindowName = wideName.c_str();

        WNDCLASSEX wc = { };

        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszClassName = CLASS_NAME;
        CGFavicon::favicon faviconInstance;

        // Register the window class (ensure you're using the wide version)
        if (RegisterClassEx(&wc) == 0) {
            std::cerr << "GRCG02: Can't register window class. \n";
            return nullptr;  // Return if window class registration failed
        }

        // Create the window using CreateWindowExW (wide-character version)
        HWND hwnd = CreateWindowEx(
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

        if(!faviconInstance.isCharacterNotBlank(faviconInstance.getFirstCharacter(favicon))){
            favicon = "Assets/DefaultIcon32.ico";
            faviconInstance.SetFavicon(favicon, hwnd);
        }
        else {
            faviconInstance.SetFavicon(favicon, hwnd);
        }

        if (!hwnd) {
            std::cerr << "GRCG03: Window is Invalid. ";
            return nullptr;  // Return if window creation failed
        }

        // Display and update the window
        ShowWindow(hwnd, SW_SHOWNORMAL);
        UpdateWindow(hwnd);

        return hwnd;
    }
    #endif

    void* CPPGAME::Linux(std::string Name, int sizeX, int sizeY) {
        std::cerr << "Debug Error. This class hasn't been implemented yet." << std::endl;
        return nullptr;
    }

    void* CPPGAME::Mac(std::string Name, int sizeX, int sizeY) {
        std::cerr << "Debug Error. This class hasn't been implemented yet." << std::endl;
        return nullptr;
    }

    // Function to generate the window for a specific OS
    WindowHandle CPPGAME::GenerateWindow(std::string Name, int sizeX, int sizeY, HINSTANCE hInstance) {
        os = getOperatingSystem();

        if (os == "Windows") {
            return Windows(Name, sizeX, sizeY, hInstance);
        } else if (os == "Linux") {
            return Linux(Name, sizeX, sizeY);
        } else if (os == "Apple") {
            return Mac(Name, sizeX, sizeY);
        } else {
            std::cerr << "GRCG01: The current operating system can't be identified." << std::endl;
            return nullptr;
        }
    }
    void SetFavicon(std::string Path) {
        CGFavicon::favicon faviconInstance;
        faviconInstance.SetFavicon(Path);
    }

}

// Window Procedure for Windows messages
#ifdef _WIN32
LRESULT CALLBACK cppgame::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        // Destroys the Window
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        // Makes the window scale up and down
        case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd,&ps);
            FillRect(hdc,&ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));
            EndPaint(hwnd,&ps);
            return 0;
        }
        case WM_SIZE:
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);  // Default handling
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    cppgame::CPPGAME game;
    CGFavicon::favicon faviconInstance;
    game.favicon = "Assets/DefaultIcon32.ico";
    cppgame::WindowHandle hwnd = game.GenerateWindow("Test", 500, 500, hInstance);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
#endif