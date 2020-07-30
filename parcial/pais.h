#include "LinkedList.h"
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    int recuperados;
    int infectados;
    int muertos;
}ePais;


#endif // PAIS_H_INCLUDED

int menu();
/** \brief muestra opciones y devuelve la elegida por el usuario
 *
 * \return opcion elegida por el usuario
 *
 */

ePais* nuevoPais();
/** \brief constructor de ePais
 *
 * \return un puntero a una ePais
 *
 */

ePais* nuevoPaisParam(char* idStr, char* nombre, char* recuperadosStr, char* infectadosStr, char* muertosStr);
/** \brief constructor de ePais con atributos pasados por parametro
 *
 * \param char id del pais a crear
 * \param char nombre del pais a crear
 * \param char recuperados del pais a crear
 * \param char infectados del pais a crear
 * \param char muertos del pais a crear
 * \return
 *
 */

int pais_setId(ePais* this, int id);
/** \brief recibe por parametro el valor del id que le asignara al pais recibido
 *
 * \param ePais* puntero a la ePais a modificar
 * \param int id que se le asignara al ePais recibido
 * \return 1 si pudo asignarla, -1 si no
 *
 */

int pais_setNombre(ePais* this, char* nombre);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int pais_setRecuperados(ePais* this, int recuperados);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int pais_setInfectados(ePais* this, int infectados);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int pais_setMuertos(ePais* this, int muertos);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int pais_getRecuperados(ePais* this, int* recuperados);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

int pais_getInfectados(ePais* this, int* infectados);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int pais_getMuertos(ePais* this, int* muertos);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void borrarPais(ePais* this );
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int mostrarPais(ePais* this);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void* cambiarEstadisticas(void* this);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void filtrarPorPaisExitoso(LinkedList* this);
/** \brief
*
* \param
* \param
* \return
*
*/

int paisExitoso(void* this);
/** \brief
*
* \param
* \param
* \return
*
*/

void filtrarPorPaisHorno(LinkedList* this);
/** \brief
*
* \param
* \param
* \return
*
*/

int paisHorno(void* this);
/** \brief
*
* \param
* \param
* \return
*
*/

int compararPaisesPorInfectados(void* paisA,void* paisB);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 LinkedList* compararPaisesPorMuertos(LinkedList* this);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
