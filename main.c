#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void selecionaMenu(); // protótipo da função

void menu(){
    printf("1. Adicionar uma nova tarefa\n");
    printf("2. Modificar uma tarefa\n");
    printf("3. Concluir uma tarefa\n");
    printf("4. Atualizacao do status da tarefa\n");
    printf("5. Listar tarefas pendentes\n");
    printf("6. Listar tarefas concluidas\n");
    printf("7. Listar tarefas concluidas com e sem atraso\n");
    printf("8. Sair do programa\n");
    selecionaMenu();
}


/// Inicio do bloco para receber a data do sistema
struct Data{
    int dia;
    int mes;
    int ano;
};

int recebeData(int *dia, int *mes, int *ano){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    *dia = tm.tm_mday;
    *mes = tm.tm_mon + 1;
    *ano = tm.tm_year + 1900;
    return 0;
}
/// Fim do bloco para receber data

/// Estrutura da tarefa
 typedef struct Tarefa{
    int codigoTarefa;
    char nomeTarefa;
    char nomeProjeto;
    int dataInicio_dia;
    int dataInicio_mes;
    int dataInicio_ano;
    int dataTermino_dia;
    int dataTermino_mes;
    int dataTermino_ano;
    int status;
} Tarefa;

/// Estrutura No da fila 
typedef struct No{
    Tarefa tarefa;
    struct No *prox;
} No;

/// Estrutura fila
typedef struct Fila{
    No *ini;
    No *fim;
} Fila;

/// Função cria fila
Fila *criaFila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

//função para inserir no fim da fila
No* ins_fim(No* fim, Tarefa A){
    No* p = (No*)
    malloc(sizeof(No));
    p->tarefa=A;
    p->prox = NULL;
    if(fim!= NULL) /*verifica se lista nao estiver vazia*/
    fim->prox=p;
    return p;
}

//função para modificar uma tarefa
Tarefa modificatarefa (int codigotarefa){
    int flag = 0;
    Tarefa tarefa;
    tarefa.codigoTarefa = codigotarefa;
    printf("\nDigite o nome da tarefa: ");
    scanf("%s", &tarefa.nomeTarefa);
    printf("\nDigite o nome do projeto: ");
    scanf("%s", &tarefa.nomeProjeto);
    printf("\ndigite a data de inicio: (dia/mes/ano):\n");
    do{
        printf("\nDigite o dia: ");
        scanf("%d", &tarefa.dataInicio_dia);
        }while(tarefa.dataInicio_dia > 31 || tarefa.dataInicio_dia < 1);
    do{
        printf("\nDigite o mes: ");
        scanf("%d", &tarefa.dataInicio_mes);
        }while(tarefa.dataInicio_mes > 12 || tarefa.dataInicio_mes < 1);
        printf("\nDigite o ano: ");
        scanf("%d", &tarefa.dataInicio_ano);
    printf("\nData de inicio da tarefa: %d/%d/%d", tarefa.dataInicio_dia, tarefa.dataInicio_mes, tarefa.dataInicio_ano);
    
    printf("\ndigite a data de termino: (dia/mes/ano)\n");
    do{
        printf("\nDigite o dia: ");
        scanf("%d", &tarefa.dataTermino_dia);
        }while(tarefa.dataTermino_dia > 31 || tarefa.dataTermino_dia < 1);
    do{
        printf("\nDigite o mes: ");
        scanf("%d", &tarefa.dataTermino_mes);
        }while(tarefa.dataTermino_mes > 12 || tarefa.dataTermino_mes < 1);
        printf("\nDigite o ano: ");
    scanf("%d", &tarefa.dataTermino_ano);
    printf("\nData de termino da tarefa: %d/%d/%d", tarefa.dataTermino_dia, tarefa.dataTermino_mes, tarefa.dataTermino_ano);
    
    return tarefa;
}

