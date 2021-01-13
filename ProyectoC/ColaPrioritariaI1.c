/*
Programa: ColasPrioridadI1.c
Autor: Due√±as Contreras Yehoshuah Alexis
Fecha: 9/dic/2020
Descripci√≥n: Implentaci√≥n uno de una cola prioritaria
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//Constantes
#define VERDADERO 1
#define FALSO 0
//Estructura
typedef struct ColaPri {
  int Pri;
  struct ColaPri *pSiguiente;
}TrCoPr;
//Tipo abstracto apuntador
typedef TrCoPr *pApuntador;
//Prototipos
int Cola_Llena();
int Cola_vacia(pApuntador ini);
int Encolar(pApuntador *ini, pApuntador *fin, int ele);
int Desencolar(pApuntador *ini);
void Ver_frente(pApuntador ini);
void Ver_cola(pApuntador ini);
//Funcion principal
int main() {
  //Variables locales
  pApuntador pInicio = NULL, pFinal = NULL;
printf("Encolar 1: %d\n", Encolar(&pInicio, &pFinal, 30));

 printf("\nEncolar 2: %d", Encolar(&pInicio, &pFinal, 50));
  
  printf("\nEncolar 3: %d\n", Encolar(&pInicio, &pFinal, 10));
  
  printf("\nEncolar 4: %d", Encolar(&pInicio, &pFinal, 40));
  
  printf("\nEncolar 5: %d\n", Encolar(&pInicio, &pFinal, 20));
  
	
  Ver_frente(pInicio);
  Ver_cola(pInicio);



  return 0;
}
//Definiciones
int Cola_Llena(){
  if ((pApuntador) calloc(1, sizeof(TrCoPr)) == NULL) {
    return VERDADERO;
  } else {
    return FALSO;
  }

}
int Cola_vacia(pApuntador ini){
  if (ini == NULL) {
    return VERDADERO;
  } else {
    return FALSO;
  }
}
int Encolar(pApuntador *ini, pApuntador *fin, int ele){
  //Variables locales
  pApuntador pNuevo, pTemporal, aux;
  int elemento;
  //Reservamos espacio de memoria para la estructura
  pNuevo = (pApuntador) calloc (1, sizeof(TrCoPr));
  //Metemos el elemento a la estructura
  pNuevo -> Pri = ele;
  //se hace una copia del elemento o dato
  elemento = ele;

  //preguntamos si la cola esta llena
  if (Cola_Llena(*ini) == VERDADERO) {
    printf("La cola ya esta llena\n");
    return -1;
  //Preguntamos si es nuetro primer elemento
}/*Fin en caso de que la cola este llena*/else if(Cola_vacia(*ini)== VERDADERO){
    //Apuntador inicio y final apuntan ahora al primer elemento
    *ini = pNuevo;
    *fin = pNuevo;
    pNuevo->pSiguiente = NULL;
    //El apuntador de nuestra estructura apunta NULL
  //fallo en bicolas  (*ini) -> pSiguiente = NULL;
    /*Preguntamos si el dato que vamos a meter es mayor o igual al elemento
    que ya hay en la cola*/
   printf("Se mete el primer elemento");
   
   }/*Fin en el caso de que sea el primer elemento*/else{
   	
   	//Inicio en caso de que sea el segundo elemento
    if(*ini == *fin){
    	//Inicio en caso de que el elemnto sea mayor o igual al primer elemento
    	if (ele >= (*fin) -> Pri) {
    	/*while (ele >= (*ini)-> Pri) {

    	}*/
    	//Unimos las estructuras
    	(*fin) -> pSiguiente = pNuevo;
    	//Actualizamos el final
    	*fin = pNuevo;
    	//El apuntador de nuestra estructura apunta NULL
    	(*fin) -> pSiguiente = NULL;
    	//de lo contrario si el elemento es menor
    	}/*Fin en caso de que sea mayor al primer elemento*/else {
    	//unimos la estructura
    	pNuevo -> pSiguiente = *ini;
    	//actualizamos el inicio
    	*ini = pNuevo;
		}//Fin en caso de que sea menor al primer elemento

	}/*Fin en caso de que sea el segundo elemento*/ else{ 
		//(else)Inicio en caso de que sea el tercer elemento en adelante 		
  	pTemporal = *ini;
  	aux = pTemporal->pSiguiente;
  	printf("Funciona antes del ciclo");
  	/*1er CondiciÛn del ciclo me sirve para saber si va ir el elemento al inicio
	  2da CondiciÛn me sirve para saber si va en medio de dos elementos
	  3era CodiciÛn me sirve para saber si va hasta el final el elemento*/
  	while (ele > pTemporal->Pri && ele > aux->Pri && aux->pSiguiente != NULL) {
	printf("Funciona dentro del ciclo");
		
		pTemporal = pTemporal->pSiguiente;
		aux = aux->pSiguiente;
		
    }
 
	 if(ele <= pTemporal->Pri){ //Primer if 	
	 
	 	pNuevo->pSiguiente = pTemporal;
	 	*ini = pNuevo;
	 	
	 }else if(ele <= aux->Pri){
	 	
	 	pTemporal->pSiguiente = pNuevo;
	 	pNuevo->pSiguiente = aux;
	 
	  
	 }else if(aux->pSiguiente == NULL){
	 	
	 	aux->pSiguiente = pNuevo;
	 	*fin = pNuevo; 
	    (*fin)->pSiguiente = NULL; //pNuevo->pSiguiente = NULL;
	    
	}
	 	
		
	}//Fin del caso de que sea el tercer elemento en adelante
	
	
}//Fin En caso de que no sea primer elemento
 	
  //regresamos la copia del dato
return elemento;
	
}
int Desencolar(pApuntador *ini){
  //variables locales
  pApuntador pTemporal;
  int elemento;
  //preguntamos si la cola esta vacia
  if (Cola_vacia(*ini) == VERDADERO) {
    printf("No hay elementos que eliminar\n");
  } else {
    //nuestro apuntador temporal apunta al inicio de la cola
    pTemporal = *ini;
    //hacemos una copia del elemento
    elemento = pTemporal -> Pri;
    //Recorremos el inicio
    *ini = pTemporal -> pSiguiente;
    //Borramos el elemento
    free(pTemporal);
  }
  return elemento;
}
void Ver_frente(pApuntador ini){
//preguntamos si la cola esta vacia
if (Cola_vacia(ini) == VERDADERO) {
  printf("No hay frente en la cola, esta vacia\n");
  } else {
    printf("\nEl frente es: %i \n", (ini) -> Pri);
  }
}
void Ver_cola(pApuntador ini){
//Variable local
pApuntador pTemporal;
int eContador = 0;
//preguntamos si la cola esta vacia
if (Cola_vacia(ini) == VERDADERO) {
  printf("No hay elementos en la cola que mostrar\n");
  } else {
    //apuntamos a inicio
    pTemporal = ini;
    //Mientras nuestro Temporal no apunte null se repetira
    while (pTemporal != NULL) {
      printf("\nElemento %i de la cola es: %i", eContador + 1, pTemporal -> Pri);
      pTemporal = pTemporal -> pSiguiente;
      eContador ++;
    }
  }
}
