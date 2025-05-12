#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define SIZE 9
#define BOOKED 10

char seat[SIZE][SIZE];		// �D�y��}�C 
char temp[SIZE][SIZE];		// �Ȧs�}�C�A�Ω�y���� 

// ��l�ƩҦ��y�쬰 '-'�A��ܥ��Q�w�q 
void initSeats(char seat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seat[i][j] = '-';
}
// ��ܥثe�y�쪬�A
void showSeats(char seat[SIZE][SIZE]) {
    system("cls");
    printf("\\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {	// �q�U���W��ܮy��
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seat[i][j]);
        }
        printf("\n");
    }
    printf("�����N���^�D���...\n");
    getch();
}
// �H���w�q�@�Ǯy��A�� '*' ��ܤw�w�q 
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
// �D�{��  
int main() {
    char password[5];
    int count = 0;
    int inputTimes = 0;
    char Menu;
    char seat[SIZE][SIZE];

    srand(time(NULL));

    // �ʭ��e��
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
    printf("|                E1B15���X�q                 |\n");
    printf("|                                            |\n");
    printf("|               �{���]�p�@�~�T               |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");
    printf("|                                            |\n");
    printf("|             �����N�����~��{��             |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");

    getch();
    system("cls");

    while (count < 3) {
        printf("�п�J�|��ƱK�X�G");
        for (int i = 0; i < 4; i++) {
            password[i] = getch();
            printf("*");
        }
        password[4] = '\0';
        inputTimes++;

        printf("\n�A��J���K�X�O�G%s\n", password);

        if (password[0] == '2' && password[1] == '0' &&
            password[2] == '2' && password[3] == '5') {
            printf("�K�X���T�I�����N��i�J�D���\n");
            getch();
            break;
        } else {
            printf("\a�K�X���~�A�Э��s��J�C\n");
            count++;
            if (count == 3) {
                printf("\n���~�T���A�{�������C\n");
                printf("�`�@��J�F %d ���K�X�C\n", inputTimes);
                system("pause");
                return 0;
            }
        }
    }

	initSeats(seat);		 // �I�s��l�Ʈy�쪺�l�{��  
    randomBooking(seat);	 // �H�����w�q�@�Ǯy��  

    // �D���
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
        printf("�п�J�ﶵ�G");
        scanf(" %c", &Menu);

        switch (Menu) {
            case 'a':
                showSeats(seat);
                break;
            default:
                printf("�L�Ŀﶵ�A�Э��s��J�C\n");
                system("pause");
        }
    }

    return 0;
}

