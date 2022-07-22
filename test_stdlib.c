#include <stdio.h>
#include <stdint.h>

int test_atoi(char const *str)
{
    int val = 0;
    int i = 0;
    while (str[i] >= 48 && str[i] <= 57)
    {
        val = val * 10 + (str[i] - 48);
        i++;
    }
    return val;
}
double test_atof(char const *str)
{
    double val = 0;
    double a = 1;
    int i = 0;
    while (str[i] >= 48 && str[i] <= 57)
    {
        val = val * 10 + (str[i] - 48);
        i++;
    }
    if (str[i] == 46)
    {
        i+=1;
        while (str[i] >= 48 && str[i] <= 57)
        {
            a = a / 10;
            val = val + (str[i] - 48) * a;
            i++;
        }
    }
    return val;
}
double test_strtod(char *str, char **endptr)
{
    double val = 0;
    double a = 1;
    int i = 0;
    while (str[i] >= 48 && str[i] <= 57)
    {
        val = val * 10 + (str[i] - 48);
        i++;
    }
    if (str[i] == 46)
    {
        i++;
        while (str[i] >= 48 && str[i] <= 57)
        {
            a = a / 10;
            val = val + (str[i] - 48) * a;
            i++;
        }
    }
    *endptr = &str[i];
    return val;
}
char *test_strtok(char str[], char delim[])
{
    static char *ptr;
    if (str != NULL)
        ptr = str;
    char *ptrReturn = ptr;

    if (delim == NULL)
        return str;
    if (ptr[0] == '\0')
        return NULL;
    for (int j = 0; ptr != '\0'; j++)
    {
        for (int i = 0; delim[i] != '\0'; i++)
        {
            if (ptr[j] == '\0')
            {
                ptr += j;
                return ptrReturn;
            }
            if (ptr[j] == delim[i])
            {
                ptr[j] = '\0';
                ptr += j + 1;
                return ptrReturn;
            }
        }
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    char str[100] = "123.456;Hom nay, troi dep - cao xanh";
    char str2[100] = "Le Tan Dat;0309191016-Cao Thang";
    char s[] = "-.,;";
    char *p;
    
        printf("%d\n", test_atoi(str));
        printf("%lf\n", test_atof(str));
        printf("%lf|", test_strtod(str, &p));
        printf("%s\n", p);
    
    p = test_strtok(str, s);
    printf("%s\n", p);
    p = test_strtok(str2, s);
    while (p != NULL)
    {
        printf("%s\n", p);

        p = test_strtok(NULL, s);
    }
    return 0;
}