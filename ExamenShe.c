#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
    struct Nodo *ant;
};

struct Nodo *inicio = NULL;

void insertar(int valor) {

    struct Nodo *nuevo = malloc(sizeof(struct Nodo));

    nuevo->dato = valor;

    if(inicio == NULL) {

        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        inicio = nuevo;
    }
    else {

        struct Nodo *ultimo = inicio->ant;

        nuevo->sig = inicio;
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        inicio->ant = nuevo;
    }

    printf("Numero insertado\n");
}

void mostrar() {

    if(inicio == NULL) {
        printf("Lista vacia\n");
        return;
    }

    struct Nodo *aux = inicio;

    do {

        printf("%d ", aux->dato);
        aux = aux->sig;

    } while(aux != inicio);

    printf("\n");
}


void eliminar(int valor) {

    if(inicio == NULL) {
        printf("Lista vacia\n");
        return;
    }

    struct Nodo *aux = inicio;

    do {

        if(aux->dato == valor) {

            if(aux->sig == aux) {
                inicio = NULL;
            }
            else {

                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;

                if(aux == inicio) {
                    inicio = aux->sig;
                }
            }

            free(aux);

            printf("Numero eliminado\n");
            return;
        }

        aux = aux->sig;

    } while(aux != inicio);

    printf("Numero no encontrado\n");
}

int main() {

    int op, num;

    do {

        printf("\n1. Insertar");
        printf("\n2. Eliminar");
        printf("\n3. Mostrar");
        printf("\n4. Salir");
        printf("\nOpcion: ");
        scanf("%d", &op);

        switch(op) {

            case 1:

                printf("Numero: ");
                scanf("%d", &num);

                insertar(num);
                break;

            case 2:

                printf("Numero a eliminar: ");
                scanf("%d", &num);

                eliminar(num);
                break;

            case 3:

                mostrar();
                break;

            case 4:

                printf("Fin del programa\n");
                break;

            default:

                printf("Opcion incorrecta\n");
        }

    } while(op != 4);

    return 0;
}