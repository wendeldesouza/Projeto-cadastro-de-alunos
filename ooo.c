#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int curso, curso2, mat, idade, sexv, turno, turno2, val;
	char nome[30], sex[10], turn[10], turn2[10], curs[10], curs2[10];
	float mens;
}TAluno;

FILE *paluno;
TAluno aluno_aux, aluno_nulo;

int mostre();

void linha(){
    int i;
        for (i=1;i<=80;i++)
            printf("*");
}

void linha2(){
    int i;
        for (i=1;i<=80;i++)
            printf("+");
}

void linha3(){
    int i;
        for(i=1;i<=80;i++)
            printf("_");
}

void cabec(){
    system("cls");
    linha();
    printf("\t\t\t ### FACULDADE JOAQUIM NABUCO ### ");
    printf("\n");
    linha();
}

void SI(){
	system("color F0");
	printf("\n\n\n");
	printf("\t\t\t\t 888888  8888\n");
	printf("\t\t\t\t 88  88   88\n");
	printf("\t\t\t\t 88       88\n");
	printf("\t\t\t\t 888888   88\n");
	printf("\t\t\t\t     88   88\n");
	printf("\t\t\t\t 88  88   88\n");
	printf("\t\t\t\t 888888  8888\n");
	printf("\n\n\n\n");
	printf("\t\t\t         *PROJETO C* \n");
	printf("\t\t\t       AMELIARA FREIRE");
	printf("\n\n\n");
	printf("\t\t\t\t    LILIAN \n\t\t\t\t    LUCAS \n\t\t\t\t    WENDEL");
	printf("\n\n\n");
linha();
getche();
system("cls");
}

void abre_arquivo(){
    paluno = fopen("aluno.txt", "r+b");
        if(paluno == NULL)
            paluno = fopen("aluno.txt", "w+b");
}

void matricula(){
	int matt, pos;
		do{
			printf("\nDIGITE A MATRICULA: ");
				scanf("%d",&matt);
			pos=procura(matt);
				if(pos ==- 1){
					aluno_aux.mat = matt;
				}else{
					system("cls");
						printf("\n\nMATRICULA JA CADASTRADA!\n\n");
							mostre(pos);
						printf("Tecle ENTER para voltar, para digitar novamente a matricula...");
							getche();
								system("cls");
				}
		}while(pos !=-1);
		}


