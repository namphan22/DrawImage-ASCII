#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<stdint.h>
using namespace std;
void question_part(void)
{
    string question[50];
    string  ans[30];
    string  answer_user;
    uint16_t num=0;
    uint16_t count;
    
    fstream File;
    File.open("question_user.txt",ios::in);// mở file ở chế độ đọc
    while(!File.eof()) // đọc tới cuối file trả lại giá trị true
    {
        getline(File,question[num]);
        getline(File,ans[num++]);
        
       
    }
    File.close();
    
    for(count =0;count <num;count++)
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
int main()
{
    question_part();
}