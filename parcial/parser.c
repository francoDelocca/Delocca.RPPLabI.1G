#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pListaPaises)
{
    int cantParametros;
    ePais* auxPais;
    int todoOk = -1;
    char buffer[5][100];
    int flag = 1;

    if (pFile != NULL  && pListaPaises != NULL)
    {
        //fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile,"%[^,] , %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                flag = 0;
            }

            fscanf(pFile,"%[^,] , %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            //auxPais = nuevoPais();
            auxPais = nuevoPaisParam(buffer[0], buffer[1], buffer[2],  buffer[3], buffer[4]);
            if(auxPais != NULL){
                ll_add(pListaPaises, auxPais);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

//************************************************************************************************************************************/