void cadastro(){
	int  resp=0, resp2, desc;
	char php[10]= "PHP",java[10]= "JAVA",delphi[10] = "DELPHI";
	char sex1[10], fem[4] ="FEM", mas[4] = "MAS";
	char turno1[5], diruno[10] ="dia", noturno[10] ="noite";
	
		do{
			cabec();
				printf("###CADASTRO DO ALUNO###\n\n");
					matricula();
												
				printf("\n::Nome: ");
					fflush(stdin);
						gets(aluno_aux.nome);
					
				printf("\n::Idade: ");
					scanf("%d",&aluno_aux.idade);
	
			do{	
				printf("\n::Sexo: (1-F/2-M)");
					scanf("%d",&aluno_aux.sexv);
						if((aluno_aux.sexv != 1) && (aluno_aux.sexv != 2)){
							printf("\nERRO");
						}
				}while ((aluno_aux.sexv!= 1 ) && (aluno_aux.sexv != 2 ));
					if (aluno_aux.sexv == 1 ){
						strcpy(aluno_aux.sex,"FEM");
					}
					if(aluno_aux.sexv == 2 ){
						strcpy(aluno_aux.sex,"MAS");
					}	
																						
					printf("\n::Cadastro de curso \n");
					printf("\n::Preencha os dados da sua primeira opcao: ");				
																										
				printf("\n\n::Turno: ");
				printf("\n\nDiurno[1] \n");
				printf("\nNoturno[2] \n");
					scanf("%d",&aluno_aux.turno);
						do{
							if((aluno_aux.turno !=1) && (aluno_aux.turno !=2)){
								printf("\nERRO");
								printf("\nDiginte: Diurno[1] ou Noturno[2]");
									scanf("%d",&aluno_aux.turno);
							}
						}while((aluno_aux.turno !=1) && (aluno_aux.turno !=2));			
							if(aluno_aux.turno ==1){
								strcpy(aluno_aux.turn,"Diurno");
							}
							if(aluno_aux.turno == 2){
								strcpy(aluno_aux.turn,"Noturno");
							}			

				printf("\n::Escolha o curso: ");
				printf("\n\nCurso: 1-PHP | Diurno R$210,00 | Noturno R$260,00\n");
				printf("       2-Java | Diurno R$320,00 | Noturno R$390,00\n");
				printf("       3-Delphi | Diurno R$290,00 | Noturno R$310,00\n\n");
					scanf("%d",&aluno_aux.curso);					
						do{
							if((aluno_aux.curso !=1) && (aluno_aux.curso !=2) && (aluno_aux.curso !=3)){
								printf("\nERRO");
								printf("\nINFORME APENAS (1, 2 ou 3)");
									scanf("%d",&aluno_aux.curso);
							}
							if (aluno_aux.curso == 1){
								strcpy(aluno_aux.curs,"PHP");
							}
							if (aluno_aux.curso == 2){
								strcpy(aluno_aux.curs,"JAVA");
							}
							if (aluno_aux.curso == 3){
								strcpy(aluno_aux.curs,"DELPHI");
							}
						}while ((aluno_aux.curso != 1) && (aluno_aux.curso != 2) && (aluno_aux.curso != 3));
				
		do {
			printf("\nDeseja cadastrar outro curso? 1 - Sim ou 2 - Nao: ");
				scanf("%d",&resp2);
			if(resp2 == 1 ){
				aluno_aux.val= 1;
				}
			if((resp2 != 1) && (resp2 != 2)){
				printf("\n OPCAO INVALIDA.\n");
				}
		}while ((resp2 !=1) && (resp2 != 2));
			
			if(resp2 == 1){
				do{
				printf("\n\n::Turno: ");
				printf("\n\nDiurno[1] \n");
				printf("\nNoturno[2] \n");
						scanf("%d",&aluno_aux.turno2);
						if(aluno_aux.turno2 == 1){
							strcpy(aluno_aux.turn2,"Diurno");
							}
						if(aluno_aux.turno2 == 2){
							strcpy(aluno_aux.turn2,"Noturno");
							}
						if((aluno_aux.turno2 != 1) && (aluno_aux.turno2 != 2)){
							printf("\nERRO");
							printf("\nDiginte: Diurno[1] ou Noturno[2]");
							}
						if (aluno_aux.turno == aluno_aux.turno2){
							if ((aluno_aux.turno == 1) && (aluno_aux.turno2 ==1)){
								printf("\n TURNO DIURNO JA CADASTRADO. \n");		
								}
							if ((aluno_aux.turno == 2) && (aluno_aux.turno2 == 2)){
								printf("\n TURNO NOTURNO JA CADASTRADO \n");	
									}
							}
						}while (((aluno_aux.turno2 == 1) || (aluno_aux.turno2 != 2)) && ((aluno_aux.turno2 != 1) || (aluno_aux.turno2 != 2)));
						
				do{
					printf("\n::Escolha o curso: ");
				printf("\n\nCurso: 1-PHP | Diurno R$210,00 | Noturno R$260,00\n");
				printf("       2-Java | Diurno R$320,00 | Noturno R$390,00\n");
				printf("       3-Delphi | Diurno R$290,00 | Noturno R$310,00\n\n");
					scanf("%d",&aluno_aux.curso2);
					if (aluno_aux.curso2 == 1){
						strcpy(aluno_aux.curs2,"PHP");
						}
					if (aluno_aux.curso2 == 2){
						strcpy(aluno_aux.curs2,"JAVA");
						}
					if (aluno_aux.curso2 == 3){
						strcpy(aluno_aux.curs2,"DELPHI");
						}
					if ((aluno_aux.curso2 != 1) && (aluno_aux.curso2 != 2) && (aluno_aux.curso2 != 3)){
						printf("\nERRO");
						printf("\nINFORME APENAS (1, 2 ou 3)");
							}
				if(aluno_aux.curso == aluno_aux.curso2){
					if((aluno_aux.curso == 1) && (aluno_aux.curso2 == 1)){
						printf("\n CURSO PHP JA CADASTRADO... \n");
						}	
					if((aluno_aux.curso == 2) && (aluno_aux.curso2 == 2)){
						printf("\n CURSO JAVA JA CADASTRADO \n");
							}	
					if((aluno_aux.curso == 3) && (aluno_aux.curso2 == 3)){
						printf("\n CURSO DELPHI JA CADASTRADO \n");
							}			
						}
					}while (aluno_aux.curso2 == aluno_aux.curso);		
	  	  }		
						
		if((aluno_aux.idade > 45) && (aluno_aux.turno == 1) && (aluno_aux.curso == 1)){
			desc = (210*15)/100;
				aluno_aux.mens = 210 - desc;
		}
					
		if((aluno_aux.idade > 45) && (aluno_aux.turno == 2) && (aluno_aux.curso == 1)){
			desc = (260*15)/100;
				aluno_aux.mens = 260 - desc;
		}
					
		if((aluno_aux.idade > 45) && (aluno_aux.turno == 1) && (aluno_aux.curso == 2)){
			desc = (320*15)/100;
				aluno_aux.mens = 320 - desc;
		}
					
		if((aluno_aux.idade > 45) && (aluno_aux.turno == 2) && (aluno_aux.curso == 2)){
			desc = (390*15)/100;
				aluno_aux.mens = 390 - desc;
		}
					
		if((aluno_aux.idade > 45) && (aluno_aux.turno == 1) && (aluno_aux.curso == 3)){
			desc = (290*15)/100;
				aluno_aux.mens = 290 - desc;
		}
					
		if((aluno_aux.idade > 45) && (aluno_aux.turno == 2) && (aluno_aux.curso == 3)){
			desc = (310*15)/100;
				aluno_aux.mens = 310 - desc;
		}
				
		if((aluno_aux.idade <= 45) && (aluno_aux.turno == 1) && (aluno_aux.curso == 1)){
			aluno_aux.mens = 210;
		}
					
		if((aluno_aux.idade <= 45) && (aluno_aux.turno == 2) && (aluno_aux.curso == 1)){
			aluno_aux.mens = 260;
		}
					
		if((aluno_aux.idade <= 45) && (aluno_aux.turno == 1) && (aluno_aux.curso == 2)){
			aluno_aux.mens = 320;
		}
					
		if((aluno_aux.idade <= 45) && (aluno_aux.turno == 2) && (aluno_aux.curso == 2)){
			aluno_aux.mens = 390;
		}
		
		if((aluno_aux.idade <= 45) && (aluno_aux.turno == 1) && (aluno_aux.curso == 3)){
			aluno_aux.mens = 290;
		}
					
		if((aluno_aux.idade <= 45) && (aluno_aux.turno == 2) && (aluno_aux.curso == 3)){
			aluno_aux.mens = 310;
		}
				
		if((aluno_aux.turno == 1) && (aluno_aux.curso ==1) && (aluno_aux.turno2 == 2) && (aluno_aux.curso2 == 2)){
			desc = ((210 + 390)*30)/100;
				aluno_aux.mens = (210+390)- desc;
		}
				
		if((aluno_aux.turno == 2) && (aluno_aux.curso == 1) && (aluno_aux.turno2 == 1) && (aluno_aux.curso2 == 2)){
			desc = ((260+320)*30)/100;
				aluno_aux.mens = (260+320)- desc;
		}
				
		if((aluno_aux.turno == 1) && (aluno_aux.curso == 1) && (aluno_aux.turno2 == 2) && (aluno_aux.curso2 == 3)){
			desc = ((210+310)*30)/100;
				aluno_aux.mens = (210+310)- desc;
		}
				
		if((aluno_aux.turno == 2) && (aluno_aux.curso != 1) && (aluno_aux.turno2 != 1) && (aluno_aux.curso2 == 3)){
			desc = ((260 + 290)*30)/100;
				aluno_aux.mens =(260+290)- desc;
		}
				
		if((aluno_aux.turno == 1) && (aluno_aux.curso != 2) && (aluno_aux.turno2 == 2) && (aluno_aux.curso2 == 3)){
			desc = ((320 + 310)*30)/100;
				aluno_aux.mens = (320+310)- desc;
		}
				
		if((aluno_aux.turno == 2) && (aluno_aux.curso == 2) && (aluno_aux.turno2 == 1) && (aluno_aux.curso2 == 3)){
			desc = ((390 + 290)*30)/100;
				aluno_aux.mens = (390+290)- desc;
		}				
											
			fseek(paluno, 0, SEEK_END);
			fwrite(&aluno_aux, sizeof(TAluno), 1, paluno);	
		
		printf("\n\nALUNO CADASTRADO COM SUCESSO!\n\n");
		printf("\n\n::DESEJA CADASTRAR OUTRO ALUNO (1-SIM / 2-NAO)?: ");
			scanf("%d", &resp);	
			do{
				if ((resp !=1) && (resp != 2)) {
				printf("\n OPCAO INVALIDA... \n");
					}
			}while ((resp != 1) && (resp != 2));
		}while(resp==1);
}

