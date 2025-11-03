#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct student
{
    int sID;
    char name[50];
    float cp;
    float ds;
    float math;
    float os;
    float excel;
    float avg;
};

int isAlpha(char *name)
{
    for(int i=0; name[i]!='\0'; i++)
    {
        if (!isalpha(name[i])){
            return 0;
        }
    }
    return 1;
}

int Input(struct student *s1)
{
    char temp[50];

    //Input student ID and Name
    printf("Enter student ID: ");
    if (scanf("%d",&s1->sID) !=1){
        printf("Error! Enter a valid int number. \n");
        return 1;
    }
    printf("Enter student name: ");
    scanf("%49s",temp);
    if(!isAlpha(temp)){
        printf("Error! Name must contain only alphabetic characters \n");
        return 1; //Exit because name invalid
    }
    strcpy(s1->name,temp);

    //Input student marks
    printf("Enter subject marks - Computer Programming   ");
    if (scanf("%f", &s1->cp) != 1){
        printf("Error! Enter a valid float number. \n");
        return 1;
    }
    printf("Enter subject marks - Data Science   ");
    if (scanf("%f", &s1->ds) != 1){
        printf("Error! Enter a valid float number. \n");
        return 1;
    }
    printf("Enter subject marks - Maths   ");
    if (scanf("%f", &s1->math) != 1){
        printf("Error! Enter a valid float number. \n");
        return 1;
    }
    printf("Enter subject marks - Operating System   ");
    if (scanf("%f", &s1->os) != 1){
        printf("Error! Enter a valid float number. \n");
        return 1;
    }
    printf("Enter subject marks - Excel   ");
    if (scanf("%f", &s1->excel) != 1){
        printf("Error! Enter a valid float number. \n");
        return 1;
    }
    //Calculating average 
    s1->avg = (s1->cp + s1->ds + s1->math + s1->os + s1->excel)/5;

    //Displaying the input
    printf("\nID        Name        CP        DS        Math        OS        Excel        Average\n");
    printf("%-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f \n", s1->sID, s1->name, s1->cp, s1->ds, s1->math, s1->os, s1->excel, s1->avg);
    return 0;
}

int Add(struct student *s1)
{
    return Input(s1);
}

void Display(struct student s[], int num)
{
    printf("\nID        Name        CP        DS        Math        OS        Excel        Average\n");
    for(int i=0; i<num; i++)
    {
        printf("%-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n", s[i].sID, s[i].name, s[i].cp, s[i].ds, s[i].math, s[i].os, s[i].excel, s[i].avg);
    }
}

int main()
{
    struct student s[15];
    int num=0;
    char choice='y';

    while(choice == 'y')
    {
        printf("\nMENU \n1. Input student data \n2. Display student data \n3. Add student \n4. Remove student \n5. Quit \n");
        int ch;
        printf("Enter your choice(1-5)....");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
                if (num<15)
                {
                    Input(&s[num]);
                    num++;
                }
                else{
                    printf("Maximum number of students reached \n");
                }

                break;
            }
            case 2:
            {
                Display(s,num);
                break;
            }
            case 3:
            {
                if (num<15)
                {
                    Add(&s[num]);
                    num++;
                }
                break;
            }
            case 4:
            {
                char del[50];
                printf("Enter name of Student to be deleted : ");
                scanf("%49s", del);
                int index = -1;
                for(int i=0; i<num; i++)
                {
                    if(strcmp(s[i].name, del) == 0)
                    {
                        index = i;
                        break;
                    }
                }
                if (index == -1)
                {
                    printf("Student not found\n");
                }
                else
                {
                    for(int i = index; i<num-1; i++)
                    {
                        s[i]=s[i+1];
                    }
                }
                num--;
                break;
            }
            case 5:
            { 
                choice = 'n';
                break;
            }
            default:
            {
                printf("INVALID INPUT GIVEN");
            }
        }
    }
    return 0;
}


