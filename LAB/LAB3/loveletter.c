#include <stdio.h>
#include <ctype.h>

int main() {
    char coded[102];
    char decode[102];
    char check;
    int i , j = 0;

    scanf("%[^\n]s" , coded);
    
    for (i = 0 ; (coded[i] != '\0'); i++ ) {
        if ((coded[i] == 'a' || coded[i] == 'e' || coded[i] == 'i' || coded[i] == 'o' || coded[i] == 'u')  ){
            check = coded[i];
            if (coded[i+1] == 'p' && coded[i+2] == check) {
               
                    decode[j++] = check;
                    i+=2;

                 
                
            } else {
                decode[j++] = coded[i];


            }
        } else {
                    decode[j++] = coded[i];


        }


        }
    
    decode[j] = '\0';

    printf("%s", decode);
}


//pepen phupuepeapan kapan lapaepe dipilapaepeopo