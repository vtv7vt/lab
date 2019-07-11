//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <windows.h>
//---------------------------------------------------------------------------
void f(string way,HKEY s)
{  cout<<way<<"\n";
string mask;
char query[999];
char value[999];
  HKEY x=0;
 // cout<<"Введите путь к разделу реестра\n";
 // cin>>way;
  char*j="SAM\0";
  if(RegOpenKeyEx(s,way.c_str(),0,/*,(char*)way.c_str(),*/KEY_READ,&x)!= ERROR_SUCCESS)
  {cout<<"err";

  //RegQueryInfoKey(x,query,)

//  cout<<(*x);
   cout<<GetLastError();
  /*cout<<(way.c_str());*/}
 // cout<<"Введите маску поиска\n";
  //cin>>mask;
  unsigned long f1=999;
  unsigned long count1;
  unsigned long count2;
 RegQueryInfoKey(x,0,0,0,&count1,0,0,&count2,0,0,0,0);
 cout<<count1<<" ";
 cout<<count2<<"\n";
 for (unsigned int i=0;i<count2;i++)
{  RegEnumValue(x,i,value,&f1,0,0,0,0);
 // if (value!="")
  cout<<value<<"\n";
  f1=999; }
  cout<<888<<"\n";
   for (unsigned int i=0;i<count1;i++)
{  RegEnumKeyEx(x,i,value,&f1,0,0,0,0);
 // if (value!="")
  cout<<value<<"\n";
  if(count1!=0)
  {char*value2=value;
  string way2=way+"\\"+value2;
//  Sleep(1000);
getch();
  f(way2,s); }
  f1=999; }


  }
#pragma argsused
int main(int argc, char* argv[])
{HKEY a=0;
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
string way="HKEY_LOCAL_MACHINE\\HARDWARE\\99";
string mask;
cout<<"Введите путь к разделу\n";
//cin>>way;
string f1="HKEY_CLASSES_ROOT";
string f2="HKEY_CURRENT_USER";
string f3="HKEY_LOCAL_MACHINE";
string f4="HKEY_USERS";
string f5="HKEY_CURRENT_CONFIG";
if(way.find(f1,0)==0)
{a=HKEY_CLASSES_ROOT;
way.erase(0,f1.length()+1);}

if(way.find(f2,0)==0)
{a=HKEY_CURRENT_USER;
way.erase(0,f2.length()+1);}

if(way.find(f3,0)==0)
{a=HKEY_LOCAL_MACHINE;
way.erase(0,f3.length()+1);}

if(way.find(f4,0)==0)
{a=HKEY_USERS;
way.erase(0,f4.length()+1);}

if(way.find(f5,0)==0)
{a=HKEY_CURRENT_CONFIG;
way.erase(0,f5.length()+1);}

if(a==0)
cout<<"Неверный путь к разделу";
else{
 cout<<"Введите маску поиска\n";
cin>>mask;}
f(way,a);
  getch();


        return 0;
}
//---------------------------------------------------------------------------
 