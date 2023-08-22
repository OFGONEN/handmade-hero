// OFGONEN - 2023
#include <windows.h>

// This Is called from C-Runtime Lib not Windows
int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    MessageBox(0, "OFG",  "Omer", MB_OK | MB_ICONINFORMATION);
    return 0;
}