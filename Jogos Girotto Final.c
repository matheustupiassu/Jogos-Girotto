#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

#define RESET   "\033[0m"
#define VERMELHO "\033[1;31m"
#define VERDE    "\033[1;32m"
#define AMARELO  "\033[1;33m"
#define AZUL     "\033[1;34m"
#define CIANO    "\033[1;36m"

void jogar_pergunta_resposta();
void jogar_cobra_caixa();
void gousmas_war();
void limpa_buffer();

void setup() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
}

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int opcao;
    int validacao;
    int quer_jogar;
    int valido;

    setup();

    do {
        system("cls");
        printf(AZUL "\n==============================\n" RESET);
        printf(CIANO  "      ARCADE DE TESTE     \n" RESET);
        printf(AZUL "==============================\n" RESET);
        printf(AMARELO "1: Perguntas e Respostas\n" RESET);
        printf(AMARELO "2: Cobra na Caixa!\n" RESET);
        printf(AMARELO "3: Gousmas War\n" RESET);
        printf(VERMELHO "4: Sair\n" RESET);
        printf(AZUL "==============================\n" RESET);
        
        valido = 0;
        while (!valido) {
            printf("Escolha uma opção: ");
            validacao = scanf("%d", &opcao);
            
            if (validacao != 1) {
                printf(VERMELHO "Digite apenas números.\n" RESET);
                limpa_buffer();
            } else if (opcao < 1 || opcao > 4) {
                printf(VERMELHO "Opção inválida! Escolha de 1 a 4.\n" RESET);
            } else {
                valido = 1;
            }
        }

        if (opcao == 1) {
            system("cls");
            printf(CIANO "\n--- PERGUNTAS E RESPOSTAS ---\n" RESET);
            printf("Responda 5 perguntas de múltipla escolha.\n");
            printf("No final, você verá quantas alternativas acertou.\n\n");
            
            valido = 0;
            while (!valido) {
                printf("Deseja iniciar a partida?\n1- Sim\n2- Voltar\nEscolha: ");
                validacao = scanf("%d", &quer_jogar);
                
                if (validacao != 1) {
                    printf(VERMELHO "Por favor, digite 1 ou 2.\n" RESET); 
                    limpa_buffer(); 
                } else if (quer_jogar == 1 || quer_jogar == 2) {
                    valido = 1;
                } else {
                    printf(VERMELHO "Opção inválida!\n" RESET);
                }
            }
            
            if(quer_jogar == 1) {
                jogar_pergunta_resposta();
            }
        } 
        else if (opcao == 2) {
            system("cls");
            printf(CIANO "\n--- COBRA NA CAIXA ---\n" RESET "Jogo de sorte e risco para 2 jogadores.\nEscolham entre 5 caixas a cada turno.\nEncontrem o botão para vencer, mas evitem a cobra mortal!\n\n");
            
            valido = 0;
            while (!valido) {
                printf("Deseja iniciar a partida?\n1- Sim\n2- Voltar\nEscolha: ");
                validacao = scanf("%d", &quer_jogar);
                
                if (validacao != 1) {
                    printf(VERMELHO "Por favor, digite 1 ou 2.\n" RESET); 
                    limpa_buffer(); 
                } else if (quer_jogar == 1 || quer_jogar == 2) {
                    valido = 1;
                } else {
                    printf(VERMELHO "Opção inválida!\n" RESET);
                }
            }
            
            if(quer_jogar == 1) {
                jogar_cobra_caixa();
            }
        } 
        else if (opcao == 3) {
            system("cls");
            printf(AZUL "\n--- GOUSMAS WAR ---\n" RESET "Jogo de estratégia para 2 jogadores.\nAtaque para sobrecarregar as Gousmas inimigas.\nDivida sua fúria para reviver aliados e vencer!\n\n");
            
            valido = 0;
            while (!valido) {
                printf("Deseja iniciar a partida?\n1- Sim\n2- Voltar\nEscolha: ");
                validacao = scanf("%d", &quer_jogar);
                
                if (validacao != 1) {
                    printf(VERMELHO "Por favor, digite 1 ou 2.\n" RESET); 
                    limpa_buffer(); 
                } else if (quer_jogar == 1 || quer_jogar == 2) {
                    valido = 1;
                } else {
                    printf(VERMELHO "Opção inválida!\n" RESET);
                }
            }
            
            if(quer_jogar == 1) {
                gousmas_war();
            }
        } 
        else if (opcao == 4) {
            printf(VERDE "\nEncerrando o Arcade... Até logo!\n" RESET);
            Sleep(2000);
        }
    } while (opcao != 4);
    
    return 0;
}

