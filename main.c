#include <stdio.h>
#include <string.h>



int rollNUmber[100];
int numberOfStudentsAdded;
char name[100][22];
void addStudents() {
    int jRollNumber;
    char m,e;
    char jName[22];

    printf("Welcome To Add Module\n");
    printf("Enter roll number : ");
    scanf("%d",&jRollNumber);
    fflush(stdin);
    if (jRollNumber<0){
        printf("Invalid Input\n");
        return;
    }
    e=0;
    while (e<numberOfStudentsAdded)
    {
        if (jRollNumber==rollNUmber[e])
        {
            printf("Roll Number Allotted To %s\n", name[e]);
            return;
        }
        e++;
    }
    printf("Enter Name : ");
    fgets(jName,22,stdin);
    fflush(stdin);
    jName[strlen(jName)-1]='\0';
    printf("Save (Y/N) : ");
    m= getchar();
    if (m!='y' && m!='Y')
    {
        printf("Student Not Added\n");
        return;
    }
    rollNUmber[numberOfStudentsAdded]=jRollNumber;
    strcpy(name[numberOfStudentsAdded],jName);
    numberOfStudentsAdded++;
    printf("Student added successfully, press any key to continue \n");
    m=getchar();
    fflush(stdin);
}

void editStudents(){ }
void deleteStudents(){ }
void searchStudents(){ }
void displayListOfAllStudents()
{
    char f;
    printf("Welcome To Display Module\n");
    f=0;
    while (f<numberOfStudentsAdded)
    {
        printf("Roll Number : %d\t\tName : %s", rollNUmber[f],name[f]);
        f++;
    }
    printf("Student displayed successfully, press any key to continue ");
    f=getchar();
    fflush(stdin);
}


int main(){
    int ch;
    numberOfStudentsAdded=0;
    while(1)
    {
        printf("1. Add Students\n");
        printf("2. Edit Students\n");
        printf("3. Delete Students\n");
        printf("4. Search Students\n");
        printf("5. Display List Of  Students\n");
        printf("6. Exit\n");
        scanf("%d",&ch);
        fflush(stdin);
        if (ch<1 || ch>6)
        {
            printf("INVALID INPUT\n");
            continue;
        }
        if(ch==1) addStudents();
        if(ch==2) editStudents();
        if(ch==3) deleteStudents();
        if(ch==4) searchStudents();
        if(ch==5) displayListOfAllStudents();
        if(ch==6) break;
    }
    return 0;
}




