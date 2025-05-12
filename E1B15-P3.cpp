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
// 電腦協助自動安排連續的座位 
void computerAssign(char seat[SIZE][SIZE]) {
    int n, i, j;
    int found = 0; // 用來記錄是否成功找到合適座位

    // 要求使用者輸入需要的座位數（1~4）
    printf("請問需要幾個座位 (1~4)：");
    scanf("%d", &n);

    // 處理需求為1~3個座位的情況
    if (n >= 1 && n <= 3) {
        for (i = 0; i < SIZE && found == 0; i++) {
            for (j = 0; j <= SIZE - n; j++) {
                // 檢查從 seat[i][j] 開始連續 n 個位置是否為 '-'
                if (seat[i][j] == '-' &&
                    (n < 2 || seat[i][j+1] == '-') &&
                    (n < 3 || seat[i][j+2] == '-')) {
                    
                    // 預先標示預約的座位為 '@'
                    if (n >= 1) seat[i][j] = '@';
                    if (n >= 2) seat[i][j+1] = '@';
                    if (n >= 3) seat[i][j+2] = '@';

                    found = 1; // 表示已找到位置
                    break;     // 跳出內層迴圈
                }
            }
        }
    } 
    // 若需要4個座位
    else if (n == 4) {
        // 先嘗試找一排中連續4個空位
        for (i = 0; i < SIZE && found == 0; i++) {
            for (j = 0; j <= SIZE - 4; j++) {
                if (seat[i][j] == '-' && seat[i][j+1] == '-' &&
                    seat[i][j+2] == '-' && seat[i][j+3] == '-') {

                    // 標記4個橫向座位為 '@'
                    seat[i][j] = seat[i][j+1] = seat[i][j+2] = seat[i][j+3] = '@';
                    found = 1;
                    break;
                }
            }
        }

        // 如果找不到橫向4連位，改找 2x2 的區塊（上下排各兩個）
        if (found == 0) {
            for (i = 0; i < SIZE - 1 && found == 0; i++) {
                for (j = 0; j < SIZE - 1; j++) {
                    if (seat[i][j] == '-' && seat[i][j+1] == '-' &&
                        seat[i+1][j] == '-' && seat[i+1][j+1] == '-') {
                        
                        // 標記2x2方塊的4個位置為 '@'
                        seat[i][j] = seat[i][j+1] = seat[i+1][j] = seat[i+1][j+1] = '@';
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    // 若成功找到位置
    if (found) {
        showSeats(seat); // 顯示目前座位狀況（含預約的 '@'）
        char ok;
        printf("是否滿意這個安排？(y/n)：");
        scanf(" %c", &ok); // 注意前面有空格是為了忽略前一輸入的換行

        if (ok == 'y') {
            // 使用者滿意，將 '@' 轉為正式預約的 '*'
            for (i = 0; i < SIZE; i++)
                for (j = 0; j < SIZE; j++)
                    if (seat[i][j] == '@') seat[i][j] = '*';
        } else {			// 不滿意，還原 '@' 為空位 '-'
            for (i = 0; i < SIZE; i++)
                for (j = 0; j < SIZE; j++)
                    if (seat[i][j] == '@') seat[i][j] = '-';
        }
    } else {
        // 找不到符合需求的連續空位
        printf("找不到連續 %d 個空位。\n", n);
        system("pause");
    }
}
// 使用者自行輸入座位選擇 
void chooseSeats(char seat[SIZE][SIZE]) {
    char ch;                     // 用來接收使用者每次輸入的字元
    int row = 0, col = 0, state = 0;  // row 與 col 儲存解析後的座位座標，state 表示解析的狀態（0=等待列數，1=等待行數，2=等待逗號）
    char input[50];             // 用來儲存整個輸入的字串（例如 "1-2,3-4"）
    int index = 0;              // 目前解析的位置

    // 初始化 temp 座位圖為 '-'
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = '-';

    printf("請輸入座位（格式：1-2,2-9），按Enter結束：\n");

    // getche() 讀取使用者輸入，直到按下 Enter（ASCII 13）
    while ((ch = getche()) != 13)
        input[index++] = ch;
    input[index] = '\0'; // 字串結尾補上 '\0'

    index = 0;
    // 開始解析輸入的字串
    while (input[index] != '\0') {
        // 處理數字字元（1~9）
        if (input[index] >= '1' && input[index] <= '9') {
            if (state == 0) {             // 等待 row 的狀態
                row = input[index] - '1'; // 轉換為索引（row=1→0）
                state = 1;                // 接下來等 col
            }
            else if (state == 1) {        // 等待 col 的狀態
                col = input[index] - '1';
                state = 2;                // 接下來等逗號
            }
        }
        else if (input[index] == '-') {
            // '-' 應該在 row 與 col 中間出現，所以 state 必須是 1
            if (state != 1) {
                printf("\n格式錯誤！\n");
                system("pause");
                return;
            }
        }
        else if (input[index] == ',') {
            // ',' 應該在一個完整座標（row-col）後出現
            if (state != 2 || row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
                printf("\n格式或座標錯誤！\n");
                system("pause");
                return;
            }

            // 檢查座位是否已被預訂或重複選取
            if (seat[row][col] == '*' || temp[row][col] == '@') {
                printf("\n座位[%d,%d]已預訂或重複！\n", row+1, col+1);
                system("pause");
                return;
            }

            temp[row][col] = '@'; // 暫時記錄選取的座位
            state = 0;            // 重設狀態，準備處理下一組座標
        }
        else {
            // 若遇到無效的字元
            printf("\n無效字元！\n");
            system("pause");
            return;
        }
        index++;
    }

    // 處理最後一組座標（如果使用者沒打逗號就結束）
    if (state == 2 && row >= 0 && row < SIZE && col >= 0 && col < SIZE && seat[row][col] != '*')
        temp[row][col] = '@';
    else {
        printf("\n格式錯誤或座位已訂！\n");
        system("pause");
        return;
    }

    // 將 temp 中的選擇結果套用到 seat 中（變成 '@' 狀態）
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (temp[i][j] == '@')
                seat[i][j] = '@';

    showSeats(seat); // 顯示目前座位圖（含選中的 '@'）

    // 使用者看完後，將 '@' 轉為正式預訂的 '*'
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seat[i][j] == '@')
                seat[i][j] = '*';
}
// 詢問使用者是否退出程式 
void askToExit() {
    char confirm;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &confirm);
        if (confirm == 'y') {
            return; // 回到主選單
        } else if (confirm == 'n') {
            printf("感謝使用，程式結束。\n");
            exit(0); // 結束程式
        } else {
            printf("輸入錯誤，請輸入 'y' 或 'n'\n");
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
            case 'b':
                computerAssign(seat);
                break;
            case 'c':
            	chooseSeats(seat);
                break;
            case 'd':
                askToExit();
                exit(0);
            default:
                printf("無效選項，請重新輸入。\n");
                system("pause");
        }
    }

    return 0;
}