void jogar_pergunta_resposta() {
    int resposta;
    int acertos;
    int jogar_novamente = 1;
    int validacao;
    int valido;

    while (jogar_novamente == 1) {
        acertos = 0;
        system("cls");
        printf(CIANO "\n=== Perguntas e Respostas ===\n" RESET);
        printf("Escolha a alternativa correta de 1 a 5.\n\n");

        printf(AMARELO "Pergunta 1: Qual foi o maior dinossauro que já existiu?\n" RESET);
        printf("1 - T-Rex\n2 - Brachiosaurus\n3 - Sauroposeidon\n4 - Diplodocus\n5 - Argentinosaurus\n");
        valido = 0;
        while (!valido) {
            printf("Resposta: ");
            validacao = scanf("%d", &resposta);
            if (validacao != 1) { printf(VERMELHO "Digite apenas números!\n" RESET); limpa_buffer(); }
            else if (resposta >= 1 && resposta <= 5) valido = 1;
            else printf(VERMELHO "Alternativa inválida!\n" RESET);
        }
        if (resposta == 5) { printf(VERDE "Correto!\n\n" RESET); acertos++; Sleep(1500); } 
        else { printf(VERMELHO "Errado! a resposta certa era a 5 - Argentinosaurus\n\n" RESET); Sleep(2500); }

        system("cls");
        printf(AMARELO "Pergunta 2: Qual país foi o primeiro a conceder o direito de voto às mulheres?\n" RESET);
        printf("1 - Brasil\n2 - Nova Zelândia\n3 - França\n4 - Estados Unidos\n5 - Reino Unido\n");
        valido = 0;
        while (!valido) {
            printf("Resposta: ");
            validacao = scanf("%d", &resposta);
            if (validacao != 1) { printf(VERMELHO "Digite apenas números!\n" RESET); limpa_buffer(); }
            else if (resposta >= 1 && resposta <= 5) valido = 1;
            else printf(VERMELHO "Alternativa inválida!\n" RESET);
        }
        if (resposta == 2) { printf(VERDE "Correto!\n\n" RESET); acertos++; Sleep(1500); } 
        else { printf(VERMELHO "Errado! a resposta certa era a 2\n" RESET); Sleep(2500); }

        system("cls");
        printf(AMARELO "Pergunta 3: Quantos Pokémons existem na primeira geração?\n" RESET);
        printf("1 - 151\n2 - 150\n3 - 200\n4 - 152\n5 - 100\n");
        valido = 0;
        while (!valido) {
            printf("Resposta: ");
            validacao = scanf("%d", &resposta);
            if (validacao != 1) { printf(VERMELHO "Digite apenas números!\n" RESET); limpa_buffer(); }
            else if (resposta >= 1 && resposta <= 5) valido = 1;
            else printf(VERMELHO "Alternativa inválida!\n" RESET);
        }
        if (resposta == 1) { printf(VERDE "Correto!\n\n" RESET); acertos++; Sleep(1500); } 
        else { printf(VERMELHO "Errado! a resposta certa era a 1\n\n" RESET); Sleep(2500); }

        system("cls");
        printf(AMARELO "Pergunta 4: Quem escreveu \"O Capital\", obra fundamental do socialismo?\n" RESET);
        printf("1 - Émile Durkheim\n2 - Nikola Tesla\n3 - Max Weber\n4 - Karl Marx\n5 - Adam Smith\n");
        valido = 0;
        while (!valido) {
            printf("Resposta: ");
            validacao = scanf("%d", &resposta);
            if (validacao != 1) { printf(VERMELHO "Digite apenas números!\n" RESET); limpa_buffer(); }
            else if (resposta >= 1 && resposta <= 5) valido = 1;
            else printf(VERMELHO "Alternativa inválida!\n" RESET);
        }
        if (resposta == 4) { printf(VERDE "Correto!\n\n" RESET); acertos++; Sleep(1500); } 
        else { printf(VERMELHO "Errado! a resposta certa era a 4\n\n" RESET); Sleep(2500); }

        system("cls");
        printf(AMARELO "Pergunta 5: Quantas unidades de um mesmo item cabem em um único slot do inventário do Minecraft?\n" RESET);
        printf("1 - 16\n2 - 32\n3 - 64\n4 - 99\n5 - 100\n");
        valido = 0;
        while (!valido) {
            printf("Resposta: ");
            validacao = scanf("%d", &resposta);
            if (validacao != 1) { printf(VERMELHO "Digite apenas números!\n" RESET); limpa_buffer(); }
            else if (resposta >= 1 && resposta <= 5) valido = 1;
            else printf(VERMELHO "Alternativa inválida!\n" RESET);
        }
        if (resposta == 3) { printf(VERDE "Correto!\n\n" RESET); acertos++; Sleep(1500); } 
        else { printf(VERMELHO "Errado! a resposta certa era a 3\n" RESET); Sleep(2500); }

        system("cls");
        printf(AZUL "=============================\n" RESET);
        printf(VERDE "Fim do jogo! Você acertou %d de 5 perguntas.\n" RESET, acertos);
        printf(AZUL "=============================\n" RESET);

        valido = 0;
        while (!valido) {
            printf("\nDeseja jogar novamente?\n1 - Sim\n2 - Voltar ao menu\nEscolha: ");
            validacao = scanf("%d", &jogar_novamente);
            if (validacao != 1) { printf(VERMELHO "Digite apenas números.\n" RESET); limpa_buffer(); }
            else if (jogar_novamente == 1 || jogar_novamente == 2) valido = 1;
            else printf(VERMELHO "Opção inválida!\n" RESET);
        }
    }
}

