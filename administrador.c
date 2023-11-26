#include<stdio.h>
#include<string.h>
#include "administrador.h"
#include "usuarios.h"

int contUsuarios = 0;
struct user usuarios[100];

void menuAdministrador(){
  int op;
  char username[10];
  printf("1. Crear Usuario\n");
  printf("2. Actualizar Usuario\n");
  printf("3. Mostrar usuarios\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);

  switch(op) {
    case 1: 
      crearUsuario();
      break;
    case 2:
      printf("Ingrese el usuario para actualizar: ");
      scanf("%s", username);
      actualizarUsuario(username);
      break;
	case 3:
      mostrarUsuarios();
      break;
    default:
      printf("Opcion invalida\n");
      menuAdministrador();
      break;
  }
}

void crearUsuario() {
  struct user newUser;
  printf("Ingrese el nombre del usuario: ");
  scanf("%s", newUser.username);
  printf("Ingrese la contraseña del usuario: ");
  scanf("%s", newUser.password);
  printf("Ingrese el tipo de usuario: ");
  scanf("%s", newUser.type);
  usuarios[contUsuarios] = newUser;
  //SE AUMENTA EL CONTADOR DE USUARIOS EN EL SISTEMA;
  contUsuarios++;
guardarUsuariosEnArchivo();
  menuAdministrador();
}

void actualizarUsuario(char name[10]) {
  int op;
  int userIndex;
  for(int i = 0; i < contUsuarios; i++) {
    if(strcmp(usuarios[i].username, name) == 0){
      userIndex = i;
    }
  }
  printf("1. Cambiar contrasena\n");
  printf("2. Cambiar tipo\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);
  switch(op) {
    case 1:
      printf("Ingrese la nueva contrasena: ");
      scanf("%s", usuarios[userIndex].password);
      break;
    case 2:
      printf("Ingrese nuevo tipo: ");
      scanf("%s", usuarios[userIndex].type);
      break;
    default:
      printf("Opcion invalida\n");
      break;
  }
  guardarUsuariosEnArchivo();
  menuAdministrador();
}

void mostrarUsuarios() {
	for(int i = 0; i < contUsuarios; i++) {
		imprimirUsuario(usuarios[i]);
	}	
	menuAdministrador();
}

void imprimirUsuario(struct user u) {
	printf("Nombre: %s\n", u.username);
	printf("Tipo: %s\n", u.type);
	printf("----------------------\n");
}
