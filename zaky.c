#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
int j=0;
struct student_info {
    char name_first[20];
    char name_last[20];
    int id;
    struct birthdate {
        int day;
        int month;
        int year;

    }birth_date;
    int last_year_score;
};
struct node {
    struct student_info data;
    struct node* next;
};
void append(struct student_info** head_ref);
void insert(struct node* prev);
void first(struct node** old);
void clean(struct node** data);
void index(struct node*data,int position);
void calling(){
    struct node* head;
    int sizearray = 0;
    struct student_info* ptr = (struct student_info*)malloc(sizeof(struct student_info) * sizearray);
    int menu=1;
    int response = 1;
    int m;
    int number;
    head = NULL;
    printf("\n you can save the data in \n 1.linked list\n 2.dynamic array\n your response: ");
    fflush(stdout);
    scanf("%d", &menu);
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
    while (response != 0 && menu != 0)
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
            printf("\n 2.add a student in the middle of your array");
            printf("\n 3.add a student at the end of your array");
            printf("\n 4.view your array data");
            printf("\n your response: ");
            fflush(stdout);
            scanf("%d", &response);
            if (response == 1)
                push_first_array(&ptr, &sizearray);
            else if (response == 2)
                push_into_middle(&ptr, &sizearray);
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
void push_first_array(struct student_info**h,int*n){
	/*we used pointer to pointer in order to make changes to the array itself like its size not just its values*/
	int i;
	(*n)+=1;
	*h=(struct student_info *)realloc(*h,sizeof(struct student_info)*(*n));/*realloc the array to the size needed*/
	/*shifting the elements to the right by 1*/
	for(i=(*n)-1;i>=1;i--){
	(*h)[i].id=(*h)[i-1].id;
	(*h)[i].birth_date.day=(*h)[i-1].birth_date.day;
	(*h)[i].birth_date.month=(*h)[i-1].birth_date.month;
	(*h)[i].birth_date.year=(*h)[i-1].birth_date.year;
	(*h)[i].last_year_score=(*h)[i-1].last_year_score;
	strcpy((*h)[i].name_first,(*h)[i-1].name_first);
	strcpy((*h)[i].name_last,(*h)[i-1].name_last);

	}
	/*inserting the new student */
	printf("\nenter the student name(first and last) :");
	fflush(stdout);
	scanf("%s %s",(*h)[0].name_first,(*h)[0].name_last);
	printf("\nenter the student id : ");
	fflush(stdout);
	scanf("%d",&(*h)[0].id);
	printf("\nenter the student birth date (day month year) : ");
	fflush(stdout);
	scanf("%d %d %d",&(*h)[i].birth_date.day,&(*h)[i].birth_date.month,&(*h)[i].birth_date.year);
	printf("\nenter the student last year score :");
	fflush(stdout);
	scanf("%d",&(*h)[0].last_year_score);
	fflush(stdin);
}
void push_into_middle(struct student_info**h,int*n){
	/*we used pointer to pointer in order to make changes to the array itself like its size not just its values*/
	int i;
	(*n)+=1;
	*h=(struct student_info *)realloc(*h,sizeof(struct student_info)*(*n));/*realloc the array to the size needed*/
	/*shifting the elements to the right by 1*/
	for(i=(*n)-1;i>(*n)/2;i--){
	(*h)[i].id=(*h)[i-1].id;
	(*h)[i].birth_date.day=(*h)[i-1].birth_date.day;
	(*h)[i].birth_date.month=(*h)[i-1].birth_date.month;
	(*h)[i].birth_date.year=(*h)[i-1].birth_date.year;
	(*h)[i].last_year_score=(*h)[i-1].last_year_score;
	strcpy((*h)[i].name_first,(*h)[i-1].name_first);
	strcpy((*h)[i].name_last,(*h)[i-1].name_last);

	}
	i=(*n)/2;
	/*inserting the new student */
	printf("\nenter the student name(first and last) :");
		fflush(stdout);
		scanf("%s %s",(*h)[i].name_first,(*h)[i].name_last);
	printf("\nenter the student id : ");
	fflush(stdout);
	scanf("%d",&(*h)[i].id);
	printf("\nenter the student birth date (day month year) :");
	fflush(stdout);
	scanf("%d %d %d",&(*h)[i].birth_date.day,&(*h)[i].birth_date.month,&(*h)[i].birth_date.year);
	printf("\nenter the student last year score : ");
	fflush(stdout);
	scanf("%d",&(*h)[i].last_year_score);
	fflush(stdin);
}
void insert_student_last(struct student_info**h,int*n){
	(*n)+=1;
	*h=(struct student_info *)realloc(*h,sizeof(struct student_info)*(*n));/*realloc the array to the size needed*/
	/*inserting the new student */
	printf("\nenter the student name(first and last) :");
		fflush(stdout);
		scanf("%s %s",(*h)[(*n)-1].name_first,(*h)[(*n)-1].name_last);
		printf("enter the student id : \n");
		fflush(stdout);
		scanf("%d",&(*h)[(*n)-1].id);
		printf("enter the student birth date (day month year) : \n");
		fflush(stdout);
		scanf("%d %d %d",&(*h)[(*n)-1].birth_date.day,&(*h)[(*n)-1].birth_date.month,&(*h)[(*n)-1].birth_date.year);
		printf("enter the student last year score : \n");
		fflush(stdout);
		scanf("%d",&(*h)[(*n)-1].last_year_score);
		fflush(stdin);
}
void print_array(struct student_info a[],int arraysize){
	int i;
	for(i=0;i<arraysize;i++){
		printf("\nname : %s %s\nbirth date : %d/%d/%d",a[i].name_first,a[i].name_last,a[i].birth_date.day,a[i].birth_date.month,a[i].birth_date.year);
		printf("\nid : %d\nlast year score : %d",a[i].id,a[i].last_year_score);
	}
	fflush(stdout);
}
int main()
{
    printf("\n welcome to our program, here u can save your students data  \n ");
    calling();
    return 0;
}
