#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int q0(char *, int, int);
int q1(char *, int, int);
int q2(char *, int, int);
int q3(char *, int, int);
int q4(char *, int, int);
int q5(char *, int, int, int);

int main()
{
    int index = 0, size; char *fita;

    fita = (char*)malloc(1000 * sizeof(char));
    if(fita != NULL) {
        do {
            system("cls");
            printf("\nINFORME UMA PALAVRA:");
            gets(fita);
            size = strlen(fita);
            if(q0(fita, index, size) == true) {
                printf("\nPALAVRA ACEITA\n\n");
            } else {
                printf("\nPALAVRA REJEITADA\n\n");
            }
            system("pause");
        } while(true);
    }
}

int q0(char *fita, int index, int size)
{
    if(fita[index] == 'x')
        return q1(fita, ++index, size);
    if(fita[index] == 'z')
        return q3(fita, ++index, size);
    return false;
}

int q1(char *fita, int index, int size)
{
    if(fita[index] == 'x')
        return q1(fita, ++index, size);
    if(q2(fita, index, size) == true || q3(fita, index, size) == true)
        return true;
    return false;
}

int q2(char *fita, int index, int size)
{
    if(fita[index] == 'y')
        return q2(fita, ++index, size);
    return q5(fita, index, size, 2);
}

int q3(char *fita, int index,  int size)
{
    if(fita[index] == 'z')
        return q3(fita, ++index, size);
    if(fita[index] == 'v')
        return q4(fita, ++index, size);
    return q5(fita, ++index, size, 3);
}

int q4(char *fita, int index,  int size)
{
    return q5(fita, ++index, size, 4);
}

int q5(char *fita, int index,  int size, int estado)
{
    if(estado == 2)
        if(index == size) return true;
    if(estado == 3 || estado == 4)
        if(--index == size) return true;
    return false;
}
