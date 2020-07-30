#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"
#include "Controller.h"
#include "validations.h"
#include "parser.h"
#include <ctype.h>
#include<string.h>

int controller_loadFromText(char* path, LinkedList* pListaPaises)
{
    int todoOk = -1;
    FILE* pFile;
    if(path != NULL && pListaPaises != NULL)
    {

        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_EmployeeFromText(pFile, pListaPaises) == 1)
            {
                todoOk = 1;
                printf("Paises cargadas correctamente. \n");
            }
            else
            {
                printf("No se pudieron cargar los paises.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
        }
    }

    return todoOk;
}

//************************************************************************************************************************************/
int controller_ListarPaises(LinkedList* pListaPaises)
{
    int todoOk = -1;
    int tam = ll_len(pListaPaises);
    int flag = 0;
    ePais* auxPais;

    if( pListaPaises != NULL)
    {
        todoOk = 1;
        printf("\n  Id                          Nombre                  recuperados                  infectados                 muertos \n");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {
            auxPais = ll_get(pListaPaises, i);
            if (  auxPais  != NULL )
            {
                mostrarPais( auxPais );
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf("\nNo hay paises que mostrar\n");
        }
    }
    return todoOk;

}

//************************************************************************************************************************************/
int controller_guardarComoTexto(char* path, LinkedList* pListaPaises)
{
    FILE* f = fopen(path,"w") ;
    int tam =  ll_len(pListaPaises);
    ePais* auxPais;
    int todoOk = -1;

    if(f != NULL)
    {
        fprintf(f,"id,nombre,recuperados,infectados,muertos\n");
        for (int i =0; i<tam; i++)
        {
            auxPais = (ePais*) ll_get(pListaPaises, i);
            if (auxPais !=NULL)
            {
                fprintf(f, "%d,%s,%d,%d,%d\n", auxPais->id, auxPais->nombre, auxPais->recuperados, auxPais->infectados, auxPais->muertos);
                todoOk = 1;
            }
        }
        fclose(f);

    }
    return todoOk;
}

//************************************************************************************************************************************/

int controller_sortPaises(LinkedList* pListaPaises)
{
    int ordenamiento = 1;
    int todoOk =-1;

    if( pListaPaises != NULL)
    {

       todoOk = ll_sort(pListaPaises, compararPaisesPorInfectados, ordenamiento);

    }

    return todoOk;
}

//************************************************************************************************************************************/

int controller_sortPaisesMuertos(LinkedList* pListaPaises)
{
    int ordenamiento = 1;
    int todoOk =-1;

    if( pListaPaises != NULL)
    {

       todoOk = ll_sort(pListaPaises, compararPaisesPorMuertos, ordenamiento);

    }

    return todoOk;
}