void jogar_cobra_caixa() {
    char nomes[7][20] = {"Kilian", "Malco", "Salim", "Rodrigo", "Banna", "Tupiassu", "Girotto"};
    char nome1[20], nome2[20];
    char jogador_atual[20];
    int i, c;
    int p1, p2; 
    int jogar_novamente = 1;
    int caixas[5];
    int abertas[5];
    int botao, cobra; 
    int vez;
    int fim_jogo;
    int caixa_escolhida, indice;
    int validacao;
    int valido;

    system("cls");
    printf(AMARELO "\n===============================\n" RESET);
    printf(AMARELO   "        COBRA NA CAIXA          \n" RESET);
    printf(AMARELO "===============================\n\n" RESET);
    
    printf(CIANO "Personagens disponíveis:\n" RESET);
    for(i = 0; i < 7; i++) {
        printf(CIANO "%d. %s\n" RESET, i + 1, nomes[i]);
    }

    valido = 0;
    while (!valido) {
        printf(CIANO "\nJogador 1, escolha o seu personagem (1-7): " RESET);
        validacao = scanf("%d", &p1);
        if (validacao == 1 && p1 >= 1 && p1 <= 7) valido = 1;
        else { printf(VERMELHO "Digite um número válido de 1 a 7.\n" RESET); limpa_buffer(); }
    }
    strcpy(nome1, nomes[p1-1]);
    
    valido = 0;
    while (!valido) {
        printf(CIANO "Jogador 2, escolha o seu personagem (1-7): " RESET);
        validacao = scanf("%d", &p2);
        if (validacao == 1 && p2 >= 1 && p2 <= 7) valido = 1;
        else { printf(VERMELHO "Digite um número válido de 1 a 7.\n" RESET); limpa_buffer(); }
    }
    strcpy(nome2, nomes[p2-1]);

    while (jogar_novamente == 1) {
        for(i = 0; i < 5; i++) {
            caixas[i] = 0;
            abertas[i] = 0;
        }
        fim_jogo = 0;

        system("cls");
        printf(AZUL "A partida entre %s e %s vai começar!\n" RESET, nome1, nome2);
        
        botao = rand() % 5;
        do { cobra = rand() % 5; } while (cobra == botao);

        caixas[botao] = 1;
        caixas[cobra] = 2;
        vez = rand() % 2; 

        while (fim_jogo == 0) {
            if (vez == 0) {
                strcpy(jogador_atual, nome1);
            } else {
                strcpy(jogador_atual, nome2);
            }

            printf(AMARELO "\n-------------------------------\n" RESET);
            printf("Vez de: " CIANO "%s\n" RESET, jogador_atual);
            printf("Caixas: ");
            for(c = 0; c < 5; c++) {
                if(abertas[c] == 1) printf("[ X ] ");
                else printf("[ %d ] ", c + 1);
            }                
            
            valido = 0;
            while (!valido) {
                printf("\nQual caixa deseja abrir? (1-5): ");
                validacao = scanf("%d", &caixa_escolhida);
                
                if (validacao != 1) {
                    printf(VERMELHO "Digite o número da caixa.\n" RESET);
                    limpa_buffer(); 
                } else {
                    indice = caixa_escolhida - 1;
                    if (caixa_escolhida < 1 || caixa_escolhida > 5) { 
                        printf(VERMELHO "Opção inválida! Escolha de 1 a 5.\n" RESET); 
                    } else if (abertas[indice] == 1) { 
                        printf(VERMELHO "Esta caixa já está aberta. Escolha outra.\n" RESET); 
                    } else {
                        valido = 1;
                    }
                }
            }
            
            abertas[indice] = 1;
            system("cls");

            if (caixas[indice] == 1) {
                printf(VERDE "%s abriu a caixa e encontrou o botão!\n" RESET, jogador_atual);
                printf(VERDE "\n*** VITÓRIA DE %s! ***\n" RESET, jogador_atual);
                fim_jogo = 1; 
            } else if (caixas[indice] == 2) {
                printf(VERMELHO "A caixa continha uma cobra! Ela atacou %s!\n" RESET, jogador_atual);
                printf(VERMELHO "\n*** %s FOI ELIMINADO! ***\n" RESET, jogador_atual);
                fim_jogo = 1; 
            } else {
                printf("%s abriu a caixa %d e estava vazia...\n", jogador_atual, caixa_escolhida);
                printf("O jogo continua. Próximo jogador.\n");
                
                if (vez == 0) {
                    vez = 1;
                } else {
                    vez = 0;
                }
            }
        } 
        
        valido = 0;
        while (!valido) {
            printf(AMARELO "\n===============================\n" RESET);
            printf("Deseja jogar novamente?\n1- Sim\n2- Voltar ao menu\nEscolha: ");
            validacao = scanf("%d", &jogar_novamente);
            
            if (validacao != 1) { 
                printf(VERMELHO "Digite apenas números.\n" RESET); 
                limpa_buffer(); 
            } else if (jogar_novamente == 1 || jogar_novamente == 2) {
                valido = 1; 
            } else {
                printf(VERMELHO "Opção inválida!\n" RESET);
            }
        }
    } 
}

