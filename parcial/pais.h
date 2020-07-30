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
/** \brief recibe por parametro el valor del nombre que le asignara al pais recibido
 *
 * \param ePais
 * \param char nombre
 * \return 1 o -1
 *
 */

int pais_setRecuperados(ePais* this, int recuperados);
/** \brief recibe por parametro el valor de recuperados que le asignara al pais recibido
 *
 * \param ePais* puntero a la ePais a modificar
 * \param int recuperados que se le asignara al ePais recibido
 * \return 1 si pudo asignarla, -1 si no
 *
 */

int pais_setInfectados(ePais* this, int infectados);
/** \brief recibe por parametro el valor de infectados que le asignara al pais recibido
 *
 * \param ePais* puntero a la ePais a modificar
 * \param int infectados que se le asignara al ePais recibido
 * \return 1 si pudo asignarla, -1 si no
 *
 */

 int pais_setMuertos(ePais* this, int muertos);
/** \brief recibe por parametro el valor de muertos que le asignara al pais recibido
 *
 * \param ePais* puntero a la ePais a modificar
 * \param int muertos que se le asignara al ePais recibido
 * \return 1 si pudo asignarla, -1 si no
 *
 */

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */
 int pais_getId(ePais* this, int* id);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 int pais_getNombre(ePais* this, char* nombre);

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
/** \brief borra el pais que se le pasa
 *
 * \param
 * \param
 * \return
 *
 */

 int mostrarPais(ePais* this);
/** \brief muestra el pais que se paso como parametro
 *
 * \param
 * \param
 * \return
 *
 */

void* cambiarEstadisticas(void* this);
/** \brief genera numeros random y los asigna al pais
 *
 * \param
 * \param
 * \return
 *
 */

void filtrarPorPaisExitoso(LinkedList* this);
/** \brief filtra por pais exitoso
*
* \param
* \param
* \return
*
*/

int paisExitoso(void* this);
/** \brief se fija si el pais tiene menos de 5000 muertos y lo agrega al orden
*
* \param
* \param
* \return
*
*/

void filtrarPorPaisHorno(LinkedList* this);
/** \brief filtra por pais al horno
*
* \param
* \param
* \return
*
*/

int paisHorno(void* this);
/** \brief se fija si el pais esta al horno (cuando la cantidad de infectados triplica la cantidad de recuperados)
*
* \param
* \param
* \return
*
*/

int compararPaisesPorInfectados(void* paisA,void* paisB);
/** \brief compara los infectados de un pais con los del otro
 *
 * \param
 * \param
 * \return
 *
 */

 LinkedList* compararPaisesPorMuertos(LinkedList* this);
/** \brief ve la lista que se le pasa, genera una nueva lista con los datos ya comparados y la devuelve
 *
 * \param LinkedList this
 * \param
 * \return
 *
 */
