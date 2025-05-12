#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define SIZE 9
#define BOOKED 10

char seat[SIZE][SIZE];		// 主座位陣列 
char temp[SIZE][SIZE];		// 暫存陣列，用於座位選擇 

// 初始化所有座位為 '-'，表示未被預訂 
void initSeats(char seat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seat[i][j] = '-';
}
// 顯示目前座位狀態
void showSeats(char seat[SIZE][SIZE]) {
    system("cls");
    printf("\\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {	// 從下往上顯示座位
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seat[i][j]);
        }
        printf("\n");
    }
    printf("按任意鍵返回主選單...\n");
    getch();
}
// 隨機預訂一些座位，用 '*' 表示已預訂 
void randomBooking(char seat[SIZE][SIZE]) {
    int count = 0;
    while (count < BOOKED) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (seat[r][c] != '*') {
            seat[r][c] = '*';
            count++;
        }
    }
}
// 主程式  
int main() {
    char password[5];
    int count = 0;
    int inputTimes = 0;
    char Menu;
    char seat[SIZE][SIZE];

    srand(time(NULL));

    // 封面畫面
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
    printf("|               程式設計作業三               |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");
    printf("|                                            |\n");
    printf("|             按任意按鍵繼續程式             |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");

    getch();
    system("cls");

    while (count < 3) {
        printf("請輸入四位數密碼：");
        for (int i = 0; i < 4; i++) {
            password[i] = getch();
            printf("*");
        }
        password[4] = '\0';
        inputTimes++;

        printf("\n你輸入的密碼是：%s\n", password);

        if (password[0] == '2' && password[1] == '0' &&
            password[2] == '2' && password[3] == '5') {
            printf("密碼正確！按任意鍵進入主選單\n");
            getch();
            break;
        } else {
            printf("\a密碼錯誤，請重新輸入。\n");
            count++;
            if (count == 3) {
                printf("\n錯誤三次，程式結束。\n");
                printf("總共輸入了 %d 次密碼。\n", inputTimes);
                system("pause");
                return 0;
            }
        }
    }

	initSeats(seat);		 // 呼叫初始化座位的子程式  
    randomBooking(seat);	 // 隨機先預訂一些座位  

    // 主選單
    while (1) {
        system("cls");
        printf("|-------------[Booking  System]----------|\n");
        printf("|                                        |\n");
        printf("|          a.  Available  seats          |\n");
        printf("|                                        |\n");
        printf("|          b.  Arrange  for  you         |\n");
        printf("|                                        |\n");
        printf("|          c.  Choose  by  yourself      |\n");
        printf("|                                        |\n");
        printf("|          d.  Exit                      |\n");
        printf("|                                        |\n");
        printf("|----------------------------------------|\n");
        printf("請輸入選項：");
        scanf(" %c", &Menu);

        switch (Menu) {
            case 'a':
                showSeats(seat);
                break;
            default:
                printf("無效選項，請重新輸入。\n");
                system("pause");
        }
    }

    return 0;
}

