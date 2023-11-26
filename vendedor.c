#include <stdlib.h>
#include "vendedor.h"
// actualizar parte bodega
#include "bodeguero.h"
#include <stdio.h>
#include <string.h>


int contVentas = 0;
void cargarVentasDesdeArchivo();
void guardarVentasEnArchivo();
void registrarVenta();
struct venta ventas[50];

void menuVendedor() {
  int op;
  char name[5];

  cargarVentasDesdeArchivo();

  printf("1. Registrar Venta\n");
  printf("2. Mostrar ventas\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);

  switch (op) {
  case 1:
    registrarVenta();
    break;
  case 2:
  	mostrarVentas();
  	break;
  default:
    printf("Opcion invalida\n");
    break;
  }
  
}
/*
Local,
vendedor,
fecha de venta,
precio de venta y
reducir la cantidad de producto en bodega.
*/

void registrarVenta() {
  char nombreP[50];
  int cantidad;

  struct venta registroEnVentas;
  printf("Ingrese el nombre del vendedor: ");
  scanf("%s", registroEnVentas.n_vendedor);
  printf("Ingrese el nombre del producto: ");
  scanf("%s", nombreP);
  printf("Ingrese la cantidad productos de la venta: ");
  scanf("%d", &cantidad);
  printf("Ingrese la fecha de venta (formato(dia/mes/a�o): ");
  scanf("%s", registroEnVentas.fecha);
  printf("Ingrese el local que realiza la venta: ");
  scanf("%s", registroEnVentas.local);
  actualizarProdPorVenta(nombreP, cantidad);
  ventas[contVentas] = registroEnVentas;
  contVentas++;

  actualizarProdPorVenta(nombreP, cantidad);
  guardarVentasEnArchivo();   /**/
  menuVendedor();
}

void mostrarVentas() {
  for (int i = 0; i < contVentas; i++) {
    imprimirVentas(ventas[i]);
  }
  menuVendedor();
}

void imprimirVentas(struct venta v) {
  printf("Nombre del vendedor: %s\n", v.n_vendedor);
  printf("local: %s\n", v.local);
  printf("fecha de venta: %s\n", v.fecha);
  printf("----------------------\n");
}


void cargarVentasDesdeArchivo() {
    FILE *file = fopen("sales.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo de ventas");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%19s %19s %19s", ventas[contVentas].n_vendedor, ventas[contVentas].fecha, ventas[contVentas].local) == 3) {
        contVentas++;
    }

    fclose(file);
}

void guardarVentasEnArchivo() {
    FILE *file = fopen("sales.txt", "w");
    if (file == NULL) {
        perror("Error al abrir el archivo de ventas");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s %s %s\n", ventas[contVentas - 1].n_vendedor, ventas[contVentas - 1].fecha, ventas[contVentas - 1].local);

    fclose(file);
}