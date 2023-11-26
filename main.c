#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "administrador.h"
#include "bodeguero.h"
#include "vendedor.h"
#include "data.h"


/*int contUsuarios = 0;        */               /**/
struct user actualUser;                       /***/
void cargarUsuariosDesdeArchivo();
void guardarUsuariosEnArchivo();


int verificarUsuario(char name[10], char pass[10]);

int main(void) {
  char name[10], pass[10];
  /*
  struct user admin1;
  strcpy(admin1.username, "admin");
  strcpy(admin1.password, "123");
  strcpy(admin1.type, "admin");
  usuarios[0] = admin1;
  contUsuarios++;
*/
  printf("Ingrese usuario: ");
  scanf("%s", name);
  printf("Contraseña: ");
  scanf("%s", pass);
  if(verificarUsuario(name, pass) == 1) {
    if(strcmp(actualUser.type, "admin") == 0) {
      menuAdministrador();
    }else if(strcmp(actualUser.type, "vendedor") == 0) {
      menuVendedor();
    }else if(strcmp(actualUser.type, "bodeguero") == 0) {
      menuBodeguero();
    }
  }else {
    printf("Usuario no existente en el sistema\n\n");
    main();
  }
}
void cargarUsuariosDesdeArchivo() {
  FILE *file = fopen("validUsers.txt", "r");
  if (file == NULL) {
    perror("Error al abrir el archivo de usuarios");
    exit(EXIT_FAILURE);
  }

  while (fscanf(file, "%9s %9s %14s", usuarios[contUsuarios].username, usuarios[contUsuarios].password, usuarios[contUsuarios].type) == 3) {
    contUsuarios++;
  }

  fclose(file);
}

void guardarUsuariosEnArchivo() {
  FILE *file = fopen("validUsers.txt", "w");
  if (file == NULL) {
    perror("Error al abrir el archivo de usuarios");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < contUsuarios; i++) {
        fprintf(file, "%s %s %s\n", usuarios[i].username, usuarios[i].password, usuarios[i].type);
  }

  fclose(file);
}

int verificarUsuario(char name[10], char pass[10]) {
  for (int i = 0; i < contUsuarios; i++) {

    if (strcmp(usuarios[i].username, name) == 0 && strcmp(usuarios[i].password, pass) == 0) {
      actualUser = usuarios[i];
      return 1;
    }
  }
  return 0;
}