#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct
typedef struct player
{
    char name[30];
    char nation[30];
    char league[30];
    char team[30];
    char position[10];
    int age;
    int height;
    int number;
}Player;
//function
void Add(Player * arr, int * pnum);
void Delete(Player * arr, int * pnum);
void Print_List(Player * arr, int pnum);
void Search(Player * arr, int * pnum);
void Save_Data(Player * arr, int pnum);
void Load_Data(Player * arr, int * pnum);   //new function
//global
Player arr[100];
int pnum = 0;

void main(void)
{
    int m;

    system("clear");
    printf("\n\n   Player Management Program!\n\n");
    while(1)
    {
        printf("---------------------Menu--------------------\n\n");
        printf("   1. Add Player\n");
        printf("   2. Delete Player\n");
        printf("   3. Player List\n");
        printf("   4. Search Player\n");
        printf("   5. Save Data\n");
        printf("   6. Load Data\n");
        printf("   7. Exit Program\n");
        printf("   >> Select : ");
        scanf("%d", &m);
        fflush(stdin);

        switch(m)
        {
            case 1:
                Add(arr, &pnum);
                break;
            case 2:
                Delete(arr, &pnum);
                break;
            case 3:
                Print_List(arr, pnum);
                break;
            case 4:
                Search(arr, &pnum);
                break;
            case 5:
                Save_Data(arr, pnum);
                break;
            case 6:
                Load_Data(arr, &pnum);
                break;
            case 7:
                printf("\n   -> Program has been closed!\n\n");
                return;
                break;
            default :
                printf("\n   Please enter the correct menu!\n\n");
                break;
        }
    }
}

void Add(Player * arr, int * pnum)
{
    char name[30];
    char nation[30];
    char league[30];
    char team[30];
    char position[10];
    int age;
    int height;
    int number;

    int l;

    system("clear");

    printf("\n------------------------Add Player------------------------\n\n");
    printf("   Name : ");
    scanf("%s", name);
    printf("   Nation : ");
    scanf("%s", nation);
    printf("   League : 1. Premier / 2. La Liga / 3.Serie A / 4. Bundesliga\n");    //new
    printf("   >>Select : ");
    scanf("%d", &l);
    fflush(stdin);
    switch(l)
    {
        case 1:
            strcpy(league, "Premier");
            break;
        case 2:
            strcpy(league, "La Liga");
            break;
        case 3:
            strcpy(league, "Serie A");
            break;
        case 4:
            strcpy(league, "Bundesliga");
            break;
        default:
            strcpy(league, "Independent");
            break;
    }
    printf("   Team : ");
    scanf("%s", team);
    printf("   Position : ");
    scanf("%s", position);
    printf("   Age : ");
    scanf("%d", &age);
    printf("   Height : ");
    scanf("%d", &height);
    printf("   Number : ");
    scanf("%d", &number);

    strcpy(arr[*pnum].name, name);
    strcpy(arr[*pnum].nation, nation);
    strcpy(arr[*pnum].league, league);
    strcpy(arr[*pnum].team, team);
    strcpy(arr[*pnum].position, position);
    arr[*pnum].age = age;
    arr[*pnum].height = height;
    arr[*pnum].number = number;
    (*pnum)++;

    system("clear");
    printf("\n-------------Registerd Player!-------------\n\n");
}

void Delete(Player * arr, int * pnum)
{
    char name[30];
    int i, j;

    system("clear");

    printf("\n---------------Delete Player---------------\n\n");
    printf("   Enter name to delete : ");
    scanf("%s", name);

    system("clear");

    for(i=0 ; i<*pnum ; i++)
    {
        if(strcmp(arr[i].name, name) == 0)
        {
            for(j=i+1 ; j<*pnum ; j++)
            {
                strcpy(arr[j-1].name, arr[j].name);
                strcpy(arr[j-1].nation, arr[j].nation);
                strcpy(arr[j-1].league, arr[j].league);
                strcpy(arr[j-1].team, arr[j].team);
                strcpy(arr[j-1].position, arr[j].position);
                arr[j-1].age = arr[j].age;
                arr[j-1].height = arr[j].height;
                arr[j-1].number = arr[j].number;
            }
            (*pnum)--;
            return;
        }
    }

    printf("\n   -> There is no such name!\n\n");
}

void Print_List(Player * arr, int pnum)
{
    int i;

    system("clear");

    printf("\n----------------Player List----------------\n\n");

    for(i=0 ; i<pnum ; i++)
    {
        printf("   Player %d\n", i+1);
        printf("   Name : \t%s\n", arr[i].name);
        printf("   Nation : \t%s\n", arr[i].nation);
        printf("   League : \t%s\n", arr[i].league);
        printf("   Team : \t%s\n", arr[i].team);
        printf("   Position : \t%s\n", arr[i].position);
        printf("   Age : \t%d\n", arr[i].age);
        printf("   Height : \t%d\n", arr[i].height);
        printf("   Number : \t%d\n\n", arr[i].number);
    }
}

void Search(Player * arr, int * pnum)
{
    char name[30];
    int i = 0;

    system("clear");

    printf("\n-----------Search Player-----------\n\n");
    printf("   Enter name to such : ");
    scanf("%s", name);

    for(i=0 ; i<*pnum ; i++)
    {
        if(strcmp(arr[i].name, name) == 0)
        {
            printf("\n   A recognized player\n");
            printf("   Name : \t%s\n", arr[i].name);
            printf("   Nation : \t%s\n", arr[i].nation);
            printf("   League : \t%s\n", arr[i].league);
            printf("   Team : \t%s\n", arr[i].team);
            printf("   Position : \t%s\n", arr[i].position);
            printf("   Age : \t%d\n", arr[i].age);
            printf("   Height : \t%d\n", arr[i].height);
            printf("   Number : \t%d\n\n", arr[i].number);
            return;
        }
    }

    printf("\n   -> There is no such name as that!\n\n");
}

void Save_Data(Player * arr, int pnum)
{
    int i;
    FILE *fp = fopen("data.txt", "wt");
    if(fp == NULL)
    {
        printf("   \nFailed to open file!\n\n");
        return;
    }

    for(i=0 ; i<pnum ; i++)
    {
        fprintf(fp, "%s\n", arr[i].name);
        fprintf(fp, "%s\n", arr[i].nation);
        fprintf(fp, "%s\n", arr[i].league);
        fprintf(fp, "%s\n", arr[i].team);
        fprintf(fp, "%s\n", arr[i].position);
        fprintf(fp, "%d\n", arr[i].age);
        fprintf(fp, "%d\n", arr[i].height);
        fprintf(fp, "%d\n\n", arr[i].number);
    }

    system("clear");
    printf("\n----------Saved Player Information!----------\n\n");
}


void Load_Data(Player * arr, int * pnum)
{
    FILE *fp = fopen("data.txt", "rt");
    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        fscanf(fp, "%s", arr[*pnum].name);
        fscanf(fp, "%s", arr[*pnum].nation);
        fscanf(fp, "%s", arr[*pnum].league);
        fscanf(fp, "%s", arr[*pnum].team);
        fscanf(fp, "%s", arr[*pnum].position);
        fscanf(fp, "%d", &arr[*pnum].age);
        fscanf(fp, "%d", &arr[*pnum].height);
        fscanf(fp, "%d", &arr[*pnum].number);

        if(feof(fp) != 0)
            break;
        (*pnum)++;
    }

    system("clear");
    printf("\n----------Loaded Player Information----------\n\n");
}
