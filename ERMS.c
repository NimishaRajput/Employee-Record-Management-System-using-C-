//Employee Record System
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct Employee
{
char Employee_Name[50], Employee_Father_Name[50];
char Employee_Address[60];
int Employee_Id;
float Employee_Salary;
};
struct Employee Emp;
//Display message
void welcomeMessage()
{
printf("\n\t\t **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\n\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\t\t       =                WELCOME                    =");
printf("\n\t\t       =                   TO                      =");
printf("\n\t\t       =            Employee Record                =");
printf("\n\t\t       =               MANAGEMENT                  =");
printf("\n\t\t       =                 SYSTEM                    =");
printf("\n\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\t\t **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\n\n\n\t\t\t Enter any key to continue.....");
getch();
}
void EmployeeRecord()
{
printf("\n MAIN MENU");
printf("\n1.Add Employee:");
printf("\n2.Search Employee by Name:");
printf("\n3.Search Employee Detail by ID:");
printf("\n4.View Employee:");
printf("\n5.Delete Employee Detail:");
printf("\n6.Update Employee Detail:");
printf("\n7.Exit");
printf("\nEnter your choice:");
}
//Add employee
void New_Employee()
{
FILE *E1;
    int i;
    E1=fopen("Employee data.txt","a+b");
    if(E1 == NULL)
   {
    E1= fopen("Employee data.txt", "wb+");
    if (E1 == NULL)
{
    printf("\nCannot open file...");
    exit(1);
    }
   }
     printf("\nEnter Employee ID:");
     scanf("%d",&Emp.Employee_Id);
     printf("\nEnter Employee Name:");
     scanf("%s",Emp.Employee_Name);
     printf("\nEnter Employee Father Name:");
     scanf("%s",Emp.Employee_Father_Name);
     printf("\nEnter Employee Address:");
     scanf("%s",Emp.Employee_Address);
     printf("\nEnter Employee Salary:");
     scanf("%f",&Emp.Employee_Salary);
     fwrite(&Emp,sizeof(Emp),1,E1);
   fclose(E1);
 }
    //Search Employee Detail by Name
    void Search_Employee_Name()
     {
      FILE*E1;
      char Ename[30];
      int found=0;
      E1=fopen("Employee data.txt","rb");
      printf("\nEnter Employee Name to Search:");
      fflush(stdin);
      scanf("%s",Ename);
      while(!feof(E1))
         {
         fread(&Emp,sizeof(Emp),1,E1);
         if(feof(E1)) break;
         if(strcmp(Emp.Employee_Name,Ename)==0)
            {
            found=1;
             printf("\nEmployee ID:%7d\nEmployee Name:%8s\nEmployee Father Name:%8s\nEmployee Address:%8s\nEmployee Salary:%7f",Emp.Employee_Id,Emp.Employee_Name,Emp.Employee_Father_Name,Emp.Employee_Address,Emp.Employee_Salary);
            }  
         }
           if(found==0)
             printf("\n %s is not found in the record",Ename);
            fclose(E1);
       }
//Search Employee Detail by ID
void Search_Employee_ID()
   {
       FILE *E1;
       int i,E_ID;
       int found=0;
       E1=fopen("Employee data.txt","a+b");
       printf("\nEnter Employee ID to Search:");
       scanf("%d",&E_ID);
       while(!feof(E1))
        {
          fread(&Emp,sizeof(Emp),1,E1);
          if(feof(E1)) break;
         if(Emp.Employee_Id==E_ID)
            {
             found=1;
             printf("\nEmployee ID:%7d\nEmployee Name:%8s\nEmployee Father Name:%8s\nEmployee Address:%8s\nEmployee Salary:%7f",Emp.Employee_Id,Emp.Employee_Name,Emp.Employee_Father_Name,Emp.Employee_Address,Emp.Employee_Salary);
            }
        }
       if(found==0)
        printf("\n %d Employee ID is not found in the record",E_ID);
        fclose(E1);
    }
// View Employee Details
void View_Employee()
{
FILE *E1;
E1=fopen("Employee data.txt","rb");
printf("==========================================================");
printf("\nE_Id\tE_Name\tE_Father_Name\tE_Address\tE_Salary\n",Emp.Employee_Id,Emp.Employee_Name,Emp.Employee_Father_Name,Emp.Employee_Address,Emp.Employee_Salary);
printf("==========================================================");
while(!feof(E1))
{
fread(&Emp,sizeof(Emp),1,E1);
if(feof(E1)) break;
printf("\n%7d %8s %8s %8s %7f\n",Emp.Employee_Id,Emp.Employee_Name,Emp.Employee_Father_Name,Emp.Employee_Address,Emp.Employee_Salary);
}
fclose(E1);
}

// Delete Employee Details
void Delete_Employee_Details()                              
{
    struct Employee Emp;
FILE *E1,*E2;
    char empname[50];
       printf("\nDelete Record");
       printf("\nEnter employee name to delete: ");
       scanf("%s",empname);
       E1=fopen("Employee data.txt","rb");
       E2=fopen("Record.txt","wb");
       while(fread(&Emp,sizeof(Emp),1,E1)>0)
          {
            if(strcmp(Emp.Employee_Name,empname)!=0)
            {
            fwrite(&Emp,sizeof(Emp),1,E2);
   }
}
            fclose(E2);
            fclose(E1);
            remove("Employee data.txt");
            rename("Record.txt","Employee data.txt");
            printf("Record Deleted");    
     }
// Update Employee Details
void Update_Employee_Detail()
{
FILE *E1;
system("cls");
char empname[50];
char another = 'y';
E1=fopen("Employee data.txt","a+b");
while(another == 'y')
{
printf("\nEnter Employee Name to Modify:");
scanf("%s", empname);

// While File is open
while (fread(&Emp, sizeof(Emp), 1, E1) == 1) {
// Compare the employee name
// with ename
if (strcmp(Emp.Employee_Name, empname) == 0) {
printf("\nEnter New Employee ID:");
scanf("%d",&Emp.Employee_Id);
printf("\nEnter New Employee Name:");
scanf("%s",Emp.Employee_Name);
printf("\nEnter New Employee Father Name:");
scanf("%s",Emp.Employee_Father_Name);
printf("\nEnter New Employee Address:");
scanf("%s",Emp.Employee_Address);
printf("\nEnter New Employee Salary:");
scanf("%f",&Emp.Employee_Salary);
fseek(E1,sizeof(Emp), SEEK_CUR);
fwrite(&Emp, sizeof(Emp), 1, E1);
break;
}
}
// Ask for modifying another record
printf("\nWant to modify another record (Y/N) :");
fflush(stdin);
scanf("%c",&another);
}
fclose(E1);
}
void main()
{
int choice=0;
welcomeMessage();
do{
EmployeeRecord();
scanf("%d",&choice);
switch(choice)
{
case 1:New_Employee();break;
case 2:Search_Employee_Name();break;
case 3:Search_Employee_ID();break;
case 4:View_Employee();break;
case 5:Delete_Employee_Details();break;
case 6:Update_Employee_Detail();break;
case 7:printf("Exit");
break;
default:printf("Wrong choice");
}
}while(choice!=7);
}

