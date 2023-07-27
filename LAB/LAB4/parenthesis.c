#include <stdio.h>

int main() {
    char input[2000];
    int count = 0 , i, check = 0;
    
    scanf("%s" , input);

    for (i = 0 ; input[i] != '\0'; i++) {
        if (input[0] == ')' ) {
            check = 1;
            break;
        }
        if (input[i] == '(') {
            count++;
        

        } else if (input[i] == ')') {
            count--;

        }

    }

    if (count != 0 ) {
        check = 1;
    }

    if (check == 0) {
        printf("YES");
    } else {
        printf("NO");
    }

}