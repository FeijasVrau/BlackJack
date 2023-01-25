#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>                //Usaso para Srand ((unsigned) time(NULL)) 
#include <process.h>             //Usado para o comando 'cls'
#include <locale.h>				 //PTBR
#include <string.h>
#include "conio.h"

#define espada 06                 //Simbolo de espada
#define paus 05                  //Simbolo de paus 
#define ouros 04               //Simbolo de ouro
#define copas 03                 //Simbolo de copas
#define Jogador "Jogador.dat"		   //nome do arquivo



typedef struct ca{
	char nome[70];
	int rendimento;
	int codigo;
	
}Cassino;

typedef struct player{
	char nome[70];
	int codigo;
	int dinheiro; 
	
}Player;	

typedef struct item{
    int codigoItem;
	char item_nome[79];
    Player player;
}Item;												

//vari�veis globais
int k;
int l;
int d;
int aposta; //aposta
int carta_aleatoria; //carta aleat�ria
int Jogador_total=0; //total do jogador
int dealer_total; 
int dinheiroc=500;
int b=1;
int c=1;

//Fun��es
int cartaPaus();      //Mostra a imagem da carta de paus 
int cartaOuros();   //Mostra a imagem da carta de ouros
int cartaCopas();     //Mostra a imagem da carta de copas 
int cartaEspada();     //Mostra a imgem da carta de espada
int randcarta();      //Gera cartas aleat�rias 
int apostas();       //Pergunta a quantidade da aposta
void menu();     //Vai ao menu do jogo
void regras();        //Mostra as regras do 21 (Blackjack)
void jogar();         //Starta o jogo l.680
void dealer();       //Fun��o para o dealer 
void parar();         //Fun��o caso o jogador queira Parar
void Tdinheiro();    //Verifica se o jogador ainda t�m dinheiro
void PerguntarN();      //Pergunta se o jogador deseja continuar jogando
void criarJogador();		  //criar player
Player salvar_dinheiro(Player player);       //Salva o dinheiro do player 
void salvar_dinheiro_cass();  //Salva e calcula o rendimento do cassino
void escolher_jogador();      //Lista de jogadores existentes
void cassinos();  			  //cassinos
void inventario(Player player, Cassino cassino); //lojinha hype
Player Agiotagem (Player player);
void criacao_itens(Item item);


//Fun��o principal
int main(void){
	
	
	
	
	setlocale(LC_ALL,"Portuguese");
	
	Player player;
	Cassino cassino;
    int opcao1;
    textcolor(4);
    printf("\n                                                       "); 
    printf("\n              222          111                   ");
    printf("\n            222 222      11111      %c %c   %c %c", copas,copas,copas,copas);
    printf("\n           222   222    11 111    %c %c %c %c %c %c %c ",copas,copas,copas,copas,copas,copas,copas); 
    printf("\n                222        111   %c %c %c %c %c %c %c %c",copas,copas,copas,copas,copas,copas,copas,copas);
    printf("\n               222         111    %c %c %c %c %c %c %c",copas,copas,copas,copas,copas,copas);  
    printf("\n             222           111     %c %c %c %c %c %c ",copas,copas,copas,copas,copas);
    printf("\n            222            111       %c %c %c %c     ",copas,copas,copas,copas);
    printf("\n          222              111         %c %c          ",copas,copas);
    printf("\n          222222222        111                     ");
    textcolor(15);
    printf("\n                                                         ");
    printf("\n                                                         ");
    printf("\n                                                         "); 
    printf("\n  ==================================\n");

    cassinos(&cassino); 
    
    printf("\n");
    
    menu(&player, &cassino);
    
    printf("\n");
    printf("\n");
    
    system("pause");
    return(0);
} //Fim

void inventario(Player player, Cassino cassino){ //Fun��o para mostrar itens do jogador
	 Item item;
	 char opcao3;
    
    int carregarCodigo,i=0;
        FILE *itensAgiota=NULL;
    itensAgiota=fopen("item.dat", "rb");
    system("cls");
    printf("\t\tINVENTARIO DE:\n");
    printf("\t\t%s\n",player.nome); 
    printf("======================================================================\n\n");
    while(fread(&item, sizeof(Item),1,itensAgiota)!=0){
        if(strcmp(item.player.nome,player.nome)==0){
        	printf("%d - %s\n", item.codigoItem, item.item_nome); 
        }
    }
    fclose(itensAgiota);
    
    
    printf("\nVoc� deseja ir para a tela anterior do programa?");
     printf("\n                  (S/N)\n                    ");
    scanf(" %c",&opcao3);
     getchar();

	if((opcao3 == 'S') || (opcao3 == 's')) // Se sim, volta ao menu
	{ 
            system("cls");
            menu(&player, &cassino);
            
	} // Fim do loop

	else if((opcao3 == 'N') || (opcao3 == 'n')) //Volta ao menu
	{
		system("cls");
        menu(&player, &cassino);
    }  
}


