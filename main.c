#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define waitfreq 5   /*點擊開始等待時間*/

int freq = 1,incase = 1;
char question[];

void windowSet();
unsigned int YesOrNo(char []);
void mouseclick(unsigned int);

void windowSet()               /*設定視窗與標題*/
{
    system("mode con:cols=40 lines=20");
    system("TITLE 滑鼠連點程式--by Xjpjeass");
    SetWindowPos(GetConsoleWindow(),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
}

unsigned int YesOrNo(char question[])           /*問二選一問題，答案只有0跟1，其他答案視為0*/
{
    printf("\n %s \n",question);
    printf("\n 請選擇:按下y接受，n拒絕 \n");
    while(GetAsyncKeyState(89) == 0 || GetAsyncKeyState(78) == 0 )
    {
        if(GetAsyncKeyState(89) != 0)
        {
            return 1;
        }
        else if(GetAsyncKeyState(78) != 0)
        {
            return 0;
        }
    }
}

void mouseclick(unsigned int f)
{
    system("CLS");
    printf("將在%d秒後開始執行滑鼠連點，請先將游標置於欲點擊位置。\n",waitfreq);
    Sleep(1000*waitfreq);
    printf("開始點擊!\n");
    while(GetAsyncKeyState(VK_ESCAPE) == 0)
    {
        mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        printf("點擊一次(按下ESC鍵離開)....\n");
        Sleep(100*f);
    }
}

int main()
{
    windowSet();
    while(incase == 1)
    {
        printf("========滑鼠連點程式========\n");
        printf("=請設定頻率(零點幾秒按一次)=\n");
        scanf("%d",&freq);
        if(freq > 100 || freq < 1)
        {
            printf("不適用範圍!\n");
            system("CLS");
        }
        else
        {
            printf("設定為%.1f秒...\n",0.1*(float)freq);
            switch(YesOrNo("確定設定為這個頻率嗎?\n"))
            {
            case 1:
                printf("選擇頻率為%.1f秒點擊一次。\n",0.1*(float)freq);
                Sleep(1000);
                system("CLS");
                getche();
                printf("\b");
                incase = 0;
                break;
            case 0:
                printf("重新選擇。\n");
                Sleep(1000);
                system("CLS");
                getche();
                printf("\b");
                break;
            }
        }
    }
    printf("按下F1鍵開始進行連點程序!\n");
    while(GetAsyncKeyState(VK_ESCAPE) == 0)
    {
        while(GetAsyncKeyState(VK_F1) != 0)
        {
            mouseclick((unsigned int)freq);
            printf("再次按下F1鍵繼續以相同頻率連點，否則按下ESC鍵離開。\n");
        }
    }
    return 0;
}
