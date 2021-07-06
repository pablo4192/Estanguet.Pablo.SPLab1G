#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parcial2_laboratorio1.h"
#include "parser.h"
#include "informes.h"
#include "LinkedList.h"
#include "utn.h"

void* asignarPorcentaje(void* pais)
{
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;

    if(pais!=NULL)
    {
        vac1Dosis=(rand() % 60 - 1 + 1) + 1;
        vac2Dosis=(rand() % 40 - 1 + 1) + 1;
        sinVacunar= 100 - (vac1Dosis + vac2Dosis);

        if(! (paisSetVac1Dosis(pais, vac1Dosis) && paisSetVac2Dosis(pais, vac2Dosis) && paisSetSinVacunar(pais, sinVacunar)))
        {
            printf("Hubo un error al cargar los porcentajes en los campos de ePais\n");
        }
    }
    return pais;    //retorno el pais seteado
}

int filtrarPaisExitoso(void* pais)
{
    int retorno=0;
    int vac2Dosis;

    if(pais!=NULL)
    {
        if(paisGetVac2Dosis(pais, &vac2Dosis))
        {
            if(vac2Dosis>30)
            {
                retorno=1;
            }
        }
    }
    return retorno;
}

int filtrarPaisAlHorno(void* pais)
{
    int retorno=0;
    int sinVacunar;
    int vac1Dosis;
    int vac2Dosis;

    if(pais!=NULL)
    {
       if( (paisGetVac1Dosis(pais, &vac1Dosis) && paisGetVac2Dosis(pais, &vac2Dosis) && paisGetSinVacunar(pais, &sinVacunar)) )
       {
           if(sinVacunar>(vac1Dosis+vac2Dosis))
           {
               retorno=1;
           }
       }
    }

    return retorno;
}

int ordenarPorVac1Dosis(void* a, void* b)
{
    int retorno=0;
    int vac1Dosis1;
    int vac1Dosis2;
    ePais* pais1=NULL;
    ePais* pais2=NULL;

    if(a!=NULL && b!=NULL)
    {
        pais1= (ePais*) a;
        pais2= (ePais*) b;
        if( (paisGetVac1Dosis(pais1, &vac1Dosis1) &&
             paisGetVac1Dosis(pais2, &vac1Dosis2)) )
        {
            if(vac1Dosis1>vac1Dosis2)
            {
                retorno=1;
            }
            else if(vac1Dosis1<vac1Dosis2)
            {
                retorno=-1;
            }
        }
    }

    return retorno;
}

int mostrarPaisMasCastigado(LinkedList* lista)
{
    int retorno=0;
    int tam;
    int sinVacunar;
    int mayor;
    ePais* auxPais=NULL;

    if(lista!=NULL)
    {
        tam=ll_len(lista);
        for(int i=0; i<tam; i++)
        {
            auxPais= (ePais*) ll_get(lista, i);
            if(auxPais!=NULL)
            {
                paisGetSinVacunar(auxPais, &sinVacunar);
                if(i==0 || sinVacunar>mayor)
                {
                    mayor=sinVacunar;
                    retorno=1;
                }
            }
        }
        printf("***Pais/es con mas cantidad de personas sin vacunar (castigado)***\n");
        printf("Id                Nombre     Vac1Dosis Vac2Dosis  SinVacunar\n");
        for(int i=0; i<tam; i++)
        {
            auxPais= (ePais*) ll_get(lista, i);
            paisGetSinVacunar(auxPais, &sinVacunar);
            if(sinVacunar==0)
            {
                printf("En la lista hay 0 personas sin vacunar, primero asigne porcentaje con la opcion 3\n");
                break;
            }
            if(sinVacunar==mayor)
            {
                mostrarPais(auxPais);
            }
        }
    }
    return retorno;
}











