#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define push_first_array
#define push_into_middle
#define insert_student_last
#define  print_array
int j=0;//global variable to counts the stundets
struct student_info { //defining structure for the students data
    char name_first[20];//a char has a size of 1 byte so an array of 20 char has a size of 20 bytes
    char name_last[20];//also has a size of 20 bytes
    int id;//integer has a size of 4 bytes
    struct birthdate {
        int day;
        int month;
        int year;

    }birth_date;//has a size of 12 bytes
    int last_year_score;//has a size of 4 bytes
};//so the structure has a total size of 60 bytes
struct node {//defining the node of the linked list
    struct student_info data;//has a size of 60 bytes
    struct node* next;//size of a pointer is dependant on the address bus of the cpu ,in our case the pointer has a size of 12 bytes
};//one node has a total size of 72 bytes
/*we need to calculate the time complexity of every function asked so we will use our mode machine in which
 * arithmetic and logic operation and assignments takes 1 unit time. ignoring the calculation of printf and scanf
 * because they are the same in both linked list and array so no need for them in comparison.
 */
void append(struct student_info** head_ref){                        //this function adds data in the end of the list
    system("cls");
    j++;//its cost is 2T for incrementation and assignment 
    struct node* new_student = (struct node*) malloc(sizeof(struct student_info));       //defining new node,it has a cost of 1T
    struct node* last = *head_ref;                                                       //defining a pointer to the head,it has a cost of 1T
    printf("\n student number %d name (first and last) : ", j);                          //entering new data
    scanf("%s %s", new_student->data.name_first, new_student->data.name_last);
    printf("\n student number %d id : ", j);
    scanf("%d", &(new_student->data.id));
    printf("\n student number %d score : ", j);
    scanf("%d", &(new_student->data.last_year_score));
    printf("\n student number %d birth date day/month/year ", j);
    scanf("%d", &(new_student->data.birth_date.day));
    scanf("%d", &(new_student->data.birth_date.month));
    scanf("%d", &(new_student->data.birth_date.year));
    new_student->next = NULL;                                                   //make the next node = NULL
    while (last->next != NULL)
    {
        last = last->next;                                                     //move from the head to the tail,it has a cost of 1T and n number of times while n is the number of elements of linked list
    }
    last->next = new_student;//has a cost of 1T                                                  //insert the new node in the tail
    return;//has a cost of 1T 
}//so it has a total cost of time =5T+1T*n;
void insert(struct node* prev) {                                            //this function adds data in the middle of the list
    j++;
    system("cls");
    if (prev == NULL)
    {
        printf("you have to enter some data first\n");
        return;
    }
    int z = j % 2;                                                //trying to find out if the number of students is even or odd
    struct node* temp = prev;
    if (z == 0)
    {
        for (int i = 2; i <= (j / 2) - 1; i++)
            temp = temp->next;
    }                                                             //move from the head to the middle of the list
    else {
        for (int i = 2; i <= (j + 1) / 2 - 1; i++)
            temp = temp->next;
    }
    struct node* new_student = (struct node*) malloc(sizeof(struct student_info));      //defining new node with new data
    printf("\n student number %d name (first and last) : ", j);
    scanf("%s %s", new_student->data.name_first, new_student->data.name_last);
    printf("\n student number %d id : ", j);
    scanf("%d", &(new_student->data.id));
    printf("\n student number %d score : ", j);
    scanf("%d", &(new_student->data.last_year_score));
    printf("\n student number %d birth date day/month/year : ", j);
    scanf("%d", &(new_student->data.birth_date.day));
    scanf("%d", &(new_student->data.birth_date.month));
    scanf("%d", &(new_student->data.birth_date.year));
    new_student->next = temp->next;                                 //inserting the new node
    temp->next = new_student;
}
void first(struct node** old) {                                  //this function adds data in the first position of the list
    j++;//its cost is 2T for incrementation and assignment 
    system("cls");
    struct node* new_student = (struct node*) malloc(sizeof(struct student_info));     //defining new node with new dataوit has a cost of 1T
    printf("\n student number %d name (first and last) : ", j);
    scanf("%s %s", new_student->data.name_first, new_student->data.name_last);
    printf("\n student number %d id : ", j);
    scanf("%d", &(new_student->data.id));
    printf("\n student number %d score : ", j);
    scanf("%d", &(new_student->data.last_year_score));
    printf("\n student number %d birth date day/month/year : ", j);
    scanf("%d", &(new_student->data.birth_date.day));
    scanf("%d", &(new_student->data.birth_date.month));
    scanf("%d", &(new_student->data.birth_date.year));
    new_student->next = *old;                                              //inserting the new node,it has a cost of 1T
    *old = new_student;                                                    //it has a cost of 1T
}// SO sum of total time cost is equal to 5T
void print(struct node* data) {                                     //this function print all the data in the list
    system("cls");
    while (data != NULL)
    {
        printf("\n %s %s", data->data.name_first, data->data.name_last);
        printf("\n id: %d", data->data.id);
        printf("\n score: %d", data->data.last_year_score);
        printf("\n date of birth : %d/%d/%d", data->data.birth_date.day, data->data.birth_date.month, data->data.birth_date.year);
        printf("\n ________________________________________\n");
        data = data->next;
    }
}
void clean(struct node** data) {                //this function clear the data of the list in the memory
    struct node* current = *data;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }*data = NULL;
}
void index(struct node*data,int position){                //this function adds data at a specific position in the list
    j++;//its cost is 2T for incrementation and assignment
    system("cls");
    struct node*temp=data;
    struct node* new_student = (struct node*) malloc(sizeof(struct student_info));        //defining new node with new data,it has a cost of 1T
    printf("\n student number %d name (first and last) : ", j);
    scanf("%s %s", new_student->data.name_first, new_student->data.name_last);
    printf("\n student number %d id : ", j);
    scanf("%d", &(new_student->data.id));
    printf("\n student number %d score : ", j);
    scanf("%d", &(new_student->data.last_year_score));
    printf("\n student number %d birth date day/month/year : ", j);
    scanf("%d", &(new_student->data.birth_date.day));
    scanf("%d", &(new_student->data.birth_date.month));
    scanf("%d", &(new_student->data.birth_date.year));
    if(temp!=NULL)
        for(int i=1;i<position-1;i++)                        //moving from the head to the position,this line has a cost of 2T and numbers of times = position-1
        temp=temp->next;                                      //this line has a cost of 1T and numbers of times = position-2
    new_student->next = temp->next;                           //inserting the new node,has a cost of 1T
    temp->next = new_student;                                 //has a cost of 1T

}// so the the total cost of time is 6T+2T*(position-1)+1T*(position-2)
void calling(){                                        //this function used to provide a menu to the user to use our program
    struct node* head;
    int sizearray = 0;
    struct student_info* ptr = (struct student_info*)malloc(sizeof(struct student_info) * sizearray);
    int menu=1;
    int z;
    int response = 1;
    int m;
    int number;
    head = NULL;
    printf("\n you can save the data in \n 1.linked list\n 2.dynamic array\n your response: ");
    fflush(stdout);                                                //first u have to enter number of students and enter their data
    scanf("%d", &menu);                                            //to create some data to make your operations
    printf("\n number of students : ");
    fflush(stdout);
    scanf("%d", &number);
    system("cls");
    if (menu == 1){
        while (j != number){
        	if(j==0)
            first(&head);
        	else
        		append(&head);
        }}
    else if (menu == 2){
        while (sizearray != number){
			if(sizearray==0)
		push_first_array(&ptr, &sizearray);
	        else
			insert_student_last(&ptr, &sizearray);
		  }}
    while (response != 0 && menu != 0)                                      //here u can choose what is the function u want to call
    {
        if (menu == 1)
        {
            printf("\n 0.to exit and clear your data");
            printf("\n 1.add a student at the beginning of your list ");
            printf("\n 2.add a student in the middle of your list");
            printf("\n 3.add a student at a specific position ");
            printf("\n 4.add a student at the end of your list");
            printf("\n 5.view your data");
            printf("\n your response: ");
            fflush(stdout);
            scanf("%d", &response);
            if (response == 4)
                append(&head);
            else if (response == 1)
                first(&head);
            else if (response == 2)
                insert(head);
            else if (response == 5)
                print(head);
            else if (response == 3)
            {printf("\n enter the index : ");
             scanf("%d",&m);
             index(head,m);
            }
            else if (response == 0)
                break;
        }
        else if (menu == 2)
        {
            printf("\n 0.to exit and clear your data");
            printf("\n 1.add a student at the beginning of your array ");
            printf("\n 2.add a student in a certain position of your array");
            printf("\n 3.add a student at the end of your array");
            printf("\n 4.view your array data");
            printf("\n your response: ");
            fflush(stdout);
            scanf("%d", &response);
            if (response == 1)
                push_first_array(&ptr, &sizearray);
            else if (response == 2){
            	printf("\nplease enter the position you want to insert your student into :(starting from zero) ");
            	fflush(stdout);
            	scanf("%d",&z);
                push_into_middle(&ptr, &sizearray,z);
            }
            else if (response == 3)
                insert_student_last(&ptr, &sizearray);
            else if (response == 4)
                print_array(ptr, sizearray);
            else if (response == 0)
                break;
        }

    }free(ptr);
    clean(&head);
     return ;
}

int main()
{
    printf("\n welcome to our program, here u can save your students data  \n ");
    calling();
    return 0;
}


