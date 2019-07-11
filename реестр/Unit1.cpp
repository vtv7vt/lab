//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <windows.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{SetConsoleCP(1251);
SetConsoleOutputCP(1251);
string way="SOFTWARE\\Microsoft\\Fax";
string mask;
char query[999];
char value[999];
  HKEY x=0;
  cout<<"¬ведите путь к разделу реестра\n";
 // cin>>way;
  char*j="SAM\0";
  if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,way.c_str(),0,/*,(char*)way.c_str(),*/KEY_READ,&x)!= ERROR_SUCCESS)
  {cout<<"err";

  //RegQueryInfoKey(x,query,)

//  cout<<(*x);
   cout<<GetLastError();
  /*cout<<(way.c_str());*/}
  cout<<"¬ведите маску поиска\n";
  cin>>mask;
  unsigned long f=999;
  unsigned long count1;
  unsigned long count2;
 RegQueryInfoKey(x,0,0,0,&count1,0,0,&count2,0,0,0,0);
 cout<<count1<<" ";
 cout<<count2<<"\n";
 for (int i=0;i<count2;i++)
{  RegEnumValue(x,i,value,&f,0,0,0,0);
 // if (value!="")
  cout<<value<<"\n";
  f=999; }
   for (int i=0;i<count1;i++)
{  RegEnumKeyEx(x,i,value,&f,0,0,0,0);
 // if (value!="")
  cout<<value<<"\n";
  f=999; }
 // else cout<<876;

/*HKEY hRootKey = HKEY_LOCAL_MACHINE;
   TCHAR *sKey = "MEOW";
   TCHAR *sVal = (char*)string("Department").c_str();
   HKEY hKeyResult = NULL;
   DWORD dwDisposition = 0;
   LONG rc = RegCreateKeyEx(hRootKey,sKey,0,sVal,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKeyResult,&dwDisposition);
   if(rc==ERROR_SUCCESS)
   {
   //  ShowMessage(SysErrorMessage(GetLastError()));
   cout<<888;
   }
   else
   {
    cout<<GetLastError();
   // ShowMessage("jrj: "+SysErrorMessage(GetLastError()));
   }   */

  getch();


        return 0;
}
//---------------------------------------------------------------------------
 