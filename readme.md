# CAPP (Learning C++ App)
Really simple app made to learn C++ and CMake.\
It uses [Microsoft VCPKG](https://vcpkg.io/en/index.html) as Package Manager, this tool was used to add [Microsoft C++ REST SDK](https://github.com/microsoft/cpprestsdk) to create an HTTP Server that acts as a very simple Microservice.

> Note: This is just meant to be used as start reference by beginners.

# Dependencies
Current dev configuration was made for a Windows environment:

- [CMake (Builder)](https://cmake.org/)
- [VCPKG (Package Manager)](https://vcpkg.io/en/index.html)
- [Visual Studio 2022 & C++ Dev Tools (Compiler)](https://visualstudio.microsoft.com/vs/)

# Working on Windows

## Initial project setup
The following command can be used to initialize project on a development machine.
```
PS path/to/capp> ./scripts/init.bat
```

## Build
```
PS path/to/capp> ./scripts/build.bat
```
> [Visual Studio Code](https://code.visualstudio.com/) users can also perform build by pressing `CTRL` + `Shift` + `b`.

## Running
```
PS path/to/capp> ./scripts/run.bat
```

## Debugging
You can debug the project using  [Visual Studio Code](https://code.visualstudio.com/).\
To debug you need to install [C++ Support Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)\
After that you can run app on debug mode by pressing `F5`.
