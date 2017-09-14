/*
*   Programa: Factura electronica
*   Fecha: 13/10/2017
*   Elaborado por: Alejandro Santibañez, Kelin Arboleda y Camila Borja.
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creacion estructuras
struct cliente{
    int id;
    char cedula[12];
    char nombre[30];
    char direccion[30];
    char telefono[30];
}clientes[100], *pclientes = clientes;

struct producto{
    int id;
    char nombre[30];
    float valor;
}productos[100], *pproductos = productos;

struct factura{
    int id_factura;
    int id_cliente;
    int id_producto[100];
    int cantidad[100];
    int proComprados;
    float total;
    bool estado;
}facturas[100], *pfacturas = facturas;

//Protipo funciones
void menu();
void creacionCliente();
void creacionProducto();
void creacionFactura();
void mostrarClientes();
void mostrarFacturas();

//Funciones cliente
void crearClientes();
void listarCliente();
void editarClientes();

//Funciones producto
void crearProducto();
void listarProducto();
void editarProducto();

//Funciones factura
void crearFactura();
void listarFactura();
void editarFactura();
bool validarCliente(int );
float validarProducto(int );

//Variables globales
int cantClientes = 0;
int cantProductos = 0;
int cantFacturas = 0;

//Funcion principal
int main(){
    menu();

    return 0;
}
//Menu principal
void menu(){
    int opcion;

    do{
        printf("|----------------------------------------------------------|\n");
		printf("|                 MENU FACTURA ELECTRONICA                 |\n");
		printf("|----------------------------------------------------------|\n");
		printf("|                                   |                      |\n");
		printf("| 1. Crear, Listar y Editar Cliente |  5.  Mostrar Facturas|\n");
		printf("| 2. Crear, Listar y Editar Poducto |  0.  Salir           |\n");
		printf("| 3. Crear, Listar y Editar Factura |                      |\n");
		printf("| 4. Mostrar Clientes               |                      |\n");
		printf("|                                   |                      |\n");
		printf("|----------------------------------------------------------|\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");

		switch(opcion){
            case 1: creacionCliente();
                break;
            case 2: creacionProducto();
                break;
            case 3: creacionFactura();
                break;
            case 4: mostrarClientes();
                break;
            case 5: mostrarFacturas();
                break;
            case 0: exit(0);
                break;
            default: printf("No es una opcion valida\n");
		}
		system("pause");
        system("cls");
    }while(opcion != 0);
}
//Funciones cliente
void creacionCliente(){
    int opcion;

    do{
        printf("|----------------------------------------|\n");
		printf("|                MENU CLIENTE            |\n");
		printf("|----------------------------------------|\n");
		printf("|                        |               |\n");
		printf("|  1. Crear Cliente      |               |\n");
		printf("|  2. Listar Ciente      |               |\n");
		printf("|  3. Editar Cliente     |               |\n");
		printf("|  0. Salir              |               |\n");
		printf("|----------------------------------------|\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");

		switch(opcion){
            case 1: crearClientes();
                break;
            case 2: listarCliente();
                break;
            case 3: editarClientes();
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida\n");
		}
		system("pause");
        system("cls");
    }while(opcion != 0);
}

void crearClientes(){
    int numClientes;
    int cantClientesCrear;

    printf("Ingrese cantidad de clientes a crear: ");
    scanf("%d", &numClientes);

    cantClientesCrear = cantClientes + numClientes;

    for(int i = cantClientes; i < cantClientesCrear; i++){
        fflush(stdin);
        ((pclientes + i)->id) = i + 1;
        printf("Ingrese el nombre del cliente: ");
        fgets((pclientes + i)->nombre,30,stdin);
        printf("Ingrese cedula del cliente: ");
        fgets((pclientes + i)->cedula,12,stdin);
        printf("Ingrese la direccion del cliente: ");
        fgets((pclientes + i)->direccion,30,stdin);
        printf("Ingrese el telefono del cliente: ");
        fgets((pclientes + i)->telefono,30,stdin);
        printf("\n");
        cantClientes += 1;
    }
}

void listarCliente(){
    if(cantClientes == 0){
        printf("No hay clientes registrados \n");
    }else{
        for(int i = 0; i < cantClientes; i++){
            printf("ID: \t%d\n", (pclientes + i)->id);
            printf("Nombre: \t%s", (pclientes + i)->nombre);
            printf("Cedula: \t%s", (pclientes + i)->cedula);
            printf("Direccion: \t%s", (pclientes + i)->direccion);
            printf("Telefono: \t%s", (pclientes + i)->telefono);
            printf("\n");
        }
    }
}

void editarClientes(){
    int idClienteCambio, aux, cantComparaciones;

    printf("Ingrese el ID del cliente que desea cambiar: ");
    scanf("%d", &idClienteCambio);

    for(int i = 0; i < cantClientes; i++){
        if((pclientes + i)->id == idClienteCambio){
            printf("ID: \t%d\n", (pclientes + i)->id);
            printf("1. Nombre: \t%s", (pclientes + i)->nombre);
            printf("2. Cedula: \t%s", (pclientes + i)->cedula);
            printf("3. Direccion: \t%s", (pclientes + i)->direccion);
            printf("4. Telefono: \t%s", (pclientes + i)->telefono);
            printf("5. Cambiar todos los datos\n");
            printf("Que desea cambiar: ");
            scanf("%d", &aux);
            fflush(stdin);

            switch(aux){
                case 1: printf("Ingrese el nombre del cliente: ");
                        fgets((pclientes + i)->nombre,30,stdin);
                        printf("Cambiado con exito");
                    break;
                case 2: printf("Ingrese cedula del cliente: ");
                        fgets((pclientes + i)->cedula,12,stdin);
                        printf("Cambiado con exito");
                    break;
                case 3: fgets((pclientes + i)->cedula,12,stdin);
                        printf("Ingrese la direccion del cliente: ");
                        printf("Cambiado con exito");
                    break;
                case 4: printf("Ingrese el telefono del cliente: ");
                        fgets((pclientes + i)->telefono,30,stdin);
                        printf("Cambiado con exito");
                    break;
                case 5: printf("Ingrese el nombre del cliente: ");
                        fgets((pclientes + i)->nombre,30,stdin);
                        printf("Ingrese cedula del cliente: ");
                        fgets((pclientes + i)->cedula,12,stdin);
                        printf("Ingrese la direccion del cliente: ");
                        fgets((pclientes + i)->direccion,30,stdin);
                        printf("Ingrese el telefono del cliente: ");
                        fgets((pclientes + i)->telefono,30,stdin);
                        printf("Cambiado con exito\n");
            }
            break;
        }else{
            cantComparaciones += 1;
        }
    }
    if(cantComparaciones > 0){
        printf("el usuario no esta registrado \n");
    }
}

void creacionProducto(){
    int opcion;

    do{
        printf("|----------------------------------------|\n");
		printf("|                MENU PRODUCTOS          |\n");
		printf("|----------------------------------------|\n");
		printf("|                        |               |\n");
		printf("|  1. Crear Producto     |               |\n");
		printf("|  2. Listar Produto     |               |\n");
		printf("|  3. Editar Producto    |               |\n");
		printf("|  0. Salir              |               |\n");
		printf("|----------------------------------------|\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion){
            case 1: crearProducto();
                break;
            case 2: listarProducto();
                break;
            case 3: editarProducto();
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida\n");
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

//Funciones producto
void crearProducto(){
    int numProductos;
    int cantProductosCrear;

    printf("Ingrese cantidad de productos a registrar: ");
    scanf("%d", &numProductos);

    cantProductosCrear = cantProductos + numProductos;

    for(int i = cantProductos; i < cantProductosCrear; i++){
        fflush(stdin);
        (pproductos + i)->id = i + 1;
        printf("Ingrese el nombre del producto: ");
        fgets((pproductos + i)->nombre,30,stdin);
        printf("Ingrese el valor del producto: ");
        scanf("%f", &(pproductos + i)->valor);
        printf("\n");
        cantProductos += 1;
    }
}

void listarProducto(){
    if(cantProductos == 0){
        printf("No hay productos registrados \n");
    }else{
        for(int i = 0; i < cantProductos; i++){
            printf("ID: \t\t%d\n", (pproductos + i)->id = i + 1);
            printf("Nombre: \t%s", (pproductos + i)->nombre);
            printf("Valor: \t\t%f\n", (pproductos + i)->valor);
            printf("\n");
        }
    }
}

void editarProducto(){
    int idProductoCambio, aux, cantComparaciones;

    printf("Ingrese el ID del cliente que desea cambiar: \n");
    scanf("%d", &idProductoCambio);

    for(int i = 0; i < cantProductos; i++){
        if((pproductos + i)->id == idProductoCambio){
            printf("ID: \t%d\n", (pclientes + i)->id);
            printf("1. Nombre: \t%s", (pproductos + i)->nombre);
            printf("2. Valor: \t%f\n", (pproductos + i)->valor);
            printf("3. Cambiar todos los datos\n");
            printf("Que desea cambiar: ");
            scanf("%d", &aux);
            fflush(stdin);

            switch(aux){
                case 1: printf("Ingrese el nombre del producto: ");
                        fgets((pproductos + i)->nombre,30,stdin);
                        printf("Cambiado con exito\n");
                    break;
                case 2: printf("Ingrese el valor del producto: ");
                        scanf("%f", (pproductos + i)->valor);
                        printf("Cambiado con exito\n");
                    break;
                case 3: printf("Ingrese el nombre del producto: ");
                        fgets((pproductos + i)->nombre,30,stdin);
                        printf("Ingrese el valor del producto: ");
                        scanf("%f", &(pproductos + i)->valor);
                        printf("Cambiados con exito\n");
                    break;
            }
            break;
        }else{
            cantComparaciones += 1;
        }
    }
    if(cantComparaciones > 0){
        printf("el producto no esta registrado \n");
    }
}

//Funciones factura
void creacionFactura(){
    int opcion;

    do{
        printf("|----------------------------------------|\n");
		printf("|                MENU FACTURAS           |\n");
		printf("|----------------------------------------|\n");
		printf("|                        |               |\n");
		printf("|  1. Crear Factura      |               |\n");
		printf("|  2. Listar Factura     |               |\n");
		printf("|  3. Editar Factura     |               |\n");
		printf("|  0. Salir              |               |\n");
		printf("|----------------------------------------|\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");

		switch(opcion){
            case 1: crearFactura();
                break;
            case 2: listarFactura();
                break;
            case 3: editarFactura();
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida\n");
		}
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void crearFactura(){
    int numFacturas;
    int cantFacturasCrear;
    int id_cliente;
    int id_productos;
    int numproductos;
    int acum = 0;
    float valorProducto;

    (pfacturas + cantFacturas)->id_factura = cantFacturas + 1;
    listarCliente();

    while(true){
        printf("Ingrese el id del cliente: ");
        scanf("%d", &id_cliente);
        if(validarCliente(id_cliente)){
            (pfacturas + cantFacturas)->id_cliente = id_cliente;
            break;
        }else{
            printf("El ID del cliente no es valido\n");
        }
    }
    listarProducto();

    printf("Ingrese la cantidad de productos a facturar: ");
    scanf("%d", &numproductos);

    (pfacturas + cantFacturas)->proComprados = numproductos;

    for(int i = 0; i < numproductos; i++){
        while(true){
            printf("Ingrese el id del producto %d: ", i + 1);
            scanf("%d", &id_productos);
            valorProducto = validarProducto(id_productos);
            if( valorProducto != 0){
                *(((pfacturas + cantFacturas)->id_producto) + i) = id_productos;
                printf("Ingrese cantidad a comprar: ");
                scanf("%d",&((pfacturas + cantFacturas)->cantidad) + i);
                //acum = *(pfacturas + 1)->cantidad ;
                acum += (valorProducto * *(((pfacturas + cantFacturas)->cantidad) + i));
                break;
            }else{
                printf("El ID del producto no es valido\n");
            }
        }
    }
    (pfacturas + cantFacturas)->total = acum;
    (pfacturas + cantFacturas)->estado = true;
    cantFacturas++;
    printf("Factura creada con exito\n");
}

bool validarCliente(int cliente){
    int i;

    for(i = 0; i <cantClientes; i++){
        if((pclientes + i)->id == cliente){
           return true;
           break;
        }
    }return false;
}

float validarProducto(int producto){
    int i;

    for(i = 0; i <cantProductos; i++){
        if((pproductos + i)->id == producto){
           return (pproductos + i)->valor;
           break;
        }
    }return 0;
}

void listarFactura(){
    printf("Listado facturas\n");

    printf("Estado \t id factura \t id cliente \t cantidad productos \t Total\n");
    printf("-------------------------------------------------------------------\n");
    for(int i = 0; i < cantFacturas; i++){
        if((pfacturas + i)->estado){
            printf("Pago \t");
        }
        printf(" %d \t\t %d \t\t %d \t\t %0.2f\n", (pfacturas + i)->id_factura, (pfacturas + i)->id_cliente, (pfacturas + i)->id_cliente, (pfacturas + i)->proComprados, (pfacturas + i)->total);
    }
}

void editarFactura(){
    int id_facturaCambio, aux, cantcomparaciones;

    printf("Ingrese el id de la factura que desea cambiar: ");
    scanf("%d", &id_facturaCambio);

    for(int i = 0; i < cantFacturas; i++){
        if((pfacturas + i)->id_factura == id_facturaCambio){
            printf("Estado \t id factura \t id cliente \t cantidad productos \t Total\n");
            printf("-------------------------------------------------------------------\n");
            for(int i = 0; i < cantFacturas; i++){
                if((pfacturas + i)->estado){
                printf("Pago \t");
                }
                printf("Estado: \t%d", (pfacturas + i)->id_factura);
                printf("Factura: \t%d",(pfacturas + i)->id_cliente);
                printf("Id Caliente: \t%d",  (pfacturas + i)->id_cliente);
                printf("Cantidad Productos: \t%d", (pfacturas + i)->proComprados);
                printf("Total: \t%0.2f", (pfacturas + i)->total);
                printf("Que desea cambiar: \n");
                scanf("%d", &aux);
                fflush(stdin);

                switch(aux){
                    case 1: printf("1. cambio de estado: ");
                            (pfacturas + cantFacturas)->estado = false;
                            printf("Cambiado con exito\n");
                        break;
                    case 2: printf("2. Ingrese la cantidad de productos: ");
                            scanf("%d", &(pfacturas + i)->proComprados);
                            printf("Cambiado con exito\n");
                        break;
                }
                break;
            }
        }else{
                cantcomparaciones += 1;
            }

    }
    if(cantcomparaciones > 0){
        printf("el producto no esta registrado \n");
    }
}

void mostrarFacturas(){
    printf("Las facturas totales son:\n\n");

    if(cantFacturas == 0){
        printf("No hay facturas registradas\n");
    }else{
        printf("Estado \t id factura \t id cliente \t cantidad productos \t Total\n");
        printf("-------------------------------------------------------------------\n");
        for(int i = 0; i < cantFacturas; i++){
            if((pfacturas + i)->estado){
            printf("Pago \t");
            }
            printf(" %d \t\t %d \t\t %d \t\t %0.2f\n", (pfacturas + i)->id_factura, (pfacturas + i)->id_cliente, (pfacturas + i)->id_cliente, (pfacturas + i)->proComprados, (pfacturas + i)->total);
        }
    }
}

void mostrarClientes(){
    printf("Lista de clientes registrados en el sistema:\n\n");

    if(cantClientes == 0){
        printf("No hay clientes registrados \n");
    }else{
        for(int i = 0; i < cantClientes; i++){
            //printf("ID: \t%d\n", (pclientes + i)->id);
            printf("Nombre: \t%s", (pclientes + i)->nombre);
            printf("Cedula: \t%s", (pclientes + i)->cedula);
            printf("Direccion: \t%s", (pclientes + i)->direccion);
            printf("Telefono: \t%s", (pclientes + i)->telefono);
            printf("\n");
        }
    }
}
