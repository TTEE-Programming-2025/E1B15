#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main ()
{
    char password[4],letter,ch='"';//�ŧi�K�X�r����ܼ�   
    printf("|--------------------------------------|\n");
    printf("|  ******* *     *   *     *  *******  |\n");
    printf("|     *    *     *   * *   *  *        |\n");
    printf("|     *    *     *   *   * *  *   ***  |\n");
    printf("|     *     *****    *     *  *******  |\n");                                
    printf("|--------------------------------------|\n");
    printf("|             E1B15���X�q              |\n");
    printf("|            �{���]�p�@�~�@            |\n");
    printf("|--------------------------------------|\n");
    printf("|          �����N�����~��{��          |\n");
    printf("|--------------------------------------|\n");
    getch();
    system("cls");
    printf("��J�|��ƱK�X�G\n");
    for(int i=0;i<4;i++)/*�K�X��J�r�����ܦ̦r��*/
	{
        password[i]=getch();
        printf("*");
    }
    printf("\n");
    if(password[0]=='2'&&password[1]=='0'&&password[2]=='2'&&password[3]=='5')/*�P�_�K�X*/
	{
        printf("�����N����i�J�D���");
        getch();
    }
    else{
        printf("\a��J���~\n");
        system("pause");
        return 0;
    }
    system("cls");
    printf("|--------------------------|\n"); 
    printf("|'A'...'Z': Uppercase      |\n");
    printf("|                          |\n");
    printf("|'a'...'z': Lowercase      |\n");  
    printf("|                          |\n");
    printf("|'0'...'9': Digit          |\n");
    printf("|                          |\n");
    printf("|Otherwise : my name       |\n");
    printf("|--------------------------|\n");
    printf("��J�@�Ӧr�� : ");
    letter=getche();
    printf("\n");
    if(letter>='A'&&letter<='Z')/*�P�_��J���r��*/  
	    {   
			printf("Uppercase\n");
    		printf("�����N���䵲���{��");
    		getch();
    		return 0;
    	}
		else if(letter>='a'&&letter<='z')
		{
    		printf("Lowercase\n");
    		printf("�����N���䵲���{��");
    		getch();
    		return 0;
	    }
	    else if(letter>='0'&&letter<='9')
		{
	    	printf("Digit\n");
    	    printf("�������N�䵲���{��");
    	    getch();
    	    return 0;
	    }
	    else
	    
		{
	    	printf("E1B15���X�q\n");
    	    printf("�����N���䵲���{��");
    	    getch();
    	    return 0;
		}
}
/*�o���@�~���ھǨ�F�\�h��Ϊ��ޥ��A�Ҧp�p�󵲦X cls ���O�P�w�İϡA���e��������y�Z�A�W�j�{������ı�ĪG�C
���~�A�b�]�p�K�X��J�\��ɡA�ڹB�ΤF getch �����ÿ�J���e�A�å� * �Ÿ��Ө��N��J���r���A�o�ϱo�K�X��J��[���[�P�w���C
�b����P�_�譱�A�ڽm�ߤF if-else �_�����c�A���{����ھڿ�J����@�r���ӧP�_�������A�� switch �ԭz�h���U�ڳ]�p�F�@�ӥi�L����������檺�\��A
�����ܵ����{�����ﶵ����C�o�ǥ\�઺��{�ݭn�Y�Ԫ��޿��ҡA���M�L�{���J��F���֬D�ԡA���]���ڧ�z�ѵ{�����B�@��z�C
���~�A���پǲߤF�p��B�βŸ���ø�s�ϮסA�ó]�p�ݩ�ۤv����ءC�b��ҡu�ӤH�S��v�ɡA�ڤ@�׷P��x�b�A
�̫�M�w�H�ۤv�̳��w����ϧ@���e�{�覡�A�o������@�~��[����A�]�i�{�F�ڪ�����C�o�����@�~���ڦ�ì�����A�]�E�y�ګ����i�ۤv���{���]�p��O�C*/ 
