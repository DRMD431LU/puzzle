/*
 *
 * A)El programa deberá iniciar con un tablero aleatorio
 * 1.se debe proporcionar una semilla aleatoria
 * 2. de una lista enlazada se deberan obtener los valores
 * 3. se apunta al valor y se busca en la lista, se extrae
 * 4. se añade el return del pop a la lista tablero
 * 5. se hace iterativamente hasta vaciar la lista original
 * 6. se imprime el tablero inicial
 * B) el ultimo sera un espacio en blanco para mover las piezas
 * C) habrá 4 posibles movimientos establecer limites del tablero
 * D) se realizara una comprobacion de los elementos ordenados
 * E) en caso de cumplir con el ordenamiento se procedera a finalizar el juego
 * F) realizar pruebas para limites, valores de entrada, posibles finales...
 *
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

const int tablero_ganador[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

struct Node{
 int data;
 struct Node *next;
}*first = NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("[%d]\n",p->data);
        p=p->next;
    }
}
int buscar_valor(int aleatorio,int tablero[4][4]){
    int probable=0;
    for(int x=0; x<4;x++) {
        int y = 0;
        for (y; y < 4; y++) {
            if(tablero[x][y] != aleatorio){
                probable=aleatorio;
            }
            else{
                continue;
            }
        }
    }
    return probable;
}

int rellenar_tablero(int tablero[4][4]){
    int casilla=0;
    int rellenador = 0;
    srand(time(NULL));
    while (1){
        int aleatorio = rand()%15+1;
        casilla=buscar_valor(aleatorio,tablero);
//        printf("%d",casilla);
        if(casilla) {
            return casilla;
        }
    }
}
void iniciar_tablero(int tablero[4][4]){
    int y=0;
    for(int x=0;x<4;x++){
        y=0;
        for(y;y<4;y++){
            tablero[x][y] = -1;
        }
    }
    for(int x=0;x<4;x++){
        int y=0;
        for(y;y<4;y++){
            tablero[x][y] = rellenar_tablero(tablero);
            printf("[%2i]",tablero[x][y]);
        }
        printf("\n");
    }
}

int main(){
    int tablero_longitud = sizeof(tablero_ganador)/sizeof(int);
    int tablero[4][4];
    iniciar_tablero(tablero);
    return 0;
}




/*
int tabla [4][4];
int x=3, y=3;
char enter, caracter;
int main(){

    //inicializador la tabla de juego
    iniciar_tablero();
    imprimir_tablero();
    do{
        caracter=getchar();
        enter=getchar();
        switch(caracter){
            case 'w'://arriba
                if(y<=2){
                    //movimiento de ficha
                    tabla[y][x]=tabla[y+1][x];
                    tabla[y+1][x]=0;
                    imprimir_tablero();
                    y++;}
                else{
                    printf("fuera de los limites\n");}
                break;
            case 's'://abajo
                if(y>=1){
                    //movimiento de ficha
                    tabla[y][x]=tabla[y-1][x];
                    tabla[y-1][x]=0;
                    imprimir_tablero();
                    y--;}
                else{
                    printf("fuera de los limites\n");}
                break;
            case 'a'://izquierda
                if(x<=2){
                    //movimiento de ficha
                    tabla[y][x]=tabla[y][x+1];
                    tabla[y][x+1]=0;
                    imprimir_tablero();
                    x++;}
                else{
                    printf("fuera de los limites\n");}
                break;
            case 'd'://derecha
                if(x>=1){
                    //movimiento de ficha
                    tabla[y][x]=tabla[y][x-1];
                    tabla[y][x-1]=0;
                    imprimir_tablero();
                    x--;}
                else{
                    printf("fuera de los limites\n");}
                break;
            case'0'://salida
                break;
            default:
                printf("caracter incorrecto");
                break;}
        printf("caracter:%c\n",caracter);}
    while(caracter!='0');
    return 0;
}
void imprimir_tablero(){
    int i=0,j;
    while(i<4){
        j=0;
        while(j<4){
            if(tabla[i][j]!=0){
                printf("[%2i]",tabla[i][j]);}
            else{
                printf("[  ]");
            }
            j++;}
        printf("\n");
        i++;}
}

void iniciar_tablero(){
    int i=0, j=0, contador=1;
    int n=0;
    while(i<4){
        j=0;
        while(j<4){
            tabla[i][j] = rand() % 15 + 1;;
            j++;
            contador++;}
        printf("\n");
        i++;}
    tabla [y][x]=0;

}
*/