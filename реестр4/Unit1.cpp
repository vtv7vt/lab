//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <windows.h>
//---------------------------------------------------------------------------
string mask;
void f(string way,HKEY s)
{   cout<<"Просматривается раздел "<<way<<"\n";
char subs[999];
char value[999];
  HKEY x=0;
  if(RegOpenKeyEx(s,way.c_str(),0,KEY_READ | KEY_WOW64_64KEY,&x)!= ERROR_SUCCESS)
  {
   cout<<"Неверный путь к разделу";
   return;}

  unsigned long f1=999;
  unsigned long count1;
  unsigned long count2;
 RegQueryInfoKey(x,0,0,0,&count1,0,0,&count2,0,0,0,0);
 cout<<"Параметры,удовлетворяющие маске поиска, ";
 bool h1=0;
 for (unsigned int i=0;i<count2;i++)
{f1=999;
 RegEnumValue(x,i,value,&f1,0,0,0,0);
string h=value;
 if (h.find(mask,0)==0)
 {if(!h1)
 cout<<"\n";
 cout<<value<<"\n";
 h1=1;}}
 if(!h1)
 cout<<"отсутствуют";
 cout<<"\n";
 bool h2=0;
   cout<<"Подразделы,удовлетворяющие маске поиска, ";
   for (unsigned int i=0;i<count1;i++)
{f1=999;
 RegEnumKeyEx(x,i,value,&f1,0,0,0,0);
string h=value;
 if (h.find(mask)==0)
  {if(!h2)
 cout<<"\n";
  cout<<value<<"\n";
  h2=1;}

  }
  if(!h2)
 cout<<"отсутствуют";
 cout<<"\n\n";

  unsigned long f2=999;
  if(count1!=0)
  {for (unsigned int i=0;i<count1;i++)
{f2=999;
RegEnumKeyEx(x,i,subs,&f2,0,0,0,0);

  string way2;
  if(way!="")
  way2=way+"\\";
  way2+=subs;
  f(way2,s);}}
  }
#pragma argsused
int main(int argc, char* argv[])
{HKEY a=0;
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
string way;

cout<<"Введите путь к разделу\n";
cin>>way;
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
cin>>mask;
if(mask[mask.length()-1]!='*')
cout<<"Неверная маска поиска";
else
{mask.erase(mask.length()-1,1);
f(way,a);} }
  getch();
        return 0;
}
//---------------------------------------------------------------------------
