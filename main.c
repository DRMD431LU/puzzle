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
void imprimir_tablero();
int verificar_juego();
void terminar_juego();

const int tablero_ganador[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int tablero[4][4];
int ganador=0;


void menu(){
    ;
}
int main(){
    srand(time(NULL));
    menu();
    limpiar_tablero();
    iniciar_tablero();
    imprimir_tablero();
    mover_pieza();
    return 0;
}
void imprimir_tablero(){
    int y=0,x=0;
    for(y;y<4;y++){
        x=0;
        for(x;x<4;x++){
            if(tablero[y][x]!=0){
                printf("[%2i]",tablero[y][x]);}
            else{
                printf("[  ]");
            }
            }
        printf("\n");
        }
}
void mover_pieza(){
    int x = 3, y = 3;
    int movs=0;
    char enter,caracter;
    do{
        caracter=getchar();
        enter=getchar();
        switch(caracter){
            case 'w'://arriba
                if(y<=2){
                    //movimiento de ficha
                    tablero[y][x]=tablero[y+1][x];
                    tablero[y+1][x]=0;
                    y++;
                    imprimir_tablero();
                }
                else{
                    printf("fuera de los limites\n");
                }
                break;
            case 's'://abajo
                if(y>=1){
                    //movimiento de ficha
                    tablero[y][x]=tablero[y-1][x];
                    tablero[y-1][x]=0;
                    y--;
                    imprimir_tablero();
                }
                else{
                    printf("fuera de los limites\n");
                }
                break;
            case 'a'://izquierda
                if(x<=2){
                    //movimiento de ficha
                    tablero[y][x]=tablero[y][x+1];
                    tablero[y][x+1]=0;
                    x++;
                    imprimir_tablero();
                }
                else{
                    printf("fuera de los limites\n");
                }
                break;
            case 'd'://derecha
                if(x>=1){
                    //movimiento de ficha
                    tablero[y][x]=tablero[y][x-1];
                    tablero[y][x-1]=0;
                    x--;
                    imprimir_tablero();

                }
                else{
                    printf("fuera de los limites\n");
                }
                break;
            case'0'://salida
                break;
            default:
                printf("caracter incorrecto");
                break;}
        printf("%c \n",caracter);
        movs++;
        ganador=verificar_juego();
        if(ganador){
            terminar_juego(movs);
        }
    }
    while(caracter!='0');
}

int verificar_juego(){
    int x=0,y=0;
    int contador_ganador=0;
    for(y;y<4;y++){
        x=0;
        for(x=0;x<4;x++){
            if(tablero_ganador[y][x]==tablero[y][x]){
                contador_ganador++;
            }
        }
    }
    if (contador_ganador==16){
        return 1;
    }
    return 0;
}
void terminar_juego(movs){
    printf("Ganaste El juego >:v9 en: %d movimientos.", movs);
    menu();
}
void limpiar_tablero(){
    int x=0;
    for(int y=0;y<4;y++){
        x=0;
        for(x;x<4;x++){
            tablero[y][x] = -1;
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
        y=0;
        contador=0;
        aleatorio=generar_aleatorio(aleatorio);
        for(y;y<4;y++){
            x=0;
            for(x;x<4;x++){
                if(tablero[y][x]!=aleatorio){
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
    int x=0;
    int rellenador = 0;
    for(int y=0;y<4;y++){
        x=0;
        for(x;x<4;x++){
            if(rellenador>14){
                tablero[y][x] = 0;
            }
            else {
                tablero[y][x] = rellenar_tablero();
                rellenador++;
            }
        }
    }
}