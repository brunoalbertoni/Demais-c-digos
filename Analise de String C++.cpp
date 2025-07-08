#include <iostream>    
#include <cctype>
#include <stdio.h.>    

using namespace std;

int main() {
    string texto = "Hello World!";
    int vog=0,cons=0,num=0,spc=0;
    for (char x:texto) {
        if (isalpha(x)) {
            char lower=tolower(x);
            if (lower=='a'||lower=='e'||lower=='i'||lower=='o'||lower=='u') {
                vog++;
            } else {
                cons++;
            }
        } else if(isdigit(x)) {
            num++;
        } else if(isspace(x)) {
            spc++;
        }
    }
    printf("Texto analisado:\n");
    printf("Quantidade de vogais: %d\n",vog);
    printf("Quantidade de consoantes: %d\n",cons);
    printf("Quantidade de digitos: %d\n",num);
    printf("Quantidade de espacos em branco: %d\n",spc);

    return 0;
}
