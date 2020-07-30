#include <stdio.h>
#include <stdlib.h>
#include "pais.h"
#include "validations.h"
#include <string.h>
#include "Controller.h"

//************************************************************************************************************************************/
int menu()
{
    int option;

    system("cls");
    printf("**** Menu de pandemia **** \n\n");
    printf("1.   Cargar archivo. \n");
    printf("2.   Listar paises. \n");
    printf("3.   Asignar estadisticas.\n");
    printf("4.   Filtrar por pais exitoso.\n");
    printf("5.   Filtrar por pais en el horno.\n");
    printf("6.   Ordenar por nivel de infeccion. \n");
    printf("7.   Mostrar mas castigado.\n");
    printf("8.   Salir.\n");
    if(utn_getNumero(&option, "Enter option: ","",1,8,0) == -1)
    {
        option = 0;
    }

    return option;

}

//************************************************************************************************************************************/
ePais* nuevoPais()
{
    return (ePais*) malloc(sizeof(ePais));
}

//************************************************************************************************************************************/
ePais* nuevoPaisParam(char* idStr, char* nombre, char* recuperadosStr, char* infectadosStr, char* muertosStr)
{
    ePais*  paisNuevo;

    paisNuevo = nuevoPais();

    if(paisNuevo != NULL)
    {

        if   ( (pais_setId(paisNuevo, atoi(idStr)) == -1) ||
                (pais_setNombre(paisNuevo, nombre) ==-1) ||
                (pais_setRecuperados(paisNuevo, atoi(recuperadosStr)) ==-1) ||
                (pais_setInfectados(paisNuevo, atoi(infectadosStr)) ==-1) ||
                (pais_setMuertos(paisNuevo, atoi(muertosStr)) ==-1))

        {

            borrarPais(paisNuevo);
            paisNuevo = NULL;
        }

    }
    return paisNuevo;
}

