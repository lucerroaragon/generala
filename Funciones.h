#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
void cargarVector(int v[], int tam);///asigna valores a cada una de las posiciones del vector

int vectorMaximo(int v[],int tam);

void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector

int contarNumerosRepetidos(int v[], int numero , int tam);///cuenta la cantidad de veces que se repite un //número en el vector

void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

void ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector

int sumarVector(int v[], int tam ); /// suma los valores contenidos en el vector

bool compararVectores(int v[], int v2[],int tam );// compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false

int mostrar_tipo_juego(int dados_repetidos[], int tam,int vDados, int juegosYaElegidos);

int GeneralaServida(int dados_repetidos[]);

int opcionYaElegida(int juegosYaElegidos[], int opcionActual){
    int yaElegido = 0;
    if(juegosYaElegidos[opcionActual-1] == opcionActual){
        yaElegido = 1;
    }
    return yaElegido;
}

/// Desarrollo de funciones / Definiciones
int * mostrar_tipo_juego(int dados_repetidos[], int tam,int vDados[], int juegosYaElegidos[]){
    int i, juegos_individuales[6],contador=0,ContadorFull=0,band1=1,band2=1,opJuego,vPuntos[10],suma=0,yaExiste=0;
    static int resultado[2];
    resultado[0] = 0;
    cout<<"\t\t\t\tELIJA LA OPCION DESEADA:"<<endl;
    ///juegos individuales
    for(i=0;i<=5;i++){
        juegos_individuales[i]=(i+1)*dados_repetidos[i];
    }
    for(i=0;i<=5;i++){
        if(juegos_individuales[i]!=0){
            yaExiste = opcionYaElegida(juegosYaElegidos, i+1);
            if(yaExiste != 1){
                cout<<endl;
                cout<<"\t\t\t\t"<<i+1<<". "<<"JUEGOS DE "<<i+1<<" : "<<juegos_individuales[i]<<" PUNTOS"<<endl;
            }
        }
    }
    ///escalera
    for(i=0;i<=5;i++){
        if(dados_repetidos[i]==1){
            contador++;
            if (contador==5){
                yaExiste = opcionYaElegida(juegosYaElegidos, 7);
                if(yaExiste != 1){
                    cout<<endl;
                    cout<<"\t\t\t\t7. ESCALERA : 25 PUNTOS"<<endl;
                }
            }
        }
        else contador=0;
    }


    ///FULL
    for(i=0;i<=5;i++){
        if(dados_repetidos[i]==3&&band1==1){
            ContadorFull++;
            band1=0;
        }
        if(dados_repetidos[i]==2&&band2==1){
            ContadorFull++;
            band2=0;
        }
    }
    if(ContadorFull==2){
        yaExiste = opcionYaElegida(juegosYaElegidos, 8);
        if(yaExiste != 1){
        cout<<endl;
        cout<<"\t\t\t\t8. FULL : 30 PUNTOS"<<endl;
        }
    }
    ///POKER
    for(i=0;i<=5;i++){
        if(dados_repetidos[i]>=4){
            yaExiste = opcionYaElegida(juegosYaElegidos, 9);
            if(yaExiste != 1){
            cout<<endl;
            cout<<"\t\t\t\t9. POKER : 40 PUNTOS"<<endl;
            }
        }
    }
    ///GENERALA
    for(i=0;i<=5;i++){
        if(dados_repetidos[i]==5){
            yaExiste = opcionYaElegida(juegosYaElegidos, 10);
            if(yaExiste != 1){
            cout<<endl;
            cout<<"\t\t\t\t10. GENERALA : 50 PUNTOS"<<endl;
            }
        }

    }
    cout<<endl;
    cout<<"\t\t\t\tOPCION: ";
    cin>>opJuego;

    switch (opJuego){
        case 1:
            vPuntos[0]=1*dados_repetidos[0];
            suma=vPuntos[0];
        break;
        case 2:
            vPuntos[1]=2*dados_repetidos[1];
            suma=vPuntos[1];
        break;
        case 3:
            vPuntos[2]=3*dados_repetidos[2];
            suma=vPuntos[2];
        break;
        case 4:
            vPuntos[3]=4*dados_repetidos[3];
            suma=vPuntos[3];
        break;
        case 5:
            vPuntos[4]=5*dados_repetidos[4];
            suma=vPuntos[4];
        break;
        case 6:
            vPuntos[5]=6*dados_repetidos[5];
            suma=vPuntos[5];
        break;
        case 7:
            vPuntos[6]=25;
            suma=25;
        break;
        case 8:
            vPuntos[7]=30;
            suma=30;
        break;
        case 9:
            vPuntos[8]=40;
            suma=40;
        break;
        case 10:
            vPuntos[9]=50;
            suma=50;
        break;
    }
    resultado[0]=suma;
    resultado[1]=opJuego;
    return resultado;
}
/////////////////////////
int tacharJuego (int juegosYaElegidos[]){
    int i,yaExiste=0,op;
    cout<<endl;
    cout<<"\t\t\t\tTACHE UN JUEGO"<<endl;
    for(i=0;i<=5;i++){
            yaExiste = opcionYaElegida(juegosYaElegidos, i+1);
            if(yaExiste != 1){
                cout<<endl;
                cout<<"\t\t\t\t"<<i+1<<". "<<"JUEGOS DE "<<i+1<<endl;
            }
    }
    yaExiste = opcionYaElegida(juegosYaElegidos, 7);
    if(yaExiste != 1){
        cout<<endl;
        cout<<"\t\t\t\t7. ESCALERA"<<endl;
    }
    yaExiste = opcionYaElegida(juegosYaElegidos, 8);
    if(yaExiste != 1){
        cout<<endl;
        cout<<"\t\t\t\t8. FULL"<<endl;
    }
    yaExiste = opcionYaElegida(juegosYaElegidos, 9);
    if(yaExiste != 1){
        cout<<endl;
        cout<<"\t\t\t\t9. POKER"<<endl;
    }
    yaExiste = opcionYaElegida(juegosYaElegidos, 10);
    if(yaExiste != 1){
        cout<<endl;
        cout<<"\t\t\t\t10. GENERALA"<<endl;
    }
    cout<<endl;
    cout<<"\t\t\t\tOPCION: ";
    cin>>op;
    return op;
}

