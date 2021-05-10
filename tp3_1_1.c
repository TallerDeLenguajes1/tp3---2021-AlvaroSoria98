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

int main(){
    return 0;
}