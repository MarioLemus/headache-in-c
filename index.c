/* preguntas c */

// [x] crear estructura basica de main?
// - se crea una funcion, y ya

// [x] como compilar?
// - gcc -o <alias para ejecutable> index.c(archivo src)

// [x] como saber, si la funcion concluyo con exito o no?
//  - se retorna 0 para exito y 1 para error

// [x] que es un file descriptor?
//  - es un numero de identificacion que se utiliza para identificar un archivo abierto,
//    un socket, tuberia u otro recurso del sistema que puede ser accedido a traves de i/o

// [x] que es un puntero?
//  - es una variable, que almacena la direccion en memoria de otra variable

// [x] como declarar y asignar un puntero?
//  - para declarar un puntero se hace asi, "*" antes del nombre de la variable
//  - para inicializar un puntero se hace asi, "&" antes de la variable
//    de la cual se desea obtener su direccion

// [x] como allocar memoria?
//  - se utiliza la funcion malloc (se encuentra en, stdlib)
//  - se puede utilizar calloc tambien que inicializa los valores a 0,
//    ayuda a evitar los problemas de acceso de memoria

// [x] como se calcula el tamaño en memoria que tiene cada elemento?
//  - bit = 0-1
//  - byte = 0101 0101 -> combinacion de bits que pueden generar muchos valores

// [x] a cuantos bytes equivale un char?
//  - 1 byte

// [x] cuantos digitos numericos se pueden representar con 1 byte?
//  - depende del tamaño, pero posiblemente en un solo byte se puedan representar 256 digitos aprox.

// [x] es necesario usar malloc siempre?
//  - no, solo se utilizar para asignar memoria dinamicamente en tiempo de ejecucion,
//    debido a que normalmente la memoria se suele allocar de manera estatica
//    al momento de compilar (al compilar se setean los tamaños de la data, lo que lo vuelve inflexible)

// [x] como acceder al valor allocado en una cierta direccion de memoria?
//  - se almacena el pointer en una nueva variable comun

// [x] como lidiar con la reserva y liberacion de memoria?
//  - se utiliza la funcion, free() para des-allocar aquel puntero previamente allocado

// [x] debo usar free siempre? 
//  - no, debido a que solo se puede utilizar en variables en las que se use "malloc"

// [x] que es un null pointer?
//  - es cuando se apunta a una direccion de memoria no valida

// [x] como representar un null pointer manualmente?
//  - se utiliza NULL

// [] como asignar memoria de manera correcta?
//  - 

// [x] como revisar posibles problemas de memoria?
//  - utilizar valgrind
//  - forma de utilizarlo: valgrind ./index 

// [x] diferencia entre null y nill?
//  - es lo mismo, aunque en C no existe nil


// usar punteros para almacenar strings, solo si definen al instante
// si se desea almacenar strings es preferente usar la sintaxis de array
/*----------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void presentation_logs() {
    char *welcome_msg = "WELCOME TO YOUR PASSWORD VAULT";
    char *options_selection = "Select one (by their number) of the following options:";

    printf("%s\n", welcome_msg);
    printf("%s\n\n", options_selection);
}


void options_logs() {
    char *option_1 = "1. Add a new password";
    char *option_2 = "2. List saved passwords";
    char *option_3 = "3. Search specific password";
    char *option_4 = "4. Delete password";
    char *option_5 = "5. Update password";
    
    printf("%s\n", option_1);
    printf("%s\n", option_2);
    printf("%s\n", option_3);
    printf("%s\n", option_4);
    printf("%s\n\n", option_5);
}

void error_log(char *custom_error) {
    char *error = custom_error;
    printf("%s\n", error);
}

void instructive_log (char *msg) {
    printf("%s", msg);
}

int main() {
    int option_selection;
    char website_url[50];
    char raw_pass[75];
    int first_option = 1;
    int last_option = 5;
    int valid_oportunities = 2;
    int curr_arr_data_size = 0;
    struct Options {
        int add;
        int list;
        int search;
        int delete;
        int update;
    } options = {1, 2, 3, 4, 5};
    struct Pass_data {
        int id;
        char *website;
        char *password;
    };

    presentation_logs();
    options_logs();

    scanf("%d", &option_selection);
    
    if (option_selection < first_option || option_selection > last_option) {
        return 1;
    }
    
    if (option_selection == options.add) {
        struct Pass_data data[25];
        int random_number = rand() % 10000;

        instructive_log("Write website url:");
        scanf("%s", website_url);
        
        instructive_log("Write password:");
        scanf("%s", raw_pass);
        
        
        data[curr_arr_data_size].id = random_number;
        data[curr_arr_data_size].website = website_url;
        data[curr_arr_data_size].password = raw_pass;

        curr_arr_data_size += 1;

        printf("id is: %d", data[0].id);
        printf("web is: %s", data[0].website);
        printf("pass is: %s", data[0].password);
    }
    // create -> encriptar
    // create -> escribir en memoria

    // read -> se busca un valor que coincida con la web guardada
    // read -> si existe, se retorna la contraseña des-encriptada
    // read -> si no hay coincidencias, se pregunta por almacenar una nueva

    // update -> si no existe, se repite el mismo procedimiento que read (linea 1 y 3)
    // update -> si existe, se permite cambiar la contra (no se devuelve)

    // delete -> si no existe, se repite el mismo procedimiento que read (linea 1 y 3)
    // delete -> si existe, se borra y se lista el numero de registros que todavia existen
    // delete -> si ya no hay registros, exit 0

    // app -> si deja de haber input se escribe en un arhivo, los valores almacenados en memoria
    // app -> si deja de haber input se libera la memoria

    return 0;
}


