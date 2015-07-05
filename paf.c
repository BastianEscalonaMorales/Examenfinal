//Bastian Escalona Morales ICI 2015.
//Examen Final.
//Lenguaje de Programacion.
//Programa definido para numeros naturales entre 1-9 dentro del arreglo (Puede trabajar con 0).
#include <stdio.h>
#define N 200
int main(){

    FILE *lee; //Declaracion de variables.
    FILE *resultado;
    int i=0,j=0,k=1;
    int cont=0;
    int hola=3;
    char *p;
    int *pu;
    int *yoshi;
    char array[N];
    for (i = 0; i < N; ++i) array[i]=0; //Se recorre el arreglo.
    int minimadif=0;
    int suma1=0,suma2=0,suma3=0,suma4=0;
    int ext[N];
    for (i = 0; i < N; ++i) ext[i]=0; //Se recorre el arreglo.
    int array2[N];
    for (i = 0; i < N; ++i) array2[i]=0; //Se recorre el arreglo.
    lee=fopen("entrada.ent","r"); //Se abre el archivo donde estan nuestros numeros.
    if (lee == NULL)
        printf("Error al leer el archivo\n");
    else{
    fseek(lee,hola,0); //Lo usamos para "saltar" e ignorar la cantidad de numeros y el ENTER del archivo.
        fgets(array,N,lee);
        if(array[0] < 48 || array[0]>58){ //Abrimos el archivo y analizamos.
            hola++;
        }
        fseek(lee,hola,0);
        fgets(array,N,lee); //Abrimos el archivo y analizamos.
        if(array[0] < 48 || array[0] >58){
        hola++;
        }
        fseek(lee,hola,0); //Abrimos el archivo en la posicion donde esten nuestros numeros.
        fgets(array,N,lee);
    }
    p=&array[0];
    for(i=0; i<N;i++){
        if(48 < *p && *p < 58){ //Pasamos los caracteres del archivo (ascii) a enteros.
            array2[j]= *p -48;
            printf("%d",array2[j]); //Guardamos los numeros enteros en un arreglo. 
            j++;
        }
        *p++;
    }
    printf("\n"); //Usamos un contador para evitar iteracciones vacias.
    for (i = 0; i < N; ++i){
        if (array2[i]!=0) cont++;
        else break;
    }
    printf("La cantidad de numeros son :  %d\n",cont );
    pu=&array2[0];
    for (i = 0; i < cont; ++i){ //Hacemos una copia del arreglo entero (Para evitar problemas en las operaciones)
        ext[i]= *pu;
        pu++;
        if(*pu==0) break;
    }
    yoshi=&ext[0];
    pu=&array2[0];
    while(k<cont){
        for(i=0;i<k;i++){ //Sumamos de la posicion 0 hasta que el valor de "i" no sobrepase a "k" (Mientras "k" cambia la posicion de la suma igual lo hara)
            suma1=*(pu+i)+suma1;
        }
        for (j = i; j < cont; ++j){ //Se comenzara a sumar desde la ultima posicion que tuvo acceso "i".
            suma2=*(yoshi+j)+suma2;
        }
        if(k==1){ //Este es el primer caso cuando a la primera posicion se le resta a las demas.
            suma3=(suma1-suma2);
            if (suma3 < 0){
                suma3 = suma3 * -1; //Si el numero es negativo se multiplicara por -1 para que quede positivo.
            }
        }
        if(k>1){ //Este es el caso cuando se le suma a la primera posicion la posicion que continua y se le resta con las sobrantes.
            suma4=(suma1-suma2);
            if (suma4 < 0){
                suma4 = suma4 * -1; //Si el numero es negativo se multiplicara por -1 para que quede positivo.
            }
            if(suma4 < suma3){
                suma3=suma4;
            }
        }
        suma1=0;
        suma2=0;
        k++;
    }
    minimadif = suma3;
    printf("El minimo divisor es : %d\n",minimadif); //Se muestra en pantalla el minimo divisor.
    resultado=fopen("salida.sal","w+b"); //Abre el archivo si no existe lo crea.
    fprintf(resultado, "%d", minimadif); //Ingresa el valor de la minima diferencia al archivo creado.
    return 0;
}