#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;

/*void F(HDC hdc, int x, int y, int a)
{
    if(a>2){
        F(hdc, x-a, y-a, a/2);
        F(hdc, x+a, y-a, a/2);
        F(hdc, x-a, y+a, a/2);
        F(hdc, x+a, y+a, a/2);
    }
    Rectangle(hdc, x-a,  y-a, x+a, y+a);

}
*/


void L(HDC hdc, int x, int y, int a, int c, int e)
{
    int minA=5;
    Sleep(0);
    if(c<4)
    {
        switch(e)
        {
        case 1:
            MoveToEx(hdc, x-a,y, NULL);
            LineTo(hdc, x-a, y-a/2);
            c++;
            L(hdc, x,y,a,c,2);
            if(a>minA)
            {
                L(hdc, x-a, y-a, a/2, 1, 4);
            }
            else{
                MoveToEx(hdc,x-a, y-a/2, NULL);
                LineTo(hdc, x-a, y-a);
                LineTo(hdc, x-a/2, y-a);
            }

            MoveToEx(hdc, x-a/2, y-a, NULL);
            LineTo(hdc, x, y-a);
            break;

        case 2:
            MoveToEx(hdc, x,y-a, NULL);
            LineTo(hdc, x+a/2, y-a);
            c++;
            L(hdc, x,y,a,c,3);

            if(a>minA)
            {
                L(hdc, x+a, y-a, a/2, 1, 1);
            }
            else{
                MoveToEx(hdc,x+a/2, y-a, NULL);
                LineTo(hdc, x+a, y-a);
                LineTo(hdc, x+a, y-a/2);
            }

            MoveToEx(hdc, x+a, y-a/2, NULL);
            LineTo(hdc, x+a, y);
            break;

        case 3:
            MoveToEx(hdc, x+a, y, NULL);
            LineTo(hdc, x+a, y+a/2);

            L(hdc, x,y,a,++c,4);

            if(a>minA)
            {
                L(hdc, x+a, y+a, a/2, 1, 2);
            }
            else{
                MoveToEx(hdc,x+a, y+a/2, NULL);
                LineTo(hdc, x+a, y+a);
                LineTo(hdc, x+a/2, y+a);
            }

            MoveToEx(hdc, x+a/2, y+a, NULL);
            LineTo(hdc, x, y+a);
            break;

        case 4:
            MoveToEx(hdc, x, y+a, NULL);
            LineTo(hdc, x-a/2, y+a);

            L(hdc, x,y,a,++c,1);

            if(a>minA)
            {
                L(hdc, x-a, y+a, a/2, 1, 3);
            }
            else{
                MoveToEx(hdc,x-a/2, y+a, NULL);
                LineTo(hdc, x-a, y+a);
                LineTo(hdc, x-a, y+a/2);
            }

            MoveToEx(hdc, x-a, y+a/2, NULL);
            LineTo(hdc, x-a, y);

            break;

        default:
            break;
        }
    }
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_PAINT:
        {
            HDC hdc;
            PAINTSTRUCT ps;
            hdc=BeginPaint(hwndDlg, &ps);
            //Rectangle(hdc, 125,125,375,375);
            //MoveToEx(hdc, 125, 250, NULL);
            L(hdc, 256,256, 128,0,1);
            //LineTo(hdc, 250, 250);
            //LineTo(hdc,250 , 125);


            //F(hdc, 250, 250, 125);

            EndPaint(hwndDlg,&ps);

        }
        case WM_INITDIALOG:
        {

        }
        return TRUE;

        case WM_CLOSE:
        {
            EndDialog(hwndDlg, 0);//cerrar la ventana, osea x superior de la esquina
        }
        return TRUE;

        case WM_COMMAND:
        {
            switch(LOWORD(wParam)) //comando para botones
            {
            }
        }
        return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
