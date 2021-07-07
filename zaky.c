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
void calling();
void push_first_array(struct student_info**h,int*n);
void push_into_middle(struct student_info**h,int*n,int z);
void insert_student_last(struct student_info**h,int*n);
void print_array(struct student_info a[],int arraysize);
int main()
{
    printf("\n welcome to our program, here u can save your students data  \n ");
    calling();
    return 0;
}
