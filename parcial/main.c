#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#include "pais.h"
#include "controller.h"

int main()
{
    srand (time(NULL));
    char confirm ='n';
    char seguir = 's';
    char archivo[20];
    int posicionesAsignadas = -1;
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* paisesCastigados = ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese el nombre del archivo a cargar: ");
            scanf("%s", archivo);
            controller_loadFromText(archivo, listaPaises);
            system("pause");
            break;
        case 2:
            if( !ll_isEmpty(listaPaises))
            {
                controller_ListarPaises(listaPaises);
            }
            else
            {
                printf("La lista de paises esta vacia. Debe cargar al menos un pais primero.\n");
            }
            system("pause");
            break;
        case 3:

            if( !ll_isEmpty(listaPaises))
            {
                listaPaises = ll_map(listaPaises, cambiarEstadisticas);
                posicionesAsignadas = 1;
                controller_ListarPaises(listaPaises);
            }
            else
            {
                printf("No se pudo asignar nuevas estadisticas ya que la lista esta vacia, debe cargarla desde un archivo primero.\n");
            }
            system("pause");
            break;
        case 4:
            filtrarPorPaisExitoso(listaPaises);
            break;
        case 5:
            filtrarPorPaisHorno(listaPaises);
            break;
        case 6:
            if(posicionesAsignadas == 1 &&  !ll_isEmpty(listaPaises))
            {
                if (controller_sortPaises(listaPaises) != -1)
                {
                    controller_ListarPaises(listaPaises);
                }
            }else{
                printf("No se pudo asignar posiciones ya que la lista esta vacia o no se asignaron estadisticas, debe cargarla desde un archivo primero y asignarle nuevas estadisticas.\n");
            }

            system("pause");
            break;
            case 7:
            paisesCastigados = compararPaisesPorMuertos(listaPaises);
            if(posicionesAsignadas == 1 &&  !ll_isEmpty(paisesCastigados))
            {

                    controller_ListarPaises(paisesCastigados);

            }else{
                printf("No se pudo asignar posiciones ya que la lista esta vacia o no se asignaron estadisticas, debe cargarla desde un archivo primero y asignarle nuevas estadisticas.\n");
            }
            system("pause");
            break;

        case 8:
            printf("Esta seguro que desea salir? [s/n] : ");
            fflush(stdin);
            scanf("%c", &confirm);
            if (confirm == 's')
            {
                seguir = 'n';
            }
            break;
        }
    }
    while(seguir == 's');
    ll_deleteLinkedList(listaPaises);
    return 0;
}