int procura(int matp){
    int p; //variavel declarada
    p=0; //validação da variavel acima
    rewind(paluno);
    fread(&aluno_aux, sizeof(TAluno), 1, paluno);
    while (feof(paluno)==0){
        if(aluno_aux.mat == matp)
            return p;
    else{
        fread(&aluno_aux, sizeof(TAluno), 1, paluno);
        p++;
    	}
    }
return -1;
}

int mostre(int pos){
    fseek(paluno, pos*sizeof(TAluno), SEEK_SET);
    fread(&aluno_aux, sizeof(TAluno), 1, paluno);
    linha();
    	printf("\nMATRICULA | NOME | SEXO | IDADE | TURNO|TURNO2 | CURSO1 | CURSO2 |  MENSALIDADE\n");
	linha3();
    	printf("   %d    %-2s    %-4s    %d     %-6s|%-5s      %s   %s      %.2f\n",aluno_aux.mat, aluno_aux.nome, aluno_aux.sex, aluno_aux.idade,aluno_aux.turn, aluno_aux.turn2, aluno_aux.curs, aluno_aux.curs2, aluno_aux.mens);
    linha3();
}

void remover(){
    int matrem, conf, resp, posicao;
    aluno_nulo.mat = 0;
    do{
    cabec();
    	printf("\n\nEXCLUSAO DE CADASTRO\n\n\n");
    	printf("MATRICULA: ");
    		scanf("%d",&matrem);
    posicao = procura(matrem);
    if(posicao == -1){
        printf("\nALUNO INEXISTENTE!!\a");
    }else{
        mostre(posicao);
        printf("\n\nDESEJA PROSSEGUIR COM A EXCLUSAO(1-S/0-N)?\n ");
        	scanf("%d",&conf);
        if (conf == 1){
            fseek(paluno, posicao*sizeof (TAluno),SEEK_SET);
            fwrite(&aluno_nulo, sizeof(TAluno), 1, paluno);
            printf("\n\nALUNO DESVINCULADO COM SUCESSO!");
        }else{
            printf("\nEXCLUSAO CANCELADA!");
    	}
	}
    printf("\n\n\nDESEJA EXCLUIR ALGUM OUTRO CADASTRO(1-S/0-N)? ");
    	scanf("%d",&resp);
    }while(resp ==1);
}

