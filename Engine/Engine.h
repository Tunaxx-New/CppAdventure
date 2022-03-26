#include <windows.h>

//
// Engine class is main console management class
// Which will interact with game only with some public functions
class Engine
{
public:
    void initialize();
    HWND getHConsole();
private:
    //
    // Console info
    //
    CONSOLE_SCREEN_BUFFER_INFO csbi_;

    //
    // Console HWND
    //
    HWND hConsole_;

    //
    // Getting rows in console
    // @return rows
    int getRows();

    //
    // Getting columns of console
    // @return columns
    int getColumns();
};