/* bibliotecas */
#include <stdio.h>

/* constantes */
#define QTDDADOS 25

/* funcoes */
void corrigirSalario(float salario, float taxaTR, float taxaSELIC, float *total){

    float salarioDobrado, TR, SELIC, salarioCorrigido;

    salarioDobrado = salario * 2; // 1- dobrar salario
    TR = salarioDobrado * taxaTR / 100; // 2- calcular taxa TR
    SELIC = salarioDobrado * taxaSELIC / 100; // 3- calcular taxa SELIC
    salarioCorrigido = salarioDobrado + TR + SELIC; // 4- fazer correcao do salario
	*total += salarioCorrigido; // calculo do total devido

    printf("\t\tR$%.2f\t\t%.4f\t\t%.2f\t\tR$%.2f\tR$%.2f\t\tR$%.2f\t\t\tR$%.2f\n",salario,taxaTR,taxaSELIC,salarioDobrado,TR,SELIC,salarioCorrigido);
}   


/* corpo do programa */
int main(void){

    // definir variaveis locais
    char datas[QTDDADOS][7] = {
        {"out/22"}, {"nov/22"}, {"dez/22"}, {"jan/23"}, {"fev/23"},
        {"mar/23"}, {"abr/23"}, {"mai/23"}, {"jun/23"}, {"jul/23"},
        {"ago/23"}, {"set/23"}, {"out/23"}, {"nov/23"}, {"dez/23"},
        {"jan/24"}, {"fev/24"}, {"mar/24"}, {"abr/24"}, {"mai/24"},
        {"jun/24"}, {"jul/24"}, {"ago/24"}, {"set/24"}, {"out/24"}
    };

    float dados[QTDDADOS][2] = { 
        {0.1494, 1.02}, {0.1507, 1.02}, {0.2072, 1.12}, {0.2081, 1.12}, {0.0830, 0.92},
        {0.2392, 1.17}, {0.0821, 0.92}, {0.2147, 1.12}, {0.1799, 1.07}, {0.1581, 1.07},
        {0.2160, 1.14}, {0.1130, 0.97}, {0.1056, 1.00}, {0.0775, 0.92}, {0.0690, 0.89},
        {0.0875, 0.97}, {0.0079, 0.80}, {0.0331, 0.83}, {0.1023, 0.89}, {0.0870, 0.83},
        {0.0365, 0.79}, {0.0739, 0.91}, {0.0707, 0.87}, {0.0675, 0.84}, {0.0977, 0.93}
    };
    
    float salario = 1839.03;
    float total = 0;
    int i;

	// mostrar dados de cada periodo
    printf("Periodo\t\tSalario Original\tTaxa TR\t\tTaxa SELIC\tSalario Dobrado\tCorrecao TR\tCorrecao Selic\tSalario Corrigido\n");
    for (i = 0; i < QTDDADOS; i++){
        printf("%s",datas[i]);
        corrigirSalario(salario,dados[i][0],dados[i][1], &total);
    }

	
	// mostrar total devido
    printf("\nTOTAL DEVIDO: R$%.2f\n",total);

    return 0;   
}
