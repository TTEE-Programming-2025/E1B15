#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main ()
{
    char password[4],letter,ch='"';//宣告密碼字串跟變數   
    printf("|--------------------------------------|\n");
    printf("|  ******* *     *   *     *  *******  |\n");
    printf("|     *    *     *   * *   *  *        |\n");
    printf("|     *    *     *   *   * *  *   ***  |\n");
    printf("|     *     *****    *     *  *******  |\n");                                
    printf("|--------------------------------------|\n");
    printf("|             E1B15童琪皓              |\n");
    printf("|            程式設計作業一            |\n");
    printf("|--------------------------------------|\n");
    printf("|          按任意按鍵繼續程式          |\n");
    printf("|--------------------------------------|\n");
    getch();
    system("cls");
    printf("輸入四位數密碼：\n");
    for(int i=0;i<4;i++)/*密碼輸入字串並顯示米字號*/
	{
        password[i]=getch();
        printf("*");
    }
    printf("\n");
    if(password[0]=='2'&&password[1]=='0'&&password[2]=='2'&&password[3]=='5')/*判斷密碼*/
	{
        printf("按任意按鍵進入主選單");
        getch();
    }
    else{
        printf("\a輸入錯誤\n");
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
    printf("輸入一個字元 : ");
    letter=getche();
    printf("\n");
    if(letter>='A'&&letter<='Z')/*判斷輸入的字元*/  
	    {   
			printf("Uppercase\n");
    		printf("按任意按鍵結束程式");
    		getch();
    		return 0;
    	}
		else if(letter>='a'&&letter<='z')
		{
    		printf("Lowercase\n");
    		printf("按任意按鍵結束程式");
    		getch();
    		return 0;
	    }
	    else if(letter>='0'&&letter<='9')
		{
	    	printf("Digit\n");
    	    printf("按任按意鍵結束程式");
    	    getch();
    	    return 0;
	    }
	    else
	    
		{
	    	printf("E1B15童琪皓\n");
    	    printf("按任意按鍵結束程式");
    	    getch();
    	    return 0;
		}
}
/*這次作業讓我學到了許多實用的技巧，例如如何結合 cls 指令與緩衝區，讓畫面切換更流暢，增強程式的視覺效果。
此外，在設計密碼輸入功能時，我運用了 getch 來隱藏輸入內容，並用 * 符號來取代輸入的字元，這使得密碼輸入更加直觀與安全。
在條件判斷方面，我練習了 if-else 巢狀結構，讓程式能根據輸入的單一字元來判斷其類型，而 switch 敘述則幫助我設計了一個可無限次切換選單的功能，
直到選擇結束程式的選項為止。這些功能的實現需要嚴謹的邏輯思考，雖然過程中遇到了不少挑戰，但也讓我更理解程式的運作原理。
此外，我還學習了如何運用符號來繪製圖案，並設計屬於自己的邊框。在思考「個人特色」時，我一度感到困惑，
最後決定以自己最喜歡的梗圖作為呈現方式，這讓整體作品更加有趣，也展現了我的風格。這次的作業讓我收穫滿滿，也激勵我持續精進自己的程式設計能力。*/ 
