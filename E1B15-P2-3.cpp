#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() 
{
    char password[5], letter, ch = '"'; // �h�@��s '\0'
    int count = 0; // �O�����~����
    int inputTimes = 0; // �O����J����

    // �e�����
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
    printf("|               �{���]�p�@�~�G               |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");
    printf("|                                            |\n");
    printf("|             �����N�����~��{��             |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");

    getch();
    system("cls");

    while (count < 3) 
    {
        printf("��J�|��ƱK�X�G\n");

        for (int i = 0; i < 4; i++) { 
            password[i] = getch();
            printf("*");
        }
        password[4] = '\0'; // �r�굲���Ÿ�

        inputTimes++; // �O����J����
        
        printf("\n�ثe�w�g��J�F %d ���K�X�C\n", inputTimes); // <<< �C�����L�X�ثe����
 
        printf("�A��J���K�X�O�G%s\n", password); // ��ܿ�J���K�X

        if (password[0] == '2' && password[1] == '0' && password[2] == '2' && password[3] == '5') 
        {
            printf("�K�X���T�I�����N��i�J�D���\n");
            getch();
            break; // ���\�i�J�A���X while
        } 
        else 
        {
            printf("\a�K�X���~�A�Э��s��J�C\n");
            count++; // ���~����+1

            if (count == 3) 
            {
                printf("\n���~�T���A�{������\n");
                printf("�`�@��J�F %d ���K�X�C\n", inputTimes);
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
        printf("|       ��J'A'or'a' (�����T����)       |\n");
        printf("|                                       |\n");
		printf("|       ��J'B'or'b' (���k��)           |\n");
        printf("|                                       |\n");
		printf("|       ��J'C'or'c' (����)             |\n");
        printf("|                                       |\n");
        printf("|---------------------------------------|\n");
    }    
}