//função para criar uma nova tarefa
Tarefa novatarefa(){
    Tarefa tarefa;
    printf("\nDigite o codigo da tarefa: ");
    scanf("%d", &tarefa.codigoTarefa);
    printf("\nDigite o nome da tarefa: ");
    scanf("%s", &tarefa.nomeTarefa);
    printf("\nDigite o nome do projeto: ");
    scanf("%s", &tarefa.nomeProjeto);
    printf("\ndigite a data de inicio: (dia/mes/ano):\n");
    do{
        printf("\nDigite o dia: ");
        scanf("%d", &tarefa.dataInicio_dia);
        }while(tarefa.dataInicio_dia > 31 || tarefa.dataInicio_dia < 1);
    do{
        printf("\nDigite o mes: ");
        scanf("%d", &tarefa.dataInicio_mes);
        }while(tarefa.dataInicio_mes > 12 || tarefa.dataInicio_mes < 1);
        printf("\nDigite o ano: ");
        scanf("%d", &tarefa.dataInicio_ano);
    printf("\nData de inicio da tarefa: %d/%d/%d", tarefa.dataInicio_dia, tarefa.dataInicio_mes, tarefa.dataInicio_ano);
    
    printf("\ndigite a data de termino: (dia/mes/ano)\n");
    do{
        printf("\nDigite o dia: ");
        scanf("%d", &tarefa.dataTermino_dia);
        }while(tarefa.dataTermino_dia > 31 || tarefa.dataTermino_dia < 1);
    do{
        printf("\nDigite o mes: ");
        scanf("%d", &tarefa.dataTermino_mes);
        }while(tarefa.dataTermino_mes > 12 || tarefa.dataTermino_mes < 1);
        printf("\nDigite o ano: ");
    scanf("%d", &tarefa.dataTermino_ano);
    printf("\nData de termino da tarefa: %d/%d/%d", tarefa.dataTermino_dia, tarefa.dataTermino_mes, tarefa.dataTermino_ano);
    return tarefa;
};

//função para inserina uma tarefa na fila
void insereFila(Fila* fila, Tarefa tarefa){
    fila->fim=ins_fim(fila->fim,tarefa);
    if(fila->ini==NULL)/*fila antes vazia?*/
    fila->ini=fila->fim;
    printf("\n\n\ttest1\n");
    imprime(fila);
    menu();
};


/// Busca o codigo na fila
Fila *trocatarefa(Fila *fila , int codigotarefa , Tarefa tarefa){

    No *aux = fila->ini;
    while(aux != NULL){
        if(aux->tarefa.codigoTarefa == codigotarefa){
            printf("Tarefa encontrada\n");

            aux->tarefa = tarefa;
            return fila;
            menu();
        }
        aux = aux->prox;
    }
    
    printf("Tarefa nao encontrada\n");
    menu();
}

/// Imprime a fila inteira
void imprimeFila(Fila *fila){
    No *aux = fila->ini;
    printf("verificando funcao");
    while(aux != NULL){
        printf("Codigo da tarefa: %d\n", aux->tarefa.codigoTarefa);
        printf("Nome da tarefa: %s\n", aux->tarefa.nomeTarefa);
        printf("Nome do projeto: %s\n", aux->tarefa.nomeProjeto);
        printf("Data de inicio da tarefa: %2d/%2d/%2d\n", aux->tarefa.dataInicio_dia, aux->tarefa.dataInicio_mes, aux->tarefa.dataInicio_ano);
        printf("Data de termino da tarefa: %2d/%2d/%2d\n", aux->tarefa.dataTermino_dia, aux->tarefa.dataTermino_mes, aux->tarefa.dataTermino_ano);
        printf("Status da tarefa: %d\n", aux->tarefa.status);
        printf("\n");
        aux = aux->prox;
    }
}

void selecionaMenu(){
    Fila *fila = criaFila();
    int opcao = 0;
    scanf("%d", &opcao);
    system("cls");
    Tarefa tarefa;
    int codigo;
    switch(opcao){
        case 1:
        /// Cria uma nova tarefa e insere na fila
            printf("\nAdicionar uma nova tarefa\n");
            tarefa = novatarefa();
            insereFila(fila , tarefa);
            printf("\n\t\tteste2\n");
            imprime(fila);
            break;
        case 2:
        /* programa pergunta o código da tarefa que deseja altera; cria uma nova tarefa com o mesmo código 
        porem dando ao usuario a oportunidade de trocar todos os dados da tarefa; depois o programa chama uma 
        função a qual pega a nova tarefa criada e seu código com isso ela procura na fila o código e caso ache 
        ele coloca a nova tarefa na posição da com o mesmo código */
            printf("Modificar uma tarefa\nDigite o codigo da tarefa: ");
            scanf("%d", &codigo);
            tarefa = modificatarefa(codigo);
            trocatarefa( fila, codigo , tarefa);
            break;
        case 3:
            /// printf("Concluir uma tarefa\n");
            printf("imprime fila\n");
            imprimeFila(fila);
            break;
        case 4:
            printf("Atualizacao do status da tarefa\n");
            break;
        case 5:
            printf("Listar tarefas pendentes\n");
            break;
        case 6:
            printf("Listar tarefas concluidas\n");
            break;
        case 7:
            printf("Listar tarefas concluidas com e sem atraso\n");
            break;
        case 8:
            printf("Sair do programa\n");
            break;
        default:
            printf("Opcao invalida\n");
            selecionaMenu();
            break;
    }
}

int main(){

   
    system("cls");
    menu();

    /// Recebe data atual
    /*int dd, mm, aa;
    recebeData(&dd, &mm, &aa);
    printf("Data: %d/%d/%d\n", dd, mm, aa);*/
    


    return 0;
}