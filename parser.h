#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief Carga los datos desde el archivo
 *
 * \param lista LinkedList* LinkedList
 * \param flagYaSeCargo int* Flag que me indica si ya se cargaron los datos 1 vez, o no
 * \return int 1 exito, 0 error
 *
 */
int cargarDatosTxt(LinkedList* lista, int* flagYaSeCargo);

/** \brief Parsea los datos desde el archivo
 *
 * \param pFile FILE* Puntero a FILE
 * \param lista LinkedList* LinkedList
 * \return int 1 exito, 0 error
 *
 */
int parser_PaisesFromTxt(FILE* pFile, LinkedList* lista);

/** \brief Guarda los datos en el archivo
 *
 * \param path char* Path del archivo a guardar
 * \param lista LinkedList* LinkedList
 * \return int 1 exito, 0 error
 *
 */
int guardarDatosTxt(char* path, LinkedList* lista);
