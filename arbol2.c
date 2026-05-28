#include <stdio.h>
#include <stdlib.h>

struct arbol {
    int dato;
    struct arbol *izq,*der;
};
    int menu(){
    int op;
        printf("\n---MENú---\n");
        printf("1 - Insertar\n");
        printf("2 - Mostrar InOrden\n");
        printf("0 - Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &op);
        return op;
}


struct arbol *crearNodo(void){
   struct arbol *ptrTemp=NULL;
    int dato;
    ptrTemp = (struct arbol *) malloc(sizeof(struct arbol));

    if(ptrTemp==NULL){
        printf("No se reservo memoria\n");
        return NULL;
    }else{
        printf("Ingrese el dato: ");
        scanf("%d", &dato);
        ptrTemp->dato=dato;
        ptrTemp->izq=NULL;
        ptrTemp->der=NULL;
        return ptrTemp;
    }
}

void insertar(struct arbol **ptr){
    struct arbol *ptrTemp;
    struct arbol *ptrAux;

    ptrTemp=crearNodo();

    if(ptrTemp==NULL){
        printf("No se creo Nodo");
    }else{
        if(*ptr==NULL){
            *ptr=ptrTemp;
        }else{
            ptrAux = *ptr;

            while(1){
                if(ptrTemp->dato > ptrAux->dato){

                    if(ptrAux->der != NULL){
                        ptrAux = ptrAux->der;
                    }else{
                        ptrAux->der = ptrTemp;
                        break;
                    }

                }else{

                    if(ptrAux->izq != NULL){
                        ptrAux = ptrAux->izq;
                    }else{
                        ptrAux->izq = ptrTemp;
                        break;
                    }
                }
            }
        }
    }
}

int inOrden(struct arbol *ptr){
    if(ptr==NULL){
        return 0;
    }else{
        inOrden(ptr->izq);
        printf(" %d ->",ptr->dato);
        inOrden(ptr->der);
        return 0;
    }
}

    int preOrden(struct arbol *ptr){
        if(ptr==NULL){
            return 0;
        }else{
            printf(" %d ->",ptr->dato);
            preOrden(ptr->izq);
            preOrden(ptr->der);
            return 0;
        }
}

        int posOrden(struct arbol *ptr){
            if(ptr==NULL){
                return 0;
            }else{
                posOrden(ptr->izq);
                posOrden(ptr->der);
                printf(" %d ->",ptr->dato);
                return 0;
            }
}

            int main() {
                struct arbol *raiz=NULL,*ptrTemp=NULL,*ptrAux=NULL,*ptrNuevo=NULL;
                int op;
                do {
                    op=menu();
                    switch(op) {
                        case 1:
                            insertar(&raiz);
                            break;

                        case 2:
                            inOrden(raiz);
                            printf("\n");
                            break;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                        case 0:
                            printf("Saliendo...\n");     
                            break;

                        default:
                            printf("Opcion invalida\n");
                    }
                } while(op != 0);

    return 0;
}