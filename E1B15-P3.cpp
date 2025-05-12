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
// �q����U�۰ʦw�Ƴs�򪺮y�� 
void computerAssign(char seat[SIZE][SIZE]) {
    int n, i, j;
    int found = 0; // �ΨӰO���O�_���\���X�A�y��

    // �n�D�ϥΪ̿�J�ݭn���y��ơ]1~4�^
    printf("�аݻݭn�X�Ӯy�� (1~4)�G");
    scanf("%d", &n);

    // �B�z�ݨD��1~3�Ӯy�쪺���p
    if (n >= 1 && n <= 3) {
        for (i = 0; i < SIZE && found == 0; i++) {
            for (j = 0; j <= SIZE - n; j++) {
                // �ˬd�q seat[i][j] �}�l�s�� n �Ӧ�m�O�_�� '-'
                if (seat[i][j] == '-' &&
                    (n < 2 || seat[i][j+1] == '-') &&
                    (n < 3 || seat[i][j+2] == '-')) {
                    
                    // �w���Хܹw�����y�쬰 '@'
                    if (n >= 1) seat[i][j] = '@';
                    if (n >= 2) seat[i][j+1] = '@';
                    if (n >= 3) seat[i][j+2] = '@';

                    found = 1; // ��ܤw����m
                    break;     // ���X���h�j��
                }
            }
        }
    } 
    // �Y�ݭn4�Ӯy��
    else if (n == 4) {
        // �����է�@�Ƥ��s��4�ӪŦ�
        for (i = 0; i < SIZE && found == 0; i++) {
            for (j = 0; j <= SIZE - 4; j++) {
                if (seat[i][j] == '-' && seat[i][j+1] == '-' &&
                    seat[i][j+2] == '-' && seat[i][j+3] == '-') {

                    // �аO4�Ӿ�V�y�쬰 '@'
                    seat[i][j] = seat[i][j+1] = seat[i][j+2] = seat[i][j+3] = '@';
                    found = 1;
                    break;
                }
            }
        }

        // �p�G�䤣���V4�s��A��� 2x2 ���϶��]�W�U�ƦU��ӡ^
        if (found == 0) {
            for (i = 0; i < SIZE - 1 && found == 0; i++) {
                for (j = 0; j < SIZE - 1; j++) {
                    if (seat[i][j] == '-' && seat[i][j+1] == '-' &&
                        seat[i+1][j] == '-' && seat[i+1][j+1] == '-') {
                        
                        // �аO2x2�����4�Ӧ�m�� '@'
                        seat[i][j] = seat[i][j+1] = seat[i+1][j] = seat[i+1][j+1] = '@';
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    // �Y���\����m
    if (found) {
        showSeats(seat); // ��ܥثe�y�쪬�p�]�t�w���� '@'�^
        char ok;
        printf("�O�_���N�o�Ӧw�ơH(y/n)�G");
        scanf(" %c", &ok); // �`�N�e�����Ů�O���F�����e�@��J������

        if (ok == 'y') {
            // �ϥΪ̺��N�A�N '@' �ର�����w���� '*'
            for (i = 0; i < SIZE; i++)
                for (j = 0; j < SIZE; j++)
                    if (seat[i][j] == '@') seat[i][j] = '*';
        } else {			// �����N�A�٭� '@' ���Ŧ� '-'
            for (i = 0; i < SIZE; i++)
                for (j = 0; j < SIZE; j++)
                    if (seat[i][j] == '@') seat[i][j] = '-';
        }
    } else {
        // �䤣��ŦX�ݨD���s��Ŧ�
        printf("�䤣��s�� %d �ӪŦ�C\n", n);
        system("pause");
    }
}
// �ϥΪ̦ۦ��J�y���� 
void chooseSeats(char seat[SIZE][SIZE]) {
    char ch;                     // �Ψӱ����ϥΪ̨C����J���r��
    int row = 0, col = 0, state = 0;  // row �P col �x�s�ѪR�᪺�y��y�СAstate ��ܸѪR�����A�]0=���ݦC�ơA1=���ݦ�ơA2=���ݳr���^
    char input[50];             // �Ψ��x�s��ӿ�J���r��]�Ҧp "1-2,3-4"�^
    int index = 0;              // �ثe�ѪR����m

    // ��l�� temp �y��Ϭ� '-'
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = '-';

    printf("�п�J�y��]�榡�G1-2,2-9�^�A��Enter�����G\n");

    // getche() Ū���ϥΪ̿�J�A������U Enter�]ASCII 13�^
    while ((ch = getche()) != 13)
        input[index++] = ch;
    input[index] = '\0'; // �r�굲���ɤW '\0'

    index = 0;
    // �}�l�ѪR��J���r��
    while (input[index] != '\0') {
        // �B�z�Ʀr�r���]1~9�^
        if (input[index] >= '1' && input[index] <= '9') {
            if (state == 0) {             // ���� row �����A
                row = input[index] - '1'; // �ഫ�����ޡ]row=1��0�^
                state = 1;                // ���U�ӵ� col
            }
            else if (state == 1) {        // ���� col �����A
                col = input[index] - '1';
                state = 2;                // ���U�ӵ��r��
            }
        }
        else if (input[index] == '-') {
            // '-' ���Ӧb row �P col �����X�{�A�ҥH state �����O 1
            if (state != 1) {
                printf("\n�榡���~�I\n");
                system("pause");
                return;
            }
        }
        else if (input[index] == ',') {
            // ',' ���Ӧb�@�ӧ���y�С]row-col�^��X�{
            if (state != 2 || row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
                printf("\n�榡�ήy�п��~�I\n");
                system("pause");
                return;
            }

            // �ˬd�y��O�_�w�Q�w�q�έ��ƿ��
            if (seat[row][col] == '*' || temp[row][col] == '@') {
                printf("\n�y��[%d,%d]�w�w�q�έ��ơI\n", row+1, col+1);
                system("pause");
                return;
            }

            temp[row][col] = '@'; // �ȮɰO��������y��
            state = 0;            // ���]���A�A�ǳƳB�z�U�@�ծy��
        }
        else {
            // �Y�J��L�Ī��r��
            printf("\n�L�Ħr���I\n");
            system("pause");
            return;
        }
        index++;
    }

    // �B�z�̫�@�ծy�С]�p�G�ϥΪ̨S���r���N�����^
    if (state == 2 && row >= 0 && row < SIZE && col >= 0 && col < SIZE && seat[row][col] != '*')
        temp[row][col] = '@';
    else {
        printf("\n�榡���~�ήy��w�q�I\n");
        system("pause");
        return;
    }

    // �N temp ������ܵ��G�M�Ψ� seat ���]�ܦ� '@' ���A�^
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (temp[i][j] == '@')
                seat[i][j] = '@';

    showSeats(seat); // ��ܥثe�y��ϡ]�t�襤�� '@'�^

    // �ϥΪ̬ݧ���A�N '@' �ର�����w�q�� '*'
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seat[i][j] == '@')
                seat[i][j] = '*';
}
// �߰ݨϥΪ̬O�_�h�X�{�� 
void askToExit() {
    char confirm;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &confirm);
        if (confirm == 'y') {
            return; // �^��D���
        } else if (confirm == 'n') {
            printf("�P�¨ϥΡA�{�������C\n");
            exit(0); // �����{��
        } else {
            printf("��J���~�A�п�J 'y' �� 'n'\n");
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
                printf("�L�Ŀﶵ�A�Э��s��J�C\n");
                system("pause");
        }
    }

    return 0;
}

