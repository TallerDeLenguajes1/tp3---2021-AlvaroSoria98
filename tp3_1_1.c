#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *t_productos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct producto_t{
    int productoID; //numerado en ciclo iterativo
    int cantidad;// entre 1 y 10
    char *tipoProducto;//algun valor del arreglo Tipproduct
    float precioUnitario;
};
typedef struct producto_t product;
struct cliente_t{
    int cliendteID; // numerado en el cliclo iterativo
    char *nombreCliente; //ingresado por usuario
    int cantProducApedir;//alatoreo entre 1 y 5
    product *producto;//tamaño de este arreglo depende de la variable cantProducApedir
};
typedef struct cliente_t client;
/*Declaracion de Funciones*/
client *asigMD(client *datos, int *n);
void CargarCliente(client *datos, int *n);

int main(){
    srand(time(NULL));
    int cantClient;
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", &cantClient);
    client *p_client=asigMD(p_client,&cantClient);
    CargarCliente(p_client,&cantClient);
    puts(p_client->producto->tipoProducto[0]);
    free(p_client);
    return 0;
}

//Funciones
client *asigMD(client *memoria, int *n){
    client *clienteN=(client*)malloc(*n*sizeof(client));
    return memoria;
}

void CargarCliente(client *datos, int *n){
    for(int i=0; i < *n; i++){
        datos->cliendteID= i+1;
        datos->nombreCliente=malloc(20*sizeof(char));
        printf("Ingrese el nombre del cliente: ");
        gets(datos->nombreCliente);
        datos->cantProducApedir=rand()%(5-1+1)+1;
        for (int i = 0; i < datos->cantProducApedir; i++)
        {
            datos->producto=(product*)malloc(i*sizeof(product));
            datos->producto->productoID=i+1;
            datos->producto->cantidad=rand()%(10-1+1)+1;
            strcpy(datos->producto->tipoProducto[i],*t_productos[i]);
        }
        datos++;
    }
}