#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>

int N;

//The structure has a total size of 60 bytes
typedef struct st
{
    int id;
    char name[40];
    int birth_year;
    int birth_month;
    int birth_day;
}st;

//one node has a total size of 72 bytes
typedef struct node
{
    st stu;
    struct node *next;
}node;

void get_info(node  *n);
void insertend(node **tailp);
void insertbeg(node **headp);
void insertmiddle(node *head, int x);
void list (void);

void get_infoarr(struct st  *arr);
void array(void);
void insertendarr(st *arr);
void insertbegarr(st **a);
void insertmidarr(st **a, int x);


int main()
{
    printf("hello to students Data structure program \n");
    array();
    list();
}

/* contructing the dynamic array */
void array(void)
{
    N = 0;
    printf("\nNumber of students intially: ");
    scanf("%i" , &N);
    fflush(stdin);
    if( N== INT_MAX )
    {
        return;
    }
    st *arr = malloc(sizeof(st)*N);
    for (int i=0; i < N; i++)
    {
        printf("\nenter student %i info \n", i+1);
        get_infoarr(arr+i);
    }
    for (int i=0; i < N; i++)
    {
        printf("%i\n", (arr+i) -> id);
    }

    insertbegarr(&arr);
    insertendarr(arr);

    int x;
    printf("\nindex of new node (note that index start from 0 and ends at %i): ", N-1);
    scanf("%i" , &x);
    fflush(stdin);
    if (x == N)
    {
        insertendarr(arr);
    }
    else if(x == 0)
    {
        insertbegarr(&arr);
    }
    else
    {
        insertmidarr(&arr ,x);
    }

    for (int i=0; i < N; i++)
    {
        printf("%i\n", (arr+i) -> id);
    }
    free(arr);


}

/* contructing the linked list */

void list (void)
{
    N = 0;
    node *head = NULL;
    node *tail = NULL;
    printf("\nNumber of students intially: ");
    scanf("%i" , &N);
    fflush(stdin);
    if( N== INT_MAX )
    {
        return;
    }

    for (int i=0; i < N; i++)
    {
        node *n = malloc (sizeof(node));
        if (!n)
        {
            return;
        }

        printf("\nenter student %i info \n", i+1);
        get_info(n);

        if (head)
        {
            for (node *ptr = head; ptr != NULL; ptr = ptr -> next )
            {
                if(ptr-> next == NULL)
                {
                   ptr-> next = n;
                   break;
                }
            }
        }
        else
        {
            head = n;
        }

        if ( i == N-1 )
        {
            tail = n;
        }
    }

    insertbeg(&head);
    insertend(&tail);
    int x;
    printf("\nindex of new node (note that index start from 0 and ends at %i): ", N-1);
    scanf("%i" , &x);
    fflush(stdin);
    if (x == N)
    {
        insertend(&tail);
    }
    else if (x == 0)
    {
        insertbeg(&head);
    }
    else
    {
        insertmiddle(head,x);
    }

    for (node *ptr = head; ptr != NULL; ptr = ptr -> next )
    {
        printf("%i\n", ptr -> stu.id);
    }



    /* deleting allocated memory */
    node *ptr = head;
    while(ptr != NULL)
    {
        node *nxt = ptr -> next;
        free(ptr);
        ptr = nxt;
    }
}

/* functions of list */

void get_info(struct node  *n)
{

        printf("student id: ");
        scanf("%i" , &(n->stu.id));
        fflush(stdin);
        printf("student birth year : ");
        scanf("%i" , &(n->stu.birth_year));
        fflush(stdin);
        printf("student birth month : ");
        scanf("%i" , &(n->stu.birth_month));
        fflush(stdin);
        printf("student birth day : ");
        scanf("%i" , &(n->stu.birth_day));
        fflush(stdin);

        n -> next = NULL;

        printf("student name: ");
        scanf("%s" , (n->stu.name));
        fflush(stdin);
}

void insertbeg(node **headp)
{
        node *n = malloc (sizeof(node));
        if (!n)
        {
            return;
        }

        printf("\nenter student info \n");
        get_info(n);
        n -> next = *headp;
        *headp = n;
        N++;
}

void insertend(node **tailp)
{
        node *tail = *tailp;
        node *n = malloc (sizeof(node));
        if (!n)
        {
            return;
        }

        printf("\nenter student info \n");
        get_info(n);
        tail -> next = n;
        *tailp = n;
        N++;
}

void insertmiddle(node *head, int x)
{

        if (x >= N || x <= 0)
        {
            printf("index is not correct\n");
            return;
        }

        node *n = malloc (sizeof(node));
        if (!n)
        {
            return;
        }
        printf("\nenter student info \n");
        get_info(n);
        node *pre = head;
        for (int k = 0; k < x-1; k++)
        {
            pre = pre -> next;
        }
        n -> next = pre -> next;
        pre -> next = n;
        N++;
}

/* functions of array */

void get_infoarr(struct st  *arr)
{

    printf("student id: ");
    scanf("%i" , &(arr->id));
    fflush(stdin);
    printf("student birth year : ");
    scanf("%i" , &(arr->birth_year));
    fflush(stdin);
    printf("student birth month : ");
    scanf("%i" , &(arr->birth_month));
    fflush(stdin);
    printf("student birth day : ");
    scanf("%i" , &(arr->birth_day));
    fflush(stdin);
    printf("student name: ");
    scanf("%s" , (arr->name));
    fflush(stdin);

}

void insertendarr(st *arr)
{
    N++;
    arr = realloc(arr,sizeof(st)*N);
    printf("\nenter student info \n");
    get_infoarr(arr+N-1);
}
void insertbegarr(st **a)
{
    N++;
    st *temp = malloc(sizeof(st)*N);
    for (int i=0; i < N-1; i++)
    {
        (temp + i + 1)->birth_day = ( (*a) + i )->birth_day;
        (temp + i + 1)->birth_month = ( (*a) + i )->birth_month;
        (temp + i + 1)->birth_year = ( (*a) + i )->birth_year;
        (temp + i + 1)->id = ( (*a) + i )->id;
        strcpy((temp + i + 1) -> name , ( (*a) + i ) -> name ) ;
    }
    free(*a);
    printf("\nenter student info \n");
    get_infoarr(temp);
    *a = temp;
}
void insertmidarr(st **a, int x)
{
    if (x >= N || x <= 0)
    {
        printf("index is not correct\n");
        return;
    }
    N++;
    st *temp = malloc(sizeof(st)*N);
    for (int i=0; i < x; i++)
    {
        (temp + i )->birth_day = ( (*a) + i )->birth_day;
        (temp + i )->birth_month = ( (*a) + i )->birth_month;
        (temp + i )->birth_year = ( (*a) + i )->birth_year;
        (temp + i )->id = ( (*a) + i )->id;
        strcpy((temp + i + 1) -> name , ( (*a) + i ) -> name ) ;
    }
    printf("\nenter student info \n");
    get_infoarr(temp + x);
    for (int i = x + 1; i < N; i++)
    {
        (temp + i )->birth_day = ( (*a) + i - 1)->birth_day;
        (temp + i )->birth_month = ( (*a) + i - 1)->birth_month;
        (temp + i )->birth_year = ( (*a) + i - 1)->birth_year;
        (temp + i )->id = ( (*a) + i - 1)->id;
        strcpy((temp + i + 1) -> name , ( (*a) + i - 1 ) -> name ) ;
    }
    free(*a);
    *a = temp;
}
