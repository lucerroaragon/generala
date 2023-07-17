#ifndef CODIGOS_H_INCLUDED
#define CODIGOS_H_INCLUDED

string empezarJuego(int cantJugadores,string nombre_max,int v_max[]);
void PuntuacionMaxima(int v_ant[], string nombre_ant, int v_max[], string nombre_max);

string empezarJuego(int cantJugadores, string nombre_max, int v_max[]){
    int j,vDados[5],dados_pregunta=0,dados_vuelta,Lanzamiento[cantJugadores],LanzamientoTot[cantJugadores],opAnotarPuntos,i,posicionDelCambio,Ronda=0,RondasAjugar,dados_repetidos[6];
    int Puntos[cantJugadores],juegoTachado=0,juegosYaElegidos[cantJugadores][10],Fin,prox=0,ProxRonda=1,posicion;
    string nombre[cantJugadores];

    char continuar='s', modoGenerala = 'n';
    int * PuntosP;
    ponerCero(Puntos, cantJugadores);
    ponerCero(LanzamientoTot,cantJugadores);
    ponerCero(Lanzamiento,cantJugadores);
    for(j = 0; j<cantJugadores;j++){
        cout<<"\n\t\t\t\t------------------------------------------"<<endl;
        cout<<"\n\t\t\t\tNOMBRE DEL JUGADOR "<<j+1<<": ";
        cin>>nombre[j];
    }
    system("cls");
    cout<<"\n\t\t-------------------------------------------------------------------"<<endl;
    cout<<"\n\t\tCUANTAS RONDAS DESEA JUGAR? (COMO MAXIMO SE PERMITEN 10 RONDAS) : ";
    cin>>RondasAjugar;
    system("cls");
    while(RondasAjugar!=Ronda){
        Ronda++;
        for(j = 0; j<cantJugadores;j++){
            Lanzamiento[j]=1;
            LanzamientoTot[j]++;
            while(continuar!='n'){
                    Turnos( nombre, Ronda, Puntos,  Lanzamiento,  LanzamientoTot, j);

                cargarAleatorio(vDados,5,6);
                ///cargarVector(vDados,5);
                mostrarVector(vDados,5);
                for(i=0;i<=5;i++){
                    dados_repetidos[i]=contarNumerosRepetidos(vDados,i+1,5);
                }



                Fin=GeneralaServida(dados_repetidos);
                cout<<endl;
                cout<<endl;
                /// PARA UN JUGADOR GANAS SACANDO GENERALA SERVIDA
                if(Lanzamiento[j] == 1 && Fin==1 && cantJugadores == 1){
                    continuar='n';
                    Lanzamiento[j]=4;
                    RondasAjugar=Ronda;
                    Puntos[j]+=50;
                    cout<<"\t\t\t\tGENERALA SERVIDA - HA GANADO EL JUEGO"<<endl;
                    system("pause");
                }
                /// SI SON DOS JUGADORES ESPERA A QUE EL PRÓXIMO TIRE
                if(Lanzamiento[j] == 1 && Fin==1 && j == 0 && cantJugadores > 1){
                    modoGenerala = 's';
                    continuar='n';
                    Lanzamiento[j]=4;
                    Puntos[j]+=50;
                    cout<<"\t\t\t\tGENERALA SERVIDA - ESPERANDO PROXIMO JUGADOR"<<endl;
                    system("pause");
                }
                /// SI EL PRIMERO TIRA Y NO SACA GENERALA SERVIDA Y EL OTRO SI GANA EL QUE HAYA SACADO GENERALA SERVIDA
                if(modoGenerala == 'n' && Fin == 1 && j > 0 ){
                    continuar='n';
                    Lanzamiento[j]=4;
                    RondasAjugar=Ronda;
                    Puntos[j]+=50;
                    cout<<"\t\t\t\tGENERALA SERVIDA - HA GANADO EL JUEGO"<<endl;
                    system("pause");
                }
                /// SI EL OTRO JUGADOR SACA GENERALA SERVIDA, EL JUEGO SIGUE NORMALMENTE
                if( j>0 && modoGenerala == 's'){
                    if(Fin == 1){
                        modoGenerala = 'n';
                        continuar='n';
                        Lanzamiento[j]=4;
                        Puntos[j]+=50;
                        cout<<"\t\t\t\tGENERALA SERVIDA - EL JUEGO CONTINUA"<<endl;
                        system("pause");
                    }
                    else {
                        continuar='n';
                        Lanzamiento[j]=4;
                        RondasAjugar=Ronda;
                        Puntos[j]+=0;
                        cout<<"\t\t\t\tNO HA SACADO GENERALA SERVIDA - FIN DEL JUEGO"<<endl;
                        system("pause");
                    }
                }
                while(Lanzamiento[j]!=4){
                    if(Lanzamiento[j]==1){
                        cout<<"\t\t\t\tCONTINUAR LANZANDO? (S/N): ";
                        cin>>continuar;
                        cout<<endl;
                        if(continuar!='n'){
                            cout<<"\t\t\t\tCUANTOS DADOS VUELVES A TIRAR?: ";
                            cin>>dados_pregunta;
                            cout<<endl;
                            Lanzamiento[j]++;
                            LanzamientoTot[j]++;
                        }
                        else{
                            for(i=0;i<=5;i++){
                                dados_repetidos[i]=contarNumerosRepetidos(vDados,i+1,5);
                            }
                            cout<<"\t\t\t\tELIJA OPCION"<<endl;
                            cout<<"\t\t\t\t1. ELEGIR COMBINACION GANADORA DISPONIBLE"<<endl;
                            cout<<"\t\t\t\t2. ANULAR UNA COMBINACION"<<endl;
                            cout<<"\t\t\t\tOPCION: ";
                            cin>>opAnotarPuntos;
                            cout<<endl;
                            if(opAnotarPuntos==1){
                                PuntosP=mostrar_tipo_juego(dados_repetidos,6,vDados,juegosYaElegidos[j]);
                                Puntos[j]=PuntosP[0]+Puntos[j];
                                juegosYaElegidos[j][PuntosP[1]-1] = PuntosP[1];
                                cout<<endl;
                                cout<<"\t\t\t\t--------------------------"<<endl;
                                cout<<"\t\t\t\tPUNTAJE DE LA RONDA: "<<PuntosP[0]<<endl;
                                cout<<"\t\t\t\t--------------------------"<<endl;
                                cout<<endl;
                                system("pause");
                                Lanzamiento[j]=4;
                            }
                            else{
                                juegoTachado=tacharJuego(juegosYaElegidos[j]);
                                juegosYaElegidos[j][juegoTachado-1] = juegoTachado;
                                Lanzamiento[j]=4;
                            }
                        }
                        }


                    else {
                        system("cls");
                        cout<<endl;
                        Turnos( nombre, Ronda, Puntos, Lanzamiento,  LanzamientoTot, j);

                        mostrarVector(vDados,5);
                        cout<<endl;
                        cout<<endl;
                        if(Lanzamiento[j]!=3){
                            cout<<"\t\t\t\tCONTINUAR LANZANDO? (S/N): ";
                            cin>>continuar;
                            cout<<endl;
                            if(continuar!='n'){
                                cout<<"\t\t\t\tCUANTOS DADOS VUELVES A TIRAR?: ";
                                cin>>dados_pregunta;
                                cout<<endl;
                                Lanzamiento[j]++;
                                LanzamientoTot[j]++;
                            }
                            else{
                                Lanzamiento[j]++;
                                dados_pregunta=0;
                                for(i=0;i<=5;i++){
                                    dados_repetidos[i]=contarNumerosRepetidos(vDados,i+1,5);
                                }
                                cout<<"\t\t\t\tELIJA OPCION"<<endl;
                                cout<<"\t\t\t\t1. ELEGIR COMBINACION GANADORA DISPONIBLE"<<endl;
                                cout<<"\t\t\t\t2. ANULAR UNA COMBINACION"<<endl;
                                cout<<"\t\t\t\tOPCION: ";
                                cin>>opAnotarPuntos;
                                cout<<endl;
                                if(opAnotarPuntos==1){
                                    PuntosP=mostrar_tipo_juego(dados_repetidos,6,vDados,juegosYaElegidos[j]);
                                    Puntos[j]=PuntosP[0]+Puntos[j];
                                    juegosYaElegidos[j][PuntosP[1]-1] = PuntosP[1];
                                    cout<<endl;
                                    cout<<"\t\t\t\t--------------------------"<<endl;
                                    cout<<"\t\t\t\tPUNTAJE DE LA RONDA: "<<PuntosP[0]<<endl;
                                    cout<<"\t\t\t\t--------------------------"<<endl;
                                    cout<<endl;
                                    system("pause");
                                    Lanzamiento[j]=4;
                                }
                                else{
                                    juegoTachado=tacharJuego(juegosYaElegidos[j]);
                                    juegosYaElegidos[j][juegoTachado-1] = juegoTachado;
                                    Lanzamiento[j]=4;
                                }
                            }
                        }
                        else{
                            Lanzamiento[j]++;
                            dados_pregunta=0;
                            for(i=0;i<=5;i++){
                                dados_repetidos[i]=contarNumerosRepetidos(vDados,i+1,5);
                            }
                            cout<<"\t\t\t\tELIJA OPCION"<<endl;
                            cout<<"\t\t\t\t1. ELEGIR COMBINACION GANADORA DISPONIBLE"<<endl;
                            cout<<"\t\t\t\t2. ANULAR UNA COMBINACION"<<endl;
                            cout<<"\t\t\t\tOPCION: ";
                            cin>>opAnotarPuntos;
                            cout<<endl;
                            if(opAnotarPuntos==1){
                                PuntosP=mostrar_tipo_juego(dados_repetidos,6,vDados,juegosYaElegidos[j]);
                                Puntos[j]=PuntosP[0]+Puntos[j];
                                juegosYaElegidos[j][PuntosP[1]-1] = PuntosP[1];
                                cout<<endl;
                                cout<<"\t\t\t\t--------------------------"<<endl;
                                cout<<"\t\t\t\tPUNTAJE DE LA RONDA: "<<PuntosP[0]<<endl;
                                cout<<"\t\t\t\t--------------------------"<<endl;
                                cout<<endl;
                                system("pause");
                                Lanzamiento[j]=4;
                            }
                            else{
                                juegoTachado=tacharJuego(juegosYaElegidos[j]);
                                juegosYaElegidos[j][juegoTachado-1] = juegoTachado;
                                Lanzamiento[j]=4;
                            }
                        }
                    }
                    if(dados_pregunta==5){
                        cargarAleatorio(vDados,5,6);
                    }
                    else{
                        for(i=1;i<=dados_pregunta;i++){
                            cout<<"\t\t\t\tCUAl?: ";
                            cin>>dados_vuelta;
                            cargarAleatorio(&posicionDelCambio,1,6);
                            vDados[dados_vuelta-1]=posicionDelCambio;
                        }
                    }
                    cout<<endl;
                }
                if(Lanzamiento[j]==4){
                    continuar='n';
                }
            }

            continuar = 's';
            system("cls");
            cout<<"\t\t\t\t------------------------------------------"<<endl;
            if(j+1 == cantJugadores){
                prox = 0;
                ProxRonda=Ronda+1;
            }
            else {
                prox++;
            }
            if(ProxRonda <= RondasAjugar){
                cout<<"\t\t\t\tRONDA N: "<<ProxRonda<<endl;
                cout<<"\t\t\t\tPROXIMO TURNO: "<<nombre[prox]<<endl;
            }
            else {
                cout<<"\t\t\t\tRONDA N: "<<Ronda<<endl;
            }
            cout<<endl;
            for(i=0;i<cantJugadores;i++){
                cout<<endl;
                cout<<"\t\t\t\tPUNTAJE DE "<<nombre[i]<<" - "<<Puntos[i]<<" PUNTOS"<<endl;
                cout<<"\t\t\t\tCANTIDAD DE LANZAMIENTOS TOTALES: "<<LanzamientoTot[i]<<endl;
            }
            cout<<"\t\t\t\t------------------------------------------"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            continuar='s';
        }
    }
    posicion=vectorMaximo(Puntos,cantJugadores);
    cout<<"\t\t\t\t------------------------------------------"<<endl;
    cout<<"\t\t\t\tFIN DEL JUEGO "<<endl;
    cout<<endl;
    cout<<"\t\t\t\tEL GANADOR ES: "<<nombre[posicion]<<" - PUNTOS TOTALES: "<<Puntos[posicion]<<endl;
    cout<<endl;
    cout<<"\t\t\t\tCANTIDAD DE LANZAMIENTOS TOTALES: "<<LanzamientoTot[posicion]<<endl;
    cout<<"\t\t\t\t------------------------------------------"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
    nombre_max = nombre[posicion];
    v_max[0] = Puntos[posicion];
    v_max[1] = LanzamientoTot[posicion];

    return nombre_max;
}

///PUNTUACION MAXIMA
void PuntuacionMaxima(int v_ant[], string nombre_ant, int v_max[], string nombre_max){

int r_max, p_maximo;
string n_ganador;

r_max=P_Max( v_max, v_ant);{
if(r_max==1){
    n_ganador=nombre_max;
    interfazMaxima(n_ganador,v_max);
}
else
{
    n_ganador=nombre_ant;
    interfazMaxima(n_ganador,v_ant);
}

}
}

#endif // CODIGOS_H_INCLUDED