void editar(){
	int matedi, confirm, re, posicao;
	int  resp=0, resp2, desc;
	char php[10]= "PHP",java[10]= "JAVA",delphi[10] = "DELPHI";
	char sex1[10], fem[4] ="FEM", mas[4] = "MAS";
	char turno1[5], diruno[10] ="dia", noturno[10] ="noite";
		
		do{
			cabec();
				printf("\n\nEDITAR CADASTRO DO ALUNO\n\n\n");
				printf("\n::MATRICULA: ");
					scanf("%d", &matedi);
			
			posicao = procura(matedi);
			
			if(posicao == -1){
				printf("\n\nALUNO NAO ENCONTRADO!\n\n");				
			}else{
				mostre(posicao);
					printf("\n\nDESEJA EDITAR OS DADOS DO ALUNO (1-SIM / 2-NAO): ");
						scanf("%d", &confirm);
				
			}if(confirm==1){
				printf("\n::NOME: ");
					fflush(stdin);
						gets(aluno_aux.nome);
					
		do{
			printf("\n::Sexo: (1-F/2-M) ");
				scanf("%d",&aluno_aux.sexv);
					if((aluno_aux.sexv != 1) && (aluno_aux.sexv != 2)){
						printf("\n !Opcao invalida. Por favor informe novamente o sexo! \n");
					}
					if(aluno_aux.sexv ==1){
						strcpy(aluno_aux.sex,"FEM");
					}
					if (aluno_aux.sexv == 2){
						strcpy(aluno_aux.sex,"MAS");
					}
		}while ((aluno_aux.sexv != 1) && (aluno_aux.sexv != 2));
							
					printf("\nIdade :");
						scanf("%d",&aluno_aux.idade);
		do{
			printf("\n\n::Turno: ");
			printf("\n\nDiurno[1] \n");
			printf("\nNoturno[2] \n");
				scanf("%d",&aluno_aux.turno);
					if (aluno_aux.turno == 1 ){
						strcpy (aluno_aux.turn,"Diurno");
					}
					if (aluno_aux.turno == 2){
						strcpy (aluno_aux.turn,"NOTURNO");
					}
					if((aluno_aux.turno != 1) && (aluno_aux.turno != 2)){
						printf ("\n OPCAO INVALIDA!  \n");
					}
		}while ((aluno_aux.turno != 1) && (aluno_aux.turno != 2));
									
		do{
			printf("\n::Escolha o curso: ");
			printf("\n\nCurso: 1-PHP | Diurno R$210,00 | Noturno R$260,00\n");
			printf("       2-Java | Diurno R$320,00 | Noturno R$390,00\n");
			printf("       3-Delphi | Diurno R$290,00 | Noturno R$310,00\n\n");
				scanf("%d",&aluno_aux.curso);
					if (aluno_aux.curso == 1){
						strcpy(aluno_aux.curs,"PHP");
					}
					if (aluno_aux.curso == 2){
						strcpy(aluno_aux.curs,"JAVA");
					}
					if (aluno_aux.curso == 3){
						strcpy(aluno_aux.curs,"DELPHI");
					}
					if ((aluno_aux.curso != 1) && (aluno_aux.curso != 2) && (aluno_aux.curso != 3)){
						printf("\n OPCAO INVALIDA! \n");
					}
		}while ((aluno_aux.curso != 1) && (aluno_aux.curso != 2) && (aluno_aux.curso != 3));
		
		do {
			printf("\n DESEJA CADASTRAR OUTRO CURSO? (1-SIM / 2-NAO): ");
				scanf("%d",&resp2);
					if(resp2 == 1 ){
						aluno_aux.val = 1;
					}
					if ((resp2 != 1) && (resp2 != 2)){
						printf("\n OPCAO INVALIDA!\n");
					}
		}while ((resp2 !=1) && (resp2 != 2));
			if(resp2 == 1){
		
		do{
			printf("\nTURNO ([1]-DIURNO|[2]-NOTURNO) : ");
				scanf("%d",&aluno_aux.turno2);
					if(aluno_aux.turno2 == 1){
						strcpy(aluno_aux.turn2,"DIURNO");
					}
					if(aluno_aux.turno2 == 2){
						strcpy(aluno_aux.turn2,"NOTURNO");
					}
					if((aluno_aux.turno2 != 1) && (aluno_aux.turno2 != 2)){
						printf ("\n OPCAO INVALIDA! \n");	
					}
					if (aluno_aux.turno == aluno_aux.turno2){
						if ((aluno_aux.turno == 1) && (aluno_aux.turno2 ==1)){
							printf("\n TURNO DIURNO JA CADASTRADO! \n");		
						}
						if ((aluno_aux.turno == 2) && (aluno_aux.turno2 == 2)){
							printf("\n TURNO NOTURNO JA CADASTRADO! \n");	
						}
					}
		}while (((aluno_aux.turno2 == 1) || (aluno_aux.turno2 != 2)) && ((aluno_aux.turno2 != 1) || (aluno_aux.turno2 != 2)));									
									
		do{
			printf("\n::Escolha o curso: ");
			printf("\n\nCurso: 1-PHP | Diurno R$210,00 | Noturno R$260,00\n");
			printf("       2-Java | Diurno R$320,00 | Noturno R$390,00\n");
			printf("       3-Delphi | Diurno R$290,00 | Noturno R$310,00\n\n");
				scanf("%d",&aluno_aux.curso2);
					if (aluno_aux.curso2 == 1){
						strcpy(aluno_aux.curs2,"PHP");
					}
					if (aluno_aux.curso2 == 2){
						strcpy(aluno_aux.curs2,"JAVA");
					}
					if (aluno_aux.curso2 == 3){
						strcpy(aluno_aux.curs2,"DELPHI");
					}
					if ((aluno_aux.curso2 != 1) && (aluno_aux.curso2 != 2) && (aluno_aux.curso2 != 3)){
						printf("\n OPCAO INVALIDA! \n");
					}
					if(aluno_aux.curso == aluno_aux.curso2){
						if((aluno_aux.curso == 1) && (aluno_aux.curso2 == 1)){
							printf("\n CURSO PHP JA CADASTRADO! \n");
						}	
						if((aluno_aux.curso == 2) && (aluno_aux.curso2 == 2)){
							printf("\n CURSO JAVA JA CADASTRADO! \n");
						}	
						if((aluno_aux.curso == 3) && (aluno_aux.curso2 == 3)){
							printf("\n CURSO DELPHI JA CADASTRADO! \n");
						}			
					}
		}while (aluno_aux.curso2 == aluno_aux.curso);	
			}
				fseek(paluno, posicao*sizeof(TAluno), SEEK_SET);
				fwrite(&aluno_aux, sizeof(TAluno), 1, paluno);
				mostre(posicao);
					printf("\n\nDADOS DO ALUNO ALTERADO COM SUCESSO!!\n\n");
			}else{
				printf("\nALTERECAO CANCELADA!\n\n");
				}
				printf("\nDESEJA FAZER OUTRA AUTERACAO?(1-SIM / 2-NAO): ");
					scanf("%d", &re);
		}while(re==1);
	}

