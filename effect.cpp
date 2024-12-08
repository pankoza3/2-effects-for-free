#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>


bool showMessageBox(const std::string& title, const std::string& message, UINT iconType) {
    int response = MessageBoxA(NULL, message.c_str(), title.c_str(), MB_YESNO | iconType);
    return response == IDYES;
}






void rainbowEffect(HDC hdc, int duration) {
    srand(static_cast<unsigned>(time(0)));



    auto startTime = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count() < duration) {
        HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
        SelectObject(hdc, brush);
        PatBlt(hdc, 0, 0, 1920, 1080, PATINVERT);
        DeleteObject(brush);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
  
}


void moveScreenDown(HDC hdc, int duration) {
    
    auto startTime = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count() < duration) {
        BitBlt(hdc, 0, 5, 1920, 1080, hdc, 0, 0, SRCCOPY);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    
}

int main() {
   
    if (!showMessageBox("malware name by your name", "Do you want to run this malware?", MB_ICONWARNING)) {
        return 0;
    }

    
    if (!showMessageBox("malware name by your name", "Are you sure?", MB_ICONWARNING)) {
        return 0;
    }

   
    HDC hdc = GetDC(NULL);

   
    const int effectDuration = 20; 
    rainbowEffect(hdc, effectDuration);
    moveScreenDown(hdc, effectDuration);

    
    ReleaseDC(NULL, hdc);

    return 0;
}
