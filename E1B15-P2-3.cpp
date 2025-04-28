#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() 
{
    char password[5], letter, ch = '"'; // 多一格存 '\0'
    int count = 0; // 記錄錯誤次數
    int inputTimes = 0; // 記錄輸入次數

    // 畫面顯示
    printf("|--------------------------------------------|\n");
    printf("| ********  **       **  **    **  *******   |\n");
    printf("|    **     **       **  **    **  **        |\n");
    printf("|    **     **       **  **    **  **        |\n");
    printf("|    **     **       **  **    **  **  ****  |\n");
    printf("|    **     **       **  **    **  **    **  |\n");
    printf("|    **     **       **  **    **  **    **  |\n");
    printf("|    **      **     **   **    **  **    **  |\n");
    printf("|    **       *******     ******    ******   |\n");
    printf("|--------------------------------------------|\n");                             
    printf("|--------------------------------------------|\n");  
    printf("|                                            |\n");
    printf("|                E1B15童琪皓                 |\n");
    printf("|                                            |\n");
    printf("|               程式設計作業二               |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");
    printf("|                                            |\n");
    printf("|             按任意按鍵繼續程式             |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");

    getch();
    system("cls");

    while (count < 3) 
    {
        printf("輸入四位數密碼：\n");

        for (int i = 0; i < 4; i++) { 
            password[i] = getch();
            printf("*");
        }
        password[4] = '\0'; // 字串結束符號

        inputTimes++; // 記錄輸入次數
        
        printf("\n目前已經輸入了 %d 次密碼。\n", inputTimes); // <<< 每次都印出目前次數
 
        printf("你輸入的密碼是：%s\n", password); // 顯示輸入的密碼

        if (password[0] == '2' && password[1] == '0' && password[2] == '2' && password[3] == '5') 
        {
            printf("密碼正確！按任意鍵進入主選單\n");
            getch();
            break; // 成功進入，跳出 while
        } 
        else 
        {
            printf("\a密碼錯誤，請重新輸入。\n");
            count++; // 錯誤次數+1

            if (count == 3) 
            {
                printf("\n錯誤三次，程式結束\n");
                printf("總共輸入了 %d 次密碼。\n", inputTimes);
                system("pause");
                return 0;
            }
        }
    }
    system("cls");

    char Menu;
    while (1) {
        system("cls");
        printf("|---------------------------------------|\n");
        printf("|                                       |\n");
        printf("|       輸入'A'or'a' (直角三角形)       |\n");
        printf("|                                       |\n");
		printf("|       輸入'B'or'b' (乘法表)           |\n");
        printf("|                                       |\n");
		printf("|       輸入'C'or'c' (結束)             |\n");
        printf("|                                       |\n");
        printf("|---------------------------------------|\n");
    }    
}
