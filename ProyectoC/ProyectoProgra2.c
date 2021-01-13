/*
Programa: ColasPrioridadI2.c
Autor: Dueñas Contreras Yehoshuah Alexis
Fecha: 9/dic/2020
Descripción: Implentación dos de una cola prioritaria
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Constantes
#define VERDADERO 1
#define FALSO 0
#define MAX 50
//Definimos una cadena
typedef char sCadena[MAX];
//Estructuras
typedef struct Documentos {

  sCadena sNombre;
  sCadena sDescripcion;
  int iTipo;
  int iFactible;
  float fInversion;

}TrDoc;
//estructura de colas normales
typedef struct Cola {

  float Pri;
  TrDoc TrDato;
  struct Cola *pSiguiente;

}TrCola;

//Definimos un tipo apuntador a la estructura TrCola
typedef TrCola *pApuntaCo;

typedef struct CoPrio{

  sCadena sPrioridad;
  struct CoPrio *pAbajo;
  pApuntaCo pPrincipio;

}TrCoPrio;

//Definimos un tipo apuntador a la estructura TrCoPrio
typedef TrCoPrio *pApuntaPrio;

#include "ColasPrioridad.h"

//Funcion principal
int main() {
  //Variables de funcion principal
  pApuntaPrio InicioPri = NULL, pColaPri2 = NULL, FinalPri = NULL;
  pApuntaCo   pFinal1 = NULL, pFinal2 = NULL, pFinal3 = NULL;
  int iOpc, iContador = 0;
  TrDoc AuxDatos, aHistorial[MAX];




  //iniciamos cola prioritaria
  InicioPri = (pApuntaPrio) calloc (1, sizeof (TrCoPrio));
  strcpy(InicioPri->sPrioridad, "Prioridad Maxima");
  InicioPri -> pAbajo = NULL;
  InicioPri -> pPrincipio = NULL;
  pColaPri2 = (pApuntaPrio) calloc (1, sizeof (TrCoPrio));
  InicioPri -> pAbajo = pColaPri2;
  strcpy(pColaPri2->sPrioridad, "Prioridad Media");
  pColaPri2 -> pAbajo = NULL;
  pColaPri2 -> pPrincipio = NULL;
  FinalPri  = (pApuntaPrio) calloc (1, sizeof (TrCoPrio));
  pColaPri2 -> pAbajo = FinalPri;
  strcpy(FinalPri->sPrioridad, "Prioridad Minima");
  FinalPri  -> pAbajo = NULL;
  FinalPri  -> pPrincipio = NULL;



  do {
    system("clear");
  printf("\t\t\t=======Bienvenido=======\n");
  printf("\tSoftware para la toma de decisiones de la republica\n");
  printf("\t\tESTADOS UNIDOS MEXICANOS\n");
  printf("\t\t\tGobierno de la nacion\n\n");
  printf("\t\t 1.Registrar un [documento]/[contrato]\n\t\t 2.Ver prioridades\n\t\t"
        " 3.Marcar como realizado [desencolar documento/contrato]\n\t\t"
        " 4. Ver Historial de documentos realizados\n\t\t 5.Salir\n\n");
  printf("Ingrese una opcion:[ ]\b\b");
  scanf("%i", &iOpc);
    switch (iOpc) {

      case 1: Encolar(&InicioPri, &pColaPri2, &FinalPri, &pFinal1, &pFinal2, &pFinal3);
          break;
      case 2: MostrarCola(InicioPri, pColaPri2, FinalPri);
          break;

      case 3: AuxDatos = Desencolar(&InicioPri, &pColaPri2, &FinalPri, &pFinal1, &pFinal2, &pFinal3);
              if (AuxDatos.iTipo == -1) {
                  printf("No hay habia nada\n");
              } else {

                //iContador2++;


                strcpy(aHistorial[iContador].sNombre, AuxDatos.sNombre);
                printf("funciona\n");
                strcpy(aHistorial[iContador].sDescripcion, AuxDatos.sDescripcion);
                aHistorial[iContador].iTipo = AuxDatos.iTipo;
                aHistorial[iContador].iFactible = AuxDatos.iFactible;
                aHistorial[iContador].fInversion = AuxDatos.fInversion;
                //strcpy(AuxArray[iContador2-1].sNombre, aHistorial[iContador-1].sNombre);
                //strcpy(AuxArray[iContador2-1].sDescripcion, aHistorial[iContador-1].sDescripcion);
                //AuxArray[iContador2-1].iTipo =  aHistorial[iContador-1].iTipo;
                //AuxArray[iContador2-1].iFactible =  aHistorial[iContador-1].iFactible;
                //AuxArray[iContador2-1].fInversion =  aHistorial[iContador-1].fInversion;
                printf("funciona\n");
                iContador++;
              }
               getchar();
               getchar();
        break;
      case 4:  Mostrar_Elminados(aHistorial, iContador);


        break;
      case 5: system("clear");
              printf("¡Hasta pronto!\n");
        break;
        default: puts("Error en la seleccion\n");
    }
  } while(iOpc != 5);


  free(InicioPri);
  free(pColaPri2);
  free(FinalPri);

  return 0;
}
