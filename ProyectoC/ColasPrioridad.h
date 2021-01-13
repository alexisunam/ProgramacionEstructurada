//Prototipos
int Cola_Llena();
int Cola_vacia(pApuntaCo ini);
float Registro(pApuntaCo *pRe);
void Encolar(pApuntaPrio *ini1, pApuntaPrio *ini2, pApuntaPrio *ini3, pApuntaCo *fin1, pApuntaCo *fin2, pApuntaCo *fin3);
void Prioridad(pApuntaPrio *ini, pApuntaCo *fin, pApuntaCo *nuevo);
TrDoc Desencolar(pApuntaPrio *ini1, pApuntaPrio *ini2, pApuntaPrio *ini3, pApuntaCo *fin1, pApuntaCo *fin2, pApuntaCo *fin3);
TrDoc DesPrioridad(pApuntaPrio *ini, pApuntaCo *fin);
void Show(pApuntaPrio ini);
void MostrarCola(pApuntaPrio ini1, pApuntaPrio ini2, pApuntaPrio ini3);
//Definiciones
int Cola_Llena() {

  if (!(pApuntaCo) calloc(1, sizeof(TrCola))) {
    return VERDADERO;
  } else {
    return FALSO;
  }
}

int Cola_Vacia(pApuntaCo ini) {

  if (!ini) {
    return VERDADERO;
  } else {
    return FALSO;
  }
}

