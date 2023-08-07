#include <stdio.h>
#include <string.h>

void decoder(char word[]) {
     char abc[] = "nopqrstuvwxyzabcdefghijklm"; 
     char denc[] = "abcdefghijklmnopqrstuvwxyz"; // cva cba
     char word_denc[strlen(word)];

     for (int f = 0; f < strlen(word); f ++ ){
          if (word[f] == ' ' || word[f] == '\n'){
               word_denc[f] = ' ';
          }
          else {
               char lett = word[f];
               for(int i= 0; i < strlen(abc); i++){
                    if(lett == abc[i]){
                         word_denc[f] = denc[i];
                         break;
                    }
               }
          }
     }    
     word_denc[strlen(word)] = '\0';
     printf("Frase decodificada => %s\n", word_denc);
}

char encoder(char word[]) {
     char abc[] = "abcdefghijklmnopqrstuvwxyz"; // cva cba
     char enc[] = "nopqrstuvwxyzabcdefghijklm"; 
     char word_enc[strlen(word)];

     for (int f = 0; f < strlen(word); f ++ ){
          if (word[f] == ' ' || word[f] == '\n'){
               word_enc[f] = ' ';
          }
          if (word[f] == '.'){
               word_enc[f] = '.';
          }
          if (word[f] == ','){
               word_enc[f] = ',';
          }
          else {
               char lett = word[f];
               for(int i= 0; i < strlen(abc); i++){
                    if(lett == abc[i]){
                         word_enc[f] = enc[i];
                         break; 
                    }
               }
          }
     }    
     word_enc[strlen(word)] = '\0';
     printf("Frase codificada => %s\n", word_enc);
}

int main() {
     char frase[300];
     char req;
     printf("¿Qué deseas hacer?\nCodificar [e] Decodificar [d]\n");
     scanf("%c", &req);
     getchar();
     if (req == 'e') {
          printf("Ingresa una frase: \n");
          fgets(frase, sizeof(frase), stdin);
          encoder(frase);
     }
     else if (req == 'd') {
          printf("Ingresa una frase: \n");
          fgets(frase, sizeof(frase), stdin);
          decoder(frase);
     }
     else {
          printf("Por favor ingrese la opción correcta\n");
     }
}