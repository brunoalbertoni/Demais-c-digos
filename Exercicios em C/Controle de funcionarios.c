#include <stdio.h>
#include <string.h> //utilizaremos para comparar os CPF's
 typedef struct{
    char nome[30], sexo,cpf[20];
    int idade;
    float salario;
 }t_dados_funcionarios; //criando um novo tipo de dado "t_dados_funcionarios"

 void main(){
    int escolha,indice=0; //variavel indice para controlar os novos cadastros de funcionarios
    char cpf_t[20];
    t_dados_funcionarios funcionarios[100];
    do{
        fflush(stdin);
        printf("\n[1] Cadastrar novo funcionario\n[2] Buscar funcionario pelo CPF\n[3] Lista com todos os funcionarios com salario maior que a media\n[0] Encerrar programa.\n");
        scanf("%d",&escolha);   //criação do menu
        switch (escolha){
        case 1:
            if (indice==100){ //caso o limite de funcionarios ja tenha sido atingido, nao sera mais possivel cadastra-los
                printf("Nao eh possivel cadastrar mais funcionarios, limite atingido!");
                break;
            }
            fflush(stdin);
            printf("Digite o nome do funcionario: ");
            fgets(funcionarios[indice].nome, sizeof(funcionarios[indice].nome), stdin);
            fflush(stdin);
            printf("Digite o cpf do funcionario: ");
            fgets(funcionarios[indice].cpf, sizeof(funcionarios[indice].cpf), stdin);
            fflush(stdin);
            printf("Digite a idade do funcionario: ");
            scanf("%d",&funcionarios[indice].idade);
            fflush(stdin);
            printf("Digite o sexo do funcionario(M/F): ");
            fflush(stdin);
            scanf("%c",&funcionarios[indice].sexo);
            fflush(stdin);
            printf("Digite o salario: ");
            scanf("%f",&funcionarios[indice].salario);
            fflush(stdin);
            indice++; //proximo funcionario cadastrado sera no proximo indice
            break;
        case 2:
            fflush(stdin);
            printf("Digite o cpf para a procura: ");
            fgets(cpf_t, sizeof(cpf_t), stdin);
            
            for (int i=0;i<indice;i++){
                if (strcmp(cpf_t,funcionarios[i].cpf)==0){ //usa o strcmp para comparar as strings de CPF, caso sejam iguais, continuara o codigo
                    printf("\nFuncionario encontrado!");
                    printf("\nNome: %s",funcionarios[i].nome);
                    printf("CPF: %s",funcionarios[i].cpf);
                    printf("Idade: %d",funcionarios[i].idade);
                    printf("\nSexo: %c",funcionarios[i].sexo);
                    printf("\nSalario: %.2f",funcionarios[i].salario);
                    break;
                }
                  else if (i==indice-1) printf("Nao foi possivel achar esse cpf.");
            }
            break;
        case 3:
            fflush(stdin);
            float media_s=0;
            for (int i=0;i<indice;i++)
                media_s=media_s + funcionarios[i].salario; //soma dos salarios
            media_s=media_s/indice; //media
            printf("\nFuncionarios com salario maior que a media salarial: ");
            for (int i=0;i<indice;i++){
                if (funcionarios[i].salario>media_s){
                    printf("\n__________________________________");
                    printf("\nNome: %s",funcionarios[i].nome);
                    printf("CPF: %s",funcionarios[i].cpf);
                    printf("Idade: %d",funcionarios[i].idade);
                    printf("\nSexo: %c",funcionarios[i].sexo);
                    printf("\nSalario: %.2f",funcionarios[i].salario);
                }
                }
                break;     
        case 0: break;
        default: 
            printf("Digite um numero valido!\n");
            system("pause"); 
            system("cls");
            break;
        }
    }while (escolha!=0);
 }
