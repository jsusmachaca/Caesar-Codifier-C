#include <stdio.h>
#include <string.h>


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
     printf("Frase codificada =>\n%s\n", word_enc);
}

int main(int arg, char *args[]) {
     char word[300];
     for (int i = 1; i < arg; i++){
          if (strcmp(args[1], "-c") == 0 && arg <= 2 || strcmp(args[1], "--console") == 0 && arg <= 2){
               fgets(word, sizeof(word), stdin);
               encoder(word);
          }

          else if(strcmp(args[1], "-c") != 0 && strcmp(args[1], "--help") != 0 && strcmp(args[1], "--console") && args[1][0] != '-') {
               encoder(args[i]);
          }
          
          else if(strcmp(args[1], "--help") == 0) {
               printf("ARGS:\nCodifier <WORD>, para codificar palabra por palabra .\n\nOPTIONS:\n-c, --console\nIngresar a modo consola para dictar palabras .\n\n");
               
          }else {
               printf("Parametros incorrectos use --help para más información\n");
               break;
          }
     }
}