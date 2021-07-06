#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parcial2_laboratorio1.h"
#include "parser.h"
#include "informes.h"
#include "LinkedList.h"
#include "utn.h"

int cargarDatosTxt(LinkedList* lista, int* flagYaSeCargo)
{
    int retorno=0;
    char path[20];

    if(path!=NULL && lista!=NULL && *flagYaSeCargo==0)
    {
        printf("Ingrese path del archivo: \n");
        scanf("%s", path);
        FILE* f=fopen(path, "r");
        if(f!=NULL)
        {
            if(parser_PaisesFromTxt(f, lista))
            {
                retorno=1;
                *flagYaSeCargo=1;

            }
        }
        fclose(f);
    }

    return retorno;
}

int parser_PaisesFromTxt(FILE* pFile, LinkedList* lista)
{
    int retorno=0;
    char buffer[5][128];
    ePais* auxPais=NULL;

    if(pFile!=NULL && lista!=NULL)
    {
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        do
        {
            if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4])==5)
            {

                auxPais=newPaisParam(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                if(auxPais!=NULL)
                {
                    ll_add(lista, auxPais);
                    retorno=1;
                }
                else
                {
                    destroyPais(auxPais);
                }
            }
            else
            {
                printf("Hubo un problema al leer los datos desde el archivo\n");
            }

        }
        while(!feof(pFile));
    }
    return retorno;
}

int guardarDatosTxt(char* path, LinkedList* lista)
{
    int retorno=0;
    int tam;
    int id;
    char nombre[30];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
    ePais* auxPais=NULL;

    if(path!=NULL && lista!=NULL)
    {
        FILE* f=fopen(path, "w");
        if(f!=NULL)
        {
            fprintf(f, "Id, Nombre, vac1Dosis, vac2Dosis, sinVacunar\n");
            tam=ll_len(lista);
            for(int i=0; i<tam; i++)
            {
                auxPais= (ePais*) ll_get(lista, i);
                if(auxPais!=NULL)
                {
                    if( (paisGetId(auxPais, &id) &&
                         paisGetNombre(auxPais, nombre) &&
                         paisGetVac1Dosis(auxPais, &vac1Dosis) &&
                         paisGetVac2Dosis(auxPais, &vac2Dosis) &&
                         paisGetSinVacunar(auxPais, &sinVacunar)) )
                    {
                        if(fprintf(f, "%d, %s, %d, %d, %d\n", id, nombre, vac1Dosis, vac2Dosis, sinVacunar)<5)
                        {
                            printf("Hubo un problema al guardar los datos en el archivo de texto\n");
                            destroyPais(auxPais);
                            break;
                        }
                        else
                        {
                            auxPais=NULL;
                            retorno=1;
                        }
                    }
                }
            }
            fclose(f);
        }
        else
        {
            printf("No se pudo abrir el archivo '%s'\n", path);
        }
    }
    return retorno;
}




