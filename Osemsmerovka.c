#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

//	POPIS:
//	Subor obsahujuci definicie osemsmerovky a zoznamu slov.

// rozmery osemsmerovky
#define N 12
#define M 12

// rozmery zoznamu slov
#define POCET_SLOV 23
#define max_dlzka_slova 50

char osemsmerovka[N][M];
char pomocna[N][M];
char zoznamSlov[POCET_SLOV][max_dlzka_slova];


// osemsmerovka
char osemsmerovka[N][M] = {
        {"SLFOTOALBUMP"},

        {"VERTARAPATEO"},
        {"EZPOTOKARBOZ"},
        {"TNNATEVERKAG"},
        {"OARACAODUZDZ"},
        {"NMARMALOVTRM"},
        {"AOACVEIDLHAN"},
        {"ZDPRIESTUPOK"},
        {"OACIPOETICUS"},
        {"RLMOGARDISTA"},
        {"VMASTUPENECN"},
        {"IVYSTAVISKOE"}



};
char pomocna[N][M];

// zoznam slov
char zoznamSlov[POCET_SLOV][max_dlzka_slova] = {
        {"APARAT"},
        {"DARCEK"},
        {"DIEVCA"},
        {"DLATO"},
        {"DLHAN"},
        {"DZUDO"},
        {"ETAPA"},
        {"FOTOALBUM"},
        {"GARDISTA"},
        {"KREVETA"},
        {"MLADOMANZEL"},
        {"MRTVOLA"},
        {"NAMESTIE"},
        {"OPICA"},
        {"POTOK"},
        {"PRESILOVKA"},
        {"PRIESTUPOK"},
        {"STUPENEC"},
        {"SUCIT"},
        {"SVETONAZOR"},
        {"VYSTAVISKO"},
        {"ZABAL"},
        {"ZOBRAK"}
};
// Funkcia na vypráznenie stringu
void clean(char *var)
{
    int i =0;
    while(var[i]!='\0')
    {
        var[i]='\0';
        i++;
    }
}
// Funkcia na zobrazenie nevylustenej osemsmerovky
void zobraz() {
    int i ,j;
    for (i=0;i<N;i++)
    {

        for (j=0;j<M;j++)
        {
            if(j==0)
                printf("\n");
            printf("%c",pomocna[i][j]);

        }}

    printf("\n\n");
    for (i=0;i<N;i++)
    {

        for (j=0;j<M;j++)
        {
            if(j==0)
                printf("\n");
            printf("%c",osemsmerovka[i][j]);
        }}}

void zobrazZoznamSlov()
{
    int i;
    printf("\n Vypis zoznamu slov.\n");
    for (i=0;i<POCET_SLOV;i++)
    {
        printf("%s,",zoznamSlov[i]);
    }


}

void najdiSlovo(int index_slova) {

    int i,j,k,l;
    char s[20];



    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            if (osemsmerovka[i][j]==zoznamSlov[index_slova][0])
            {


                for (l=0;l<max_dlzka_slova;l++)
                {
                    // dolava
                    s[l]=osemsmerovka[i][j-l];
                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);


                        for(k=0;k<poc;k++)
                        {
                            pomocna[i][j-k]=osemsmerovka[i][j-k];

                        }
                    }
                }
                clean(s);
                for (l=0;l<max_dlzka_slova;l++)
                {
                    // dolava
                    s[l]=osemsmerovka[i][j-l];
                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);


                        for(k=0;k<poc;k++)
                        {
                            pomocna[i][j-k]=osemsmerovka[i][j-k];

                        }
                    }
                }
                clean(s);
                for (l=0;l<max_dlzka_slova;l++)
                {
                    // dole
                    s[l]=osemsmerovka[i+l][j];
                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);
                        for(k=0;k<poc;k++)
                        {
                            pomocna[i+k][j]=osemsmerovka[i+k][j];

                        }

                        //	break;
                    }
                }
                clean(s);

                for (l=0;l<max_dlzka_slova;l++)
                {
                    //doprava
                    s[l]=osemsmerovka[i][j+l];
                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);
                        for(k=0;k<poc;k++)
                        {
                            pomocna[i][j+k]=osemsmerovka[i][j+k];

                        }
                    }
                }
                clean(s);

                for (l=0;l<max_dlzka_slova;l++)
                {
                    // hore

                    s[l]=osemsmerovka[i-l][j];

                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);
                        for(k=0;k<poc;k++)
                        {
                            pomocna[i-k][j]=osemsmerovka[i-k][j];

                        }
                    }
                }
                clean(s);
                for (l=0;l<max_dlzka_slova;l++)
                {
                    // doprava

                    s[l]=osemsmerovka[i][j+l];

                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);
                        for(k=0;k<poc;k++)
                        {
                            pomocna[i][j+k]=osemsmerovka[i][j+k];

                        }
                    }
                }
                clean(s);

                for (l=0;l<max_dlzka_slova;l++)
                {
                    //doprava hore
                    s[l]=osemsmerovka[i-l][j+l];
                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);
                        for(k=0;k<poc;k++)
                        {
                            pomocna[i-k][j+k]=osemsmerovka[i-k][j+k];

                        }

                    }

                }

                clean(s);
                for (l=0;l<max_dlzka_slova;l++)
                {
                    //dolava hore

                    s[l]=osemsmerovka[i-l][j-l];
                    if (strcmp(s,zoznamSlov[index_slova]) ==0)
                    {
                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);
                        for(k=0;k<poc;k++)
                        {
                            pomocna[i-k][j-k]=osemsmerovka[i-k][j-k];

                        }

                    }


                }
                clean(s);


                for (l=0;l<max_dlzka_slova;l++)
                {
                    // doprava dole
                    s[l]=osemsmerovka[i+l][j+l];
                    if (strcmp(s,zoznamSlov[index_slova]) ==0)

                    {

                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);

                        for(k=0;k<poc;k++)
                        {
                            pomocna[i+k][j+k]=osemsmerovka[i+k][j+k];

                        }

                    }



                }
                clean(s);
                for (l=0;l<max_dlzka_slova;l++)
                {
                    //dolava dole
                    s[l]=osemsmerovka[i+l][j-l];

                    if (strcmp(s,zoznamSlov[index_slova]) ==0)

                    {

                        int poc=0;
                        poc=strlen(zoznamSlov[index_slova]);
                        for(k=0;k<poc;k++)
                        {
                            pomocna[i+k][j-k]=osemsmerovka[i+k][j-k];

                        }

                    }




                }
                clean(s);


            }

        }
    }






}

void tajnicka() {
    char slovo[20];
    int i,j,l=0,m;
    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            if ((osemsmerovka[i][j])!=(pomocna[i][j])){
                slovo[l]=osemsmerovka[i][j];
                l++;
            }
        }
    }
    printf("Ziskanie a vypis textu tajnicky.");
    int dlzka_slova;
    dlzka_slova = strlen(slovo);
    for (m = 0; m < dlzka_slova; m++)
        printf("%c",slovo[m]);
}




int main() {
    int i;


//	 vypis osemsmerovky
    printf("\n    Osemsmerovka:\n");

    //sleep(3);
    for (i;i<POCET_SLOV;i++)
    {
        najdiSlovo(i);
        zobraz();
        printf(" \n");
        zobrazZoznamSlov();
        sleep(1);
        system("cls");


    }
    zobraz();



    printf("\n\n    ");
    tajnicka();
    return 0;
}
