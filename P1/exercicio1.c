//Bruno Henrique RA:1988433
//Gabriel Ribeiro RA:1990750
//Felipe Sizilio RA:1990260

#include <stdio.h>

void maior(float a, float b, float c){
    float maior=a; //atribui a variavel maior ao valor de "a" inicialmente e compara com os outros valores
    if (b>maior)
        maior=b;
    if (c>maior)
        maior=c;
    printf("O maior numero eh %.1f",maior);
}

void elevado(float a, int b){
    float result=1;
    if (b<0){  //ve se "b" é menor que zero, caso seja, nao sera continuada a funcao
        printf("Nao foi possivel realizar a operacao pois 'b' eh negativo");
        return;
    }
    for (int i=0;i<b;i++)
        result=result*a; //resultado recebe 1 caso "b" seja zero, caso contrario ele recebe ele mesmo multiplicado por "a" uma qntd "b"+1 de vezes
    printf("%.1f",result);
}

void funcao(float x){
    float result;
    result=(x*x)-3+(x/2);
    printf("%.1f",result);
}

void tabuada(float n){

    for (int i=1;i<=10;i++) // printa todos os valores de n multiplicados de 1 a 10
        printf("%.1f x %d = %.1f\n",n,i,n*i);
}

void matriz(int m[4][5]){
    int qntd=0;
    for (int i=0;i<4;i++){ //linhas
        for (int j=0;j<5;j++){  //colunas
            if (m[i][j]%2==0) //compara todos os valores da matriz e ve se eles sao pares
                qntd+=1;
        }
    }
    printf("%d",qntd);
}

void main(){
    int m[4][5],escolha,b2;
    float a,b,c,a2,x,tab;
  

    do{
        fflush(stdin);
        printf("\n[1] Receber 3 valores e retornar o maior\n[2] Calcular a^b\n[3] Retornar o valor da funcao f(x)=x^2-3+x/2\n[4] Informar a tabuada de um numero\n[5] Receber uma matriz 4x5 e retornar quantos numeros pares tem\n[0] Encerrar programa.\n");
        scanf("%d",&escolha);
        switch (escolha){
        case 1:
            printf("Digite os 3 valores: ");
            scanf("%f%f%f",&a,&b,&c);
            maior(a,b,c);
            break;
        case 2:
            printf("Digite o valor de a e b: ");
            scanf("%f%d",&a2,&b2);
            elevado(a2,b2);;
            break;
        case 3:
            printf("Digite o valor de x: ");
            scanf("%f",&x);
            funcao(x);
            break;
        case 4:
            printf("Digite um numero: ");
            scanf("%f",&tab);
            tabuada(tab);
            break;
        case 5:
            for (int i=0;i<4;i++){
                for (int j=0;j<5;j++){
                    printf("Digite o numero da linha %d e coluna %d",i+1,j+1);
                    scanf("%d",&m[i][j]);}}
            matriz(m);
            
        case 0: break;
        default: 
            printf("Digite um numero valido!\n");
            system("pause"); 
            system("cls");
            break;
        }
    }while (escolha!=0);
}