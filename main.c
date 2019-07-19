/*
 * Se crea una semilla para la generacion aleatoria de numeros
 * se establece un arreglo con todos los numeros posibles y la combinacion ganadora
 * Se rellena cada espacio aleatoriamente y se busca si este numero ya se encuentra
 * con anterioridad en el tablero si existe se genera otro si no se añade.
 * se mueven las fichas, por cada movimiento se verifica si se cumple el arreglo ganador
 * si se cumple se muestra una pantalla los movimientos totales
 * Game over
 * si no se pide un movimiento nuevo.
 * */
//Importar modulos de la libreria estandar
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//primitivas de funciones
void limpiar_tablero();
int buscar_valor();
void iniciar_tablero();
int rellenar_tablero();
int generar_aleatorio(int aleatorio);
void mover_pieza();
void imprimir_tablero();
int verificar_juego();
void terminar_juego(int movs);
void nuevo_juego();
void imprimir_tablero_ganador();
int menu();

//variables globales y constantes
const int tablero_ganador[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
/*se pueden añadir mas combinaciones ganadoras, por cada nueva combinacion habria que verificarla en
 * verificar_juego();
*/
int tablero[4][4];
//tablero de juego
int ganador=0;
//variable de tipo entera, se usa en lugar de un booleano para verificar si se ha ganado.


int main(){
    srand(time(NULL));
    menu();
    return 0;
}


int menu(){
    /*Imprime un menu en pantalla con las opciones actualmente disponibles
     * */
    char enter,caracter;
    while(1){
        printf("Menu:\nSeleccione alguna de las siguientes opciones:\nz.-Juego Nuevo.\nq.-Salir.\nx.-Instrucciones.\n");
        caracter=getchar();
        enter=getchar();
        switch(caracter){
            case 'z':
                //nuevo juego
                nuevo_juego();
            case 'q':
                //salir
                return 0;
            case 'x':
                //Instrucciones.
                printf("Presione en cualquier momento la tecla 0 para salir.\n");
                printf("Utilice las teclas A,W,S,D para mover las fichas.\n");
                printf("Para ganar el juego deberá formar el siguiente tablero:\n");
                imprimir_tablero_ganador();
        }
    }
}


void imprimir_tablero_ganador(){
    /*Funcion que imprime la combinacion ganadora como parte de las instrucciones
     * */
    int y=0,x=0;
    for(y;y<4;y++){
        x=0;
        for(x;x<4;x++){
            if(tablero_ganador[y][x]!=0){
                printf("[%2i]",tablero_ganador[y][x]);}
            else{
                printf("[  ]");
            }
        }
        printf("\n");
    }
}


void nuevo_juego(){
    /*
     * Inicia un nuevo tablero y un juego desde 0
     */
    limpiar_tablero();
    iniciar_tablero();
    imprimir_tablero();
    mover_pieza();
}


void imprimir_tablero(){
    /*funcion recurrente que se usa para mostrar el movimiento de las piezas
     * */
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
    /*verifica el ingreso por teclado de parte del usuario para realizar movimientos en el tablero
     * por cada movimiento se compara con la combinacion ganadora, y se suma al contador de movimientos
     * */
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
                printf("No huyas cobarde! >:V9: %d movimientos.", movs);
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
    /*compara el tablero actual de juego con la combinacion ganadora
     * */
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
    /*En caso de ser iguales el tablero de juego y la combinacion ganadora se invoca esta funcion para imprimir en
     * pantalla el mensaje ganador y los movimientos totales
     * se puede configurar un mensaje distinto y con mayor informacion del juego
     * */
    printf("Ganaste El juego <]:{v en: %d movimientos.", movs);
}


void limpiar_tablero(){
    /*rellena el tablero de juego con numeros negativos para realizar un acomodo aleatorio nuevo
     * */
    int x=0;
    for(int y=0;y<4;y++){
        x=0;
        for(x;x<4;x++){
            tablero[y][x] = -1;
        }
    }
}


int generar_aleatorio(int aleatorio){
    /*a partir de la semilla, se genera un numero aleatorio en el rango entre 1 y 15.
     * */
    aleatorio = rand() % 15 + 1;
    return aleatorio;
}


int rellenar_tablero() {
    /*invoca a la funcion de comprobacion de valores, en caso de que el valor aleatorio no se encuentre en el
     * tablero de juego actual lo asigna a la siguiente casilla del tablero actual
     * */
    int casilla=0;
    casilla = buscar_valor();
    return casilla;
}


int buscar_valor(){
    /*verifica que el valor aleatorio no se encuentre en el tablero de juego actual
     * podria modificarse para añadir como limite el valor actual del tablero de juego como limites superiores e
     * inferiores
     * */
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
    /*con un tablero limpio
     * se procede a buscar valores aleatorios para cada casilla
     * una vez finalizado el rellenado del tablero, se encuentra
     * listo para los movimientos de parte del usuario*/
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