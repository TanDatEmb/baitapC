#include <stdio.h>
#include <stdlib.h>

struct List
{
    int data;
    struct List *next;
};

typedef struct List *Vertor;
Vertor Create(int value)
{
    Vertor temp;
    temp = (Vertor)malloc(sizeof(struct List));
    temp->next = NULL;
    temp->data = value;
    return temp;
}

Vertor Vertor_push_back(Vertor node, int value)
{
    Vertor temp, p;
    temp = Create(value);
    if (node == NULL)
    {
        node = temp;
    }
    else
    {
        p = node;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = temp;
    }

    return node;
}

Vertor Input()
{
    Vertor vt = NULL;
    int n, value;

    do
    {
        printf("Nhap so phan tu n=");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri can them: ");
        scanf("%d", &value);
        vt = Vertor_push_back(vt, value);
    }

    return vt;
}

int Set(Vertor note, int value, int index)
{
    int i = 0;
    Vertor pt, p = note;
    Vertor temp = Create(value);
    while (p->next != NULL && i != (index - 1))
    {
        i++;
        p = p->next;
    }
    pt = p->next;
    p->next = temp;
    p = p->next;
    p->next = pt;
    return 0;
}
int Delete(Vertor note, int index)
{
    int i = 0;
    Vertor pt, p = note;
    if (index != 0)
    {
        while (p->next != NULL && i != (index - 1))
        {
            i++;
            p = p->next;
        };
        pt = p->next;
        p->next = pt->next;
        free(pt);
    }
    /*          //khong the xoa vi tri 0
    else
    {
        note = p->next;
        pt = p->next;
        free(pt);
    }
    */
    return 0;
}
int Get(Vertor note, int index)
{
    int i = 0;
    Vertor p = note;

    while (p->next != NULL && i != index)
    {
        i++;
        p = p->next;
    }
    return p->data;
}
int main(int argc, char const *argv[])
{
    Vertor vt = Input();
    for (int i = 0; i < 4; i++)
        printf("data%d: %d\n", i, Get(vt, i));
    Set(vt, 1, 1);
    for (int i = 0; i < 4; i++)
        printf("data%d: %d\n", i, Get(vt, i));
    Delete(vt, 2);
    for (int i = 0; i < 4; i++)
        printf("data%d: %d\n", i, Get(vt, i));
    return 0;
}