//************************************************************************************************************************************/
int pais_setId(ePais* this, int id)
{
    int todoOk = -1;

    if ( this != NULL && id > 1 && id <= 1000)
    {
        this-> id = id;
        todoOk = 1;
    }
    return todoOk;
}
//************************************************************************************************************************************/
int pais_setNombre(ePais* this, char* nombre)
{
    int todoOk = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 30)
    {
        strcpy(this -> nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

//************************************************************************************************************************************/
int pais_setRecuperados(ePais* this, int recuperados)
{
    int todoOk = -1;

    if (this != NULL && recuperados >= 0 && recuperados <= 1000000)
    {
        this-> recuperados = recuperados;
        todoOk = 1;
    }
    return todoOk;
}

//************************************************************************************************************************************/
int pais_setInfectados(ePais* this, int infectados)
{
    int todoOk = -1;

    if ( this != NULL && infectados >= 0 && infectados <= 2000000)
    {
        this-> infectados = infectados;
        todoOk = 1;
    }
    return todoOk;
}

int pais_setMuertos(ePais* this, int muertos)
{
    int todoOk = -1;

    if ( this != NULL && muertos >= 0 && muertos <= 50000)
    {
        this->muertos = muertos;
        todoOk = 1;
    }
    return todoOk;
}

//************************************************************************************************************************************/
int pais_getRecuperados(ePais* this, int* recuperados)
{
    int todoOk = -1;
    if (this!= NULL && recuperados != NULL)
    {
        *recuperados = this-> recuperados;
        todoOk =1;
    }
    return todoOk;

}

int pais_getInfectados(ePais* this, int* infectados)
{
    int todoOk = -1;
    if (this!= NULL && infectados != NULL)
    {
        *infectados = this-> infectados;
        todoOk =1;
    }
    return todoOk;

}

int pais_getId(ePais* this, int* id)
{
    int todoOk = -1;
    if (this!= NULL && id != NULL)
    {
        *id = this-> id;
        todoOk =1;
    }
    return todoOk;

}

int pais_getNombre(ePais* this, char* nombre)
{
    int todoOk = -1;
    if (this!= NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk =1;
    }
    return todoOk;

}

//************************************************************************************************************************************/
int pais_getMuertos(ePais* this, int* muertos)
{
    int todoOk = -1;
    if (this!= NULL && muertos != NULL)
    {
        *muertos = this-> muertos;
        todoOk =1;
    }
    return todoOk;

}
//************************************************************************************************************************************/

void borrarPais(ePais* this )
{

    if ( this != NULL)
    {
        free(this);
    }

}

//************************************************************************************************************************************/
int mostrarPais(ePais* this)
{
    int id;
    char nombre[50];
    int recu;
    int infe;
    int muert;

    int todoOk =-1;
    if(this != NULL)
    {
        pais_getInfectados(this, &infe);
        pais_getRecuperados(this, &recu);
        pais_getMuertos(this, &muert);
        pais_getId(this, &id);
        pais_getNombre(this, nombre);
        todoOk = 1;
        printf("%4d  %30s                        %7d                   %7d                  %7d \n", id, nombre, recu, infe, muert);
    }
    return todoOk;
}

//************************************************************************************************************************************/
void* cambiarEstadisticas(void* this)
{
    ePais* auxPais;
    void * retorno = NULL;
    int aleatorioRecu;
    int aleatorioInfec;
    int aleatorioMuerto;
    if( this != NULL)
    {
        auxPais= (ePais*) this;
        aleatorioRecu = rand()%(1000001)+50000;
        aleatorioInfec = rand()%(2000001)+40000;
        aleatorioMuerto = rand()%(50001)+1000;
        pais_setRecuperados(auxPais, aleatorioRecu);
        pais_setInfectados(auxPais, aleatorioInfec);
        pais_setMuertos(auxPais, aleatorioMuerto);
        retorno = (void*) auxPais;
    }
    return retorno;
}

//************************************************************************************************************************************/
void filtrarPorPaisExitoso(LinkedList* this)
{
    LinkedList* listaFiltrada = NULL;
    listaFiltrada = ll_filter(this, paisExitoso);
    if( !ll_isEmpty(listaFiltrada))
    {
        controller_guardarComoTexto("paisesExitosos.csv", listaFiltrada);
        printf("Se han guardado satisfactoriamente los paises con menos de 5000 muertos en el archivo paisesExitosos.csv .\n");
    }
    else
    {
        printf("No se genero un archivo ya que no hay paises con menos de 5000 muertos.\n");
    }
    system("pause");

}


//************************************************************************************************************************************/
int paisExitoso(void* this)
{
    ePais* auxPais;
    int retorno = -1;
    int muertos;

    if( this != NULL)
    {
        auxPais = (ePais*) this;

        if (pais_getMuertos(auxPais, &muertos) != -1)
        {
            if(muertos <= 5000)
            {
                retorno =1;
            }
        }

    }
    return retorno;
}

//************************************************************************************************************************************/
void filtrarPorPaisHorno(LinkedList* this)
{
    LinkedList* listaFiltrada = NULL;
    listaFiltrada = ll_filter(this, paisHorno);
    if( !ll_isEmpty(listaFiltrada))
    {
        controller_guardarComoTexto("paisesEnElHorno.csv", listaFiltrada);
        printf("Se han guardado satisfactoriamente los paises que estan al horno con el triple de recuperados como infectados en el archivo paisesEnElHorno.csv .\n");
    }
    else
    {
        printf("No se genero un archivo ya que no hay paises en el horno.\n");
    }
    system("pause");

}


//************************************************************************************************************************************/
int paisHorno(void* this)
{
    ePais* auxPais;
    int retorno = -1;
    int infectados;
    int recuperados;

    if( this != NULL)
    {
        auxPais = (ePais*) this;

        if (pais_getRecuperados(auxPais, &recuperados) != -1 && pais_getInfectados(auxPais, &infectados) != -1)
        {

            if(infectados >= (recuperados * 3))
            {
                retorno =1;
            }
        }

    }
    return retorno;
}

//************************************************************************************************************************************/
int compararPaisesPorInfectados(void* paisA,void* paisB)
{
    int orden = 0;

    if( paisA != NULL && paisB != NULL )
    {
        ePais* pPaisA = (ePais*) paisA;
        ePais* pPaisB = (ePais*) paisB;
        int infectadosPaisA;
        int infectadosPaisB;

        pais_getInfectados(pPaisA, &infectadosPaisA);
        pais_getInfectados(pPaisB, &infectadosPaisB);


            if(infectadosPaisA < infectadosPaisB)
            {
                orden = 1;
            }else
            {
                orden = -1;
            }

    }
    return orden;
}

//************************************************************************************************************************************/
LinkedList* compararPaisesPorMuertos(LinkedList* this)
{
    LinkedList* listaPaises = NULL;

    int mayorMuertos = 0;
    ePais* paisActual = NULL;
    int muertosActual = 0;
    int flag = 1;
    int i;
    int h;
    if(this == NULL)
    {
        printf("No hay lista a la que buscar muertos");
    }
    else
    {
        listaPaises = ll_newLinkedList();

        for(i = 0; i <ll_len(this) ; i++)
        {

            paisActual = ll_get(this, i);
            pais_getMuertos(paisActual, &muertosActual);
            if(muertosActual > mayorMuertos || flag)
            {
                mayorMuertos = muertosActual;
                flag = 0;
            }
        }

        for(h = 0; h < ll_len(this) ; h++){
            paisActual = ll_get(this, h);
            pais_getMuertos(paisActual, &muertosActual);
            if(mayorMuertos == muertosActual){
                ll_add(listaPaises, paisActual);
            }
        }
    }

    printf("El numero de mayores muertos es %d \n", mayorMuertos);

    return listaPaises;
}

