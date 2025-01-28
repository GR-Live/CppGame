![CppGame](https://github.com/user-attachments/assets/a97c0777-f1ba-47be-9381-d90acb070bcb)
# C++Game
 C++ Framework to Assist you in making a game in C++.  Please give credits to GR Live
## Purpose
 C++ is one of the most popular programming languages. Our mission with this project is to provide you with a framework that is as simple as possible to understand and work. This project is open-source and can be contributed to at any time. This project also helps the developers understand the ins and outs of C++.
## Documentation
 C++ game is made to be easy to use and cross-compatible. This will walk you through the framework.
### Getting Setup.
 You need to download this framework and paste it into the game's main enviornment. Use the main GitHub page for **Canary Beta** testing and **Full Releases** for a heavily tested, working, framework. Once you get started, include the main file which is labled **cppgame.h**.
### First Lines.
 The first lines you need to make to get started are to reference **cppgame::CPPGAME,** and then reference **GenerateWindow()**. You will need the following parameters:
 **Name,
 Width Size,
 Height Size.**
Once you create the window you can add an **Icon** by changing the **path to favicon (C++ Game Refrence.favicon.)** **Favicon is a string** so don't use backslashes. Make sure the icon is a **.ico** file and use the Windows .ico layer format. If the icon is bigger than it supports, 32x32, manually change it in the file with the following path, src/Departments/Graphics/Images/Favicon/favicon.cpp .
