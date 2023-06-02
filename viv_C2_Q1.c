#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct studentInfo
{
int ID;
char* name;
int MarksA;
int MarksB;
int Age;
char* spec;    
}stu;

//creating the table 1
void CreateFirstTable(stu *table1, int nS)
  {
    for(int i=0; i<nS; i++)
    {
        table1[i].name = (char*)malloc(sizeof(char)*10);
        printf("Enter the Information for student %d\n",i+1);
        printf("Enter the student name: ");
        scanf("%s",table1[i].name);

        do{
        printf("Enter the student roll no (4-digit): ");
        scanf("%d",&table1[i].ID);
        }while(table1[i].ID<1000 || table1[i].ID>9999);

    }
  }


  //for printing the table 1
void PrintFirstTable(stu* table1, int nS)
  {
     printf("Table 1\n\n");
    for(int i=0; i<nS; i++)
     {
        printf("Roll NO.: %d\t",table1[i].ID);
        printf("Name: %s\t",table1[i].name);
         printf("\n");
     }
     printf("\n\n");
    
  }


//creating the table 2
  void CreateSecondTable(stu* table2, int nS)
   {
    printf("To create table 2 enter the info:\n");
    
    for(int i=0; i<nS; i++)
     {
      printf("For student: %d\n",i+1);
      do
      { printf("Enter the marks of subject A (out of 100): ");
       scanf("%d",&table2[i].MarksA);
       }
       while(table2[i].MarksA>100 || table2[i].MarksA<0 );


       do{
      printf("Enter the marks of subject B (out of 100): ");
      scanf("%d",&table2[i].MarksB);
       }
       while(table2[i].MarksB>100 || table2[i].MarksB<0);
     }
     printf("\n\n");
   }


//for printing the table 2
   void PrintSecondTable(stu* table2, stu* table1, int nS)
  {
     printf("Table 2\n\n");
    for(int i=0; i<nS; i++)
     {
        printf("Roll NO.: %d\t",table1[i].ID);
        printf("MarksA: %d\t",table2[i].MarksA);
        printf("MarksB: %d\t",table2[i].MarksB);
         printf("\n");
     }
     printf("\n\n");
    
  }

//creating the table 3
  void CreateThirdTable(stu* table3, int nS)
    {
        printf("Enter the information to create Table 3\n");
        for(int i=0; i<nS; i++)
          {
             table3[i].spec = (char*)malloc(sizeof(char)*10);
            printf("For student %d\n",i+1);

           do{ 
            printf("Enter the Age: ");
            scanf("%d",&table3[i].Age);
           }while(table3[i].Age<15 || table3[i].Age>25);


            printf("Enter the specialization: ");
            scanf("%s",table3[i].spec);
          }
          printf("\n\n");
    }

//for printing the table 3
    void PrintThirdTable(stu* table1, stu* table3, int nS)
  {
     printf("Table 3\n\n");
    for(int i=0; i<nS; i++)
     {
        
        printf("Name: %s\t",table1[i].name);
        printf("Age: %d\t\t",table3[i].Age);
        printf("Specialization: %s\t",table3[i].spec);
         printf("\n");
     }
     printf("\n\n");
    
  }

  //for searching 
  int search(stu* table1, int nS, char* str)
   {

    for(int i=0; i<nS; i++) 
     {
       if(strcmp((table1[i].name),str)==0)
         return i;
       else
         return -1;
        
     }
 
   }



int main()
 {
    int nS;
    printf("Enter the number of students: ");
    scanf("%d",&nS);
   
   //for table 1: allocation, reading, printing
    stu *table1;
    table1 = (stu*)malloc(sizeof(stu)*nS);
    CreateFirstTable(table1,nS);
    PrintFirstTable(table1,nS);

 //for table 1: allocation, reading, printing
    stu *table2;
    table2 = (stu*)malloc(sizeof(stu)*nS);
    CreateSecondTable(table2,nS);
    PrintSecondTable(table2, table1, nS);

 //for table 1: allocation, reading, printing
    stu *table3;
    table3 = (stu*)malloc(sizeof(stu)*nS);
    CreateThirdTable(table3,nS);
    PrintThirdTable(table1, table3, nS);

    //for searching

    char* str;
    str = (char*)malloc(sizeof(char)*10);
    printf("Enter the name: ");
    scanf("%s",str);
    int key;
    key=search(table1, nS, str);

    if(key!= -1)
     {
       printf("Name: %s\t",table1[key].name);
       printf("Age: %d\t\t",table3[key].Age);
       printf("Specialization: %s\t",table3[key].spec);
       printf("MarksA: %d\t",table2[key].MarksA);
       printf("MarksB: %d\t",table2[key].MarksB);
       printf("Average: %f\t",(table2[key].MarksB +table2[key].MarksA)/2.0);
     }


 }