void gousmas_war() {
    int g[2][2]; 
    int jogar_novamente = 1;
    int vez, outro;
    int acao, validacao, valido;
    int atq, alvo, doa, rec, qtd;
    int turno_feito;

    while (jogar_novamente == 1) {
        g[0][0] = 1; g[0][1] = 1; 
        g[1][0] = 1; g[1][1] = 1; 
        vez = 0; 

        while (1) {
            if (vez == 0) {
                outro = 1;
            } else {
                outro = 0;
            }

            system("cls");
            printf(AZUL "=== GOUSMAS WAR ===\n" RESET);
            
            if (g[0][0] == 0 && g[0][1] == 0) {
                printf(VERDE "\n*** O JOGADOR 2 VENCEU! ***\n" RESET);
                break;
            }
            if (g[1][0] == 0 && g[1][1] == 0) {
                printf(VERDE "\n*** O JOGADOR 1 VENCEU! ***\n" RESET);
                break;
            }

            printf(CIANO "\n[ Jogador 1 ]\n" RESET);
            if (g[0][0] == 0) printf("Gousma 1: [ X ] Destruída\n"); else printf("Gousma 1: Fúria %d\n", g[0][0]);
            if (g[0][1] == 0) printf("Gousma 2: [ X ] Destruída\n"); else printf("Gousma 2: Fúria %d\n", g[0][1]);
            
            printf(VERMELHO "\n[ Jogador 2 ]\n" RESET);
            if (g[1][0] == 0) printf("Gousma 1: [ X ] Destruída\n"); else printf("Gousma 1: Fúria %d\n", g[1][0]);
            if (g[1][1] == 0) printf("Gousma 2: [ X ] Destruída\n"); else printf("Gousma 2: Fúria %d\n", g[1][1]);

            printf(AMARELO "\n-------------------------------\n");
            if (vez == 0) {
                printf("Vez do Jogador 1!\n" RESET);
            } else {
                printf("Vez do Jogador 2!\n" RESET);
            }

            turno_feito = 0;
            while (turno_feito == 0) {
                valido = 0;
                while (!valido) {
                    printf("\nEscolha sua ação:\n1 - Atacar\n2 - Dividir\nEscolha: ");
                    validacao = scanf("%d", &acao);
                    if (validacao != 1) { printf(VERMELHO "Digite apenas números.\n" RESET); limpa_buffer(); }
                    else if (acao == 1 || acao == 2) valido = 1;
                    else printf(VERMELHO "Você não pode fazer isso!\n" RESET);
                }

                if (acao == 1) {
                    valido = 0;
                    while (!valido) {
                        printf("Escolha a gousma que vai atacar(1 ou 2): ");
                        validacao = scanf("%d", &atq);
                        if (validacao != 1) { printf(VERMELHO "Digite apenas números.\n" RESET); limpa_buffer(); }
                        else if (atq < 1 || atq > 2) printf(VERMELHO "Você não pode fazer isso!\n" RESET);
                        else if (g[vez][atq - 1] == 0) printf(VERMELHO "A gousma já foi aniquilada, ataque a outra.\n" RESET);
                        else valido = 1;
                    }

                    valido = 0;
                    while (!valido) {
                        printf("Escolha a gousma para ser atacada (1 ou 2): ");
                        validacao = scanf("%d", &alvo);
                        if (validacao != 1) { printf(VERMELHO "Digite apenas números.\n" RESET); limpa_buffer(); }
                        else if (alvo < 1 || alvo > 2) printf(VERMELHO "Você não pode fazer isso!\n" RESET);
                        else if (g[outro][alvo - 1] == 0) printf(VERMELHO "A gousma já foi aniquilada, ataque a outra.\n" RESET);
                        else valido = 1;
                    }
                    
                    g[outro][alvo - 1] = g[outro][alvo - 1] + g[vez][atq - 1];
                    if (g[outro][alvo - 1] > 5) {
                        g[outro][alvo - 1] = 0;
                    }
                    turno_feito = 1;
                } 
                else if (acao == 2) {
                    if (g[vez][0] <= 1 && g[vez][1] <= 1) {
                        printf(VERMELHO "Você não tem fúria suficiente.\n" RESET);
                        continue; 
                    }
                    
                    valido = 0;
                    while (!valido) {
                        printf("Escolha a Gousma doadora (1 ou 2): ");
                        validacao = scanf("%d", &doa);
                        if (validacao != 1) { printf(VERMELHO "Digite apenas números.\n" RESET); limpa_buffer(); }
                        else if (doa < 1 || doa > 2) printf(VERMELHO "Você não pode fazer isso!\n" RESET);
                        else if (g[vez][doa - 1] <= 1) printf(VERMELHO "Fúria insuficiente(necessário pelo menos 2).\n" RESET);
                        else valido = 1;
                    }

                    if (doa == 1) {
                        rec = 2;
                    } else {
                        rec = 1;
                    }

                    valido = 0;
                    while (!valido) {
                        printf("Quantidade de fúria para transferir (1 a %d): ", g[vez][doa - 1] - 1);
                        validacao = scanf("%d", &qtd);
                        if (validacao != 1) { printf(VERMELHO "Digite apenas números.\n" RESET); limpa_buffer(); }
                        else if (qtd < 1 || qtd >= g[vez][doa - 1]) printf(VERMELHO "Quantidade inválida!\n" RESET);
                        else valido = 1;
                    }

                    g[vez][doa - 1] = g[vez][doa - 1] - qtd;
                    g[vez][rec - 1] = g[vez][rec - 1] + qtd;
                    
                    if (g[vez][rec - 1] > 5) {
                        g[vez][rec - 1] = 0;
                    }
                    turno_feito = 1;
                }
            }

            if (vez == 0) {
                vez = 1;
            } else {
                vez = 0;
            }
        } 

        valido = 0;
        while (!valido) {
            printf(AMARELO "\n===============================\n" RESET);
            printf("Deseja jogar novamente?\n1- Sim\n2- Voltar ao menu\nEscolha: ");
            validacao = scanf("%d", &jogar_novamente);
            
            if (validacao != 1) { 
                printf(VERMELHO "Digite apenas números.\n" RESET); 
                limpa_buffer(); 
            } else if (jogar_novamente == 1 || jogar_novamente == 2) {
                valido = 1; 
            } else {
                printf(VERMELHO "Opção inválida!\n" RESET);
            }
        }
    }
}