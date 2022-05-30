//Employee Record System using C++
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<fstream>
#include<iostream>
using namespace std;
class Employee
{
char Employee_Name[50], Employee_Father_Name[50];
char Employee_Address[60];
int Employee_Id, Employee_Salary;
public:
	void New_Employee();
	void view();
	char* getname()
	{
		return Employee_Name;
	}
	int getid()
	{
		return Employee_Id;
	}
};
void wait(int delay)
{
  int now=time(NULL);
  int later=now+delay;
  while(now<=later)now=time(NULL);
}
//Display message
void welcomeMessage()
{
system("cls");
cout<<"\n\t\t **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
wait(1);
cout<<"\n\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
wait(1);
cout<<"\n\t\t       =                WELCOME                    =";
wait(1);
cout<<"\n\t\t       =                   TO                      =";
wait(1);
cout<<"\n\t\t       =             Employee Record            =";
wait(1);
cout<<"\n\t\t       =               MANAGEMENT                  =";
wait(1);
cout<<"\n\t\t       =                 SYSTEM                    =";
wait(1);
cout<<"\n\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
wait(1);
cout<<"\n\t\t **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
wait(1);
cout<<"\n\t\t Developed by............ \n";
wait(1);
cout<<"\n\n\n\t\t\t Enter any key to continue.....";
getch();
}
void main_menu()
{
system("cls");
cout<<"\n**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";	
cout<<"\n MAIN MENU";
cout<<"\n1.Add Employee:";
cout<<"\n2.Search Employee by Name:";
cout<<"\n3.Search Employee Detail by ID:";
cout<<"\n4.View Employee:";
cout<<"\n5.Delete Employee Detail:";
cout<<"\n6.Update Employee Detail:";
cout<<"\n7.Exit";
cout<<"\n**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
cout<<"\nEnter your choice:\n\n";
}
//Add employee
void Employee::New_Employee()
{
     cout<<"\nEnter Employee ID:";
     cin>>Employee_Id;
     cout<<"\nEnter Employee Name:";
     cin>>Employee_Name;
     cout<<"\nEnter Employee Father Name:";
     cin>>Employee_Father_Name;
     cout<<"\nEnter Employee Address:";
     cin>>Employee_Address;
     cout<<"\nEnter Employee Salary:";
     cin>>Employee_Salary;
      }
void Employee::view()
      {
	  	cout<<"\n"<<Employee_Id<<"\t"<<Employee_Name<<"\t"<<Employee_Father_Name<<"\t"<<Employee_Address<<"\t"<<Employee_Salary;
	  }
	void addemp()
    {
     fstream f;
     Employee E;
     E.New_Employee();
	 f.open("c:\\project\\data.dat",ios::binary|ios::app|ios::out);  
     f.write((char*)&E,sizeof(E));
     f.close();

	}
	
// View Employee Details
void View_Employee()
{
Employee E;
fstream f;
f.open("c:\\project\\data.dat",ios::binary|ios::in);
cout<<"==========================================================";
cout<<"\nE_Id\tE_Name\tE_Father_Name\tE_Address\tE_Salary\n";
cout<<"==========================================================";

while(!f.eof())
{
f.read((char*)&E,sizeof(E));
if(f.eof()) break;
E.view();
}

f.close();
getch();
}

    //Search Employee Detail by Name
    void Search_Employee_Name()
     {
      char Ename[30];
      int found=0;
      Employee E;
		fstream f;
		f.open("c:\\project\\data.dat",ios::binary|ios::in);

	  cout<<"\nEnter Employee Name to Search:";
      cin>>Ename;
      while(!f.eof())
         {
        	f.read((char*)&E,sizeof(E));
			if(f.eof()) break;
			if(strcmp(E.getname(),Ename)==0)
			  {
			   cout<<"\n\n\n Details of Employee are found as follows:\n\n";
				cout<<"==========================================================";
				cout<<"\nE_Id\tE_Name\tE_Father_Name\tE_Address\tE_Salary\n";
				cout<<"==========================================================";

			  E.view();
			  found=1;
		      }
         }
           if(found==0)
            cout<<"\n not found in the record";
        f.close();
        getch();
       }
    //Search Employee Detail by ID
    void Search_Employee_ID()
     {
      int empid,found=0;
      Employee E;
		fstream f;
		f.open("c:\\project\\data.dat",ios::binary|ios::in);

	  cout<<"\nEnter Employee ID to Search:";
      cin>>empid;
      while(!f.eof())
         {
        	f.read((char*)&E,sizeof(E));
			if(f.eof()) break;
			if(E.getid()==empid)
			  {
			   
			  cout<<"\n\n\n Details of Employee are found as follows:\n\n";
			  cout<<"==========================================================";
			  cout<<"\nE_Id\tE_Name\tE_Father_Name\tE_Address\tE_Salary\n";
              cout<<"==========================================================";

			  E.view();
			  
			  found=1;
		      }
         }
           if(found==0)
            cout<<"\n not found in the record";
        f.close();
        getch();
       }


// Delete Employee Details
void Delete_Employee_Details()                              
{
    int empid,found=0;
    Employee E;
	fstream f,f1;
	f.open("c:\\project\\data.dat",ios::binary|ios::in);
    f1.open("c:\\project\\temp.dat",ios::binary|ios::out);

	  cout<<"\nEnter Employee ID to delete:";
      cin>>empid;
      while(!f.eof())
         {
        	f.read((char*)&E,sizeof(E));
			if(f.eof()) break;
			if(E.getid()!=empid)
			  {
				f1.write((char*)&E,sizeof(E));
			  }
			else
			  found=1;
		}
            
            if(found==0)
            cout<<"\n Record not found to delete";
            else
			cout<<"\n Record Successfully Deleted";
			getch();
            
            f.close();
            f1.close();
            remove("data.dat");
            rename("temp.dat","data.dat");
                
 }
// update Employee Details
void Update_Employee_Details()                              
{
    int empid,found=0;
    Employee E;
	fstream f;
	f.open("c:\\project\\data.dat",ios::binary|ios::in|ios::out);
    cout<<"\nEnter Employee ID to update:";
    cin>>empid;
      while(f.read((char*)&E,sizeof(E)))
      {
	    	if(E.getid()==empid)
			  {
				cout<<"\nEnter new details of Employee :\n";
				E.New_Employee();
				int pos=-1*sizeof(E);
				f.seekp(pos, ios::cur);
				f.write((char*)&E,sizeof(E));
			    found=1;
			  }
	   }
            
            if(found==0)
            cout<<"\n Record not found to Update";
            else
			cout<<"\n Record Successfully Updated";
			getch();
            
            f.close();
                
 }

int main()
{
int choice=0;
welcomeMessage();
do{
main_menu();
cin>>choice;
switch(choice)
{
case 1:addemp();
       break;
case 2:Search_Employee_Name();
       break;
case 3:Search_Employee_ID();
       break;
case 4:View_Employee();
       break;
case 5:Delete_Employee_Details();
       break;
case 6:Update_Employee_Details(); 
       break;
case 7:cout<<"Exiting .......";
       break;
default:cout<<"Wrong choice";
}
}while(choice!=7);
return 0;
}



