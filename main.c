/*
 * opcion 2:
 * Gasta mayor cantidad de recursos y tiene una O complejidad de calculos cuadratica.
 * O(2)
 * Se pide una semilla para la generacion aleatoria de numeros
 * se establece un arreglo con todos los numeros posibles y la combinacion ganadora
 * Se rellena cada espacio aleatoriamente y se busca si este numero ya se encuentra
 * con anterioridad en el tablero si existe se genera otro si no se añade.
 * se mueven las fichas, por cada movimiento se verifica si se cumple el arreglo ganador
 * si se cumple se muestra una pantalla con el tiempo y los movimientos totales
 * Game over
 * si no se pide un movimiento nuevo.
 * */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void limpiar_tablero();
int buscar_valor();
void iniciar_tablero();
int rellenar_tablero();
int generar_aleatorio(int aleatorio);
void mover_pieza();
int verificar_juego();
void terminar_juego();

const int tablero_ganador[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
int tablero[4][4];
int ganador=0;

void menu(){
    ;
}
int main(){
    srand(time(NULL));
    int tablero_longitud = sizeof(tablero_ganador)/sizeof(int);
    menu();
    limpiar_tablero();
    iniciar_tablero();
    while(~ganador){
        mover_pieza();
        /*ganador=verificar_juego();
        if(ganador){
            terminar_juego();
        }*/
        break;
    }
    return 0;
}
void mover_pieza(){
    int swap =0;
    int x = 3, y = 3;
    swap = tablero[x][y-1];
    tablero[x][y-1] = tablero[x][y];
    tablero[x][y] = swap;
}

void limpiar_tablero(){
    int y=0;
    for(int x=0;x<4;x++){
        y=0;
        for(y;y<4;y++){
            tablero[x][y] = -1;
        }
    }
}
int generar_aleatorio(int aleatorio){
    aleatorio = rand() % 15 + 1;
    return aleatorio;
}
int rellenar_tablero() {
    int casilla=0;
    casilla = buscar_valor();
    return casilla;
}

int buscar_valor(){
    int probable=0;
    int aleatorio=0;
    int contador=0;
    int y=0;
    int x=0;
    while(1){
        x=0;
        contador=0;
        aleatorio=generar_aleatorio(aleatorio);
        for(x;x<4;x++){
            y=0;
            for(y;y<4;y++){
                if(tablero[x][y]!=aleatorio){
                    contador+=1;
                    if (contador>15){
                        probable=aleatorio;
                        return probable;
                    }
                }
            }
        }
    }
}

void iniciar_tablero(){
    int y=0;
    int rellenador = 0;
    for(int x=0;x<4;x++){
        y=0;
        for(y;y<4;y++){
            if(rellenador>14){
                tablero[x][y] = 0;
                printf("[%2i]", tablero[x][y]);
            }
            else {
                tablero[x][y] = rellenar_tablero();
                printf("[%2i]", tablero[x][y]);
                rellenador++;
            }
        }
        printf("\n");
    }
}