float Registro(pApuntaCo *pRe){
  //Variables
  int iTipo, iFact;
  float fInve, fResultado;
  system("clear");
  printf("\nIngrese el nombre del documento o contrato:[              ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
  fflush(stdin);
  getchar();
  fgets((*pRe) -> TrDato.sNombre, MAX, stdin);
  printf("\nIngrese una breve descripcion del documento:[                  ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
  fflush(stdin);
  fgets((*pRe) -> TrDato.sDescripcion, MAX, stdin);
  printf("\nIngrese el tipo de documento con un numero->"
  "[1. Contrato Social], [2. Contrato privado], [3. inversion internacional]:[ ]\b\b");
  do {
    scanf("%i", &iTipo);
    if (iTipo > 0 && iTipo <= 3) {

        (*pRe) -> TrDato.iTipo = iTipo;

    } else {
      printf("\nError en la seleccion, por favor ingrese solo entre 1, 2 y 3");
      iTipo = 0;
    }
  } while(iTipo == 0);
  printf("\ningrese la factibilidad del contrato o documento->\n"
  "[1. si es muy factible], [2. si solo es factible], [3. si es poco factible]:[ ]\b\b");
  do {
    scanf("%i", &iFact);
    if (iFact > 0 && iFact <= 3) {
      (*pRe) -> TrDato.iFactible = iFact;
      switch(iTipo){
        case 1: fResultado = (float)iFact + 0.1;
        break;
        case 2: fResultado = (float)iFact + 0.2;
        break;
        case 3: fResultado = (float)iFact + 0.3;
        break;
      }
    } else {
      printf("\nError en la seleccion, por favor ingrese solo entre 1, 2 y 3");
      iFact = 0;
    }
  } while(iFact == 0);
  printf("\nIngrese la cantidad de inversion:[            ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
  do {
    scanf("%f", &fInve);
    if (fInve > 0) {
      (*pRe) -> TrDato.fInversion = fInve;
    } else {
      printf("\nError no se pueden ingresar numeros rojos (negativos)");
    }
  } while(fInve <= 0);
  printf("\n%f", fResultado);
  return fResultado;
}

void Prioridad(pApuntaPrio *ini, pApuntaCo *fin, pApuntaCo *nuevo) {
pApuntaCo pTemporal, aux;
  //preguntamos si la cola esta llena
  if (Cola_Llena() == VERDADERO) {
    printf("La cola ya esta llena\n");
  //Preguntamos si es nuetro primer elemento
}/*Fin en caso de que la cola este llena*/else if(Cola_Vacia((*ini) -> pPrincipio) == VERDADERO){
    //Apuntador inicio y final apuntan ahora al primer elemento
  /*  *ini = pNuevo;*/

    (*ini) -> pPrincipio = *nuevo;
    *fin = *nuevo;
    (*nuevo) -> pSiguiente = NULL;
    //El apuntador de nuestra estructura apunta NULL
  //fallo en bicolas  (*ini) -> pSiguiente = NULL;
    /*Preguntamos si el dato que vamos a meter es mayor o igual al elemento
    que ya hay en la cola*/
   //printf("Se mete el primer elemento");

   }/*Fin en el caso de que sea el primer elemento*/else{

    //Inicio en caso de que sea el segundo elemento
    if((*ini) -> pPrincipio == (*fin)){
      //Inicio en caso de que el elemnto sea mayor o igual al primer elemento
      if ((*nuevo) -> Pri >= (*fin) -> Pri) {
      /*while (ele >= (*ini)-> Pri) {

      }*/
      //Unimos las estructuras
      (*fin) -> pSiguiente = (*nuevo);
      //Actualizamos el final
      (*fin) = *nuevo;
      //El apuntador de nuestra estructura apunta NULL
      (*fin) -> pSiguiente = NULL;
      //de lo contrario si el elemento es menor
      }/*Fin en caso de que sea mayor al primer elemento*/else {
      //unimos la estructura
      (*nuevo) -> pSiguiente = (*ini) -> pPrincipio;
      //actualizamos el inicio
      (*ini) -> pPrincipio = (*nuevo);

    }//Fin en caso de que sea menor al primer elemento

  }/*Fin en caso de que sea el segundo elemento*/ else{
    //(else)Inicio en caso de que sea el tercer elemento en adelante
    pTemporal = (*ini) -> pPrincipio;
    aux = pTemporal -> pSiguiente;
    //printf("Funciona antes del ciclo");
    /*1er Condici�n del ciclo me sirve para saber si va ir el elemento al inicio
    2da Condici�n me sirve para saber si va en medio de dos elementos
    3era Codici�n me sirve para saber si va hasta el final el elemento*/
    while ((*nuevo) -> Pri > pTemporal -> Pri && (*nuevo) -> Pri > aux -> Pri && aux -> pSiguiente != NULL) {
  printf("Funciona dentro del ciclo");

    pTemporal = pTemporal -> pSiguiente;
    aux = aux -> pSiguiente;

    }

   if((*nuevo) -> Pri <= pTemporal -> Pri){ //Primer if

    (*nuevo) -> pSiguiente = pTemporal;
    (*ini) -> pPrincipio = (*nuevo);

  }else if((*nuevo) -> Pri <= aux -> Pri){

    pTemporal -> pSiguiente = (*nuevo);
    (*nuevo) -> pSiguiente = aux;


  }else if(aux -> pSiguiente == NULL){

    aux -> pSiguiente = (*nuevo);
    *fin = *nuevo;
      (*fin) -> pSiguiente = NULL; //pNuevo->pSiguiente = NULL;

  }


  }//Fin del caso de que sea el tercer elemento en adelante


}//Fin En caso de que no sea primer elemento
}

void Encolar(pApuntaPrio *ini1, pApuntaPrio *ini2, pApuntaPrio *ini3, pApuntaCo *fin1, pApuntaCo *fin2, pApuntaCo *fin3) {
  //variables locales
  pApuntaCo pNuevo;
  pNuevo = (pApuntaCo) calloc (1, sizeof(TrCola));
  //Metemos el elemento a la estructura
  pNuevo -> Pri = Registro(&pNuevo);

  if (pNuevo -> Pri < 1.5) {
    Prioridad(ini1, fin1, &pNuevo);
  } else if (pNuevo -> Pri > 1.5 && pNuevo -> Pri < 2.5) {
    Prioridad(ini2, fin2, &pNuevo);
  }else if (pNuevo -> Pri > 2.5 && pNuevo -> Pri < 3.5) {
    Prioridad(ini3, fin3, &pNuevo);
  }
}

TrDoc DesPrioridad(pApuntaPrio *ini, pApuntaCo *fin) {
  pApuntaCo pTemporal;
  TrDoc Datos;
  if ((*ini) -> pPrincipio == (*fin)) {
    pTemporal = (*ini) -> pPrincipio;
    strcpy(Datos.sNombre, pTemporal -> TrDato.sNombre); //si no se puede hacerlo campo por campo
    strcpy(Datos.sDescripcion, pTemporal -> TrDato.sDescripcion);
    Datos.iTipo = pTemporal -> TrDato.iTipo;
    Datos.iFactible = pTemporal -> TrDato.iFactible;
    Datos.fInversion = pTemporal -> TrDato.fInversion;
    //printf("Se va a procesar el documento\n");
    (*ini) -> pPrincipio = NULL;
    (*fin) = NULL;
    free(pTemporal);
  }else{
    pTemporal = (*ini) -> pPrincipio;
    strcpy(Datos.sNombre, pTemporal -> TrDato.sNombre); //si no se puede hacerlo campo por campo
    strcpy(Datos.sDescripcion, pTemporal -> TrDato.sDescripcion);
    Datos.iTipo = pTemporal -> TrDato.iTipo;
    Datos.iFactible = pTemporal -> TrDato.iFactible;
    Datos.fInversion = pTemporal -> TrDato.fInversion;
    (*ini) -> pPrincipio = pTemporal -> pSiguiente;
    free(pTemporal);
  }
  return Datos;
}

TrDoc Desencolar(pApuntaPrio *ini1, pApuntaPrio *ini2, pApuntaPrio *ini3, pApuntaCo *fin1, pApuntaCo *fin2, pApuntaCo *fin3){
  TrDoc info;
system("clear");
if (Cola_Vacia((*ini1) -> pPrincipio) == FALSO) {
  info = DesPrioridad((ini1), fin1);
}else if (Cola_Vacia((*ini2) -> pPrincipio) == FALSO) {
    info = DesPrioridad(ini2, fin2);
  }else if (Cola_Vacia((*ini3) -> pPrincipio) == FALSO) {
      info = DesPrioridad(ini3, fin3);
    }else{
        printf("No hay documentos en la cola\n");
        info.iTipo = -1;
      }
      getchar();
      getchar();
      return info;
}

void Mostrar_Elminados(TrDoc Documentos[], int contador) {
  int iConta = 0;
  system("clear");
  printf("Los contratos/documentos ya realiazados son:\n");
  printf("iConta = %i, contador = %i\n",iConta, contador);
  for (iConta; iConta < contador; iConta++) {
    printf("Funciona\n");
    printf("\nContrato/Documento %i:", iConta + 1);
    printf("\nNombre: %s ", Documentos[iConta].sNombre);
    printf("\nDescripción: %s ", Documentos[iConta].sDescripcion);

      if (Documentos[iConta].iTipo == 1) {
        printf("\nTipo: Contrato Social");
      } else if (Documentos[iConta].iTipo == 2) {
        printf("\nTipo: Contrato Privado");
      } else if (Documentos[iConta].iTipo == 3) {
        printf("\nTipo:Contrato internacional");
      }

        if (Documentos[iConta].iFactible == 1) {
          printf("\nFactibilidad: Muy factible");
        } else if (Documentos[iConta].iFactible == 2) {
          printf("\nFactibilidad: factible");
        } else if (Documentos[iConta].iFactible == 3) {
          printf("\nFactibilidad: Poco factible");
        }
          printf("\nInversion: %f \n", Documentos[iConta].fInversion);

 }//Cierra for
      getchar();
      getchar();
}//Fin procedimiento Mostrar_Elminados

void MostrarCola(pApuntaPrio ini1, pApuntaPrio ini2, pApuntaPrio ini3) {
  //int *apuntador = NULL;

//*apuntador = &iContador;
  system("clear");
  if (Cola_Vacia(ini1 -> pPrincipio) == FALSO) {
    printf("\t\t%s\n", ini1->sPrioridad);
    Show(ini1);
  } else {
    printf("\t\t%s\n", ini1->sPrioridad);
    printf("No hay\n");
  }

    if (Cola_Vacia(ini2 -> pPrincipio) == FALSO) {
      printf("\t\t%s\n", ini2->sPrioridad);
      Show(ini2);
    } else {
      printf("\t\t%s\n", ini2->sPrioridad);
      printf("No hay\n");
    }

      if (Cola_Vacia(ini3 -> pPrincipio) == FALSO) {
        printf("\t\t%s\n", ini3->sPrioridad);
        Show(ini3);
      } else {
        printf("\t\t%s\n", ini3->sPrioridad);
        printf("No hay\n");
      }
      getchar();
      getchar();
}

void Show(pApuntaPrio ini) {
  pApuntaCo pTemporal;
    int iCon = 1;

    pTemporal = ini -> pPrincipio;

    while(pTemporal != NULL){
      printf("\nDocumento/Contrato %i\n", iCon);
      printf("\nNombre del documento: %s", pTemporal -> TrDato.sNombre);
      printf("\nDescripción del documento: %s", pTemporal -> TrDato.sDescripcion);
      if (pTemporal -> TrDato.iTipo == 1) {
        printf("\nTipo: Contrato Social");
      } else if (pTemporal -> TrDato.iTipo == 2) {
        printf("\nTipo: Contrato Privado");
      } else if (pTemporal -> TrDato.iTipo == 3) {
        printf("\nTipo:Contrato internacional");
      }
        if (pTemporal -> TrDato.iFactible == 1) {
          printf("\nFactibilidad: Muy factible");
        } else if (pTemporal -> TrDato.iFactible == 2) {
          printf("\nFactibilidad: factible");
        } else if (pTemporal -> TrDato.iFactible == 3) {
          printf("\nFactibilidad: Poco factible");
        }
          printf("\nInversion: %f \n\n", pTemporal -> TrDato.fInversion);
          pTemporal = pTemporal -> pSiguiente;
          iCon ++;
    }


}
