#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Asigna porcentaje al campo especificado de la estructura ePais
 *
 * \param pais void* Puntero a void
 * \return void* 1 exito, 0 error
 *
 */
void* asignarPorcentaje(void* pais);

/** \brief Filtra los paises de la lista por cantidad de personas vacunadas
 *
 * \param pais void* Puntero a void
 * \return int 1 exito, 0 error
 *
 */
int filtrarPaisExitoso(void* pais);

/** \brief Filtra pais segun cantidad de personas sin vacunar
 *
 * \param pais void* Puntero a void
 * \return int 1 exito, 0 error
 *
 */
int filtrarPaisAlHorno(void* pais);

/** \brief Ordena los paises en orden descendente segun cantidad de vacunados con la primer dosis
 *
 * \param a void* Puntero a void a
 * \param b void* Puntero a void b
 * \return int 1 exito, 0 error
 *
 */
int ordenarPorVac1Dosis(void* a, void* b);

/** \brief Imprime en pantalla el o los paises mas castigados
 *
 * \param lista LinkedList* Puntero a LinkedList
 * \return int 1 exito, 0 error
 *
 */
int mostrarPaisMasCastigado(LinkedList* lista);