Player Agiotagem (Player player){ //Fun��o para listar itens
	int opcao=0;
	char resposta;
	Item item;
	
	
	printf("\nQual desses itens voc� deseja fazer aquisi��o:\n");
	printf("SUA GRANA: %d",player.dinheiro);
	
	printf("\n1 - MEIAS DA SORTE - K$5 KWANZAS");
	
	printf("\n2 - UNO DA FIRMA COM ESCADA EM CIMA E LOGO DA CLARO - K$40.000 KWANZAS");
	
	printf("\n3 - MICO LE�O DOURADO COM AUTORIZA��O DO IBAMA, 100% ORIGINAL (CONFIA) - K$50.000 KWANZAS");
	
	printf("\n4 - MICROFONE ROSA DIFERENCIADO (OBS:N�O FUNCIONA COMO DEVERIA) - K$50 KWANZAS");
	
	printf("\n5 - BOLA ASSINADA POR NADA MAIS NADA MENOS QUE PEL�, O REI DO FUTEBOL- K$1.000.000.000 KWANZAS");
	
	printf("\n OS ITENS PODEM SER ADIQUIRIDOS MAIS FACILMENTE COM OS DESENVOLVEDORES");
	printf("\n");
	scanf("%d", &opcao);
	getchar();
	system("cls");
	
	switch (opcao){
		case 1:
			printf("======ETROS AD SAIEM SA AJESED EUQ AZETREC MET======?\n");
			printf("S OU N\n");
			scanf("%c", &resposta);
			
			if(resposta== 'n' || resposta=='N'){
			system("cls");
			}else
			if (resposta=='S' || resposta=='s'){
			 	player.dinheiro-=5;							
			 	player=salvar_dinheiro(player);
				item.player=player;
	            strcpy(item.item_nome, "MEIAS DA SORTE");
	            system("cls");
				criacao_itens(item);		 	
			}
			break;
			
			
			case 2:
			printf("DESESA ADQUIRIR O UNO DA FIRMA COM ESCADA EM CIMA E LOGO DA CLARO?\n");
			printf("S OU N\n");
			scanf("%c", &resposta);
			if(resposta== 'n' || resposta=='N'){
			system("cls");
			}else
			if (resposta=='S' || resposta=='s'){
				player.dinheiro-=40000;						
			 	player=salvar_dinheiro(player);
				item.player=player;
				strcpy(item.item_nome, "UNO DA FIRMA COM ESCADA EM CIMA E LOGO DA CLARO");
				system("cls");
				criacao_itens(item);
			}
			break;
			
			
			case 3:
			printf("DESEJA ADQUIRIR O INCR�VEL MICO LE�O DOURADO COM AUTORIZA��O DO IBAMA, 100% ORIGINAL (CONFIA)?\n");
			printf("S OU N\n");
			scanf("%c", &resposta);
			if(resposta== 'n' || resposta=='N'){
			system("cls");
			}else
			if (resposta=='S' || resposta=='s'){
				player.dinheiro-=50000;							
				player=salvar_dinheiro(player);
				item.player=player;
				strcpy(item.item_nome, "O INCR�VEL MICO LE�O DOURADO COM AUTORIZA��O DO IBAMA, 100% ORIGINAL (CONFIA)");
				system("cls");
				criacao_itens(item);
			}
			break;
			
			
			case 4:
			printf("DESEJA ADQUIRIR O MICROFONE ROSA DIFERENCIADO (OBS:N�O FUNCIONA COMO DEVERIA) >///< ?\n");
			printf("S OU N\n");
			scanf("%c", &resposta);
			if(resposta== 'n' || resposta=='N'){
			system("cls");
			}else
			if (resposta=='S' || resposta=='s'){
				player.dinheiro-=50;						
			 	player=salvar_dinheiro(player);
				item.player=player;
				strcpy(item.item_nome, "MICROFONE ROSA DIFERENCIADO (OBS:N�O FUNCIONA COMO DEVERIA) >///<");
				system("cls");
				criacao_itens(item);
			}
			break;	
			case 5:
			printf("DESEJA ADQUIRIR BOLA PELADA POR NADA MAIS NADA MENOS QUE BOL�, O REI DO FUTEBOL?\n");
			printf("S OU N\n");
			scanf("%c", &resposta);
			if(resposta== 'n' || resposta=='N'){
			system("cls");
			}else
			if (resposta=='S' || resposta=='s'){
				player.dinheiro-=1000000000;							
			 	player=salvar_dinheiro(player);
				item.player=player;
				strcpy(item.item_nome, "BOLA PELADA POR NADA MAIS NADA MENOS QUE BOL�, O REI DO FUTEBOL");
				system("cls");
				criacao_itens(item);
			}
			break;	
	}
	return player;
}

