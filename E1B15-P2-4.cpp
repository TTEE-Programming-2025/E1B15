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

        Menu = getch();
        system("cls");
        if (Menu == 'A' || Menu == 'a') {
    		
    		char right_triangle;
    		while (1) { // �����J���T���r��
    		    printf("�п�J 'a' �� 'n' ���r���G");
    		    scanf(" %c", &right_triangle); // �e���[�Ů��קK�Y�줧�e��J�� Enter

    		    if (right_triangle >= 'a' && right_triangle <= 'n') {
    		        break; // ���T�A���X�j��
    		    } else {
    		        printf("���~�I�Э��s��J�C\n");
    		    }
    		}

    		int rows = right_triangle - 'a' + 1;  
    		// ��ASCII�p���ơA�Ҧp 'c'-'a'=2�A�A+1�A�N�O3��

    		for (int i = 1; i <= rows; i++) {
    		    for (int j = 1; j <= rows - i; j++) {
    		        printf(" "); // ���L�Ů�A���T���ξa�k
    		    }
    		    for (int k = 0; k < i; k++) {
    		        printf("%c", 'a' + k); // �q 'a' �}�l�L�r��
    		    }
    		    printf("\n");
    		}

    		printf("�����N���^�D���\n");
    		getch(); // ���ݫ���
		}

		else if (Menu == 'B' || Menu == 'b') {
    		// ��ܭ��k��
    		int n;
    		while (1) { // �����J���T
    		    printf("�п�J 1 �� 9 ����ơG");
    		    scanf("%d", &n);

    		    if (n >= 1 && n <= 9) {
    		        break; // ���T�A���X�j��
    		    } else {
   		         printf("���~�I�Э��s��J�C\n");
    		    }
    		}

    		printf("\n���k��G\n");
    		for (int i = 1; i <= n; i++) {
    		    for (int j = 1; j <= n; j++) {
    		        printf("%d x %d = %2d  ", i, j, i * j); // %2d �O�������
    		    }
    		    printf("\n");
    		}

    		printf("\n�����N���^�D���\n");
    		getch(); // ���ݫ���
		}		
    }
}
