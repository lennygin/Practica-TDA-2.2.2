#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct Neural
{
    float x[2];
    float w[2];
    struct Neural *nextn;
} neural;

neural *new_neural()
{
    neural *temp;
    temp = (neural *)malloc(sizeof(neural));
    temp->nextn = NULL;
    return temp;
}

void OR(neural **Inicio)
{
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;

    neural *temp;
    temp = *Inicio;
    n = 0.5;
    temp->w[0] = 0.5;
    temp->w[1] = 0.5;
    printf("Inserta tu 1era entrada(0 o 1): ");
    scanf("%f", &temp->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1): ");
    scanf("%f", &temp->x[1]);

    if ((temp->x[0] == 0) && (temp->x[1] == 0))
    {
        Y = 0;
        temp->x[0] = 0.1;
        temp->x[1] = 0.1;
        printf("primer if yey");
    }
    else if ((temp->x[0] == 0) && (temp->x[1] == 1))
    {
        Y = 1;
        temp->x[0] = 0.1;
        printf("if 0 y 1");
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 0))
    {
        Y = 1;
        temp->x[1] = 0.1;
        printf("if 1 y 0");
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 1))
    {
        Y = 1;
        printf("if 1 y 1");
    }

    while (i <= 500)
    {
        Z = (temp->w[0] * temp->x[0]) + (temp->w[1] * temp->x[1]);
        Yp = (1) / (exp(-1 * Z) + 1);
        E = (Y - Yp);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        temp->w[1] = temp->w[1] + (n * E * temp->x[1]);
        printf("%d salida -> %f\nE %f\n", i, Yp, Y);

        if (Yp < 0.2)
            printf("Final 0 \n");

        if (Yp > 0.8)
            printf("Final 1 \n");

        i++;
    }
}

void AND(neural **Inicio)
{
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;

    neural *temp;
    temp = *Inicio;
    n = 0.5;
    temp->w[0] = 0.5;
    temp->w[1] = 0.5;
    printf("Inserta tu 1era entrada(0 o 1): ");
    scanf("%f", &temp->x[0]);
    printf("Inserta tu 2nda entrada(0 o 1): ");
    scanf("%f", &temp->x[1]);

    if ((temp->x[0] == 0) && (temp->x[1] == 0))
    {
        Y = 0;
        temp->x[0] = 0.1;
        temp->x[1] = 0.1;
        printf("primer if yey");
    }
    else if ((temp->x[0] == 0) && (temp->x[1] == 1))
    {
        Y = 0;
        temp->x[0] = 0.1;
        printf("if 0 y 1");
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 0))
    {
        Y = 0;
        temp->x[1] = 0.1;
        printf("if 1 y 0");
    }
    else if ((temp->x[0] == 1) && (temp->x[1] == 1))
    {
        Y = 1;
        printf("if 1 y 1");
    }

    while (i <= 500)
    {
        Z = (temp->w[0] * temp->x[0]) + (temp->w[1] * temp->x[1]);
        Yp = (1) / (exp(-1 * Z) + 1);
        E = (Y - Yp);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        temp->w[1] = temp->w[1] + (n * E * temp->x[1]);
        printf("%d salida -> %f\n", i, Yp);

        if (Yp < 0.2)
            printf("Final 0 \n");

        if (Yp > 0.8)
            printf("Final 1 \n");

        i++;
    }
}

void XOR(neural **Inicio)
{
    printf("XOR");
}

void NOT(neural **Inicio)
{
    float n = 0, E = 0, Y, Yp = 0, Z = 0;
    int i = 0;

    neural *temp;
    temp = *Inicio;
    n = 0.9;
    temp->w[0] = 0.5;
    printf("Inserta tu entrada(0 o 1):\n");
    scanf("%f", &temp->x[0]);

    if (temp->x[0] == 0)
    {
        Y = 1;
        temp->x[0] = 0.1;
    }
    else
    {
        Y = 0;
    }

    while (i <= 500)
    {
        Z = temp->w[0] * temp->x[0];
        Yp = (1) / (exp(-1 * Z) + 1);
        E = (Y - Yp);
        temp->w[0] = temp->w[0] + (n * E * temp->x[0]);
        printf("\n%d salida -> %f\n", i, Yp);

        if (Yp < 0.2)
            printf("Final 0 \n");

        if (Yp > 0.8)
            printf("Final 1 \n");

        i++;
    }
}

void XNOR(neural **Inicio)
{
    printf("XNOR");
}