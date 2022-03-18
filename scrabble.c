#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"util/scrabble.h"
#include"util/print_board.h"
#define BOARD_SIZE	15


// Am facut o functie care imi calculeaza punctajul pentru un cuvant dat,
// tinand cont si de tabla de bonus
int punctaj_cuvant(char cuvant[20], int n, int m, int d, char XX[2], char YY[2])
{
    int punct = 0, lungime, i, punctaj = 0;
    char c;
    lungime = strlen(cuvant);
    for(i = 0; i < lungime; i++)
    {
        c = cuvant[i];
        if(c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' ||
            c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
        {
             punct = 1;
        }
        if(c == 'D' || c == 'G')
        {
            punct = 2;
        }
        if(c == 'B' || c == 'C' || c == 'M' || c == 'P')
        {
            punct = 3;
        }
        if(c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
        {
            punct = 4;
        }
        if(c == 'K')
        {
            punct = 5;
        }
        if(c == 'J' || c == 'X')
        {
            punct = 8;
        }
        if(c == 'Q' || c == 'Z')
        {
            punct = 10;
        }
        punctaj += punct; 
        
    }

    int conditie1=0, conditie2=0;

    for (i = 0; i < lungime - 1; i++)
    {
        if(((XX[0] == cuvant[i]) && (XX[1] == cuvant[i+1])))
            {
                conditie1 = 1;
            }
    }
    if ((YY[0] == cuvant[lungime - 2]) && (YY[1] == cuvant[lungime - 1]))
        {
            conditie2 = 1;
        }

    if(d == 0)
    {
        for(i = 0; i < lungime; i++)
        {
            if((bonus_board[n][m+i] == 1) && (conditie1 == 1))
            {
                punctaj = punctaj * 2;
            }
            if((bonus_board[n][m+i] == 2) && (conditie2 == 1))
            {
                punctaj = punctaj * 3;
            }

        }
    }
    if(d == 1)
    {
        for(i = 0; i < lungime; i++)
        {
            if((bonus_board[n+i][m] == 1) && (conditie1 == 1))
            {
                punctaj = punctaj * 2;
            }
            if(bonus_board[n+i][m] == 2 && conditie2 == 1)
            {
                punctaj = punctaj * 3;
            }

        }
    }

    return punctaj;

}

void task0(char B[BOARD_SIZE][BOARD_SIZE])
{
    print_board(B);
}
void task1(char b[BOARD_SIZE][BOARD_SIZE])
{   int i, v[3], n, m, d, lungime, stop=0, x;
    char *p, str[100], cuvant[20], litera;
    // Am ales sa citesc inputul, folosind fgets si
    // strcspn pentru a sterge enter-ul aflat la finalul fiecarei linii.
    // Prima data citesc numarul de linii care urmeaza sa fie citite in while.
    fgets(str, 10, stdin);
    str[strcspn(str, "\n")] = 0;
    x = atoi(str);
    while(1)
    {
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = 0;
        p = strtok(str," ");
        int j=0;
        // Cu functia strtok separ fiecare linie in string-uri separate.
        while (p != NULL) 
        {
            if(j < 3)
            {
                v[j] = atoi(p);
                j++;
                // Cum primele 3 string-uri sunt mereu coordonatele
                // folosesc atoi ca sa le transform in valori de numere
                // si le pun intr-un vector de numere intregi.
            } else 
            {   
                strcpy(cuvant, p);
                // La final copiez string-ul spre care pointa p
                // in alt string pentru a lucra mai usor cu el.
            }
            
            p = strtok(NULL, " ");

        }
        n = v[0];
        m = v[1];
        d = v[2];
        // Pentru comoditate copiez valorile aferente coordonatelor
        // in alte variabile.
        lungime = strlen(cuvant);
        // Prima data verific care este directia cuvantului,
        // apoi pun fiecare litera pe tabla.
        if(d == 0)
        {   for(i = 0; i < lungime; i++)
            {   litera = cuvant[i];
                b[n][m+i] = litera;
            }
        } else if(d == 1)
        {
            for(i = 0; i < lungime; i++)
            {   litera = cuvant[i];
                b[n+i][m] = litera;
            }
        }
        // Am folosit variabila stop pentru nu a modifica valoarea lui x
        // Aceasta este mai intai marita si apoi se verfica conditia din if
        // si de asta am pus stop < x - 1.
        if(stop < x-1)
        {
            stop++;
        } else
        {
            break;
        }
        
    }
}

void task2(int *p1, int *p2, int x)
{
    int i, j=0, player1=0, player2=0, lungime, stop=0, punct;
    char *p, str[100], cuvant[20], c;
    while(1)
    {
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = 0;
        p = strtok(str," ");
        while (p != NULL) 
        {
            if(j < 3)
            {
                j++;
            } else 
            {   
                strcpy(cuvant, p);
            }
            
            p = strtok(NULL, " ");

        }
        lungime = strlen(cuvant);
        // Am copiat fiecare litera din cuvintele primite ca input in c,
        // si in functie de ce litera este atribui o valoare variabilei punct.
        for(i = 0; i < lungime; i++)
        {
            c = cuvant[i];
            if(c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' ||
                c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
            {
                punct = 1;
            }
            if(c == 'D' || c == 'G')
            {
                punct = 2;
            }
            if(c == 'B' || c == 'C' || c == 'M' || c == 'P')
            {
                punct = 3;
            }
            if(c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
            {
                punct = 4;
            }
            if(c == 'K')
            {
                punct = 5;
            }
            if(c == 'J' || c == 'X')
            {
                punct = 8;
            }
            if(c == 'Q' || c == 'Z')
            {
                punct = 10;
            }
            // Mai intai verific carui jucator ii apartine cuvantul
            // si apoi ii adaug in punctaj variabila punct.
            if(stop % 2 == 0)
            {
                player1 = player1 + punct;
            } else 
            {
                player2 = player2 + punct;
            }
        }
        if(stop < x-1)
        {
            stop++;
        } else
        {
            break;
        }
    }
    // Am folosit pointeri pentru ca am vrut sa refolosesc aceasta funtie la task5,
    // dar input-urile au fost diferite in cele doua cazuri si nu am reusit.
    // Folosind pointeri am modificat direct o valoare stocata intr-o adresa
    // pe care pot sa o accesez dupa rularea functiei si sa extrag
    // valoarea noua din ea.
    *p1 = player1;
    *p2 = player2;

}

void task3(int *p1, int *p2, char YY[2], char XX[2], int x)
{
    int i, v[3], n, m, d, lungime, stop=0, punct, conditie1=0, conditie2=0;
    char *p, str[100], cuvant[20], c;
    int player1[x], player2[x], punctaj_1=0, punctaj_2=0;

    for (i = 0; i < x; i++)
    {
        player1[i] = 0;
        player2[i] = 0;

    }

    while(1)
    {
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = 0;
        p = strtok(str," ");
        int j=0;
        while (p != NULL) 
        {
            if(j < 3)
            {
                v[j] = atoi(p);
                j++;
            } else 
            {   
                strcpy(cuvant, p);
            }
            
            p = strtok(NULL, " ");

        }
        n = v[0];
        m = v[1];
        d = v[2];
        lungime = strlen(cuvant);
        for(i = 0; i < lungime; i++)
        {
            c = cuvant[i];
            if(c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' ||
                c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
            {
                punct = 1;
            }
            if(c == 'D' || c == 'G')
            {
                punct = 2;
            }
            if(c == 'B' || c == 'C' || c == 'M' || c == 'P')
            {
                punct = 3;
            }
            if(c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
            {
                punct = 4;
            }
            if(c == 'K')
            {
                punct = 5;
            }
            if(c == 'J' || c == 'X')
            {
                punct = 8;
            }
            if(c == 'Q' || c == 'Z')
            {
                punct = 10;
            }

            if(stop % 2 == 0)
            {
                player1[stop] = player1[stop] + punct;
            } else 
            {
                player2[stop] = player2[stop] + punct;
            }
        }
        // Pentru a verifica daca cuvintele indeplinesc prima conditie de bonus
        // am pus conditia ca orice doua litere dintr-un cuvant sa corespunda
        // cu primul substring din input, caz in care setez un flag.

        for (i = 0; i < lungime - 1; i++)
        {
            if(((XX[0] == cuvant[i]) && (XX[1] == cuvant[i+1])))
                {
                   conditie1 = 1;
               }
        }
        // La a doua conditie de bonus am pus conditia ca doar ultimele litere
        // din cuvant sa corespunda cu al doilea substring dat.
         if ((YY[0] == cuvant[lungime - 2]) && (YY[1] == cuvant[lungime - 1]))
            {
                conditie2 = 1;
            }

        // In functie de directie verific daca cuvintele intersecteaza
        // un 1 sau un 2 pe tabla de bonus, si folosindu-ma de flag-urile
        // de mai sus am dublat sa triplat punctajul obtinut
        // de fiecare jucator pentru cuvantul respectiv.
        if(d == 0)
        {
            for(i = 0; i < lungime; i++)
            {
                if((bonus_board[n][m+i] == 1) && (conditie1 == 1))
                {
                    if(stop % 2 == 0)
                    {
                        player1[stop] = player1[stop] * 2;
                    } else 
                    {
                        player2[stop] = player2[stop] * 2;
                    }
                }
                if((bonus_board[n][m+i] == 2) && (conditie2 == 1))
                {
                    if(stop % 2 == 0)
                    {
                        player1[stop] = player1[stop] * 3;
                    } else 
                    {
                        player2[stop] = player2[stop] * 3;
                    }
                }

            }
        }
        if(d == 1)
        {
            for(i = 0; i < lungime; i++)
            {
                if((bonus_board[n+i][m] == 1) && (conditie1 == 1))
                {
                    if(stop % 2 == 0)
                    {
                        player1[stop] = player1[stop] * 2;
                    } else 
                    {
                        player2[stop] = player2[stop] * 2;
                    }
                }
                if(bonus_board[n+i][m] == 2 && conditie2 == 1)
                {

                    if(stop % 2 == 0)
                    {
                        player1[stop] = player1[stop] * 3;
                    } else 
                    {
                        player2[stop] = player2[stop] * 3;
                    }
                    
                }

            }
        }
        // Aici restez flag-urile
        // ca sa nu fie considerate adevarate la urmatorul cuvant.
        conditie2 = 0;
        conditie1 = 0;

        if(stop < x-1)
        {
            stop++;
        } else
        {
            break;
        }
        
        
    }
    // Am stocat fiecare punctaj obtinut de cei doi jucatori pentru
    // fiecare cuvant in parte in doi vectori, iar la final
    // am adunat toate elementele din ei ca sa obtin punctajul final.

    for(i = 0; i < x; i += 2)
    {
        punctaj_1 += player1[i];
    }
    for(i = 1; i < x; i += 2)
    {
        punctaj_2 += player2[i];
    }
    *p1 = punctaj_1;
    *p2 = punctaj_2;
}


void task4(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j, v[3], n[20], m[20], d[20], lungime[20], stop=0, x;
    char *p, str[100], XX[2], YY[2], cuvant[100][20];

    fgets(XX, 100, stdin);
    XX[strcspn(XX, "\n")] = 0;

    fgets(YY, 100, stdin);
    YY[strcspn(YY, "\n")] = 0;

    fgets(str, 10, stdin);
    str[strcspn(str, "\n")] = 0;
    x = atoi(str);

    while(1)
    {
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = 0;
        p = strtok(str," ");
        int j=0;
        while (p != NULL) 
        {
            if(j < 3)
            {
                v[j] = atoi(p);
                j++;
            } else 
            {   
                strcpy(cuvant[stop], p);
            }
            
            p = strtok(NULL, " ");

        }
        // De data asta am stocat coodrdonatele si directia in vectori
        // pentru ca am nevoie sa le stiu pentru fiecare cuvant.
        n[stop] = v[0];
        m[stop] = v[1];
        d[stop] = v[2];
        // La fel am facut si pentru lungime.
        lungime[stop] = strlen(cuvant[stop]);
        if(stop < x-1)
        {
            stop++;
        } else
        {
            break;
        }

    }

    int stop2=0;
    // Cu acest while pun pe tabla toate cuvintele stocate mai sus,
    // folosindu-ma de vectorii ce contin datele despre ele.
    while(1)
    {
        if(d[stop2] == 0)
        {   for(i = 0; i < lungime[stop2]; i++)
            {
               board[n[stop2]][m[stop2]+i] = cuvant[stop2][i];
            }
        } else if(d[stop2] == 1)
        {
            for(i = 0; i < lungime[stop2]; i++)
            {
                board[n[stop2]+i][m[stop2]] = cuvant[stop2][i];
            }
        }
        if(stop2 < x-1)
        {
            stop2++;
        } else
        {
            break;
        }
        
    }

    int c_orizontala = 1, c_verticala = 1,c_intersectie_o = 1, c_intersectie_v = 1; 
    int c_lista = 1, u, w, k, l_cuvant, stop3=0, oprire = 0;
    char cuvant_posibil[20];

    // Cu acest while verific daca un cuvant poate fi pus pe tabla
    // si il pun pe primul de pe lista care indeplineste conditiile.
    while (1)
    {
        // Pentru fiecare cuvant din lista parcurg un set de conditii,
        // *incepand de la primul.
        for(i = 0; i < 100; i++)
        {
            // Aici verfic daca a mai fost jucat cuvantul.
            for(j = 0; j < x; j++)
            {                
                if(strcmp(words[i], cuvant[j]) == 0)
                {   
                    c_lista = 0;
                }
            }
            // Daca a mai fost jucat se trece la urmatorul din lista.
            if (c_lista == 0)
            {
                c_lista = 1;
                continue;
            }

            

            strcpy(cuvant_posibil, words[i]);
            l_cuvant = strlen(cuvant_posibil);
            // Cu aceste doua for-uri parcurg toata tabla.
            for(u = 0; u < 15; u++)
            {
                for(w = 0; w < 15; w++)
                {
                    // Verific daca prima litera din cuvant se afla pe tabla.
                    if(cuvant_posibil[0] == board[u][w])
                    {   
                        // Verific daca acesta poate fi pus pe tabla fara sa iasa
                        // in afara ei, atat pe orizontala, cat si pe verticala.
                        if(w + l_cuvant - 1 <= 15)

                        {
                            c_orizontala = 0;
                            for(k = 0; k < l_cuvant - 1; k++)
                            {
                                // Verific daca pe locul unde ar trebui sa fie pus
                                // cuvantul se afla alte litere.
                                if(board[u][w+k+1] != '.') 
                                {
                                    c_intersectie_o = 1;
                                    
                                } else
                                {
                                    c_intersectie_o = 0;
                                }
                                // Daca cuvantul intersecteaza alte litere ies din for
                                // pentru ca altfel ar ramane date doar despre ultima
                                // pozitia ultimei litere din cuvant.
                                if(c_intersectie_o == 1)
                                {
                                    break;
                                }
                            }
                            
                        }
                        
                        if(u + l_cuvant - 1 <= 15)
                        {
                            c_verticala = 0;
                            for(k = 0; k < l_cuvant - 1; k++)
                            {
                                if(board[u+k+1][w] != '.')
                                {
                                    c_intersectie_v = 1;
                                    
                                } else
                                {
                                    c_intersectie_v = 0;
                                }
                                if(c_intersectie_v == 1)
                                {
                                    break;
                                }
                                
                            }
                        }
                    }
                    // In funtie de flag-uri pun sau nu pe tabla cuvantul.
                    if(c_intersectie_o == 0 && c_orizontala == 0)
                    {
                        oprire = 1;
                        for(k = 0; k < l_cuvant - 1; k++)
                        {   
                            board[u][w+k+1] = cuvant_posibil[k+1];
                        }
                    } else if(c_intersectie_v == 0 && c_verticala == 0)
                    {
                        oprire = 1;
                        for(k = 0; k < l_cuvant - 1; k++)
                        {
                            board[u+k+1][w] = cuvant_posibil[k+1];
                        }
                    }
                    // Daca a fost pus un cuvant ies din while-ul initial.
                    if(oprire == 1)
                    {   
                        break;
                    }
                }
                c_orizontala = 1;
                c_verticala = 1;
                c_intersectie_o = 1;
                c_intersectie_v = 1;
            }

            if(oprire == 1)
                {   
                    break;
                }
        }
        if(oprire == 1)
        {   
            break;
        }
        if(stop3 < x-1)
        {
            stop3++;
        } else
        {
            break;
        }


    }
    print_board(board);

}

void task5(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j, v[3], n[20], m[20], d[20], lungime[20], stop=0, x;
    char *p, str[100], XX[2], YY[2], cuvant[100][20];

    fgets(XX, 100, stdin);
    XX[strcspn(XX, "\n")] = 0;

    fgets(YY, 100, stdin);
    YY[strcspn(YY, "\n")] = 0;

    fgets(str, 10, stdin);
    str[strcspn(str, "\n")] = 0;
    x = atoi(str);
    // Stochez datele despre cuvinte.
    while(1)
    {
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = 0;
        p = strtok(str," ");
        int j=0;
        while (p != NULL) 
        {
            if(j < 3)
            {
                v[j] = atoi(p);
                j++;
            } else 
            {   
                strcpy(cuvant[stop], p);
            }
            
            p = strtok(NULL, " ");

        }
        n[stop] = v[0];
        m[stop] = v[1];
        d[stop] = v[2];
        lungime[stop] = strlen(cuvant[stop]);
        if(stop < x-1)
        {
            stop++;
        } else
        {
            break;
        }

    }
    // La fel ca la task-ul 3 calculez puntajele jucatorilor,
    // dar acum folosesc datele stocate in vectori.
    int punct, conditie1 = 0, conditie2 = 0;
    int player1[x], player2[x], punctaj_1=0, punctaj_2=0;
    char c;
    int stop2=0;

    for (i = 0; i < x; i++)
    {
        player1[i] = 0;
        player2[i] = 0;

    }


    while(1)
    {
        if(d[stop2] == 0)
        {   for(i = 0; i < lungime[stop2]; i++)
            {
               board[n[stop2]][m[stop2]+i] = cuvant[stop2][i];
            }
        } else if(d[stop2] == 1)
        {
            for(i = 0; i < lungime[stop2]; i++)
            {
                board[n[stop2]+i][m[stop2]] = cuvant[stop2][i];
            }
        }

        for(i = 0; i < lungime[stop2]; i++)
        {
            c = cuvant[stop2][i];
            if(c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' ||
                 c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
            {
                punct = 1;
            }
            if(c == 'D' || c == 'G')
            {
                punct = 2;
            }
            if(c == 'B' || c == 'C' || c == 'M' || c == 'P')
            {
                punct = 3;
            }
            if(c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
            {
                punct = 4;
            }
            if(c == 'K')
            {
                punct = 5;
            }
            if(c == 'J' || c == 'X')
            {
                punct = 8;
            }
            if(c == 'Q' || c == 'Z')
            {
                punct = 10;
            }

            if(stop2 % 2 == 0)
            {
                player1[stop2] = player1[stop2] + punct;
            } else 
            {
                player2[stop2] = player2[stop2] + punct;
            }
        }

        for (i = 0; i < lungime[stop2] - 1; i++)
        {
            if(((XX[0] == cuvant[stop2][i]) && (XX[1] == cuvant[stop2][i+1])))
                {
                   conditie1 = 1;
               }
        }
         if ((YY[0] == cuvant[stop2][lungime[stop2] - 2]) &&
                (YY[1] == cuvant[stop2][lungime[stop2] - 1]))
            {
                conditie2 = 1;
            }

        if(d[stop2] == 0)
        {
            for(i = 0; i < lungime[stop2]; i++)
            {
                if((bonus_board[n[stop2]][m[stop2]+i] == 1) &&
                    (conditie1 == 1))
                {
                    if(stop2 % 2 == 0)
                    {
                        player1[stop2] = player1[stop2] * 2;
                    } else 
                    {
                        player2[stop2] = player2[stop2] * 2;
                    }
                }
                if((bonus_board[n[stop2]][m[stop2]+i] == 2) &&
                    (conditie2 == 1))
                {
                    if(stop2 % 2 == 0)
                    {
                        player1[stop2] = player1[stop2] * 3;
                    } else 
                    {
                        player2[stop2] = player2[stop2] * 3;
                    }
                }

            }
        }
        if(d[stop2] == 1)
        {
            for(i = 0; i < lungime[stop2]; i++)
            {
                if((bonus_board[n[stop2]+i][m[stop2]] == 1) &&
                    (conditie1 == 1))
                {
                    if(stop2 % 2 == 0)
                    {
                        player1[stop2] = player1[stop2] * 2;
                    } else 
                    {
                        player2[stop2] = player2[stop2] * 2;
                    }
                }
                if(bonus_board[n[stop2]+i][m[stop2]] == 2 && conditie2 == 1)
                {

                    if(stop2 % 2 == 0)
                    {
                        player1[stop2] = player1[stop2] * 3;
                    } else 
                    {
                        player2[stop2] = player2[stop2] * 3;
                    }
                    
                }

            }
        }
        
        conditie2 = 0;
        conditie1 = 0;

        if(stop2 < x-1)
        {
            stop2++;
        } else
        {
            break;
        }
    }

    for(i = 0; i < x; i += 2)
    {
        punctaj_1 += player1[i];
    }
    for(i = 1; i < x; i += 2)
    {
        punctaj_2 += player2[i];
    }
    
    
    int c_orizontala=1, c_verticala=1,c_intersectie_o=1, c_intersectie_v=1;
    int punctaj, linia, coloana, directie, c_lista=1;
    int u, k, w, max=-99, len, l_cuvant;
    char cuvant_posibil[20], best[20];

    // Prima parte a while-ului este asemanatoare cu cel de la task-ul 4,
    // doar ca acum prioritizez pozitia pe care se poate pune un cuvant,
    // nu al catelea este in lista de cuvinte.
    while (1)
    {
            for(u = 0; u < 15; u++)
            {
                for(w = 0; w < 15; w++)
                {
                    for(i = 0; i < 100; i++)
                    {
                        for(j = 0; j < x; j++)
                        {                
                            if(strcmp(words[i], cuvant[j]) == 0)
                            {   
                                c_lista = 0;
                            }
                        }
                        if (c_lista == 0)
                        {
                            c_lista = 1;
                            continue;
                        }

                        strcpy(cuvant_posibil, words[i]);
                        l_cuvant = strlen(cuvant_posibil);
                        if(cuvant_posibil[0] == board[u][w])
                        {   
                            if(w + l_cuvant <= 15)
                            {
                                c_orizontala = 0;
                                for(k = 0; k < l_cuvant - 1; k++)
                                {
                                    if(board[u][w+k+1] != '.') 
                                    {
                                        c_intersectie_o = 1;
                                        break;
                                        
                                    } else
                                    {
                                        c_intersectie_o = 0;
                                    }
                                }
                                
                            }
                            
                            if(u + l_cuvant - 1 <= 15)
                            {
                                c_verticala = 0;
                                for(k = 0; k < l_cuvant - 1; k++)
                                {
                                    if(board[u+k+1][w] != '.')
                                    {
                                        c_intersectie_v = 1;
                                        break;
                                        
                                    } else
                                    {
                                        c_intersectie_v = 0;
                                    }
                                    
                                }
                            }
                            // Pana aici am verificat daca un cuvant poate fi pus pe tabla.
                            if(c_intersectie_o == 0 && c_orizontala == 0)
                            {
                                // Calculez puntajul maxim pe care il poate produce un cuvant
                                // daca este pus pe orizontala sau vericala si ii copiez datele.
                                punctaj = punctaj_cuvant(cuvant_posibil, u, w, 0, XX, YY);
                                if(punctaj > max)
                                {
                                    max = punctaj;
                                    strcpy(best, cuvant_posibil);
                                    linia = u;
                                    coloana = w;
                                    directie = 0;
                                    len = strlen(cuvant_posibil);
                                }
                            } else if(c_intersectie_v == 0 && c_verticala == 0)
                            {
                                punctaj = punctaj_cuvant(cuvant_posibil, u, w, 1, XX, YY);
                                if(punctaj > max)
                                {
                                    max = punctaj;
                                    strcpy(best, cuvant_posibil);
                                    linia = u;
                                    coloana = w;
                                    directie = 1;
                                    len = strlen(cuvant_posibil);
                                }
                            }
                        }
                    }
                    // Resetez flag-urile.
                    c_orizontala = 1;
                    c_verticala = 1;
                    c_intersectie_o = 1;
                    c_intersectie_v = 1;
                }
            }
            // Cand am trecut prin toate cuvintele din lista, ies din while.
            if(i == 100)
            {
                break;
            }
        }
    // Daca exista un cuvant care imi aduce castigul sau egalul
    // il pun pe tabla folosind datele copiate mai sus.
    if(max + punctaj_2 >= punctaj_1)
    {
        if(directie == 0)
            {   for(i = 0; i < len; i++)
                {
                board[linia][coloana+i] = best[i];
                }
            } else if(directie == 1)
            {
                for(i = 0; i < len; i++)
                {
                    board[linia+i][coloana] = best[i];
                }
            }
        print_board(board);
    // Daca nu exista afisez mesajul "Fail!".
    } else
    {   
        printf("Fail!\n");
    }
}  

int main ()
{
    char board[BOARD_SIZE][BOARD_SIZE] = 
    {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    char str[40], XX[2], YY[2];
    // Citesc prima linie din input si ii iau valoarea numerica
    // folosind functia atoi.
    fgets(str, 10, stdin);
    str[strcspn(str, "\n")] = 0;
    int x = atoi(str), player1, player2, X;
    // In functie de x apelez functia pentru task-ul aferent.
    switch (x)
    {
    case 0:
        task0(board);
        break;
    case 1:
        task1(board);
        print_board(board);
        break;
    case 2:
        fgets(str, 10, stdin);
        str[strcspn(str, "\n")] = 0;
        X = atoi(str);
        task2(&player1, &player2, X);
        printf("Player 1: %d Points\n", player1);
        printf("Player 2: %d Points\n", player2);
         
        break;
    case 3:
        fgets(XX, 100, stdin);
        XX[strcspn(XX, "\n")] = 0;

        fgets(YY, 100, stdin);
        YY[strcspn(YY, "\n")] = 0;

        fgets(str, 10, stdin);
        str[strcspn(str, "\n")] = 0;
        X = atoi(str);
        task3(&player1, &player2, YY, XX, X);
        printf("Player 1: %d Points\n", player1);
        printf("Player 2: %d Points\n", player2);
        break;
    case 4:
        task4(board);
        break;
    case 5:
        task5(board);
        break;
    default:
        break;
    }

    return 0;
}