int posicionNumeroEnVector(int v[],int tam, int numero){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==numero) return i;
        }
    return -1;
}
int minimoVector(int v[], int tam){
    int i, posMin=0;
    for(i=1;i<tam;i++){
        if(v[i]<v[posMin]) {
                posMin=i;
        }
    }
    return posMin;
}
void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int GeneralaServida(int dados_repetidos[]){
    int fin=0,i;
     for(i=0;i<=5;i++){
        if(dados_repetidos[i]==5){
                fin=1;
            }
        }
    return fin;
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    cout<<"\t\t\t\t";
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}


int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}


void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}


int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}


bool compararVectores(int v[], int v2[],int tam ){
   int i;
    for(i=0;i<tam;i++){
        if(v2[i]!=v[i]) return false;
    }
    return true;
}

void cargarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
        cout<<endl;
    }
}
int vectorMaximo(int v[],int tam){
    int i, pos = 0;
    int maximo = v[0];

    for(i=0;i<tam;i++){
        if(v[i]>maximo){
            maximo = v[i];
            pos = i;
        }
    }
    return pos;
}

/// INTERFAZ TURNOS:
void Turnos(string nombre[], int Ronda, int Puntos[], int Lanzamiento[], int LanzamientoTot[], int j){
    cout<<endl;
    cout<<"\t\t\t\tTURNO DE "<<nombre[j]<<" | RONDA N "<<Ronda<<" | PUNTAJE TOTAL: "<<Puntos[j]<<endl;
    cout<<"\t\t\t\t------------------------------------------"<<endl;
    cout<<"\t\t\t\tLANZAMIENTO N "<<Lanzamiento[j]<<" - LANZAMIENTOS TOTALES: "<<LanzamientoTot[j]<<endl;
    cout<<"\t\t\t\t------------------------------------------"<<endl;
}

/// Puntuación máxima:
int P_Max(int v_max[], int v_ant[]){

if(v_max[0]>v_ant[0])
{
    return 1;
}
else
{
    return 0;
}

}

///INTERFAZ PUNTUACION MAXIMA
void interfazMaxima(string NombreDelGanador,int vPuntos[]){
    cout<<endl;
    cout<<"\t\t\t\t\t============================"<<endl;
    cout<<"\t\t\t\t\tPUNTUACION MAXIMA"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\tNOMBRE: "<<NombreDelGanador<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\tPUNTUACION: "<<vPuntos[0]<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\tLANZAMIENTOS TOTALES: "<<vPuntos[1]<<endl;
    cout<<"\t\t\t\t\t============================"<<endl;
    system("pause");
    system("cls");
}
#endif // FUNCIONES_H_INCLUDED
