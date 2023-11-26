#ifndef VENDEDOR_H
#define VENDEDOR_H

// Definición de la estructura para registrar ventas
struct venta {
  char n_vendedor[20];
  char fecha[20];
  char local[20];
};

// Prototipos de las funciones del vendedor
void menuVendedor(void);
void registrarVenta(void);
void mostrarVentas(void);
void imprimirVentas(struct venta v);

#endif // VENDEDOR_H