void criacao_itens(Item item){ //Fun��o para salvar os itens
    Item item_auxiliar;
    item.codigoItem=1;

    FILE *itensAgiota=NULL;

    itensAgiota=fopen("item.dat", "ab+");

    while(fread(&item_auxiliar, sizeof(Item), 1, itensAgiota)!=0){
        item.codigoItem++;
    }



    fwrite(&item,sizeof(Item),1,itensAgiota);

    fclose(itensAgiota);
}

Player salvar_dinheiro(Player player) //Fun��o para salvar dinheiro do player
{	
int carregarCodigo,i=0;
      FILE *jogador;

    jogador=fopen("jogador.dat", "rb+");

    fseek(jogador,(player.codigo-1)*sizeof(Player),SEEK_SET);
    fwrite(&player, sizeof(Player), 1, jogador);

    fclose(jogador);
    printf("%d",player.dinheiro);

    return player;
}

void escolher_jogador(Player *player, Cassino *cassino) //Void para escolher jogador
{	
	int n, cont=0;
	char opcao4;
	FILE *jogador; 
	
	
    jogador = fopen("jogador.dat", "ab+"); 
    if(jogador == NULL) // Caso n�o tenha arquivo
    {
    printf("\nErro: Sem arquivos\n");
    system("pause");
    exit(1);
    }
    else
    {     
		while(fread(player,sizeof(struct player),1,jogador)!=0)
		{
			printf("\n nome: %s", player->nome);	
			printf("\n codigo: %d", player->codigo);
			printf("\n=============================");
		}    
		printf("\n qual o numero do jogador  ?");
		scanf("%d",&n);
		system("cls");
		
		
		fseek(jogador,0,SEEK_SET);
		while(fread(player,sizeof(struct player),1,jogador)!=0 && (cont<n-1))
		{	
			cont++;			
		
		}
		
    }
    fclose(jogador);
	 
            system("cls");
            menu(player, cassino);
            
 // Fim do loop
	}
