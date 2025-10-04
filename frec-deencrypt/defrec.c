#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ffichnumcarac(char c, FILE * fp);
void sortFrec();
void traducir(FILE * fp);
char tradC(char c);
int esLetra(char c);
char nombre[80],c;
char alfabetoE[] = {'e','a','o','l','s','n','d','r','u','i','t','c','p','m','y','q','b','h','g','f','v','j','ñ','z','x','k','w'};
char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z'};
char traduccion[1000];
int frec[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
FILE * fp;
int contador=0;

int main()
{

printf ("¿Qué fichero deseas descifrar?");
scanf("%s",nombre);
fp=fopen(nombre,"r");
if (fp==NULL)
        {
             printf("No se puede abrir el fichero %s \n",nombre);
             return -1;
         }
else
        {   
              for (int i=0; i < 27; i++){
              fp=fopen(nombre,"r");
                frec[i]=ffichnumcarac(alfabeto[i],fp);
                fclose(fp);
              }
              fp=fopen(nombre,"r");
              sortFrec();
              traducir(fp);
              fclose(fp);
              printf("La traducción es: %s \n",traduccion);
              printf("Y las frecuencias son: %s \n",alfabeto);
              char *ans;
              char *c1;
              char *c2;
              while(*ans != 'n'){
                  printf("Cambiar:");
                 scanf("%s",c1);
                  printf("Por:");
                 scanf("%s",c2);
                 for(int i = 0; i < sizeof(traduccion);i++){
                    if(traduccion[i]== *c1){
                      traduccion[i] = '%';
                    }
                    if(traduccion[i]== *c2){
                      traduccion[i] = *c1;
                    }
                    if(traduccion[i]== '%'){
                      traduccion[i] = *c2;
                    }
                 }
                 printf("La traducción es: %s \n",traduccion);
                 printf("Y las frecuencias son: %s \n",alfabeto);
                }
        }
return 0;
}
int ffichnumcarac(char c, FILE * fp)
{
        char car;
        int cont = 0;
        car=fgetc(fp);
        while(car!=EOF){
          if(esLetra(c)){
            if(c==car){
                cont = cont + 1;
            }
          }
            car=fgetc(fp);
        }
        return cont;
}
void sortFrec(){
  int tempf = 0;
  char tempC;
  int n = 27;
  for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (frec[j] <= frec[j + 1])
                tempf = frec[i];
                frec[i] = frec[j];
                frec[j] = tempf;
                
                tempC = alfabeto[i];
                alfabeto[i] = alfabeto[j];
                alfabeto[j] = tempC;
        }
    }
}
void traducir(FILE * fp){
        char car;
        int i = 0;
        car=fgetc(fp);
        while(car!=EOF){
          if(esLetra(car)==1){
            traduccion[i] = tradC(car);
          } else {
            traduccion[i] = car;
          }
          i++;
          car=fgetc(fp);
        }
}

char tradC(char c){
  int i = 0;
  char cTrad = alfabetoE[i];
  while (c != alfabeto[i]){
    i++;
    cTrad = alfabetoE[i];
  }
  return cTrad;
}

int esLetra(char c){
  int enc = 0;
  for(int i = 0; i < 27; i++ )
  {
    if ( c == alfabetoE[i] ){
    enc = 1;
    }
  }
  return enc;
}

