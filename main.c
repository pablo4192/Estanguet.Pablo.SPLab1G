#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "parcial2_laboratorio1.h"
#include "parser.h"
#include "informes.h"
#include "LinkedList.h"
#include "utn.h"

int main()
{
    char seguir='s';
    char confirma;
    int flagYaSeCargo=0;
    srand(time(NULL));

    LinkedList* lista=ll_newLinkedList();
    if(lista==NULL)
    {
        printf("No se pudo crear el linkedList\n");
        system("pause");
        exit(1);
    }

    LinkedList* listaExitosos=NULL;
    LinkedList* listaAlHorno=NULL;
    LinkedList* listaOrdenadaVac1Dosis=NULL;

    do
    {

        switch(menu())
        {
        case 1:
            if(!cargarDatosTxt(lista, &flagYaSeCargo))
            {
                printf("Hubo un problema al cargar los datos desde el archivo\n");
            }
            else
            {
                printf("Datos cargados desde el archivo con exito!!\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            if(!mostrarPaises(lista))
            {
                printf("No hay paises en la lista\n");
            }
            system("pause");
            break;
        case 3:
            if(flagYaSeCargo==1)
            {
                if(ll_map(lista, asignarPorcentaje)==NULL)
                {
                    printf("Hubo un problema al asignar los porcentajes a los campos ePais\n");
                }
                else
                {
                    printf("Campos de ePais cargados exitosamente!!\n");
                }
            }
            else
            {
                printf("No se pueden asignar porcentajes a los campos ya que no se cargaron datos desde el archivo\n");
            }
            system("pause");
            break;
        case 4:
            if(flagYaSeCargo==1)
            {
                listaExitosos = ll_filter(lista, filtrarPaisExitoso);
                if(listaExitosos!=NULL)
                {
                    guardarDatosTxt("paisesExitosos.txt", listaExitosos);
                    printf("Se creo un nuevo archivo con los paises exitosos!!\n");
                }
                else
                {
                    printf("Hubo un problema al filtrar los paises exitosos\n");
                }
            }
            else
            {
                printf("No se puede filtrar ya que no se cargaron datos desde el archivo\n");
            }
            system("pause");
            break;
        case 5:
            if(flagYaSeCargo==1)
            {
                listaAlHorno=ll_filter(lista, filtrarPaisAlHorno);
                if(listaAlHorno!=NULL)
                {
                    guardarDatosTxt("paisesAlHorno.txt", listaAlHorno);
                    printf("Se creo un nuevo archivo con los paises al horno!!\n");
                }
                else
                {
                    printf("Hubo un problema al filtrar los paises al horno\n");
                }
            }
            else
            {
                printf("No se puede filtrar ya que no se cargaron datos desde el archivo\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            listaOrdenadaVac1Dosis=ll_clone(lista);
            if(listaOrdenadaVac1Dosis!=NULL)
            {
                if(!ll_sort(listaOrdenadaVac1Dosis, ordenarPorVac1Dosis, 0))    //orden descendente
                {
                    printf("Listado de paises ordenado por vac1Dosis en orden descendente:\n\n");
                    mostrarPaises(listaOrdenadaVac1Dosis);
                }
                else
                {
                    printf("Hubo un error al ordenar los paises\n");
                }
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(!mostrarPaisMasCastigado(lista))
            {
                printf("Ocurrio un problema al mostrar los paises mas castigados\n");
            }
            system("pause");
            break;
        case 8:
            confirmacion(&confirma, "Seguro que desea salir? s(si) n(no): \n", "Error, Seguro que desea salir? s(si) n(no): \n", 2);
            if(confirma=='s')
            {
                seguir='n';
            }
            else
            {
                printf("Salida cancelada por el usuario\n");
                system("pause");
            }
            break;

        }

    }
    while(seguir=='s');

    return 0;
}
