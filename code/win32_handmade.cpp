// OFGONEN - 2023
#include <windows.h>

LRESULT CALLBACK MainWindowCallback(
    HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT Result = 0;
    switch (Message)
    {
        case WM_SIZE:
        {
            OutputDebugStringA("VM_SIZE\n");
        } break;

        case WM_DESTROY:
        {
            OutputDebugStringA("VM_DESTROY\n");
        } break;

        case WM_CLOSE:
        {
            OutputDebugStringA("VM_CLOSE\n");
        } break;

        case WM_ACTIVATEAPP:
        {
            OutputDebugStringA("VM_ACTIVATEAPP\n");
        } break;

        default:
        {
            // OutputDebugStringA("default\n");
            Result = DefWindowProc(Window, Message, WParam, LParam);
        } break;
    }

    return Result;
}

int CALLBACK WinMain(
    HINSTANCE Instance,
    HINSTANCE PrevInstance,
    LPSTR CommandLine,
    int ShowCode)
{
    WNDCLASS WindowClass = {}; // Initialize to ZERO

    WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    WindowClass.lpfnWndProc = MainWindowCallback;
    WindowClass.hInstance = Instance;
    // WindowClass.hIcon;
    // WindowClass.hCursor;
    WindowClass.lpszClassName = "HandmadeHeroWindowClass";

    if(RegisterClass(&WindowClass))
    {
        HWND WindowHandle = CreateWindowEx(
            0, 
            WindowClass.lpszClassName, 
            "Handmade-Hero",
            WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
            CW_USEDEFAULT, 
            CW_USEDEFAULT, 
            CW_USEDEFAULT, 
            CW_USEDEFAULT, 
            0, 
            0, 
            Instance, 
            0); 
        
        if(WindowHandle)
        {
            MSG Message;
            // for(;;)
            while(1)
            {
                BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
                if(MessageResult > 0)
                {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            //todo error logging
        }
    }
    else
    {
        //todo error logging
    }

    // MessageBox(0, "OFG", "Omer", MB_OK | MB_ICONINFORMATION);
    return 0;
}