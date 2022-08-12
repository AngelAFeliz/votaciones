#include <stdio.h>
#include <stdlib.h>

#define mPROGRAMACION 1
#define mMEDICINA    2
#define mMECATRONICA 3
#define PROGRAMACION  0
#define MEDICINA     1
#define MECATRONICA  2
#define SALIR        0
#define cantVotos    3
/*
Este programa es utilizado para
capturar la informacion
de una encuesta
*/
int main()
{
    unsigned int opc[cantVotos]; // estructura de datos de la votacion
    int tam = sizeof(opc) /sizeof(*opc);
    //printf("tamano de opc es: %d", tam);
    opc[0] = 0;
    opc[1] = 0;
    opc[2] = 0;
    opc[3] = 0;
    int temp = 0;//esta variable es para almacenar el valor mayor encontrado
    int valorE = -1;//Variable para captura de valor menu
    int ganador = -1;
    int empate = 0;

    printf("\nHola biembenidos a las botaciones!\n");

    while(valorE != 0)
    {
        printf("Elije tu votacion\n");
        printf("0 - Salir\n");
        printf("1 - Estudiar Programacion\n");
        printf("2 - Estudiar Medicina\n");
        printf("3 - Estudiar Mecatronica\n");

        scanf("%d",&valorE);

        if(valorE == mPROGRAMACION)
        {
            opc[PROGRAMACION] += 1;
        }
        else if(valorE == mMEDICINA)
        {
            opc[MEDICINA] += 1;
        }
        else if(valorE == mMECATRONICA)
        {
            opc[MECATRONICA] += 1;
        }
        else if(valorE == SALIR)
        {
            break;
        }
        else
        {
            printf("Valor no valido\n");
        }
    }//end while
  
    printf("Resultados Estudiar Programacion %d\n",opc[PROGRAMACION]);
    printf("Resultados Estudiar Medicina %d\n", opc[MEDICINA]);
    printf("Resultados Estudiar Mecatronica %d\n", opc[MECATRONICA]);

    //algoritmo de busqueda de mayor
    temp = opc[0];
    ganador = 0;
    for(int i = 0; i < cantVotos; i++)
    {
        if(temp < opc[i])
        {
            temp = opc[i];
            ganador = i;
        }
    }
    for(int i = 0; i < cantVotos; i++)
    {
        if(temp == opc[i])
        {
            empate +=1;
        }
    }
    //printf("\nGanador es %d con %d votos",ganador,temp);
    if(empate < 2 && empate > -1)
    {
        if(ganador == PROGRAMACION)
        {
            printf("\nGanador es Programacion con %d votos",temp);
        }
        else if (ganador == MEDICINA)
        {
            printf("\nGanador es Medicina con %d votos",temp);
        }
        else if(ganador == MECATRONICA)
        {
            printf("\nGanador es Mecatronica con %d votos",temp);
        }
    }else {
        printf("\nVotaciones canceladas por empate\n\n");
    }
    return 0;
}//end main