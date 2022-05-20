#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<stdint.h>
#include<conio.h>
using namespace std;
void gotoxy(int x,int y)

{
	// x is a length , y is a width
    COORD coordinates;
    coordinates.X =x;
    coordinates.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
void setup_color(int value_color)
{
     WORD Color;
                         
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                        
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                   
          Color = (csbi.wAttributes & 0xF0) + (value_color & 0x0F);
          SetConsoleTextAttribute(hStdOut, Color);
     }
    
}
void question_part(void)
{
    string question[50];
    string  ans[30];
    string  answer_user;
    uint16_t num=0;
    uint16_t count;
    
    fstream File;
    File.open("question_user.txt",ios::in);// mở file ở chế độ đọc
    while(!File.eof()) // dđọc tới cuối file sẽ trả lại giá trị true
    {
        getline(File,question[num]);
        getline(File,ans[num++]);
        
       
    }
    File.close();
    
    
    for(count =0;count <num-1;count++)
    {
        cout<< "Q"<<(count+1)<<":"<<endl;
        do
        {
            cout<<question[count]<<endl;
            cout<<"Tra loi cua ban:";
            getline(cin,answer_user);
            if(answer_user !=ans[count]) cout<<"Vui long thu lai"<<endl;

            
        } while (answer_user!=ans[count]);
        
    }
 }
 void pre_process(void)
 {
 	char animation1 = 177;
 	char animation2 = 219;
    setup_color(10);
    gotoxy(50,10);
    cout<<"Loading...";
    gotoxy(42,11);
    uint8_t i;
    for(i=0;i<25;i++)
    {
    	cout<<animation1;
	}
	gotoxy(42,11);
	for(i=0;i<25;i++)
	{
		cout<<animation2;
		Sleep(300);
	}
	system("color F");
	system("cls");
	
     
     
     

 }
 void image_ascii(void)
 {
 	fstream outf;
 	outf.open("picture.txt",ios ::in);
    string p;
    while (getline(outf,p))
    {
        cout<<p<<endl;
        Sleep(100);
    }
    outf.close();
    
 }
int main()
{
    question_part();
    pre_process();
    image_ascii();
}
