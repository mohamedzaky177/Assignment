#include <stdio.h>
#include <stdlib.h>

int N;
typedef struct node
{
    int id;
    char name[40];
    int birth_year;
    int birth_month;
    int birth_day;
    struct node *next;
}
node;

void get_info(node  *n);
void insertend(node **tailp);
void insertbeg(node **headp);
void insertmiddle(node *head, int x);
void list (void);

void get_infoarr(struct node  *arr);
void array(void);
void insertendarr(node *arr);
void insertbegarr(node **a);
void insertmidarr(node **a, int x);


int main()
{
    printf("hello to students Data structure program \n");
    array();
    list();
}