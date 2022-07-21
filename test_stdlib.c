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
        i++;
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
/*
char *test_strtok(char *str, const char *delim) 
{
    int i = 0;
    char *temp ;
    if (str == NULL) str = (*str + 1);
    while( str[i] != *delim && str[i] != NULL)
    { 
        temp[i] = str[i];
        i++;
    }
    str[i] = NULL;
    printf("%s\n",str);
    return temp;
}
*/
int main(int argc, char const *argv[])
{
    char str[100] = "45- Tan Dat-";
    char *p;
/* 
    printf("%d\n", test_atoi(str));
    printf("%lf\n", test_atof(str));
    printf("%lf|", test_strtod(str, &p));
    printf("%s\n", p);
*/ 

    return 0;
}