void listagem(){
	cabec();
		printf("\nMATRICULA | NOME | SEXO | IDADE | TURNO|TURNO2 | CURSO1 | CURSO2 |  MENSALIDADE\n");
	linha3();
	rewind(paluno);
		fread(&aluno_aux, sizeof(TAluno), 1, paluno);
		while (feof(paluno)==0){ 
			if (aluno_aux.mat != 0){
				printf("   %d     %-2s    %-4s   %d    %-6s|%-5s   %s    %s        %.2f \n",aluno_aux.mat, aluno_aux.nome, aluno_aux.sex, aluno_aux.idade, aluno_aux.turn, aluno_aux.turn2, aluno_aux.curs, aluno_aux.curs2,aluno_aux.mens);
			fread(&aluno_aux, sizeof(TAluno), 1, paluno);
			}
		}
	linha3();	
		printf("\nTecle ENTER para voltar ao menu...");
	getche();
}

void limpar(){
    system("pause");
}

int main(){
    int op;
    abre_arquivo();

 cabec();
 SI();

    do{
        cabec();
        system("color F0");
        	printf("\t\t\t      ### TELA INICIAL ### \n");
        	printf("\n\tTI Cursos\n\n\n");
        	printf(" ::1- CADASTRAR ALUNO\n\n");
        	printf(" ::2- REMOVER ALUNO\n\n");
        	printf(" ::3- ALTERAR REGISTRO DO ALUNO\n\n");
        	printf(" ::4- LISTAGEM GERAL\n\n");
        	printf(" ::0- SAIR\n");
        linha3();
        	printf("\t\t\t  ### ESCOLHA UM DOS NUMEROS ACIMA ###\n\t\t\t\t\t");
        		scanf("%d",&op);
        switch(op){
            case 1: cadastro(); break;
            case 2: remover(); break;
            case 3: editar(); break;
            case 4: listagem(); break;
            case 0: fclose(paluno); break;
			default: printf("\t\nOPCAO INVALIDA!");
		}
    }while(op !=0);
return 0;
}
