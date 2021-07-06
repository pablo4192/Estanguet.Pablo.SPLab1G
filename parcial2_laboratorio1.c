#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parcial2_laboratorio1.h"
#include "parser.h"
#include "informes.h"
#include "LinkedList.h"
#include "utn.h"

int menu()
{
    int opcion;

    system("cls");
    printf("***Menu de opciones***\n");
    printf("1. Cargar datos desde archivo\n");  //ok
    printf("2. Imprimir lista\n");              //ok
    printf("3. Asignar estadisticas\n");        //ok
    printf("4. Filtrar por paises exitosos\n"); //ok
    printf("5. Filtrar por paises en el horno\n"); //ok
    printf("6. Ordenar por nivel de vacunacion\n"); //ok
    printf("7. Mostrar mas castigado\n");        //ok
    printf("8. Salir\n");                        //ok
    utn_getNumero(&opcion, "Ingrese opcion: \n", "Error, Ingrese opcion: \n", 0, 8, 2);

    return opcion;
}
//CONSTRUCTORES..
ePais* newPais()
{
    ePais* newPais= (ePais*) malloc(sizeof(ePais));
    if(newPais!=NULL)
    {
        newPais->id=0;
        strcpy(newPais->nombre, " ");
        newPais->vac1Dosis=0;
        newPais->vac2Dosis=0;
        newPais->sinVacunar=0;

    }
    return newPais;
}

ePais* newPaisParam(char* strId, char* strNombre, char* strVac1Dosis, char* strVac2Dosis, char* strSinVacunar)
{
    ePais* auxPais=newPais();
    if(auxPais!=NULL)
    {
        if(!(paisSetId(auxPais, atoi(strId)) &&
             paisSetNombre(auxPais, strNombre) &&
             paisSetVac1Dosis(auxPais, atoi(strVac1Dosis)) &&
             paisSetVac2Dosis(auxPais, atoi(strVac2Dosis)) &&
             paisSetSinVacunar(auxPais, atoi(strSinVacunar)) ))

        {
            destroyPais(auxPais);
        }
    }

    return auxPais;
}

//SETTERS
int paisSetId(ePais* pais, int id)
{
    int retorno=0;

    if(pais!=NULL && id>0)
    {
        pais->id=id;
        retorno=1;
    }

    return retorno;
}

int paisSetNombre(ePais* pais, char* pNombre)
{
    int retorno=0;

    if(pais!=NULL && pNombre!=NULL && (strlen(pNombre)>2 || strlen(pNombre)<30))
    {
        strcpy(pais->nombre, pNombre);
        retorno=1;
    }

    return retorno;
}

int paisSetVac1Dosis(ePais* pais, int vac1Dosis)
{
    int retorno=0;

    if(pais!=NULL && vac1Dosis>=0)
    {
        pais->vac1Dosis=vac1Dosis;
        retorno=1;
    }

    return retorno;
}

int paisSetVac2Dosis(ePais* pais, int vac2Dosis)
{
    int retorno=0;

    if(pais!=NULL && vac2Dosis>=0)
    {
        pais->vac2Dosis=vac2Dosis;
        retorno=1;
    }

    return retorno;
}

int paisSetSinVacunar(ePais* pais, int sinVacunar)
{
    int retorno=0;

    if(pais!=NULL && sinVacunar>=0)
    {
        pais->sinVacunar=sinVacunar;
        retorno=1;
    }

    return retorno;
}

//GETTERS..
int paisGetId(ePais* pais, int* pId)
{
    int retorno=0;

    if(pais!=NULL && pId!=NULL)
    {
        *pId=pais->id;
        retorno=1;
    }

    return retorno;
}

int paisGetNombre(ePais* pais, char* pNombre)
{
    int retorno=0;

    if(pais!=NULL && pNombre!=NULL)
    {
        strcpy(pNombre, pais->nombre);
        retorno=1;
    }

    return retorno;
}

int paisGetVac1Dosis(ePais* pais, int* pVac1Dosis)
{
    int retorno=0;

    if(pais!=NULL && pVac1Dosis!=NULL)
    {
        *pVac1Dosis=pais->vac1Dosis;
        retorno=1;
    }

    return retorno;
}

int paisGetVac2Dosis(ePais* pais, int* pVac2Dosis)
{
    int retorno=0;

    if(pais!=NULL && pVac2Dosis!=NULL)
    {
        *pVac2Dosis=pais->vac2Dosis;
        retorno=1;
    }

    return retorno;
}

int paisGetSinVacunar(ePais* pais, int* pSinVacunar)
{
    int retorno=0;

    if(pais!=NULL && pSinVacunar!=NULL)
    {
        *pSinVacunar=pais->sinVacunar;
        retorno=1;
    }

    return retorno;
}

//DESTRUCTOR..
int destroyPais(ePais* pais)
{
    int retorno=0;
    if(pais!=NULL)
    {
        free(pais);
        retorno=1;
    }
    return retorno;
}

//FUNCIONES DE ABM..
int mostrarPaises(LinkedList* lista)
{
    int retorno=0;
    int tam;
    if(lista!=NULL)
    {
        tam=ll_len(lista);
        printf("Id                Nombre     Vac1Dosis Vac2Dosis  SinVacunar\n");
        for(int i=0; i<tam; i++)
        {
            mostrarPais( (ePais*) ll_get(lista,i));
            retorno=1;
        }
        printf("\n\n");

    }
    return retorno;
}

int mostrarPais(ePais* unPais)
{
    int retorno=0;
    int id;
    char nombre[30];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;

    if(unPais!=NULL)
    {
        if( paisGetId(unPais, &id) &&
           paisGetNombre(unPais, nombre) &&
           paisGetVac1Dosis(unPais, &vac1Dosis) &&
           paisGetVac2Dosis(unPais, &vac2Dosis) &&
           paisGetSinVacunar(unPais, &sinVacunar))
        {
            printf("%2d  %20s           %3d       %3d        %3d\n", id, nombre, vac1Dosis, vac2Dosis, sinVacunar);
            retorno=1;
        }
    }
    return retorno;
}








