#include "LinkedList.h"

#ifndef PARCIAL2_LABORATORIO1_H_INCLUDED
#define PARCIAL2_LABORATORIO1_H_INCLUDED

typedef struct{
int id;
char nombre[30];
int vac1Dosis;
int vac2Dosis;
int sinVacunar;
}ePais;

#endif // PARCIAL2_LABORATORIO1_H_INCLUDED

/** \brief Muestra el menu de opciones
 *
 * \return int 1 exito, 0 error
 *
 */
int menu();

/** \brief  Setea el campo id de la estructura ePais
 *
 * \param pais ePais* Puntero estructura ePais
 * \param id int Id
 * \return int 1 exito, 0 error
 *
 */
int paisSetId(ePais* pais, int id);

/** \brief Genera una estructura ePais con los campos inicializados en 0, o " "
 *
 * \return ePais* Retorna una estructura ePais inicializada
 *
 */
ePais* newPais();

/** \brief Genera una estructura ePais con datos pasados por parametro
 *
 * \param strId char* Id del pais
 * \param strNombre char* Nombre del pais
 * \param strVac1Dosis char* Vacunados con la 1 dosis
 * \param strVac2Dosis char* Vacunados con la 2 dosis
 * \param strSinVacunar char* Cantidad de personas sin vacunar
 * \return ePais* Estructura ePais
 *
 */
ePais* newPaisParam(char* strId, char* strNombre, char* strVac1Dosis, char* strVac2Dosis, char* strSinVacunar);

/** \brief Setea el campo nombre de la estructura ePais
 *
 * \param pais ePais* Puntero estructura ePais
 * \param pNombre char* Nombre
 * \return int 1 exito, 0 error
 *
 */
int paisSetNombre(ePais* pais, char* pNombre);

/** \brief Setea el campo vac1Dosis de la estructura ePais
 *
 * \param pais ePais* Puntero estructura ePais
 * \param vac1Dosis int Cantidad de vacunados con la 1 dosis
 * \return int 1 exito, 0 error
 *
 */
int paisSetVac1Dosis(ePais* pais, int vac1Dosis);

/** \brief Setea el campo vac2Dosis de la estructura ePais
 *
 * \param pais ePais* Puntero estructura ePais
 * \param vac2Dosis int Cantidad de vacunados con la 2 dosis
 * \return int 1 exito, 0 error
 *
 */
int paisSetVac2Dosis(ePais* pais, int vac2Dosis);

/** \brief Setea el campo sinVacunar de la estructura ePais
 *
 * \param pais ePais* Puntero estructura ePais
 * \param sinVacunar int Cantidad de personas sin vacunar
 * \return int 1 exito, 0 error
 *
 */
int paisSetSinVacunar(ePais* pais, int sinVacunar);

/** \brief Libera memoria de una estructura que no se utiliza mas (destruye)
 *
 * \param pais ePais* Puntero estructura ePais
 * \return int 1 exito, 0 error
 *
 */
int destroyPais(ePais* pais);

/** \brief Copia el campo especificado en la variable pasada por referencia
 *
 * \param pais ePais* Puntero estructura ePais
 * \param pId int* Puntero a id
 * \return int 1 exito, 0 error
 *
 */
int paisGetId(ePais* pais, int* pId);

/** \brief Copia el campo especificado en la variable pasada por referencia
 *
 * \param pais ePais* Puntero estructura ePais
 * \param pNombre char* Puntero a nombre
 * \return int 1 exito, 0 error
 *
 */
int paisGetNombre(ePais* pais, char* pNombre);

/** \brief Copia el campo especificado en la variable pasada por referencia
 *
 * \param pais ePais*  Puntero estructura ePais
 * \param pVac1Dosis int* Puntero a pVac1Dosis
 * \return int 1 exito, 0 error
 *
 */
int paisGetVac1Dosis(ePais* pais, int* pVac1Dosis);

/** \brief Copia el campo especificado en la variable pasada por referencia
 *
 * \param pais ePais* Puntero estructura ePais
 * \param pVac2Dosis int* Puntero a pVac2Dosis
 * \return int 1 exito, 0 error
 *
 */
int paisGetVac2Dosis(ePais* pais, int* pVac2Dosis);

/** \brief Copia el campo especificado en la variable pasada por referencia
 *
 * \param pais ePais* Puntero estructura ePais
 * \param pSinVacunar int* Puntero a pSinVacunar
 * \return int 1 exito, 0 error
 *
 */
int paisGetSinVacunar(ePais* pais, int* pSinVacunar);

/** \brief Imprime el listado de paises
 *
 * \param lista LinkedList* LinkedList
 * \return int 1 exito, 0 error
 *
 */
int mostrarPaises(LinkedList* lista);

/** \brief Imprime 1 pais especifico
 *
 * \param unPais ePais* Estructura ePais
 * \return int 1 exito, 0 error
 *
 */
int mostrarPais(ePais* unPais);














