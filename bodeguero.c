#include "bodeguero.h"
//#include "usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirProductos(struct producto prod);
void guardarProductosEnArchivo();
void cargarProductosDesdeArchivo();
int contProductos = 0;
/*-------------------------------------------------------------------------*/
void menuBodeguero() {
  int op;
  char nombre[20];
  /*
  int cantidad;
  char categoria[50];
  char marca[50];
  char codigo[50];
  float precioCompra;
  float precioVenta;
  */
  printf("1. Crear Productos\n");
  printf("2. Actualizar Productos\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);

  /*dijo que no pongamos las validaciones*/
  switch (op) {
  case 1:
    crearProducto();
    break;
  case 2:
    printf("Ingrese el producto para actualizar: ");
    scanf("%s", nombre);

    actualizarRegistrosProducto(nombre);
    break;
  default:
    printf("Opcion invalida\n");
    break;
  }

  guardarProductosEnArchivo();

}

void crearProducto() {
  struct producto nuevoProducto;
  printf("Ingrese el nombre del producto: ");
  scanf("%s", nuevoProducto.nombre);
  printf("Ingrese la cantidad del producto: ");
  scanf("%d", &nuevoProducto.cantidad);
  printf("Ingrese la marca del producto: ");
  scanf("%s", nuevoProducto.marca);
  printf("Ingrese la codigo del producto: ");
  scanf("%s", nuevoProducto.codigo);
  printf("Ingrese el precio de compra del producto: ");
  scanf("%f", &nuevoProducto.precioCompra);
  printf("Ingrese el precio de venta del producto: ");
  scanf("%f", &nuevoProducto.precioVenta);
  productos[contProductos] = nuevoProducto;
  contProductos++;
  // SE AUMENTA EL CONTADOR DE PRODUCTOS EN EL SISTEMA
  menuBodeguero();
}

void actualizarRegistrosProducto(char name[20]) {
  int op;
  int index;

  // struct producto productUP;
  for (int i = 0; i < contProductos; i++) {
    if (strcmp(productos[i].nombre, name) == 0) {
      index = i;
      //  productos[i] =productUP;
    }
  }

  printf("1. Cambiar nombre\n");
  printf("2. Cambiar cantidad en stock\n");
  printf("3. Cambiar catergoria\n");
  printf("4. Cambiar marca\n");
  printf("5. Cambiar codigo\n");
  printf("4. Cambiar precio de compra\n");
  printf("5. Cambiar precio de venta\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);
  switch (op) {
  case 1:
    printf("Ingrese el nuevo nombre: ");
    scanf("%s", productos[index].nombre); // productUP.nombre
    break;
  case 2:
    printf("Ingrese la nueva cantidad(entero): ");
    scanf("%d", &productos[index].cantidad);
    break;
  case 3:
    printf("Ingrese la nueva categoria: ");
    scanf("%s", productos[index].categoria);
    break;
  case 4:
    printf("Ingrese la nueva marca: ");
    scanf("%s", productos[index].marca);
    break;
  case 5:
    printf("Ingrese la nueva codigo: ");
    scanf("%s", productos[index].codigo);
    break;
  case 6:
    printf("Ingrese el nuevo precio de compra (formato 0.0): ");
    scanf("%f", &productos[index].precioCompra);
    break;
  case 7:
    printf("Ingrese el nuevo precio de venta(formato 0.0); ");
    scanf("%f", &productos[index].precioVenta);
    break;
  default:
    printf("Opcion invalida\n");
    break;
  }
  menuBodeguero();
}
void mostrarProductos() {
  for (int i = 0; i < contProductos; i++) {
    imprimirProductos(productos[i]);
  }
  menuBodeguero();
}

void imprimirProductos(struct producto prod) {
  printf("Nombre: %s\n", prod.nombre);
  printf("Cantidad: %d\n", prod.cantidad);
  printf("Categoria: %s\n", prod.categoria);
  printf("Marca: %s\n", prod.marca);
  printf("C�digo: %s\n", prod.codigo);
  printf("Precio de compra: %f\n", prod.precioCompra);
  printf("Precio de venta: %f\n", prod.precioVenta);
  printf("----------------------\n");
}

void actualizarProdPorVenta(char nombreProducto[20], int cantidad) {
  int userIndex;
  for (int i = 0; i < contProductos; i++) {
    if (strcmp(productos[i].nombre, nombreProducto) == 0) {
      // userIndex = i;
      if (cantidad < productos[i].cantidad) {
        productos[i].cantidad = productos[i].cantidad - cantidad;
        printf("Se vendieron %d unidades del producto \n", cantidad);
//        printf("Se vendieron %d unidades del producto %s\n", cantidad);
        
      } else {
        printf("No hay cantidad suficiente");
      }
    }
  }
}



void cargarProductosDesdeArchivo() {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo de productos");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d %s %s %s %f %f",
                  productos[contProductos].nombre,
                  &productos[contProductos].cantidad,
                  productos[contProductos].categoria,
                  productos[contProductos].marca,
                  productos[contProductos].codigo,
                  &productos[contProductos].precioCompra,
                  &productos[contProductos].precioVenta) == 7) {
        contProductos++;
    }
    

    fclose(file);
}

void guardarProductosEnArchivo() {
    FILE *file = fopen("prodcuts.txt", "w");
    if (file == NULL) {
        perror("Error al abrir el archivo de productos");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < contProductos; i++) {
        fprintf(file, "%s %d %s %s %s %f %f\n",
                productos[i].nombre,
                productos[i].cantidad,
                productos[i].categoria,
                productos[i].marca,
                productos[i].codigo,
                productos[i].precioCompra,
                productos[i].precioVenta);
    }
    fclose(file);
}


