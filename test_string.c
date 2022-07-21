#include <stdio.h>
#include <string.h>

int SoSanh(char s[], char s2[])
{
    int i, ok = 0;
    for (i = 0; i <= strlen(s); i++)
    {
        if (s[i] != s2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char s1[100], s2[100];

    printf("Nhap thu nhat: ");
    gets(s1);
    fflush(stdin);
    printf("Nhap thu hai: ");
    gets(s2);

    
    if (SoSanh(s1, s2) == 1)
        printf("Hai chuoi bang nhau!");
    else
        printf("Hai chuoi khac nhau!");
    return 0;
}