void criarJogador(Cassino cassino) // cria um novo jogador
{
	
	
    Player player, player_auxiliar;
    player.codigo=1;
    //player.nome;
    player.dinheiro= 500;
    //player.inventario; 
    //fseek(fprintf("%f"*&dinheiro->*player+100"player =jogador");// FUNCIONA ? ?)
    
    
    
    int opcao2;
    char opcao1;

    do{
        printf("\nDigite seu nome:");
        scanf("%[^\n]c",&player.nome);
        getchar();
        fflush(stdin);
        if(player.nome[0]=='\0'){
            printf("\nNome de jogador inv�lido.");
        }
    }while(player.nome[0]=='\0');
	
    FILE *jogador=NULL;

    jogador=fopen("jogador.dat", "ab+");

    while(fread(&player_auxiliar, sizeof(Player), 1, jogador)!=0){
        player.codigo++;
    }

    fwrite(&player,sizeof(Player),1,jogador);
    fclose(jogador);
    
    printf("\nVoc� deseja ir ao menu do programa?");
     printf("\n                  (S/N)\n                    ");
     scanf("\n%c",&opcao1);
     
     while((opcao1!='S') && (opcao1!='s') && (opcao1!='N') && (opcao1!='n')) // Caso haja entrada invalida
	{                                                                           
		printf("\n");
		printf("Escolha inv�lida. Por favor digite S para sim e N para n�o.\n");
		scanf("%c",&opcao1);
	}


	if((opcao1 == 'S') || (opcao1 == 's')) // Se sim, vai ao menu
	{ 
            system("cls");
            menu(player, cassino);
	} // Fim do loop
}
void salvar_dinheiro_cass(Cassino cassino) //Salva o dinheiro do cassino
{	
	FILE *ca; 
    ca = fopen("cassino.dat", "ab+"); 
    if(ca == NULL) // Caso n�o tenha arquivo
    {
    printf("\nErro: Sem arquivos\n");
    system("pause");
    exit(1);
    }
    else
    {     
		fseek(ca,c*sizeof(struct ca),SEEK_SET);
		fread(&cassino,sizeof(struct ca),1,ca);
		fwrite(&cassino,sizeof(struct ca),1,ca);
	c++;
    } 
    
    fclose(ca);
    
    return;
}
void cassinos(Cassino *cassino) //Cria e pergunta por qual cassino voc� quer jogar
{
	int nome;
	Cassino cassino_auxiliar;
	cassino->codigo=2;
	cassino->nome;
	cassino->rendimento=1;

	do{																					//Op��es de cassinos
        printf("\n Escreva por qual cassino voc� quer jogar:?");                        
        printf("\n 1-para Cassino Brasil:");
        printf("\n 2-Cassino Las Vegas: \n ");       scanf("%d",&nome);
        getchar();
        fflush(stdin);																	
        if((nome!=0)&&(nome >2)){
            printf("\nCassino inv�lido.");
        }
    }	while((nome == 0)&&(nome<3));
    
    if(nome == 1 ){
    	strcpy(cassino->nome,"Cassino Brasil");
    	system("cls");
                   
	}
 	 if(nome == 2 ){
    	strcpy(cassino->nome,"Cassino Las Vegas");
    	system("cls");
                   
 	}
	
    FILE *ca=NULL;

    ca=fopen("cassino.dat", "ab+");

    while(fread(&cassino_auxiliar, sizeof(Cassino), 1, ca)!=0){
        cassino->codigo++;
    	cassino->nome;
    }
    fwrite(&cassino,sizeof(Cassino),1,ca);
    fclose(ca);
    return;
}
void menu(Player *player, Cassino *cassino) //Pergunta ao jogador se deseja come�ar/continuar o jogo ou n�o
{ 
    int opcao2;
    
		    printf("\nAperte 1 para jogar.");
		    printf("\nAperte 2 para ver a lista de regras.");
		    printf("\nAperte 3 para criar jogador.");
		    printf("\nAperte 4 para escolher um jogador.");
		    printf("\nAperte 5 para acessar a loja de itens UwU.");
		    printf("\nAperte 6 para mostrar seus itens.");
		    printf("\nAperte 7 para sair e mostrar resultados.");
		    
		    printf("\nEscolha: ");
		    scanf("%d", &opcao2); //L� a escolha do jogador
		    getchar();
		    
		    if((opcao2<1) || (opcao2>7)) //Caso haja entrada inv�lida
		    {
                printf("\nEscolha inv�lida por favor escolha entre 1, 2 ou 3\n");
                scanf("%d", &opcao2);
            }
            switch(opcao2) // Switch case caso haja escolhas diferentes 
            {   
                case 1: // case jogar
                   system("cls");
                   
                   jogar(player, cassino);//variavel que vai dar inicio
                                      
                   break;
                   
                case 2: // case para a lista de regras
                   system("cls");
        
                   regras(player, cassino);
                                      
                   break;
                   
               case 3: // Cadastro
               		system("cls");
                    printf("\nPara come�ar o jogo por favor se cadastre");
   				    criarJogador(*cassino);
                   
                   exit(0);
                   
                   case 4: // case escolher jogador
                   system("cls");
                   escolher_jogador(player, cassino);              
                   break;  
                   
                   case 5: // loja de itens
                   system("cls");
                   
                   *player=Agiotagem(*player); 
                   menu(player, cassino);
                   break;  
                   
                   case 6: // inventario
                   system("cls");
                   
                   inventario(*player, *cassino);
                   getchar();
                                      
                   break;
                   
                case 7: // sair e resultados
                   system("cls");
                   printf("\nQue pena que saiu do jogo.");
                   printf("\nAt� mais!\n\n");
                   printf("dinheiro atual do %s: $%d ", &player->nome, player->dinheiro);
                   printf("\nrendimento do cassino atual: %d  ",cassino->rendimento);
                   *player=salvar_dinheiro(*player);
                   system("pause");
                    getchar();
                    exit(0);
                    break;
                } //Encerra o switch case	
	return;

} //Fim da fun��o menu
void regras(Player player, Cassino cassino) //Printa as regras do jogo
{
     char opcao3;
     
    printf("\n           Regras do Blackjack ou 21");
     printf("\n          ---------------------------");
     printf("\nI.");
     printf("\n     As probabilidades desse jogo s�o totalmente confi�veis.");
     printf("\n      %c As cartas do jogo s�o geradas aleatoriamente.", espada);
     printf("\n      %c Se vo�� continua perdendo a culpa � apenas sua !\n", ouros);
     
     printf("\nII.");
     printf("\n     Cada carta tem um valor.");
     printf("\n      %c As cartas tem um valor de 1 a 10 cada uma com uma numera�ao.", espada);
     printf("\n      %c Cartas J, Q, e K possuem o valor de 10.", ouros);
     printf("\n      %c As cartas �s possuem o valor de 11", paus);
     printf("\n     O objetivo do jogo � alcan�ar o valor de 21 (como o nome sugere).\n");
     
     printf("\nIII.");
     printf("\n     Ap�s receber as duas primeiras cartas, voc� deve escolher entre receber outra carta ou passar a vez.");
     printf("\n      %c Passando a vez, voc� fica com suas cartas atuais. Ao receber outra carta, voc� recebe outra carta.", espada);
     printf("\n     Como voc� est� jogando contra o dealer, voc� precisa ter uma m�o melhor que a dele.");
     printf("\n     MAS CUIDADO!.");
     printf("\n      %c Se sua m�o passar de 21, voc� perde!.", ouros);
     printf("\n     Mas a esperan�a n�o se esvaiu, voc� sempre pode jogar novamente!!!!\n");
     printf("\n%c%c%c SEUS RESULTADOS EST�O SENDO SALVOS NA MESMA PASTA EM QUE SE ENCONTRA O PROGRAMA %c%c%c\n", espada, copas, paus, paus, copas, espada);
     printf("\nVoc� deseja ir para a tela anterior do programa?");
     printf("\n                  (S/N)\n                    ");
     scanf(" %c",&opcao3);
     getchar();

	if((opcao3 == 'S') || (opcao3 == 's')) // Se sim, volta ao menu
	{ 
            system("cls");
            menu(&player, &cassino);
            
	} // Fim do loop

	else if((opcao3 == 'N') || (opcao3 == 'n')) //Volta ao menu
	{
		system("cls");
        menu(&player, &cassino);
    }
	
	return;
} //Fim da fun��o
int cartaPaus() //Mostra a carta de paus
{
    
    
    srand((unsigned) time(NULL)); //Gera uma seed aleat�ria para a fun��o rand() 
    k=rand()%13+1;
    
    if(k<=9) //Se o n�mero aleat�rio for menor que 9, printa o valor de k atual
    {
    //Carta de paus
    printf("-------\n");
    printf("|%c    |\n", paus);
    printf("|  %d  |\n", k);
    printf("|    %c|\n", paus);
    printf("-------\n");
    }
    
    
    if(k==10) //Se o n�mero aleat�rio for 10, printa a carta rei J
    {
    //Carta de paus
    printf("-------\n");
    printf("|%c    |\n", paus);
    printf("|  J  |\n");
    printf("|    %c|\n", paus);
    printf("-------\n");
    }
    
    
    if(k==11) //Se o n�mero aleat�rio for 11, printa a carta de �s
    {
    //Carta de paus
    printf("-------\n");
    printf("|%c    |\n", paus);
    printf("|  A  |\n");
    printf("|    %c|\n", paus);
    printf("-------\n");
    if(Jogador_total<=10) //Se o n�mero aleat�rio � �s, muda o valor para 11 ou 1 dependendo do total do dealer
         {
             k=11;
         }
         
         else
         {

             k=1;
         }
    }
    
    
    if(k==12) //Se o n�mero aleat�rio � 12, printa a carta da rainha
    {
    //Carta de paus
    printf("-------\n");
    printf("|%c    |\n", paus);
    printf("|  Q  |\n");
    printf("|    %c|\n", paus);
    printf("-------\n");
    k=10; //seta o valor da letra para 10
    }
    
    
    if(k==13) //Se o n�mero aleat�rio for 13, printa a carta rei K
    {
    //carta de paus
    printf("-------\n");
    printf("|%c    |\n", paus);
    printf("|  K  |\n");
    printf("|    %c|\n", paus);
    printf("-------\n");
    k=10; //Seta o valor da letra para 10
    }
    return k;           
}// Fim da fun��o
int cartaOuros() //Mostra a carta de ouros
{
    
    
    srand((unsigned) time(NULL)); //Gera a seed aleat�ria do rand
    k=rand()%13+1;
    
    if(k<=9) //Se o n�mero aleat�rio for 9 ou menos, printa o n�mero al
    {
    //Carta de ouros
    printf("-------\n");
    printf("|%c    |\n", ouros);
    printf("|  %d  |\n", k);
    printf("|    %c|\n", ouros);
    printf("-------\n");
    }
    
    if(k==10) //Se o n�mero aleat�rio for 10, printa a carta J
    {
    //Carta de ouros
    printf("-------\n");
    printf("|%c    |\n", ouros);
    printf("|  J  |\n");
    printf("|    %c|\n", ouros);
    printf("-------\n");
    }
    
    if(k==11) //Se o n�mero aleat�rio for 11, printa a carta �s
    {
    //Carta de ouros
    printf("-------\n");
    printf("|%c    |\n", ouros);
    printf("|  A  |\n");
    printf("|    %c|\n", ouros);
    printf("-------\n");
    if(Jogador_total<=10) //Se o n�mero aleat�rio for um �s, o valor muda para 11 ou 1 dependendo do total do dealer
         {
             k=11;
         }
         
         else
         {
             k=1; 
         }
    }
    
    if(k==12) //Se o n�mero aleat�rio � 12, printa a carta da rainha
    {
    //Carta de ouros
    printf("-------\n");
    printf("|%c    |\n", ouros);
    printf("|  Q  |\n");
    printf("|    %c|\n", ouros);
    printf("-------\n");
    k=10; //Seta o valor da letra para 10
    }
    
    if(k==13) //Se o n�mero aleat�rio for 13, printa a carta rei K
    {
    //Carta de ouros
    printf("-------\n");
    printf("|%c    |\n", ouros);
    printf("|  K  |\n");
    printf("|    %c|\n", ouros);
    printf("-------\n");
    k=10; //Seta o valor da letra para 10
    }
    return k;
}// Fim da fun��o
int cartaCopas() //mostra a carta de copas
{
    
    
    srand((unsigned) time(NULL)); //rand 
    k=rand()%13+1;
    if(k<=9) //Se o n�mero aleat�rio for 9 ou menos, printa n�mero aleat�rio
    {
    //carta de copas
    printf("-------\n");
    printf("|%c    |\n", copas); 
    printf("|  %d  |\n", k);
    printf("|    %c|\n", copas);
    printf("-------\n");
    }
    
    if(k==10) //Se o n�mero aleat�rio for 10, printa carta J
    {
    //carta de copas
    printf("-------\n");
    printf("|%c    |\n", copas);
    printf("|  J  |\n");
    printf("|    %c|\n", copas);
    printf("-------\n");
    }
    
    if(k==11) //Se o n�mero aleat�rio for 11, printa carta �s
    {
    //carta de copas
    printf("-------\n");
    printf("|%c    |\n", copas);
    printf("|  A  |\n");
    printf("|    %c|\n", copas);
    printf("-------\n");
    if(Jogador_total<=10) //Se o n�mero aleat�rio for �s, muda o valor para 1 ou 11 dependendo do total do dealer
         {
             k=11;
         }
         
         else
         {
             k=1;
         }
    }
    
    if(k==12) //Se o n�mero aleat�rio for 12, printa carta rainha Q
    {
    //carta de copas
    printf("-------\n");
    printf("|%c    |\n", copas);
    printf("|  Q  |\n");
    printf("|    %c|\n", copas);
    printf("-------\n");
    k=10; //Seta letra para 10
    }
    
    if(k==13) //Se o n�mero aleat�rio for 13, printa carta rei k
    {
    //carta de copas
    printf("-------\n");
    printf("|%c    |\n", copas);
    printf("|  K  |\n");
    printf("|    %c|\n", copas);
    printf("-------\n");
    k=10; //Seta a letra para 10
    }
    return k;
} //Fim da fun��o
int cartaEspada() //Mostra a carta de espada
{
    
    
    srand((unsigned) time(NULL)); //rand
    k=rand()%13+1;
    
    if(k<=9) //Se o n�mero aleat�rio for 9 ou menos, printa n�mero aleat�rio
    {
    //casta de espada 
    printf("-------\n");
    printf("|%c    |\n", espada);
    printf("|  %d  |\n", k);
    printf("|    %c|\n", espada);
    printf("-------\n");
    }
    
    if(k==10) //Se o n�mero aleat�rio for 10, printa carta J
    {
    //casta de espada 
    printf("-------\n");
    printf("|%c    |\n", espada);
    printf("|  J  |\n");
    printf("|    %c|\n", espada);
    printf("-------\n");
    }
    
    if(k==11) //Se o n�mero aleat�rio for 11, printa carta �s
    {
    //casta de espada 
    printf("-------\n");
    printf("|%c    |\n", espada);
    printf("|  A  |\n");
    printf("|    %c|\n", espada);
    printf("-------\n");
    if(Jogador_total<=10) //Se o n�mero aleat�rio for �s, muda o valor para 1 ou 11 dependendo do total do dealer
         {
             k=11;
         }
         
         else
         {
             k=1;
         }
    }
    
    if(k==12) //Se o n�mero aleat�rio for 12, printa carta rainha Q
    {
    //casta de espada 
    printf("-------\n");
    printf("|%c    |\n", espada);
    printf("|  Q  |\n");
    printf("|    %c|\n", espada);
    printf("-------\n");
    k=10; //Seta letra para 10
    }
    
    if(k==13) //Se o n�mero aleat�rio for 13, printa carta rei k
    {
    //casta de espada 
    printf("-------\n");
    printf("|%c    |\n", espada);
    printf("|  K  |\n");
    printf("|    %c|\n", espada);
    printf("-------\n");
    k=10; //Seta letra para 10
    }
    return k;
} //Fim da fun��o
int randcarta() //Gera cartas aleat�rias                      
{
     
               
     srand((unsigned) time(NULL)); //Gera a seed aleat�ria do rand
     carta_aleatoria = rand()%4+1;
     
     if(carta_aleatoria==1)
     {   
         cartaPaus();
         l=k;
     }
     
     if(carta_aleatoria==2)
     {
         cartaOuros();
         l=k;
     }
     
     if(carta_aleatoria==3)
     {
         cartaCopas();
         l=k;
     }
         
     if(carta_aleatoria==4)
     {
         cartaEspada();
         l=k;
     }    
     return l;
} //Fim da fun��o   
void jogar(Player player, Cassino cassino) //Starta o jogo
{
     int p=0; //Segura o valor total dos jogadores
     int i=1; // contador para pedir ao usu�rio entre segurar ou ficar (turnos do jogo)
     
     char opcao3;
     
     Tdinheiro(player);
	
     printf("\nJogador atual:%s", player.nome); 
	 printf("\nCassino atual :%s", cassino.nome);
     printf("\n seu dinheiro: $%d\n",player.dinheiro); //Printa a quantidade de dinheiro que o jogador tem
     randcarta(); //Gerador de carta aleat�ria
     Jogador_total = p + l; //Calcula o total do jogador
     p = Jogador_total;
     printf("\nSeu total � %d\n", p); //Printa o total do jogador
     dealer(); //Calcula e printa o total do dealer
     apostas(player); //Pede ao usu�rio que entre com o valor da aposta
       
     while(i<=21) //Loop de while para perguntar se o jogador quer mais uma carta ou parar, no maximo 21 vezes 
                  //Porque h� chance do jogador tirar 1 21 vezes
     {
         if(p==21) //Se o total do jogador � 21, ele ganha :)
         {
             printf("\nPar�bens pela vit�ria!\n");
             player.dinheiro = player.dinheiro + aposta;
            // dinheiroc = dinheiro + aposta;
    
            // cassino.rendimento= dinheiroc;
             dealer_total=0;
             PerguntarN(player, cassino);
         }
     
         if(p>21) //Se o total do jogador � maior do que 21, derrota
         {
             printf("\nQue pena voc� perdeu.\n");
             player.dinheiro = player.dinheiro - aposta;
             dinheiroc = aposta;
             cassino.rendimento= dinheiroc; 
             dealer_total=0;
             PerguntarN(player, cassino);
         }
     
         if(p<=21) //Se o total do jogador � menor que 21, pergunta se deseja mais uma carta ou se quer parar
         {         
               
             scanf("%c", &opcao3);
             while((opcao3!='M') && (opcao3!='m') && (opcao3!='R') && (opcao3!='r')) //Caso haja entrada inv�lida
	         {                                                                           
                 printf("\n");
                 printf("\n");
		         printf("Deseja parar ou deseja mais uma carta? 'M' para mais uma e 'R' para parar.\n");
		         scanf("%c",&opcao3);
		         printf("\n");
	         }

	         if((opcao3=='M') || (opcao3=='m')) //Se optar por mais uma, continua
	         { 
                 randcarta();
                 Jogador_total = p + l;
                 p = Jogador_total;
                 printf("\nSeu total � %d\n", p);
                 dealer();
                  if(dealer_total==21) //Se o total do dealer � 21, derrota
                  {
                      printf("\nA m�o do dealer era melhor, VOC� PERDEU bob�o.\n");
                      player.dinheiro = player.dinheiro - aposta;
                      dinheiroc = aposta;
                      cassino.rendimento= dinheiroc;
                      dealer_total=0;
                      PerguntarN(player, cassino);
                  } 
     
                  if(dealer_total>21) //Se o total do dealer for maior que 21, vit�ria
                  {                      
                      printf("\nO dealer se deu mal!. voc� ganhou!\n");
                      player.dinheiro = player.dinheiro+aposta;
                     // dinheiroc = dinheiro+aposta;
                    //  cassino.rendimento= dinheiroc;
                      
                      dealer_total=0;
                      PerguntarN(player, cassino);
                  }
             }
             if((opcao3=='R') || (opcao3=='r')) //Caso pare o jogo finaliza indicando se o jogador perdeu
             {
                printf("\nVoc� decidiu param em %d.\n", Jogador_total);
                parar(player, cassino);
             }
          }
             i++; //Enquanto o total do dealer e do jogador � menor que 21 restarta o loop while
     } //Finaliza o while
} //Fim de fun��o
void parar(Player player, Cassino cassino) //Fun��o para quando o jogador decide parar
{
     dealer(); //Caso pare, o dealer continua o jogo
     if(dealer_total>=17)
     {
      if(Jogador_total>=dealer_total) //Se o total do jogador � maior do que o do dealer, vit�ria
      {
         printf("\nVoc� levou essa!! parab�ns\n");
         player.dinheiro = player.dinheiro+aposta;
       //  dinheiroc = dinheiro+aposta;
         //cassino.rendimento= dinheiro;
         //printf("%f", dinheiroc);
         dealer_total=0;
         PerguntarN(player, cassino);
      }
      if(Jogador_total<dealer_total && dealer_total<=21) //Se o total do jogador for menor que o do dealer, derrota
      {
         printf("\nA m�o do dealer era melhor, voc� perdeu.\n");
         player.dinheiro = player.dinheiro - aposta;
         dinheiroc = aposta;
         cassino.rendimento= dinheiroc;
         dealer_total=0;
         PerguntarN(player, cassino);
      }
      if(dealer_total>21) //Se o total do dealer for maior que 21, vit�ria
      {
         printf("\nWOW voc� ganhou essa, incr�vel\n");
         player.dinheiro = player.dinheiro+aposta;
        // dinheiroc = dinheiro+aposta;
        // cassino.rendimento= dinheiroc;
         dealer_total=0;
         PerguntarN(player, cassino);
     }
     else   
     {
         parar(player, cassino);
     }
	 }
     
} // End Function
void dealer() //Fun��o para fazer o dealer jogar 
{
     int z;
     
     if(dealer_total<17)
     {
      srand((unsigned) time(NULL) + 1); //Gera seed aleat�ria para o rand
      z=rand()%13+1;
      if(z<=10) //Se o n�mero aleat�rio for 10 ou menos, mant�m o valor
      {
         d=z;
         
      }
     
      if(z>11) //Se o n�mero aleat�rio for menor do que 11, seta o vlaor para 10
      {
         d=10;
      }
     
      if(z==11) //Se o n�mero aleat�rio � 11(�s), mudar o valor para 11 ou 1 dependendo do total do dealer
      {
         if(dealer_total<=10)
         {
             d=11;
         }
         
         else
         {
             d=1;
         }
      }
     dealer_total = dealer_total + d;
     }
          
     printf("\nO dealer tem um total de %d", dealer_total); //Printa o total do dealer
     
} //Fim da fun��o
void Tdinheiro(Player player, Cassino cassino) //Teste se o usu�rio tem dinheiro
{
     if (player.dinheiro <= 0) //Assim que o usu�rio n�o tiver dinheiro restante, o jogo termina e solicita que o usu�rio jogue novamente
     {
        printf("Voc� ficou pobre kkkkk. perdeu tudo");
        PerguntarN(player, cassino);
     }
} // 
int apostas(Player player) //Pede ao usu�rio quanto apostar
{ 
	printf("\n\n Sua aposta: $");
	scanf("%d", &aposta);

 if (aposta > player.dinheiro) //Se o jogador tentar apostar mais dinheiro do que o jogador tem
 {
        printf("\nVoc� n�o tem dinheiro suficinte.");
        printf("\nSua aposta: ");
        scanf("%d", &aposta);
        return aposta;
 }
 else return aposta;
} //
void PerguntarN(Player player, Cassino cassino) //Fun��o para perguntar ao jogador se ele deseja jogar novamente
{
    char opcao1;

     printf("\nGOSTARIA DE JOGAR NOVAMENTE?");
     printf("\nDigite S para Sim ou N para N�o\n");
     scanf("\n%c",&opcao1);

    while((opcao1!='S') && (opcao1!='s') && (opcao1!='N') && (opcao1!='n')) 
    {
        printf("\n");
        printf("Escolha incorreta. Digite S para Sim ou N para N�o.\n");
        scanf("%c",&opcao1);
    }


    if((opcao1 == 'S') || (opcao1 == 's'))// continua o jogo 
    { 
            system("cls");
            jogar(player, cassino);
    }
 
      else if((opcao1 == 'N') || (opcao1 == 'n')) // saiu do programa
    {
       // arquivoResultado();
       system("cls");
       salvar_dinheiro_cass(cassino);
    	menu(&player, &cassino);
       	
    }
    return;
} // SAINDO DA F�
