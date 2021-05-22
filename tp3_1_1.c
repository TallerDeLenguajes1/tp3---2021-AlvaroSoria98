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
void CargarCliente(client *datos, int n);

int main(){
    srand(time(NULL));
    int cantClient;
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", &cantClient);
    
    client *p_client=(client*)malloc(cantClient*sizeof(client));
    CargarCliente(p_client,cantClient);

	int i;
	
    for ( i = 0; i < cantClient; i++)
    {
        /* code */
        printf("CLIENTE ID: %d \n Nombre: ",p_client->cliendteID);
        puts(p_client->nombreCliente);
        printf(" Cantidad de productos a pedir: %d", p_client->cantProducApedir);
        printf("\n");
        int j;
        for ( j = 0; j < p_client->cantProducApedir; j++)
        {
            printf("\n  PRODUCTO ID: %d \n  Nombre de Producto: ",p_client->producto->productoID);
            puts(p_client->producto->tipoProducto);
            printf("  CANTIDAD: %d",p_client->producto->cantidad);
        }
        
        
        printf("\n\n");
		p_client++;
    }
    free(p_client);
    
    return 0;
}

//Funciones

void CargarCliente(client *datos, int n){
	int i;
    for( i=0; i < n; i++){
        //cliente id
        datos->cliendteID= i + 1;

        //Nombre cliente
        printf("\n=========================================\n");
        printf("ingrese el nombre del cliente %d: ", i+1);
        datos->nombreCliente=(char *)malloc(sizeof(char)*20);
        fflush(stdin);
        gets(datos->nombreCliente);
        printf("=========================================\n");
        printf("\n");

        //cantidad de productos a pedir
        datos->cantProducApedir=rand()%(5 - 1 + 1) + 1;

        //tipo de productos
        int j;
        for ( j = 0; j < datos->cantProducApedir; j++)
        {
            datos->producto=(product*)malloc(sizeof(product)*datos->cantProducApedir);
            fflush(stdin);
            //ID producto
            datos->producto->productoID=j+1;

            //cantidad
            datos->producto->cantidad=rand()%(10 - 1 + 1) + 1;

            //tipo producto
            datos->producto->tipoProducto=(char*)malloc(sizeof(char)*20);
            fflush(stdin);
            int temp=rand()%(5-1+1)+1;
            strcpy(datos->producto->tipoProducto,t_productos[temp]);
            fflush(stdin);
            datos->producto++;
        }
        
        datos++;
    }
}
