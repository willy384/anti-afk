#include <Windows.h>
#include <iostream>
#include <chrono>
#include <cstdlib> 
int setPause(0);

int main() {
    //HWND hWnd = GetConsoleWindow();
    //ShowWindow(hWnd, SW_HIDE); // Esconde o console
    std::cout << "Aperte F1 para ativar e F2 para desativar!!" << std::endl;
    while (true) {
        if (GetAsyncKeyState(VK_F1) & 0x8000) {
            setPause=0;
            while(true){
                std::cout << "Ativado" << std::endl;
                auto start = std::chrono::steady_clock::now();// Aguarda 50 segundos sem travar o programa
                while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start).count() < 5) {
                    if (GetAsyncKeyState(VK_F2) & 0x8000) {
                        setPause=1;
                        break;
                    }
                }
                if(setPause==1){
                    std::cout << "Desativado" << std::endl;
                    break;
                }
                system("python macro.py"); // Executa o arquivo Python
            }
        }
    }
    return 0;
}

 
